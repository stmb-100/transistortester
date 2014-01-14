
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <stdlib.h>
#include <string.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <math.h>

#define MAIN_C
#include "Transistortester.h"

#ifndef INHIBIT_SLEEP_MODE
  // prepare sleep mode
  EMPTY_INTERRUPT(TIMER2_COMPA_vect);
  EMPTY_INTERRUPT(ADC_vect);
#endif

//begin of transistortester program
int main(void) {
  uint8_t ii;
  unsigned int max_time;
#ifdef SEARCH_PARASITIC
  unsigned long n_cval;		// capacitor value of NPN B-E diode, for deselecting the parasitic Transistor
  int8_t n_cpre;		// capacitor prefix of NPN B-E diode
#endif
  //switch on
  ON_DDR = (1<<ON_PIN);			// switch to output
#ifdef PULLUP_DISABLE
  ON_PORT = (1<<ON_PIN); 		// switch power on 
#else
  ON_PORT = (1<<ON_PIN)|(1<<RST_PIN); 	// switch power on , enable internal Pullup for Start-Pin
#endif
  uint8_t tmp;
  //ADC-Init
  ADCSRA = (1<<ADEN) | AUTO_CLOCK_DIV;	//prescaler=8 or 64 (if 8Mhz clock)
#ifdef __AVR_ATmega8__
// #define WDRF_HOME MCU_STATUS_REG
 #define WDRF_HOME MCUCSR
#else
 #define WDRF_HOME MCUSR
#endif
  tmp = (WDRF_HOME & (1<<WDRF));	// save Watch Dog Flag
  WDRF_HOME &= ~(1<<WDRF);	 	//reset Watch Dog flag
  wdt_disable();			// disable Watch Dog
#ifndef INHIBIT_SLEEP_MODE
  // switch off unused Parts
  PRR = (1<<PRTWI) | (1<<PRTIM0) | (1<<PRSPI) | (1<<PRUSART0);
  DIDR0 = (1<<ADC5D) | (1<<ADC4D) | (1<<ADC3D);	
  TCCR2A = (0<<WGM21) | (0<<WGM20);		// Counter 2 normal mode
 #if F_CPU <= 1000000UL
  TCCR2B = (1<<CS22) | (0<<CS21) | (1<<CS20);	//prescaler 128, 128us @ 1MHz
  #define T2_PERIOD 128
 #endif 
 #if F_CPU == 2000000UL
  TCCR2B = (1<<CS22) | (1<<CS21) | (0<<CS20);	//prescaler 256, 128us @ 2MHz
  #define T2_PERIOD 128
 #endif 
 #if F_CPU == 4000000UL
  TCCR2B = (1<<CS22) | (1<<CS21) | (0<<CS20);	//prescaler 256, 64us @ 2MHz
  #define T2_PERIOD 64
 #endif 
 #if F_CPU >= 8000000UL
  TCCR2B = (1<<CS22) | (1<<CS21) | (1<<CS20);	//prescaler 1024, 128us @ 8MHz, 64us @ 16MHz
  #define T2_PERIOD (1024 / (F_CPU / 1000000UL));	/* set to 128 or 64 us */
 #endif 
  sei();				// enable interrupts
#endif
  lcd_init();				//initialize LCD
	
//  ADC_PORT = TXD_VAL;
//  ADC_DDR = TXD_MSK;
  if(tmp) { 
     // check if  Watchdog-Event 
     // this happens, if the Watchdog is not reset for 2s
     // can happen, if any loop in the Program doen't finish.
     lcd_line1();
     lcd_fix_string(TestTimedOut);	//Output Timeout
     wait_about3s();				//wait for 3 s
     ON_PORT = 0;			//shut off!
//     ON_DDR = (1<<ON_PIN);		//switch to GND
     return 0;
  }
  LCDLoadCustomChar(LCD_CHAR_DIODE1);	//Custom-Character Diode symbol
  lcd_fix_customchar(DiodeIcon1);	//load Character  >|
  LCDLoadCustomChar(LCD_CHAR_DIODE2);	//Custom-Character 
  lcd_fix_customchar(DiodeIcon2);	//load Character  |<
  LCDLoadCustomChar(LCD_CHAR_CAP);	//Custom-Character  Capacitor symbol
  lcd_fix_customchar(CapIcon);		//load Character  ||
  LCDLoadCustomChar(LCD_CHAR_RESIS1);	//Custom-Character Resistor symbol
  lcd_fix_customchar(ResIcon1);		//load Character  [
  LCDLoadCustomChar(LCD_CHAR_RESIS2);	//Custom-Character 
  lcd_fix_customchar(ResIcon2);		//load Character  ]
  
  //if kyrillish LCD-Characterset is defined, load  Omega- and �-Character
#if LCD_CHAR_OMEGA < 8
  LCDLoadCustomChar(LCD_CHAR_OMEGA);	//load omega as Custom-Character
  lcd_fix_customchar(CyrillicOmegaIcon);
#endif
#if LCD_CHAR_U < 8
  LCDLoadCustomChar(LCD_CHAR_U);	//load mu as Custom-Character
  lcd_fix_customchar(CyrillicMuIcon);
#endif
#if FLASHEND > 0x3fff
  LCDLoadCustomChar(LCD_CHAR_RESIS3);	//load Resistor symbol as Custom-Character
  lcd_fix_customchar(ResIcon3);		// load character ||
#endif
#ifdef PULLUP_DISABLE
 #ifdef __AVR_ATmega8__
  SFIOR = (1<<PUD);		// disable Pull-Up Resistors mega8
 #else
  MCUCR = (1<<PUD);		// disable Pull-Up Resistors mega168 family
 #endif
#endif

//  DIDR0 = 0x3f;			//disable all Input register of ADC

#if POWER_OFF+0 > 1
  // tester display time selection
  display_time = OFF_WAIT_TIME;		// LONG_WAIT_TIME for single mode, else SHORT_WAIT_TIME
  if (!(ON_PIN_REG & (1<<RST_PIN))) {
     // if power button is pressed ...
     wait_about300ms();			// wait to catch a long key press
     if (!(ON_PIN_REG & (1<<RST_PIN))) {
        // check if power button is still pressed
        display_time = LONG_WAIT_TIME;	// ... set long time display anyway
     }
  }
#else
  #define display_time OFF_WAIT_TIME
#endif

#if POWER_OFF+0 > 1
  empty_count = 0;
  mess_count = 0;
#endif

//*****************************************************************
//Entry: if start key is pressed before shut down
start:
  PartFound = PART_NONE;	// no part found
  NumOfDiodes = 0;		// Number of diodes = 0
  ptrans.count = 0;		// Number of found P type transistors
  ntrans.count = 0;		// Number of found N type transistors
  PartMode = PART_MODE_NONE;
  WithReference = 0;		// no precision reference voltage
  lcd_clear();			// clear the LCD
  ADC_DDR = TXD_MSK;		//activate Software-UART 
  ResistorsFound = 0;		// no resistors found
  cap.ca = 0;
  cap.cb = 0;
#if FLASHEND > 0x1fff
  inductor_lpre = 0;		// mark as zero
#endif
#ifdef WITH_UART
  uart_newline();		// start of new measurement
#endif
  ADCconfig.RefFlag = 0;
  Calibrate_UR();		// get Ref Voltages and Pin resistance
  lcd_line1();			// Cursor to 1. row, column 1
  
  ADCconfig.U_Bandgap = ADC_internal_reference;	// set internal reference voltage for ADC

#ifdef BAT_CHECK
  // Battery check is selected
  ReadADC(TPBAT);	//Dummy-Readout
  ptrans.uBE = W5msReadADC(TPBAT); 	//with 5V reference
  lcd_fix_string(Bat_str);		//output: "Bat. "
 #ifdef BAT_OUT
  // display Battery voltage
  // The divisor to get the voltage in 0.01V units is ((10*33)/133) witch is about 2.4812
  // A good result can be get with multiply by 4 and divide by 10 (about 0.75%).
//  cap.cval = (ptrans.uBE*4)/10+((BAT_OUT+5)/10); // usually output only 2 digits
//  DisplayValue(cap.cval,-2,'V',2);		// Display 2 Digits of this 10mV units
#if BAT_NUMERATOR <= (0xffff/U_VCC)
  cap.cval = (ptrans.uBE*BAT_NUMERATOR)/BAT_DENOMINATOR + BAT_OUT;
#else
 #if (BAT_NUMERATOR == 133) && (BAT_DENOMINATOR == 33)
  cap.cval = (ptrans.uBE*4)+BAT_OUT;		// usually output only 2 digits
 #else
  cap.cval = ((unsigned long)ptrans.uBE*BAT_NUMERATOR)/BAT_DENOMINATOR + BAT_OUT;
 #endif
#endif
  DisplayValue(cap.cval,-3,'V',2);		// Display 2 Digits of this 10mV units
  lcd_space();
 #endif
 #if (BAT_POOR > 12000)
   #warning "Battery POOR level is set very high!"
 #endif
 #if (BAT_POOR < 2500)
   #warning "Battery POOR level is set very low!"
 #endif
 #if (BAT_POOR > 5300)
  // use .8 V difference to Warn-Level
  #define WARN_LEVEL (((unsigned long)(BAT_POOR+800)*(unsigned long)BAT_DENOMINATOR)/BAT_NUMERATOR)
 #elif (BAT_POOR > 3249)
  // less than 5.4 V only .4V difference to Warn-Level
  #define WARN_LEVEL (((unsigned long)(BAT_POOR+400)*(unsigned long)BAT_DENOMINATOR)/BAT_NUMERATOR)
 #elif (BAT_POOR > 1299)
  // less than 2.9 V only .2V difference to Warn-Level
  #define WARN_LEVEL (((unsigned long)(BAT_POOR+200)*(unsigned long)BAT_DENOMINATOR)/BAT_NUMERATOR)
 #else
  // less than 1.3 V only .1V difference to Warn-Level
  #define WARN_LEVEL (((unsigned long)(BAT_POOR+100)*(unsigned long)BAT_DENOMINATOR)/BAT_NUMERATOR)
 #endif
 #define POOR_LEVEL (((unsigned long)(BAT_POOR)*(unsigned long)BAT_DENOMINATOR)/BAT_NUMERATOR)
  // check the battery voltage
  if (ptrans.uBE <  WARN_LEVEL) {
     //Vcc < 7,3V; show Warning 
     if(ptrans.uBE < POOR_LEVEL) {	
        //Vcc <6,3V; no proper operation is possible
        lcd_fix_string(BatEmpty);	//Battery empty!
        wait_about2s();
        PORTD = 0;			//switch power off
        return 0;
     }
     lcd_fix_string(BatWeak);		//Battery weak
  } else { // Battery-voltage OK
     lcd_fix_string(OK_str); 		// "OK"
  }
#else
  lcd_fix2_string(VERSION_str);		// if no Battery check, Version .. in row 1
#endif
#ifdef WDT_enabled
  wdt_enable(WDTO_2S);		//Watchdog on
#endif

//  wait_about1s();			// add more time for reading batterie voltage
  // begin tests
#ifdef AUTO_RH
  RefVoltage();			//compute RHmultip = f(reference voltage)
#endif
#if FLASHEND > 0x1fff
  if (WithReference) {
     /* 2.5V precision reference is checked OK */
 #if POWER_OFF+0 > 1
     if ((mess_count == 0) && (empty_count == 0))
 #endif
     {
         /* display VCC= only first time */
         lcd_line2();
         lcd_fix_string(VCC_str);		// VCC=
         DisplayValue(ADCconfig.U_AVCC,-3,'V',3);	// Display 3 Digits of this mV units
         wait_about1s();
     }
  }
#endif
#ifdef WITH_VEXT
  unsigned int Vext;
  // show the external voltage
  while (!(ON_PIN_REG & (1<<RST_PIN))) {
     lcd_line2();
     lcd_clear_line();
     lcd_line2();
     lcd_fix_string(Vext_str);		// Vext=
     ADC_DDR = 0;		//deactivate Software-UART
     Vext = W5msReadADC(TPext);	// read external voltage 
//     ADC_DDR = TXD_MSK;		//activate Software-UART 
//#ifdef WITH_UART
//     uart_newline();		// start of new measurement
//#endif
 #if EXT_NUMERATOR <= (0xffff/U_VCC)
     DisplayValue(Vext*EXT_NUMERATOR/EXT_DENOMINATOR,-3,'V',3);	// Display 3 Digits of this mV units
 #else
     DisplayValue((unsigned long)Vext*EXT_NUMERATOR/EXT_DENOMINATOR,-3,'V',3);	// Display 3 Digits of this mV units
 #endif
     wait_about300ms();
  }
#endif

#ifndef DebugOut
  lcd_line2();			//LCD position row 2, column 1
#endif
  EntladePins();		// discharge all capacitors!
  if(PartFound == PART_CELL) {
    lcd_clear();
    lcd_fix_string(Cell_str);	// display "Cell!"
#if FLASHEND > 0x3fff
    lcd_line2();		// use LCD line 2
    DisplayValue(cell_mv[0],-3,'V',3);
    lcd_space();
    DisplayValue(cell_mv[1],-3,'V',3);
    lcd_space();
    DisplayValue(cell_mv[2],-3,'V',3);
#endif
    goto end;
  }

#ifdef CHECK_CALL
  AutoCheck();			//check, if selftest should be done
  lcd_line2();			//LCD position row2, column 1
  UnCalibrated = 0;
  if (eeprom_read_byte(&c_zero_tab[0]) != eeprom_read_byte(&c_zero_tab[3])) {
     // if calibrated, both c_zero_tab values are identical! c_zero_tab[3] is not used otherwise
     UnCalibrated = 1;
     lcd_data('!');
  }
#else
  lcd_line2();			//LCD position row2, column 1
#endif
  lcd_fix_string(TestRunning);		//String: testing...
     
  // check all 6 combinations for the 3 pins 
//         High  Low  Tri
  CheckPins(TP1, TP2, TP3);
  CheckPins(TP2, TP1, TP3);

  CheckPins(TP1, TP3, TP2);
  CheckPins(TP3, TP1, TP2);

  CheckPins(TP2, TP3, TP1);
  CheckPins(TP3, TP2, TP1);

  if (ResistorsFound != 0) {
     if (resis[ResistorsFound-1].checked  == 0) {
        ResistorsFound--;	// last resistor is not checked in both directions
     }
  }
  
  // Capacity measurement is only possible correctly with two Pins connected.
  // A third connected pin will increase the capacity value!
//  if(((PartFound == PART_NONE) || (PartFound == PART_RESISTOR) || (PartFound == PART_DIODE)) ) {
  if(PartFound == PART_NONE) {
     // If no part is found yet, check separate if is is a capacitor
#if FLASHEND > 0x1fff
     lcd_data('C');
#endif
     EntladePins();		// discharge capacities
     //measurement of capacities in all 3 combinations
     cap.cval_max = 0;		// set max to zero
     cap.cpre_max = -12;	// set max to pF unit
     ReadCapacity(TP3, TP1);
#if DebugOut != 10
     ReadCapacity(TP3, TP2);
     ReadCapacity(TP2, TP1);
#endif
  }

  //All checks are done, output result to display

#ifdef DebugOut 
  // only clear two lines of LCD
  lcd_line2();
  lcd_clear_line();
  lcd_line2();
  lcd_line1();
  lcd_clear_line();
  lcd_line1();
#else
  lcd_clear();				// clear total display
#endif

  _trans = &ntrans;			// default transistor structure to show
  if (PartFound == PART_THYRISTOR) {
    lcd_fix_string(Thyristor);		//"Thyristor"
    goto gakAusgabe;
  }

  if (PartFound == PART_TRIAC) {
    lcd_fix_string(Triac);		//"Triac"
    goto gakAusgabe;
  }

  if (PartFound == PART_CAPACITOR) {
//     lcd_fix_string(Capacitor);
     lcd_testpin(cap.ca);		//Pin number 1
     lcd_fix_string(CapZeich);		// capacitor sign
     lcd_testpin(cap.cb);		//Pin number 2
#if FLASHEND > 0x1fff
     GetVloss();			// get Voltage loss of capacitor
     if (cap.v_loss != 0) {
        lcd_fix_string(VLOSS_str);	// "  Vloss="
        DisplayValue(cap.v_loss,-1,'%',2);
     }
#endif
     lcd_line2(); 			//2. row 
     DisplayValue(cap.cval_max,cap.cpre_max,'F',4);
#if FLASHEND > 0x1fff
     cap.esr = GetESR(cap.cb, cap.ca);		// get ESR of capacitor
     if ( cap.esr < 65530) {
        lcd_fix_string(ESR_str);
        DisplayValue(cap.esr,-2,LCD_CHAR_OMEGA,2);
     }
#endif
     goto end;
  }

  if(PartFound == PART_DIODE) {
     if(NumOfDiodes == 1) {		//single Diode
//        lcd_fix_string(Diode);		//"Diode: "
#if FLASHEND > 0x1fff
        // enough memory to sort the pins
 #if EBC_STYLE == 321
        // the higher test pin number is left side
        if (diodes[0].Anode > diodes[0].Cathode) {
           lcd_testpin(diodes[0].Anode);
           lcd_fix_string(AnKat);	//"->|-"
           lcd_testpin(diodes[0].Cathode);
        } else {
           lcd_testpin(diodes[0].Cathode);
           lcd_fix_string(KatAn);	//"-|<-"
           lcd_testpin(diodes[0].Anode);
        }
 #else
        // the higher test pin number is right side
        if (diodes[0].Anode < diodes[0].Cathode) {
           lcd_testpin(diodes[0].Anode);
           lcd_fix_string(AnKat);	//"->|-"
           lcd_testpin(diodes[0].Cathode);
        } else {
           lcd_testpin(diodes[0].Cathode);
           lcd_fix_string(KatAn);	//"-|<-"
           lcd_testpin(diodes[0].Anode);
        }
 #endif
#else
        // too less memory to sort the pins
        lcd_testpin(diodes[0].Anode);
        lcd_fix_string(AnKat);		//"->|-"
        lcd_testpin(diodes[0].Cathode);
#endif
#if FLASHEND > 0x1fff
	GetIr(diodes[0].Cathode,diodes[0].Anode);
#endif
        UfAusgabe(0x70);
        /* load current of capacity is (5V-1.1V)/(470000 Ohm) = 8298nA */
        lcd_fix_string(GateCap_str);	//"C="
        ReadCapacity(diodes[0].Cathode,diodes[0].Anode);	// Capacity opposite flow direction
        DisplayValue(cap.cval,cap.cpre,'F',3);
        goto end3;
     } else if(NumOfDiodes == 2) { // double diode
        lcd_data('2');
        lcd_fix_string(Dioden);		//"diodes "
        if(diodes[0].Anode == diodes[1].Anode) { //Common Anode
           lcd_testpin(diodes[0].Cathode);
           lcd_fix_string(KatAn);	//"-|<-"
           lcd_testpin(diodes[0].Anode);
           lcd_fix_string(AnKat);	//"->|-"
           lcd_testpin(diodes[1].Cathode);
           UfAusgabe(0x01);
           goto end3;
        } 
        if(diodes[0].Cathode == diodes[1].Cathode) { //Common Cathode
           lcd_testpin(diodes[0].Anode);
           lcd_fix_string(AnKat);	//"->|-"
	   lcd_testpin(diodes[0].Cathode);
           lcd_fix_string(KatAn);	//"-|<-"
           lcd_testpin(diodes[1].Anode);
           UfAusgabe(0x01);
           goto end3;
//        else if ((diodes[0].Cathode == diodes[1].Anode) && (diodes[1].Cathode == diodes[0].Anode)) 
        } 
        if (diodes[0].Cathode == diodes[1].Anode) {
           // normaly two serial diodes are detected as three diodes, but if the threshold is high
           // for both diodes, the third diode is not detected.
           // can also be Antiparallel
           diode_sequence = 0x01;	// 0 1
           SerienDiodenAusgabe();
           goto end3;
        } 
        if (diodes[1].Cathode == diodes[0].Anode) {
           diode_sequence = 0x10;	// 1 0
           SerienDiodenAusgabe();
           goto end3;
        }
     } else if(NumOfDiodes == 3) {
        //Serial of 2 Diodes; was detected as 3 Diodes 
        diode_sequence = 0x33;	// 3 3
        /* Check for any constallation of 2 serial diodes:
          Only once the pin No of anyone Cathode is identical of another anode.
          two diodes in series is additionally detected as third big diode.
        */
        if(diodes[0].Cathode == diodes[1].Anode)
          {
           diode_sequence = 0x01;	// 0 1
          }
        if(diodes[0].Anode == diodes[1].Cathode)
          {
           diode_sequence = 0x10;	// 1 0
          }
        if(diodes[0].Cathode == diodes[2].Anode)
          {
           diode_sequence = 0x02;	// 0 2
          }
        if(diodes[0].Anode == diodes[2].Cathode)
          {
           diode_sequence = 0x20;	// 2 0
          }
        if(diodes[1].Cathode == diodes[2].Anode)
          {
           diode_sequence = 0x12;	// 1 2
          }
        if(diodes[1].Anode == diodes[2].Cathode)
          {
           diode_sequence = 0x21;	// 2 1
          }
#if DebugOut == 4
	lcd_line3();
        lcd_testpin(diodes[0].Anode);
        lcd_data(':');
        lcd_testpin(diodes[0].Cathode);
        lcd_space();
        lcd_string(utoa(diodes[0].Voltage, outval, 10));
        lcd_space();
        lcd_testpin(diodes[1].Anode);
        lcd_data(':');
        lcd_testpin(diodes[1].Cathode);
        lcd_space();
        lcd_string(utoa(diodes[1].Voltage, outval, 10));
	lcd_line4();
        lcd_testpin(diodes[2].Anode);
        lcd_data(':');
        lcd_testpin(diodes[2].Cathode);
        lcd_space();
        lcd_string(utoa(diodes[2].Voltage, outval, 10));
        lcd_line1();
#endif
//        if((ptrans.b<3) && (ptrans.c<3)) 
        if(diode_sequence < 0x22) {
           lcd_data('3');
           lcd_fix_string(Dioden);	//"Diodes "
           SerienDiodenAusgabe();
           goto end3;
        }
     }  // end (NumOfDiodes == 3)
     lcd_fix_string(Bauteil);		//"Bauteil"
     lcd_fix_string(Unknown); 		//" unbek."
     lcd_line2(); //2. row 
     lcd_fix_string(OrBroken); 		//"oder defekt "
     lcd_data(NumOfDiodes + '0');
     lcd_fix_string(AnKat);		//"->|-"
     goto not_known;
     // end (PartFound == PART_DIODE)
  } else if (PartFound == PART_TRANSISTOR) {
#ifdef SEARCH_PARASITIC
    if ((ptrans.count != 0) && (ntrans.count !=0)) {
       // Special Handling of NPNp and PNPn Transistor.
       // If a protection diode is built on the same structur as the NPN-Transistor,
       // a parasitic PNP-Transistor will be detected. 
       ReadCapacity(ntrans.e, ntrans.b);	// read capacity of NPN base-emitter
       n_cval = cap.cval;			// save the found capacity value
       n_cpre  = cap.cpre;			// and dimension
       ReadCapacity(ptrans.b, ptrans.e);	// read capacity of PNP base-emitter
       if (((n_cpre == cap.cpre) && (cap.cval > n_cval)) || (cap.cpre > n_cpre)){
          // the capacity value or dimension of the PNP B-E is greater than the NPN B-E
          PartMode = PART_MODE_PNP;
       } else {
          PartMode = PART_MODE_NPN;
       }
    }
#endif
#if FLASHEND > 0x1fff
    if ((ptrans.count != 0) && (ntrans.count !=0) && (!(ON_PIN_REG & (1<<RST_PIN)))) {
       // if the Start key is still pressed, use the other Transistor
       if (PartMode == PART_MODE_NPN) {
          PartMode = PART_MODE_PNP;	// switch to parasitic transistor
       } else {
          PartMode = PART_MODE_NPN;	// switch to parasitic transistor
       }
    }
#endif

    if(PartMode == PART_MODE_NPN) {
       lcd_fix_string(NPN_str);		//"NPN "
#if FLASHEND > 0x1fff
       if (ptrans.count != 0) {
          lcd_data('p');		// mark for parasitic PNp
       }
#endif
//       _trans = &ntrans;  is allready selected a default
    } else {
       lcd_fix_string(PNP_str);		//"PNP "
#if FLASHEND > 0x1fff
       if (ntrans.count != 0) {
          lcd_data('n');		// mark for parasitic NPn
       }
#endif
       _trans = &ptrans;		// change transistor structure
    }
    lcd_space();
    if( NumOfDiodes > 2) {	//Transistor with protection diode
#ifdef EBC_STYLE
 #if EBC_STYLE == 321
       // Layout with 321= style
       if (((PartMode == PART_MODE_NPN) && (ntrans.c < ntrans.e)) || ((PartMode != PART_MODE_NPN) && (ptrans.c > ptrans.e)))
 #else
       // Layout with EBC= style
       if(PartMode == PART_MODE_NPN)
 #endif
#else
       // Layout with 123= style
       if (((PartMode == PART_MODE_NPN) && (ntrans.c > ntrans.e)) || ((PartMode != PART_MODE_NPN) && (ptrans.c < ptrans.e)))
#endif
       {
          lcd_fix_string(AnKat);	//"->|-"
       } else {
          lcd_fix_string(KatAn);	//"-|<-"
       }
    }
    PinLayout('E','B','C'); 		//  EBC= or 123=...
    lcd_line2(); //2. row 
#ifdef SHOW_ICE
    if (_trans->ice0 > 0) {
       lcd_fix2_string(ICE0_str);		// "ICE0="
       DisplayValue(_trans->ice0,-5,'A',3);
       wait_for_key_5s_line2();		// wait 5s and clear line 2
    }
    if (_trans->ices > 0) {
       lcd_fix2_string(ICEs_str);		// "ICEs="
       DisplayValue(_trans->ices,-5,'A',3);
       wait_for_key_5s_line2();		// wait 5s and clear line 2
    }
#endif
    lcd_fix_string(hfe_str);		//"B="  (hFE)
    DisplayValue(_trans->hfe,0,0,3);
    lcd_space();

    lcd_fix_string(Uf_str);		//"Uf="
    DisplayValue(_trans->uBE,-3,'V',3);
    goto end;
    // end (PartFound == PART_TRANSISTOR)
  } else if (PartFound == PART_FET) {	//JFET or MOSFET
    if((PartMode&P_CHANNEL) == P_CHANNEL) {
       lcd_data('P');			//P-channel
       _trans = &ptrans;
    } else {
       lcd_data('N');			//N-channel
//       _trans = &ntrans;	is allready selected as default
    }
    lcd_data('-');

    tmp = PartMode&0x0f;
    if (tmp == PART_MODE_JFET) {
       lcd_fix_string(jfet_str);	//"JFET"
    } else {
       if ((PartMode&D_MODE) == D_MODE) {
          lcd_data('D');			// N-D or P-D
       } else {
          lcd_data('E');			// N-E or P-E
       }
       if (tmp == (PART_MODE_IGBT)) {
          lcd_fix_string(igbt_str);	//"-IGBT"
       } else {
          lcd_fix_string(mosfet_str);	//"-MOS "
       }
    }
    if (tmp == PART_MODE_IGBT) {
       PinLayout('E','G','C'); 		//  SGD= or 123=...
    } else {
       PinLayout('S','G','D'); 		//  SGD= or 123=...
    }
//    if((NumOfDiodes == 1) && ((PartMode&D_MODE) != D_MODE)) 
    if(NumOfDiodes == 1) {
       //MOSFET with protection diode; only with enhancement-FETs
#ifdef EBC_STYLE
 #if EBC_STYLE == 321
       // layout with 321= style
       if (((PartMode&P_CHANNEL) && (ptrans.c > ptrans.e)) || ((!(PartMode&P_CHANNEL)) && (ntrans.c < ntrans.e)))
 #else
       // Layout with SGD= style
       if (PartMode&P_CHANNEL) /* N or P MOS */
 #endif
#else
       // layout with 123= style
       if (((PartMode&P_CHANNEL) && (ptrans.c < ptrans.e)) || ((!(PartMode&P_CHANNEL)) && (ntrans.c > ntrans.e)))
#endif
#if FLASHEND > 0x1fff
       // there is enough space for long form of showing protection diode
       {
          lcd_data(LCD_CHAR_DIODE1);	//show Diode symbol >|
          lcd_line2();			//2. Row
          lcd_testpin(diodes[0].Anode);
          lcd_fix_string(AnKat);	//"->|-"
          lcd_testpin(diodes[0].Cathode);
       } else {
          lcd_data(LCD_CHAR_DIODE2);	//show Diode symbol |<
          lcd_line2();			//2. Row
          lcd_testpin(diodes[0].Cathode);
          lcd_fix_string(KatAn);	//"-|<-"
          lcd_testpin(diodes[0].Anode);
       }
       lcd_space();
       lcd_fix_string(Uf_str);			//"Uf="
       mVAusgabe(0);
       wait_for_key_5s_line2();		// wait 5s and clear line 2
#else
       // only little space in the flash memory show only diode symbol in right direction
       {
          lcd_data(LCD_CHAR_DIODE1);	//show Diode symbol >|
       } else {
          lcd_data(LCD_CHAR_DIODE2);	//show Diode symbol |<
       }
#endif
    }
    lcd_line2();			//2. Row
    if((PartMode&D_MODE) != D_MODE) {	//enhancement-MOSFET
	//Gate capacity
       lcd_fix_string(GateCap_str);		//"C="
       ReadCapacity(_trans->b,_trans->e);	//measure capacity
       DisplayValue(cap.cval,cap.cpre,'F',3);
       lcd_fix_string(vt_str);		// "Vt="
    } else {
       lcd_data('I');
       lcd_data('=');
       DisplayValue(_trans->current,-5,'A',2);
       lcd_fix_string(Vgs_str);		// " Vg="
    }
    //Gate-threshold voltage
    DisplayValue(_trans->gthvoltage,-3,'V',2);
    goto end;
    // end (PartFound == PART_FET)
  }
//   if(PartFound == PART_RESISTOR) 
resistor_out:
   if(ResistorsFound != 0) {
    ii = 0;
    if (ResistorsFound == 1) { // single resistor
       lcd_testpin(resis[0].rb);  	//Pin-number 1
       lcd_fix_string(Resistor_str);
       lcd_testpin(resis[0].ra);		//Pin-number 2
    } else { // R-Max suchen
       if (resis[1].rx > resis[0].rx)
          ii = 1;
       if (ResistorsFound == 2) {
          ii = 2;
       } else {
          if (resis[2].rx > resis[ii].rx) {
             ii = 2;
          }
       }
       char x = '1';
       char y = '3';
       char z = '2';
   
       if (ii == 1) {
          // x = '1';
          y = '2';
          z = '3';
       }
       if (ii == 2) {
          x = '2';
          y = '1';
          z = '3';
       }
       lcd_data(x);
       lcd_fix_string(Resistor_str);    // -[=]-
       lcd_data(y);
       lcd_fix_string(Resistor_str);    // -[=]-
       lcd_data(z);
    }
    lcd_line2(); //2. row 
    if (ResistorsFound == 1) {
       RvalOut(0);
#if FLASHEND > 0x1fff
       ReadInductance();		// measure inductance, possible only with single R<2.1k
       if (inductor_lpre != 0) {
	  // resistor have also Inductance
          lcd_fix_string(Lis_str);	// "L="
          DisplayValue(inductor_lx,inductor_lpre,'H',3);	// output inductance
       }
#endif
    } else {
       // output resistor values in right order
       if (ii == 0) {
          RvalOut(1);
          RvalOut(2);
       }
       if (ii == 1) {
          RvalOut(0);
          RvalOut(2);
       }
       if (ii == 2) {
          RvalOut(0);
          RvalOut(1);
       }
    }
    goto end;

  } // end (PartFound == PART_RESISTOR)

  lcd_fix_string(TestFailed1); 	//"Kein,unbek. oder"
  lcd_line2(); //2. row 
  lcd_fix_string(TestFailed2); 	//"defektes "
  lcd_fix_string(Bauteil);		//"Bauteil"
not_known:
#if POWER_OFF+0 > 1
  empty_count++;
  mess_count = 0;
#endif
  max_time = SHORT_WAIT_TIME;		// use allways the short wait time
  goto end2;


gakAusgabe:
  PinLayout(Cathode_char,'G','A'); 	// CGA= or 123=...
#ifdef WITH_THYRISTOR_GATE_V
  lcd_line2(); //2. row 
  lcd_fix_string(Uf_str);		// "Uf="
  DisplayValue(ntrans.uBE,-3,'V',2);
#endif
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 end:
#if POWER_OFF+0 > 1
  empty_count = 0;		// reset counter, if part is found
  mess_count++;			// count measurements
#endif
  max_time = display_time;	// full specified wait time

 end2:
  ADC_DDR = (1<<TPREF) | TXD_MSK; 	// switch pin with reference to GND, release relay
  while(!(ON_PIN_REG & (1<<RST_PIN)));	//wait ,until button is released
  if ((wait_for_key_ms(max_time)) != 0 ) goto start;
#ifdef POWER_OFF
 #if POWER_OFF > 127
  #define POWER2_OFF 255
 #else
  #define POWER2_OFF POWER_OFF*2
 #endif
 #if POWER_OFF+0 > 1
  if ((empty_count < POWER_OFF) && (mess_count < POWER2_OFF)) {
     goto start;			// repeat measurement POWER_OFF times
  }
 #endif
  // only one Measurement requested, shut off
 #if FLASHEND > 0x3fff
  // look, if the tester is uncalibrated (C-source will be included directly)
  #include "HelpCalibration.c"
 #endif
//  MCUSR = 0;
  ON_PORT &= ~(1<<ON_PIN);		//switch off power
  wait_for_key_ms(0); //never ending loop 
#else
  goto start;	// POWER_OFF not selected, repeat measurement
#endif
  return 0;

end3:
  // the diode  is already shown on the LCD
  if (ResistorsFound == 0) goto end;
  ADC_DDR = (1<<TPREF) | TXD_MSK; 	// switch pin with reference to GND, release relay
  // there is one resistor or more detected
  wait_for_key_ms(display_time);
  ADC_DDR =  TXD_MSK; 	// switch pin with reference to input, activate relay
  lcd_clear();
#if FLASHEND > 0x1fff
  lcd_data('0'+NumOfDiodes);
  lcd_fix_string(Dioden);	//"Diodes "
#endif
  goto resistor_out;

}   // end main

