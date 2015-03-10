// table of the bits for the 8x16 character set
// each byte hold 8 bits of a row, the upper bit is 1, the bit for the 8th line is 128
 #ifdef LCD_CYRILLIC                                      
  #define CHAR_COUNT16 (Cyr_ja + 16)
 #else
  #define CHAR_COUNT16 128
 #endif
 #if defined(MAIN_C)
const unsigned char PROGMEM font[CHAR_COUNT16][(FONT_WIDTH * ((FONT_HEIGHT + 7)/8))]={
{0x80,0xE0,0x20,0x20,0x20,0x20,0xE0,0x80,
 0x00,0x03,0x02,0x02,0x02,0x02,0x03,0x00},	/* 0x00 Resistor3  */
{0x80,0xF8,0xF0,0xE0,0xC0,0x80,0xF8,0x80,
 0x00,0x0F,0x07,0x03,0x01,0x00,0x0F,0x00},	/* 0x01 Diode1  */
{0x80,0xF8,0x80,0xC0,0xE0,0xF0,0xF8,0x80,
 0x00,0x0F,0x00,0x01,0x03,0x07,0x0F,0x00},	/* 0x02 Diode2  */
{0x80,0x80,0xF8,0x00,0x00,0xF8,0x80,0x80,
 0x00,0x00,0x0F,0x00,0x00,0x0F,0x00,0x00},	/* 0x03 Capacitor  */
{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,
 0x19,0x12,0x1E,0x00,0x1E,0x12,0x19,0x00},	/* 0x04 Omega  */
{0x00,0xF8,0x00,0x00,0x00,0xE0,0x20,0x00,
 0x40,0x3F,0x08,0x10,0x08,0x1F,0x10,0x00},	/* 0x05 mu  */
{0x10,0x10,0x10,0x10,0x10,0x10,0xF0,0x80,
 0x04,0x04,0x04,0x04,0x04,0x04,0x07,0x00},	/* 0x06 Resistor1  */
{0x80,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,
 0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x04},	/* 0x07 Resistor2  */
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x08 Line1 */
{0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x07,0x08,0x08,0x07,0x08,0x08,0x07,0x08},	/* 0x09 Inductor1 */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
 0x08,0x07,0x08,0x08,0x07,0x08,0x08,0x07},	/* 0x0a Inductor2 */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x0b  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x0c  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x0d  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x0e  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x0f  */
{0x00,0x00,0xF8,0x04,0x02,0xFE,0x02,0x00,
 0x70,0x18,0x17,0x10,0x10,0x1F,0x70,0x00},	/* (0xe0 - GR_OFFSET2),Cyr_D       */
{0x02,0xFE,0x02,0x00,0x02,0xFE,0x02,0x00,                                         
 0x10,0x1F,0x10,0x10,0x10,0x5F,0x30,0x00},	/* (0xe1 - GR_OFFSET2),Cyr_C       */
{0x02,0xFE,0x02,0xF0,0x02,0xFE,0x02,0x00,                                         
 0x10,0x1F,0x10,0x1F,0x10,0x5F,0x30,0x00},	/* (0xe2 - GR_OFFSET2),Cyr_Schtsch */
{0x00,0x00,0xE0,0x10,0x08,0xF8,0x08,0x00,                                         
 0x70,0x18,0x17,0x10,0x10,0x1F,0x70,0x00},	/* (0xe3 - GR_OFFSET2),Cyr_d       */
{0x80,0x40,0x28,0xF8,0x28,0x40,0x80,0x00,                                         
 0x07,0x08,0x50,0x7F,0x50,0x08,0x07,0x00},	/* (0xe4 - GR_OFFSET2),Cyr_f       */
{0x08,0xF8,0x08,0x00,0x08,0xF8,0x08,0x00,                                         
 0x10,0x1F,0x10,0x10,0x10,0x5F,0x30,0x00},	/* (0xe5 - GR_OFFSET2),Cyr_c       */
{0x08,0xF8,0x08,0xC0,0x08,0xF8,0x08,0x00,                                         
 0x10,0x1F,0x10,0x1F,0x10,0x5F,0x30,0x00},	/* (0xe6 - GR_OFFSET2),Cyr_schtsch */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x17  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x18  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x19  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x1a  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x1b  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x1c  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x1d  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x1e  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x1f  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x20 ' ' */
{0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x37,0x00,0x00,0x00,0x00},	/* 0x21 '!' */
{0x00,0x16,0x0E,0x00,0x00,0x16,0x0E,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x22 '"' */
{0x00,0x20,0xF8,0x20,0x20,0xF8,0x20,0x00,
 0x00,0x02,0x0F,0x02,0x02,0x0F,0x02,0x00},	/* 0x23 '#' */
{0x10,0x28,0x44,0xFE,0x84,0x08,0x10,0x00,
 0x03,0x04,0x08,0x1F,0x08,0x05,0x02,0x00},	/* 0x24 '$' */
{0x18,0x24,0x24,0x98,0x40,0x20,0x10,0x00,
 0x04,0x02,0x01,0x0C,0x12,0x12,0x0C,0x00},	/* 0x25 '%' */
{0x18,0xA4,0xE2,0xA2,0x12,0x8C,0x80,0x00,
 0x07,0x08,0x10,0x10,0x11,0x12,0x05,0x08},	/* 0x26 '&' */
{0x00,0x00,0x00,0x16,0x0E,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x27 ''' */
{0x00,0x00,0xF0,0x08,0x04,0x02,0x00,0x00,
 0x00,0x00,0x03,0x04,0x08,0x10,0x00,0x00},	/* 0x28 '(' */
{0x00,0x00,0x02,0x04,0x08,0xF0,0x00,0x00,
 0x00,0x00,0x10,0x08,0x04,0x03,0x00,0x00},	/* 0x29 ')' */
{0x90,0xA0,0xC0,0xF8,0xC0,0xA0,0x90,0x00,
 0x04,0x02,0x01,0x0F,0x01,0x02,0x04,0x00},	/* 0x2a '*' */
{0x80,0x80,0x80,0xF0,0x80,0x80,0x80,0x00,
 0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00},	/* 0x2b '+' */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x58,0x38,0x00,0x00,0x00},	/* 0x2c ',' */
{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x2d '-' */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},	/* 0x2e '.' */
{0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x00,
 0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x00},	/* 0x2f '/' */
{0xF8,0x04,0x02,0x02,0x02,0x04,0xF8,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x30 '0' */
{0x00,0x08,0x04,0xFE,0x02,0x00,0x00,0x00,
 0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},	/* 0x31 '1' */
{0x18,0x04,0x02,0x02,0x82,0x44,0x38,0x00,
 0x18,0x14,0x12,0x11,0x10,0x10,0x1C,0x00},	/* 0x32 '2' */
{0x0E,0x02,0x42,0x62,0x52,0x8A,0x06,0x00,
 0x06,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x33 '3' */
{0x80,0x40,0x3E,0x00,0x00,0xFC,0x00,0x00,
 0x03,0x02,0x02,0x02,0x12,0x1F,0x12,0x00},	/* 0x34 '4' */
{0x7E,0x22,0x12,0x12,0x12,0x22,0xC6,0x00,
 0x04,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x35 '5' */
{0xF8,0x44,0x22,0x12,0x12,0x24,0xC0,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x36 '6' */
{0x0E,0x02,0x82,0xC2,0x62,0x32,0x1E,0x00,
 0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00},	/* 0x37 '7' */
{0x18,0xA4,0x42,0x42,0x42,0xA4,0x18,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x38 '8' */
{0xF8,0x04,0x02,0x02,0x02,0x84,0xF8,0x00,
 0x00,0x09,0x12,0x12,0x11,0x08,0x07,0x00},	/* 0x39 '9' */
{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,
 0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00},	/* 0x3a ':' */
{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,
 0x00,0x00,0x00,0x2C,0x1C,0x00,0x00,0x00},	/* 0x3b ';' */
{0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x00,
 0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00},	/* 0x3c '<' */
{0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
 0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x00},	/* 0x3d '=' */
{0x00,0x04,0x08,0x10,0x20,0x40,0x80,0x00,
 0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00},	/* 0x3e '>' */
{0x18,0x04,0x02,0x02,0x02,0x84,0x78,0x00,
 0x00,0x00,0x00,0x36,0x01,0x00,0x00,0x00},	/* 0x3f '?' */
{0xF0,0x08,0xA4,0xA4,0xC4,0x08,0xF0,0x00,
 0x07,0x08,0x13,0x12,0x11,0x0A,0x09,0x00},	/* 0x40 '@' */
{0x00,0xF0,0x08,0x04,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x12,0x02,0x12,0x1F,0x10,0x00},	/* 0x41 'A' */
{0x02,0xFE,0x42,0x42,0x42,0xA4,0x18,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x42 'B' */
{0xF8,0x04,0x02,0x02,0x02,0x04,0x1E,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x06,0x00},	/* 0x43 'C' */
{0x02,0xFE,0x02,0x02,0x02,0x04,0xF8,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x44 'D' */
{0x02,0xFE,0x42,0x42,0xF2,0x02,0x0E,0x00,
 0x10,0x1F,0x10,0x10,0x11,0x10,0x1C,0x00},	/* 0x45 'E' */
{0x02,0xFE,0x42,0x42,0xF2,0x02,0x0E,0x00,
 0x10,0x1F,0x10,0x10,0x01,0x00,0x00,0x00},	/* 0x46 'F' */
{0xF8,0x04,0x02,0x82,0x82,0x84,0x9E,0x00,
 0x07,0x08,0x10,0x11,0x08,0x04,0x1F,0x00},	/* 0x47 'G' */
{0x02,0xFE,0x42,0x40,0x42,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x00,0x10,0x1F,0x10,0x00},	/* 0x48 'H' */
{0x00,0x02,0x02,0xFE,0x02,0x02,0x00,0x00,
 0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},	/* 0x49 'I' */
{0x00,0x00,0x02,0x02,0xFE,0x02,0x02,0x00,
 0x0C,0x10,0x10,0x10,0x0F,0x00,0x00,0x00},	/* 0x4a 'J' */
{0x02,0xFE,0xC2,0x30,0x08,0x06,0x02,0x00,
 0x10,0x1F,0x10,0x03,0x04,0x18,0x10,0x00},	/* 0x4b 'K' */
{0x02,0xFE,0x02,0x00,0x00,0x00,0x00,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x10,0x1E,0x00},	/* 0x4c 'L' */
{0x02,0xFE,0x32,0xC0,0x32,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x01,0x10,0x1F,0x10,0x00},	/* 0x4d 'M' */
{0x02,0xFE,0x1A,0xE0,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x00,0x13,0x1F,0x10,0x00},	/* 0x4e 'N' */
{0xF8,0x04,0x02,0x02,0x02,0x04,0xF8,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x4f 'O' */
{0x02,0xFE,0x02,0x02,0x02,0x84,0x78,0x00,
 0x10,0x1F,0x11,0x01,0x01,0x00,0x00,0x00},	/* 0x50 'P' */
{0xF8,0x04,0x02,0x02,0x02,0x04,0xF8,0x00,
 0x07,0x08,0x10,0x10,0x12,0x14,0x0B,0x10},	/* 0x51 'Q' */
{0x02,0xFE,0x82,0x82,0x82,0x44,0x38,0x00,
 0x10,0x1F,0x10,0x01,0x02,0x1C,0x10,0x00},	/* 0x52 'R' */
{0x18,0x24,0x42,0x42,0x42,0x84,0x1E,0x00,
 0x06,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x53 'S' */
{0x0E,0x02,0x02,0xFE,0x02,0x02,0x0E,0x00,
 0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},	/* 0x54 'T' */
{0x02,0xFE,0x02,0x00,0x02,0xFE,0x02,0x00,
 0x00,0x0F,0x10,0x10,0x10,0x0F,0x00,0x00},	/* 0x55 'U' */
{0x02,0xFE,0x02,0x00,0x02,0xFE,0x02,0x00,
 0x00,0x03,0x0E,0x18,0x0E,0x03,0x00,0x00},	/* 0x56 'V' */
{0x02,0xFE,0x02,0xF0,0x02,0xFE,0x02,0x00,
 0x00,0x07,0x1C,0x0F,0x1C,0x07,0x00,0x00},	/* 0x57 'W' */
{0x02,0x1E,0xF2,0x40,0xF2,0x1E,0x02,0x00,
 0x10,0x1F,0x11,0x00,0x11,0x1F,0x10,0x00},	/* 0x58 'X' */
{0x02,0xFE,0x82,0x00,0x82,0xFE,0x02,0x00,
 0x00,0x00,0x11,0x1F,0x11,0x00,0x00,0x00},	/* 0x59 'Y' */
{0x0E,0x02,0x82,0x42,0x22,0x12,0x0E,0x00,
 0x1E,0x11,0x10,0x10,0x10,0x10,0x1E,0x00},	/* 0x5a 'Z' */
{0x00,0xFE,0x02,0x02,0x02,0x02,0x00,0x00,
 0x00,0x3F,0x20,0x20,0x20,0x20,0x00,0x00},	/* 0x5b '[' */
{0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x00},	/* 0x5c '\' */
{0x00,0x02,0x02,0x02,0x02,0xFE,0x00,0x00,
 0x00,0x20,0x20,0x20,0x20,0x3F,0x00,0x00},	/* 0x5d ']' */
{0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x5e '^' */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00},	/* 0x5f '_' */
{0x00,0x00,0x00,0x0E,0x16,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x60 '`' */
{0x00,0x90,0x48,0x48,0x48,0x90,0xE0,0x00,
 0x07,0x08,0x10,0x10,0x08,0x04,0x1F,0x00},	/* 0x61 'a' */
{0x02,0xFE,0x12,0x08,0x08,0x10,0xE0,0x00,
 0x10,0x1F,0x08,0x10,0x10,0x08,0x07,0x00},	/* 0x62 'b' */
{0xE0,0x10,0x08,0x08,0x08,0x10,0x38,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x06,0x00},	/* 0x63 'c' */
{0xE0,0x10,0x08,0x08,0x12,0xFE,0x02,0x00,
 0x07,0x08,0x10,0x10,0x08,0x1F,0x10,0x00},	/* 0x64 'd' */
{0xE0,0x90,0x88,0x88,0x88,0x90,0xE0,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x04,0x00},	/* 0x65 'e' */
{0x40,0xF8,0x44,0x42,0x02,0x04,0x08,0x00,
 0x10,0x1F,0x10,0x10,0x00,0x00,0x00,0x00},	/* 0x66 'f' */
{0xE0,0x10,0x08,0x08,0x10,0xF8,0x08,0x00,
 0x03,0x24,0x48,0x48,0x44,0x3F,0x00,0x00},	/* 0x67 'g' */
{0x02,0xFE,0x20,0x10,0x08,0xF0,0x00,0x00,
 0x10,0x1F,0x10,0x00,0x10,0x1F,0x10,0x00},	/* 0x68 'h' */
{0x00,0x08,0x0B,0xFB,0x00,0x00,0x00,0x00,
 0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},	/* 0x69 'i' */
{0x00,0x00,0x08,0x08,0x0B,0xFB,0x00,0x00,
 0x00,0x30,0x40,0x40,0x40,0x3F,0x00,0x00},	/* 0x6a 'j' */
{0x02,0xFE,0x80,0x40,0x30,0x08,0x18,0x00,
 0x10,0x1F,0x11,0x02,0x04,0x08,0x18,0x00},	/* 0x6b 'k' */
{0x00,0x00,0x02,0x02,0xFE,0x00,0x00,0x00,
 0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00},	/* 0x6c 'l' */
{0x08,0xF8,0x08,0xF0,0x08,0xF0,0x00,0x00,
 0x10,0x1F,0x00,0x1F,0x00,0x1F,0x10,0x00},	/* 0x6d 'm' */
{0x08,0xF8,0x10,0x08,0x08,0xF0,0x00,0x00,
 0x10,0x1F,0x10,0x00,0x10,0x1F,0x10,0x00},	/* 0x6e 'n' */
{0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0x6f 'o' */
{0x08,0xF8,0x10,0x08,0x08,0x10,0xE0,0x00,
 0x40,0x7F,0x48,0x10,0x10,0x08,0x07,0x00},	/* 0x70 'p' */
{0xE0,0x10,0x08,0x08,0x10,0xF8,0x08,0x00,
 0x07,0x08,0x10,0x10,0x48,0x7F,0x40,0x00},	/* 0x71 'q' */
{0x08,0xF8,0x20,0x10,0x08,0x08,0x70,0x00,
 0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},	/* 0x72 'r' */
{0x20,0x50,0x88,0x88,0x88,0x10,0x38,0x00,
 0x06,0x08,0x10,0x10,0x10,0x09,0x06,0x00},	/* 0x73 's' */
{0x20,0x20,0xFE,0x20,0x20,0x00,0x00,0x00,
 0x00,0x00,0x0F,0x10,0x10,0x10,0x0C,0x00},	/* 0x74 't' */
{0x08,0xF8,0x08,0x00,0x08,0xF8,0x08,0x00,
 0x00,0x0F,0x10,0x10,0x08,0x1F,0x10,0x00},	/* 0x75 'u' */
{0x08,0xF8,0x08,0x00,0x08,0xF8,0x08,0x00,
 0x00,0x03,0x0E,0x18,0x0E,0x03,0x00,0x00},	/* 0x76 'v' */
{0x08,0xF8,0x08,0xC0,0x08,0xF8,0x08,0x00,
 0x00,0x0F,0x18,0x0F,0x18,0x0F,0x00,0x00},	/* 0x77 'w' */
{0x08,0x38,0xE0,0x80,0xE0,0x38,0x08,0x00,
 0x10,0x1F,0x01,0x00,0x01,0x1F,0x10,0x00},	/* 0x78 'x' */
{0x08,0xF8,0x08,0x00,0x08,0xF8,0x08,0x00,
 0x00,0x27,0x48,0x48,0x44,0x3F,0x00,0x00},	/* 0x79 'y' */
{0x38,0x08,0x08,0x88,0x48,0x28,0x18,0x00,
 0x1C,0x12,0x11,0x10,0x10,0x10,0x1E,0x00},	/* 0x7a 'z' */
{0x80,0x40,0x38,0x04,0x02,0x02,0x00,0x00,
 0x00,0x01,0x0E,0x10,0x20,0x20,0x00,0x00},	/* 0x7b '{' */
{0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00},	/* 0x7c '|' */
{0x00,0x02,0x02,0x04,0x38,0x40,0x80,0x00,
 0x00,0x20,0x20,0x10,0x0E,0x01,0x00,0x00},	/* 0x7d '}' */
{0x00,0x80,0xF0,0xE0,0xC0,0x80,0x00,0x00,
 0x00,0x00,0x07,0x03,0x01,0x00,0x00,0x00},	/* 0x7e '~' */
{0x00,0x80,0xC0,0xE0,0xF0,0x80,0x00,0x00,
 0x00,0x00,0x01,0x03,0x07,0x00,0x00,0x00},	/* 0x7f  */
 #if 0
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x80  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x81  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x82  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x83  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x84  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x85  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x86  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x87  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x88  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x89  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x8a  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x8b  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x8c  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x8d  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x8e  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x8f  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x90  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x91  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x92  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x93  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x94  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x95  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x96  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x97  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x98  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x99  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x9a  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x9b  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x9c  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x9d  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x9e  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0x9f  */
 #endif
#ifdef LCD_CYRILLIC                                      
{0x02,0xFE,0x42,0x42,0x42,0x8E,0x00,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0xa0 ,Cyr_B */
{0x02,0xFE,0x02,0x02,0x02,0x02,0x0E,0x00,
 0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},	/* 0xa1 ,Cyr_G */
{0x0B,0xFB,0x88,0xE8,0x0B,0x3B,0x00,0x00,
 0x10,0x1F,0x10,0x13,0x10,0x10,0x1C,0x00},	/* 0xa2 ,Cyr_Jo */
{0x02,0xBE,0xC0,0xFE,0xC0,0xBE,0x02,0x00,
 0x10,0x1F,0x00,0x1F,0x00,0x1F,0x10,0x00},	/* 0xa3 ,Cyr_Zsch */
{0x1E,0x04,0x02,0x42,0x42,0xA4,0x18,0x00,
 0x06,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0xa4 ,Cyr_Z */
{0x02,0xFE,0x00,0xE0,0x18,0xFE,0x02,0x00,
 0x10,0x1F,0x13,0x00,0x10,0x1F,0x10,0x00},	/* 0xa5 ,Cyr_I */
{0x04,0xFC,0x01,0xC2,0x31,0xFC,0x04,0x00,
 0x10,0x1F,0x16,0x01,0x10,0x1F,0x10,0x00},	/* 0xa6 ,Cyr_J */
{0x00,0xF0,0x08,0x04,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x00,0x00,0x10,0x1F,0x10,0x00},	/* 0xa7 ,Cyr_L */
{0x02,0xFE,0x02,0x02,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x00,0x10,0x1F,0x10,0x00},	/* 0xa8 ,Cyr_P */
{0x02,0xFE,0x02,0x00,0x02,0xFE,0x02,0x00,
 0x00,0x09,0x12,0x12,0x11,0x0F,0x00,0x00},	/* 0xa9 ,Cyr_U */
{0xF0,0x08,0x0A,0xFE,0x0A,0x08,0xF0,0x00,
 0x01,0x02,0x12,0x1F,0x12,0x02,0x01,0x00},	/* 0xaa ,Cyr_F */
{0x02,0xFE,0x02,0x00,0x02,0xFE,0x02,0x00,
 0x00,0x01,0x02,0x02,0x11,0x1F,0x10,0x00},	/* 0xab ,Cyr_Tsch */
{0x02,0xFE,0x02,0xF0,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x00},	/* 0xac ,Cyr_Sch */
{0x0E,0x02,0xFE,0x12,0x08,0x08,0xF0,0x00,
 0x10,0x10,0x1F,0x10,0x10,0x08,0x07,0x00},	/* 0xad ,Cyr_HH */
{0x02,0xFE,0x12,0x08,0xF0,0x00,0xFE,0x00,
 0x10,0x1F,0x10,0x10,0x0F,0x00,0x1F,0x00},	/* 0xae ,Cyr_Y */
{0x0E,0x04,0x02,0xF2,0x42,0x44,0xF8,0x00,
 0x06,0x08,0x10,0x11,0x10,0x08,0x07,0x00},	/* 0xaf ,Cyr_E */
{0x02,0xFE,0x40,0xFC,0x02,0x02,0xFC,0x00,
 0x10,0x1F,0x00,0x0F,0x10,0x10,0x0F,0x00},	/* 0xb0 ,Cyr_Ju */
{0x38,0x44,0x82,0x82,0x82,0xFE,0x02,0x00,
 0x10,0x1C,0x02,0x01,0x10,0x1F,0x10,0x00},	/* 0xb1 ,Cyr_Ja */
{0xF0,0x48,0x24,0x24,0x22,0x42,0x80,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0xb2 ,Cyr_b */
{0x08,0xF8,0x88,0x88,0x88,0x50,0x20,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x09,0x06,0x00},	/* 0xb3 ,Cyr_v */
{0x08,0xF8,0x08,0x08,0x08,0x38,0x00,0x00,
 0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},	/* 0xb4 ,Cyr_g */
{0xE0,0x93,0x8B,0x88,0x8B,0x93,0xE0,0x00,
 0x07,0x08,0x10,0x10,0x10,0x08,0x04,0x00},	/* 0xb5 ,Cyr_jo */
{0x08,0x78,0x80,0xF8,0x80,0x78,0x08,0x00,
 0x10,0x1F,0x01,0x1F,0x01,0x1F,0x10,0x00},	/* 0xb6 ,Cyr_zsch */
{0x38,0x10,0x08,0x88,0x88,0x50,0x20,0x00,
 0x06,0x08,0x10,0x10,0x10,0x09,0x06,0x00},	/* 0xb7 ,Cyr_z */
{0x08,0xF8,0x08,0x80,0x68,0xF8,0x08,0x00,
 0x10,0x1F,0x16,0x01,0x10,0x1F,0x10,0x00},	/* 0xb8 ,Cyr_i */
{0x08,0xF9,0x02,0x84,0x62,0xF9,0x08,0x00,
 0x10,0x1F,0x16,0x01,0x10,0x1F,0x10,0x00},	/* 0xb9 ,Cyr_j */
{0x08,0xF8,0x80,0x40,0x30,0x08,0x18,0x00,
 0x10,0x1F,0x00,0x01,0x02,0x1C,0x10,0x00},	/* 0xba ,Cyr_k */
{0x00,0xE0,0x10,0x08,0x08,0xF8,0x08,0x00,
 0x10,0x1F,0x00,0x00,0x10,0x1F,0x10,0x00},	/* 0xbb ,Cyr_l */
{0x08,0xF8,0xE8,0x80,0xE8,0xF8,0x08,0x00,
 0x10,0x1F,0x10,0x03,0x10,0x1F,0x10,0x00},	/* 0xbc ,Cyr_m */
{0x08,0xF8,0x88,0x80,0x88,0xF8,0x08,0x00,
 0x10,0x1F,0x10,0x00,0x10,0x1F,0x10,0x00},	/* 0xbd ,Cyr_n */
{0x08,0xF8,0x08,0x08,0x08,0xF8,0x08,0x00,
 0x10,0x1F,0x10,0x00,0x10,0x1F,0x10,0x00},	/* 0xbe ,Cyr_p */
{0x38,0x08,0x08,0xF8,0x08,0x08,0x38,0x00,
 0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},	/* 0xbf ,Cyr_t */
{0x08,0xF8,0x08,0x00,0x08,0xF8,0x08,0x00,
 0x00,0x01,0x02,0x02,0x11,0x1F,0x10,0x00},	/* 0xc0 ,Cyr_tsch */
{0x08,0xF8,0x08,0xC0,0x08,0xF8,0x08,0x00,
 0x10,0x1F,0x10,0x1F,0x10,0x1F,0x10,0x00},	/* 0xc1 ,Cyr_sch */
{0x38,0x08,0xF8,0x88,0x40,0x40,0x80,0x00,
 0x10,0x10,0x1F,0x10,0x10,0x08,0x07,0x00},	/* 0xc2 ,Cyr_hh */
{0x08,0xF8,0x88,0x40,0x80,0x00,0xF8,0x00,
 0x10,0x1F,0x10,0x10,0x0F,0x00,0x1F,0x00},	/* 0xc3 ,Cyr_y */
{0x08,0xF8,0x88,0x40,0x40,0x80,0x00,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},	/* 0xc4 ,Cyr_ww */
{0x38,0x10,0x08,0xC8,0x88,0x90,0xE0,0x00,
 0x06,0x08,0x10,0x11,0x10,0x08,0x07,0x00},	/* 0xc5 ,Cyr_e */
{0x08,0xF8,0x80,0xF0,0x08,0x08,0xF0,0x00,
 0x10,0x1F,0x00,0x0F,0x10,0x10,0x0F,0x00},	/* 0xc6 ,Cyr_ju */
{0xE0,0x10,0x08,0x08,0x08,0xF8,0x08,0x00,
 0x00,0x11,0x0A,0x06,0x12,0x1F,0x10,0x00},	/* 0xc7 ,Cyr_ja */
 #if 0
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xc8  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xc9  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xca  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xcb  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xcc  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xcd  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xce  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xcf  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd0  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd1  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd2  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd3  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd4  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd5  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd6  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd7  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd8  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xd9  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xda  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xdb  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xdc  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xdd  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xde  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xdf  */
{0x00,0x00,0xF8,0x04,0x02,0xFE,0x02,0x00,
 0x70,0x18,0x17,0x10,0x10,0x1F,0x70,0x00},	/* 0xe0 ,Cyr_D */
{0x02,0xFE,0x02,0x00,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x5F,0x30,0x00},	/* 0xe1 ,Cyr_d */
{0x02,0xFE,0x02,0xF0,0x02,0xFE,0x02,0x00,
 0x10,0x1F,0x10,0x1F,0x10,0x5F,0x30,0x00},	/* 0xe2 ,Cyr_f */
{0x00,0x00,0xE0,0x10,0x08,0xF8,0x08,0x00,
 0x70,0x18,0x17,0x10,0x10,0x1F,0x70,0x00},	/* 0xe3 ,Cyr_C */
{0x80,0x40,0x28,0xF8,0x28,0x40,0x80,0x00,
 0x07,0x08,0x50,0x7F,0x50,0x08,0x07,0x00},	/* 0xe4 ,Cyr_c */
{0x08,0xF8,0x08,0x00,0x08,0xF8,0x08,0x00,
 0x10,0x1F,0x10,0x10,0x10,0x5F,0x30,0x00},	/* 0xe5 ,Cyr_Schtsch */
{0x08,0xF8,0x08,0xC0,0x08,0xF8,0x08,0x00,
 0x10,0x1F,0x10,0x1F,0x10,0x5F,0x30,0x00},	/* 0xe6 ,Cyr_schtsch */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xe7  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xe8  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xe9  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xea  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xeb  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xec  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xed  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xee  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xef  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf0  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf1  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf2  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf3  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf4  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf5  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf6  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf7  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf8  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xf9  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xfa  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xfb  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xfc  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xfd  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	/* 0xfe  */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00} 	/* 0xff  */
 #endif
#endif                                          
};
#else                                                
 #ifndef __ASSEMBLER__
const unsigned char PROGMEM font[CHAR_COUNT16][16];
 #endif                                          
#endif                                          