void SerienDiodenAusgabe() {
   uint8_t first;
   uint8_t second;
   first = diode_sequence >> 4;
   second = diode_sequence & 3;
   lcd_testpin(diodes[first].Anode);
   lcd_fix_string(AnKat);	//"->|-"
   lcd_testpin(diodes[first].Cathode);
   lcd_fix_string(AnKat);	//"->|-"
   lcd_testpin(diodes[second].Cathode);
   UfAusgabe(diode_sequence);
}


//******************************************************************
// output of flux voltage for 1-2 diodes in row 2
// bcdnum = Numbers of both Diodes:
// higher 4 Bit  number of first Diode
// lower 4 Bit  number of second Diode (Structure diodes[nn])
// if number >= 3  no output is done
void UfAusgabe(uint8_t bcdnum) {
   if (ResistorsFound > 0) { //also Resistor(s) found
      lcd_space();
      lcd_data(LCD_CHAR_RESIS3);	// special symbol or R
   }
   lcd_line2(); 				//2. row
   lcd_fix_string(Uf_str);			//"Uf="
   mVAusgabe(bcdnum >> 4);
   mVAusgabe(bcdnum & 0x0f);
}
void mVAusgabe(uint8_t nn) {
   if (nn < 3) {
      // Output in mV units
      DisplayValue(diodes[nn].Voltage,-3,'V',3);
      lcd_space();
   }
}

void RvalOut(uint8_t nrr) {	
   // output of resistor value
#if FLASHEND > 0x1fff
   uint16_t rr;
   if ((resis[nrr].rx < 100) && (inductor_lpre == 0)) {
      rr = GetESR(resis[nrr].ra,resis[nrr].rb);
      DisplayValue(rr,-2,LCD_CHAR_OMEGA,3);
   } else {
      DisplayValue(resis[nrr].rx,-1,LCD_CHAR_OMEGA,4);
   }
#else
   DisplayValue(resis[nrr].rx,-1,LCD_CHAR_OMEGA,4);
#endif
   lcd_space();
 }

//******************************************************************
#include "CheckPins.c"

void ChargePin10ms(uint8_t PinToCharge, uint8_t ChargeDirection) {
   //Load the specified pin to the specified direction with 680 Ohm for 10ms.
   //Will be used by discharge of MOSFET Gates or to load big capacities.
   //Parameters:
   //PinToCharge: specifies the pin as mask for R-Port
   //ChargeDirection: 0 = switch to GND (N-Kanal-FET), 1= switch to VCC(P-Kanal-FET)

   if(ChargeDirection&1) {
      R_PORT |= PinToCharge;	//R_PORT to 1 (VCC) 
   } else {
      R_PORT &= ~PinToCharge; // or 0 (GND)
   }
   R_DDR |= PinToCharge;		//switch Pin to output, across R to GND or VCC
   wait_about10ms();			// wait about 10ms
   // switch back Input, no current
   R_DDR &= ~PinToCharge;	// switch back to input
   R_PORT &= ~PinToCharge;	// no Pull up
}

// first discharge any charge of capacitors
void EntladePins() {
  uint8_t adc_gnd;		// Mask of ADC-outputs, which can be directly connected to GND
  unsigned int adcmv[3];	// voltages of 3 Pins in mV
  unsigned int clr_cnt;		// Clear Counter
  uint8_t lop_cnt;		// loop counter
// max. time of discharge in ms  (10000/20) == 10s
#define MAX_ENTLADE_ZEIT  (10000/20)

  for(lop_cnt=0;lop_cnt<10;lop_cnt++) {
     adc_gnd = TXD_MSK;		// put all ADC to Input
     ADC_DDR = adc_gnd;
     ADC_PORT = TXD_VAL;		// ADC-outputs auf 0
     R_PORT = 0;			// R-outputs auf 0
//     R_DDR = (2<<(PC2*2)) | (2<<(PC1*2)) | (2<<(PC0*2)); // R_H for all Pins to GND
     R_DDR = (3<<(PC2*2)) | (3<<(PC1*2)) | (3<<(PC0*2)); // R_H and R_L for all Pins to GND
     adcmv[0] = W5msReadADC(PC0);	// which voltage has Pin 1?
     adcmv[1] = ReadADC(PC1);	// which voltage has Pin 2?
     adcmv[2] = ReadADC(PC2);	// which voltage has Pin 3?
     if ((PartFound == PART_CELL) || (adcmv[0] < CAP_EMPTY_LEVEL) & (adcmv[1] < CAP_EMPTY_LEVEL) & (adcmv[2] < CAP_EMPTY_LEVEL)) {
        ADC_DDR = TXD_MSK;		// switch all ADC-Pins to input
        R_DDR = 0;			// switch all R_L Ports (and R_H) to input
#if FLASHEND > 0x3fff
        cell_mv[0] = adcmv[0];		// save the voltage of pin 1
        cell_mv[1] = adcmv[1];		// save the voltage of pin 2
        cell_mv[2] = adcmv[2];		// save the voltage of pin 3
#endif
        return;			// all is discharged
     }
     // all Pins with voltage lower than 1V can be connected directly to GND (ADC-Port)
     if (adcmv[0] < 1000) {
        adc_gnd |= (1<<PC0);	//Pin 1 directly to GND
     }
     if (adcmv[1] < 1000) {
        adc_gnd |= (1<<PC1);	//Pin 2 directly to GND
     }
     if (adcmv[2] < 1000) {
        adc_gnd |= (1<<PC2);	//Pin 3 directly to  GND
     }
     ADC_DDR = adc_gnd;		// switch all selected ADC-Ports at the same time

     // additionally switch the leaving Ports with R_L to GND.
     // since there is no disadvantage for the already directly switched pins, we can
     // simply switch all  R_L resistors to GND
//     R_DDR = (1<<(PC2*2)) | (1<<(PC1*2)) | (1<<(PC0*2));	// Pins across R_L resistors to GND
     for(clr_cnt=0;clr_cnt<MAX_ENTLADE_ZEIT;clr_cnt++) {
        wdt_reset();
        adcmv[0] = W20msReadADC(PC0);	// which voltage has Pin 1?
        adcmv[1] = ReadADC(PC1);	// which voltage has Pin 2?
        adcmv[2] = ReadADC(PC2);	// which voltage has Pin 3?
        if (adcmv[0] < 1300) {
           ADC_DDR |= (1<<PC0);	// below 1.3V , switch directly with ADC-Port to GND
        }
        if (adcmv[1] < 1300) {
           ADC_DDR |= (1<<PC1);	// below 1.3V, switch directly with ADC-Port to GND
        }
        if (adcmv[2] < 1300) {
           ADC_DDR |= (1<<PC2);	// below 1.3V, switch directly with ADC-Port to GND
        }
        if ((adcmv[0] < (CAP_EMPTY_LEVEL+2)) && (adcmv[1] < (CAP_EMPTY_LEVEL+2)) && (adcmv[2] < (CAP_EMPTY_LEVEL+2))) {
           break;
        }
     }
     if (clr_cnt == MAX_ENTLADE_ZEIT) {
        PartFound = PART_CELL;	// mark as Battery
        // there is charge on capacitor, warn later!
     }
#if DebugOut == 99
        lcd_line4();
        lcd_string(utoa(adcmv[0], outval, 10));
        lcd_space();
        lcd_string(utoa(adcmv[1], outval, 10));
        lcd_space();
        lcd_string(utoa(adcmv[2], outval, 10));
#endif
     for(adcmv[0]=0;adcmv[0]<clr_cnt;adcmv[0]++) {
        // for safety, discharge 5% of discharge  time
        wait1ms();
     }
  } // end for lop_cnt
 }



#ifdef AUTO_RH
void RefVoltage(void) {
// RefVoltage interpolates table RHtab corresponding to voltage ref_mv .
// RHtab contain the factors to get capacity from load time with 470k for
// different Band gab reference voltages.
// for remember:
//resistor     470000 Ohm      1000 1050 1100 1150 1200 1250 1300 1350 1400  mV
//uint16_t RHTAB[] MEM_TEXT = { 954, 903, 856, 814, 775, 740, 707, 676, 648};

#define Ref_Tab_Abstand 50		// displacement of table is 50mV
#define Ref_Tab_Beginn 1000		// begin of table is 1000mV

  unsigned int referenz;
  unsigned int y1, y2;
  uint8_t tabind;
  uint8_t tabres;

  #ifdef AUTO_CAL
  referenz = ref_mv + (int16_t)eeprom_read_word((uint16_t *)(&ref_offset));
  #else
  referenz = ref_mv + REF_C_KORR;
  #endif
  if (referenz >= Ref_Tab_Beginn) {
     referenz -= Ref_Tab_Beginn;
  } else  {
     referenz = 0;		// limit to begin of table
  }
  tabind = referenz / Ref_Tab_Abstand;
  tabres = referenz % Ref_Tab_Abstand;
  tabres = Ref_Tab_Abstand-tabres;
  if (tabind > 7) {
     tabind = 7;		// limit to end of table
  }
  // interpolate the table of factors
  y1 = pgm_read_word(&RHtab[tabind]);
  y2 = pgm_read_word(&RHtab[tabind+1]);
  // RHmultip is the interpolated factor to compute capacity from load time with 470k
  RHmultip = ((y1 - y2) * tabres + (Ref_Tab_Abstand/2)) / Ref_Tab_Abstand + y2;
 }
#endif

#ifdef LCD_CLEAR
void lcd_clear_line(void) {
 // writes 20 spaces to LCD-Display, Cursor must be positioned to first column
 unsigned char ll;
 for (ll=0;ll<20;ll++) {
    lcd_space();
 }
}
#endif

/* ************************************************************************
 *   display of values and units
 * ************************************************************************ */


/*
 *  display value and unit
 *  - max. 4 digits excluding "." and unit
 *
 *  requires:
 *  - value
 *  - exponent of factor related to base unit (value * 10^x)
 *    e.g: p = 10^-12 -> -12
 *  - unit character (0 = none)
 *  digits = 2, 3 or 4
 */
void DisplayValue(unsigned long Value, int8_t Exponent, unsigned char Unit, unsigned char digits)
{
  char OutBuffer[15];
  unsigned int      Limit;
  unsigned char     Prefix;		/* prefix character */
  uint8_t           Offset;		/* exponent of offset to next 10^3 step */
  uint8_t           Index;		/* index ID */
  uint8_t           Length;		/* string length */


  Limit = 100;				/* scale value down to 2 digits */
  if (digits == 3) Limit = 1000;	/* scale value down to 3 digits */
  if (digits == 4) Limit = 10000;	/* scale value down to 4 digits */
  while (Value >= Limit)
  {
    Value += 5;				/* for automatic rounding */
    Value = Value / 10;			/* scale down by 10^1 */
    Exponent++;				/* increase exponent by 1 */
  }


  /*
   *  determine prefix
   */
  Length = Exponent + 12;
  if ((int8_t)Length <  0) Length = 0;		/* Limit to minimum prefix */
  if (Length > 18) Length = 18;		/* Limit to maximum prefix */
  Index = Length / 3;
  Offset = Length % 3;
  if (Offset > 0)
    {
      Index++;				/* adjust index for exponent offset, take next prefix */
      Offset = 3 - Offset;		/* reverse value (1 or 2) */
    }
#ifdef NO_NANO
  if (Index == 1)
    { /* use no nano */
      Index++;				/* use mikro instead of nano */
      Offset += 3;			/* can be 3,4 or 5 */
    }
#endif
  Prefix = MEM_read_byte((uint8_t *)(&PrefixTab[Index]));   /* look up prefix in table */
  /*
   *  display value
   */

  /* convert value into string */
  utoa((unsigned int)Value, OutBuffer, 10);
  Length = strlen(OutBuffer);

  /* position of dot */
  Exponent = Length - Offset;		/* calculate position */

  if (Exponent <= 0)			/* we have to prepend "0." */
  {
    /* 0: factor 10 / -1: factor 100 */
//    lcd_data('0');
    lcd_data('.');
#ifdef NO_NANO
    while (Exponent < 0)
      {
       lcd_data('0');	/* extra 0 for factor 10 */
       Exponent++;
      }
#else
    if (Exponent < 0) lcd_data('0');	/* extra 0 for factor 100 */
#endif
  }

  if (Offset == 0) Exponent = -1;	/* disable dot if not needed */

  /* adjust position to array or disable dot if set to 0 */
//  Exponent--;

  /* display value and add dot if requested */
  Index = 0;
  while (Index < Length)		/* loop through string */
  {
    lcd_data(OutBuffer[Index]);		/* display char */
    Index++;				/* next one */
    if (Index == Exponent) {
      lcd_data('.');			/* display dot */
    }
  }

  /* display prefix and unit */
  if (Prefix != 0) lcd_data(Prefix);
  if (Unit) lcd_data(Unit);
}

#ifndef INHIBIT_SLEEP_MODE
/* set the processor to sleep state */
/* wake up will be done with compare match interrupt of counter 2 */
void sleep_5ms(uint16_t pause){
// pause is the delay in 5ms units
uint8_t t2_offset;
#define RESTART_DELAY_US (RESTART_DELAY_TICS/(F_CPU/1000000UL))
// for 8 MHz crystal the Restart delay is 16384/8 = 2048us

while (pause > 0)
  {
 #if 3000 > RESTART_DELAY_US
   if (pause > 1)
     {
      // Startup time is too long with 1MHz Clock!!!!
      t2_offset =  (10000 - RESTART_DELAY_US) / T2_PERIOD;	/* set to 10ms above the actual counter */
      pause -= 2;
     } else {
      t2_offset =  (5000 - RESTART_DELAY_US) / T2_PERIOD;	/* set to 5ms above the actual counter */
      pause = 0;
     }
   
   OCR2A = TCNT2 + t2_offset;	/* set the compare value */
   TIMSK2 = (0<<OCIE2B) | (1<<OCIE2A) | (0<<TOIE2); /* enable output compare match A interrupt */ 
   set_sleep_mode(SLEEP_MODE_PWR_SAVE);
//   set_sleep_mode(SLEEP_MODE_IDLE);
   sleep_mode();
// wake up after output compare match interrupt
 #else
   // restart delay ist too long, use normal delay of 5ms
   wait5ms();
 #endif
   wdt_reset();
  }
TIMSK2 = (0<<OCIE2B) | (0<<OCIE2A) | (0<<TOIE2); /* disable output compare match A interrupt */ 
}
#endif

// show the Pin Layout of the device 
void PinLayout(char pin1, char pin2, char pin3) {
// pin1-3 is EBC or SGD or CGA
#ifndef EBC_STYLE
   // Layout with 123= style
   uint8_t ipp;
   lcd_fix_string(N123_str);		//" 123="
   for (ipp=0;ipp<3;ipp++) {
       if (ipp == _trans->e)  lcd_data(pin1);	// Output Character in right order
       if (ipp == _trans->b)  lcd_data(pin2);
       if (ipp == _trans->c)  lcd_data(pin3);
   }
#else
 #if EBC_STYLE == 321
   // Layout with 321= style
   uint8_t ipp;
   lcd_fix_string(N321_str);		//" 321="
   ipp = 3;
   while (ipp != 0) {
       ipp--;
       if (ipp == _trans->e)  lcd_data(pin1);	// Output Character in right order
       if (ipp == _trans->b)  lcd_data(pin2);
       if (ipp == _trans->c)  lcd_data(pin3);
   }
 #else 
   // Layout with EBC= style
   lcd_space();
   lcd_data(pin1);
   lcd_data(pin2);
   lcd_data(pin3);
   lcd_data('=');
   lcd_testpin(_trans->e);
   lcd_testpin(_trans->b);
   lcd_testpin(_trans->c);
 #endif
#endif
}

/* wait max_time or previous key press */
/* return value: 1 == key is pressed, 0 == time expired */
uint8_t wait_for_key_ms(int max_time) {
  // if key is pressed, return 1
  // if max_time == 0 , do not count, wait endless
  wait_about200ms();
// wait 28 seconds or 5 seconds (if repeat function)
  while (max_time >= 0) {
     wait_about10ms();
     if(!(ON_PIN_REG & (1<<RST_PIN))) {
        // If the key is pressed again... 
        // goto start of measurement 
        return(1);    // key is pressed
     }
     wdt_reset();
     if (max_time > 0) {		// count only, if counter > 0
        max_time -= 10;			// 10 ms are done, count down
        if (max_time == 0) max_time = -1;	// never count to zero, zero is endless!
     }
  }
 return(0);		// no key pressed within the specified time
}

#ifdef WAIT_LINE2_CLEAR
/* wait 5 seconds or previous key press, then clear line 2 of LCD and */
/* set the cursor to the beginning of line 2 */
void wait_for_key_5s_line2(void) {
  wait_for_key_ms(SHORT_WAIT_TIME);
  lcd_line2(); //2. row 
  lcd_clear_line();		// clear the whole line
  lcd_line2(); //2. row 
}
#endif

#ifdef CHECK_CALL
 #include "AutoCheck.c"
 #include "mark_as_uncalibrated.c"
#endif
#if FLASHEND > 0x1fff
 #include "GetIr.c"
#endif
