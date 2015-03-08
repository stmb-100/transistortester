#include <avr/pgmspace.h>



//*****************************************************************************
//
// The data for the bitmap bmp_p_e_igbt
// update of the bitmap bmp_n_e_igbt at location 12,0
//
// Memory usage: 38 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_p_e_igbt[(6 * 4) + 4] PROGMEM ={
 17,
  0,
  6,
 32,
 /*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00,  0x1E, 0x21, 0x21, 0x21, 
  0x12,*/0x40, 0xC0, 0xC0,  0xC0, 0xC0, 0x20,/* 0x1F,
 
  0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00,  0xF8, 0x00, 0x00, 0xDE, 
  0x88,*/0x04, 0x02, 0x01,  0x03, 0x07, 0x00,/* 0x00,
 
  0x00, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x04, 
  0x04, 0x04, 0x04, 0x04,  0x07, 0x00, 0x00, 0x3D, 
  0x08,*/0x11, 0xE2, 0xE4,  0xE0, 0x60, 0x20,/* 0x00,
 
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00,  0xFC, 0x94, 0x94, 0x94, 
  0x84,*/0x00, 0x03, 0x01,  0x00, 0x01, 0x02,/* 0xFC */  
}; /* P-E-IGBT = N-E-IGBT + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_p_e_igbt[(7 * 4) + 4] PROGMEM ={
 15,
 0,
 7,
 32,
 /* 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00,*/ 0x00,
  0x10, 0xB0, 0xF0, 0xF0, 0xF0, 0xF8,/* 0x0F, 0x07,

  0x00, 0x3C, 0x42, 0x52, 0x52, 0x34, 0x00, 0x00,
  0x00, 0xF8, 0xF8, 0x00, 0xDE, 0xDE, 0x8C,*/ 0x06,
  0x03, 0x01, 0x00, 0x00, 0x01, 0x03,/* 0x00, 0x00,

  0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
  0x0C, 0x0F, 0x0F, 0x00, 0x7B, 0x7B, 0x31,*/ 0x63,
  0xC6, 0xCC, 0xD8, 0xC0, 0xC0, 0x40,/* 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFC, 0x94, 0x94, 0x94, 0x94, 0x00,*/ 0x00,
  0x0F, 0x07, 0x03, 0x07, 0x0C, 0x18,/* 0xF0, 0xE0 */
}; /* P-E-IGBT = N-E-IGBT + UPDATE */
 #elif (ICON_TYPE == 3) /* thin icon update , Karl-Heinz */
 const unsigned char bmp_p_e_igbt[(5 * 4) + 4] PROGMEM ={
 17,
 0,
 5,
 32,
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x1E, 0x21, 0x21, 0x21, 
  0x12,*/0x20, 0x60, 0xE0,  0xE0, 0xE0,/*0x01, 0x0F,
  
  0x00, 0x00, 0x00, 0xC0,  0x20, 0x20, 0x20, 0x40,
  0x00, 0x00, 0x00, 0xFC,  0x00, 0x00, 0xFE, 0xFE,
  0x04,*/0x02, 0x01, 0x00,  0x01, 0x03,/*0x00, 0x00,
  
  0x00, 0x20, 0x20, 0x23,  0x24, 0x25, 0x25, 0x23,
  0x20, 0x20, 0x20, 0x3F,  0x00, 0x00, 0x7F, 0x7F,
  0x21,*/0xC2, 0xC4, 0xC4,  0xC0, 0x40,/*0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0xFC, 0x94, 0x94, 0x84, 
  0x00,*/0x07, 0x03, 0x01,  0x02, 0x04,/*0x08, 0xF0 */

}; /* P-E-IGBT = N-E-IGBT + UPDATE */
 #else
 const unsigned char bmp_p_e_igbt[(9 * 4) + 4] PROGMEM ={
        12,
        0,
	9, // The width of the bitmap.
	32, // The height of the bitmap.
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1e, 0x21, 0x21, */ 0xa1, 0x92, 0x00, 0x10, 
	0xb0, 0xf0, 0xf0, 0xf0,  0xf8,/* 0x1c, 0x0f, 0x07, 

	0x00, 0x80, 0x80, 0x80,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0x00, */ 0xdf, 0xdf, 0x8e, 0x07, 
	0x03, 0x01, 0x00, 0x01,  0x03,/* 0x00, 0x00, 0x00, 

	0xcf, 0xd0, 0xd4, 0xd4,  0xcd, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xff, 0xff, 0x00, */ 0xfb, 0xfb, 0x71, 0xe3, 
	0xc6, 0xcc, 0xc0, 0xc0,  0x40,/* 0x00, 0x00, 0x00, 

	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0xfc, 0x94, 0x94, 0x94, */ 0x85, 0x01, 0x00, 0x0f, 
	0x07, 0x03, 0x07, 0x0e,  0x1c,/* 0x38, 0xf0, 0xe0, */
};
 #endif
#else
 extern const unsigned char bmp_p_e_igbt[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_n_d_igbt
// update a bmp_n_e_igbt to bpm_n_d_igbt at location 12, 0
//
// Memory usage: 10 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_n_d_igbt[(1 * 2) + 4] PROGMEM ={
 15,
  8,
  1,
 16,
    /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0x21, 0x12,
       0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF,

       0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00,  0xF8, 0x00, 0x00,*/0xFE,
    /* 0x84, 0x84, 0xC4, 0xE4,  0xF4, 0x84, 0x84, 0x07,

       0x00, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x04,
       0x04, 0x04, 0x04, 0x04,  0x07, 0x00, 0x00,*/0x3F,
    /* 0x10, 0x10, 0x11, 0x13,  0x17, 0x10, 0x1F, 0xF0,

       0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x94, 0x94,
       0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF */
}; /*  N-D-IGBT = N-E-IGBT + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_n_d_igbt[(2 * 4) + 4] PROGMEM ={
        12,
        0,
	2, // The width of the bitmap.
	32, // The height of the bitmap.
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1e, 0x21, 0x21, */0xa1, 0x92,/* 0x00, 0xf0, 
	0xe0, 0xc0, 0xe0, 0x70,  0x38, 0x1c, 0x0f, 0x07, 

	0x00, 0x80, 0x80, 0x80,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0x00, */0xff, 0xff,/* 0x8e, 0x07, 
	0x03, 0x03, 0x03, 0x03,  0x02, 0x00, 0x00, 0x00, 

	0xcf, 0xd0, 0xd4, 0xd4,  0xcd, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xff, 0xff, 0x00, */0xff, 0xff,/* 0x71, 0xe3, 
	0xc6, 0x8c, 0xc0, 0xe0,  0x00, 0x00, 0x00, 0x00, 

	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0xfc, 0x94, 0x94, 0x94, */0x85, 0x01/* , 0x04, 0x06, 
	0x07, 0x07, 0x07, 0x0f,  0x1c, 0x38, 0xf0, 0xe0, */
};
 #elif (ICON_TYPE == 3) /* thin icon update , Karl-Heinz */
 const unsigned char bmp_n_d_igbt[(2 * 4) + 4] PROGMEM ={
        14,
        8,
	2, // The width of the bitmap.
	16, // The height of the bitmap.
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x1E, 0x21, 0x21, 0x21,
  0x12, 0xE0, 0xC0, 0x80,  0x40, 0x20, 0x10, 0x0F,
  
  0x00, 0x00, 0x00, 0xC0,  0x20, 0x20, 0x20, 0x40,
  0x00, 0x00, 0x00, 0xFC,  0x00, 0x00,*/0xFE, 0xFE, 
/*0x04, 0x03, 0x03, 0x03,  0x03, 0x02, 0x00, 0x00,
  
  0x00, 0x20, 0x20, 0x23,  0x24, 0x25, 0x25, 0x23,
  0x20, 0x20, 0x20, 0x3F,  0x00, 0x00,*/0x7F, 0x7F,
/* 0x10, 0x20, 0x40, 0x40,  0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0xFC, 0x94, 0x94, 0x84,
  0x00, 0x04, 0x06, 0x07,  0x07, 0x07, 0x08, 0xF0 */

};
 #else
 const unsigned char bmp_n_d_igbt[(2 * 2) + 4] PROGMEM ={
 12,
  8,
  2,
 16,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x3E, 0x41, 0x41,  0x41, 0x22, 0x00, 0xE0,
        0xC0, 0x80, 0xC0, 0xE0,  0x70, 0x18, 0x0F, 0x07,

        0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
        0x00, 0xF8, 0xF8, 0x00,*/ 0xFE, 0xFE,/* 0x8C, 0x07,
        0x07, 0x07, 0x07, 0x06,  0x04, 0x00, 0x00, 0x00,

        0x00, 0x0C, 0x0C, 0x0C,  0x0C, 0x0C, 0x0C, 0x0C,
        0x0C, 0x0F, 0x0F, 0x00,*/ 0x7F, 0x7F,/* 0x31, 0x63,
        0xC6, 0x8C, 0x98, 0xC0,  0xE0, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0xFC, 0x94, 0x94,  0x94, 0x94, 0x00, 0x04,
        0x06, 0x07, 0x07, 0x07,  0x0F, 0x18, 0xF0, 0xE0 */
}; /* N-D-IGBT = N-E-IGBT + UPDATE */

 #endif
#else
 extern const unsigned char bmp_n_d_igbt[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmapbmp_p_d_igbt
// update for n_e_igbt at location 12, 0
//
// Memory usage: 38 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_p_d_igbt[(9 * 4) + 4] PROGMEM ={
 15,
  0,
  9,
 32,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x1E, 0x21, 0x21,*/0x21,
        0x12, 0x40, 0xC0, 0xC0,  0xC0, 0xC0, 0x20, 0x1F,/*
                                           
        0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0xF8, 0x00, 0x00,*/0xFE,
        0x88, 0x04, 0x02, 0x01,  0x03, 0x07, 0x00, 0x00,/*
                                           
        0x00, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04,  0x07, 0x00, 0x00,*/0x3F,
        0x08, 0x11, 0xE2, 0xE4,  0xE0, 0x60, 0x20, 0x00,/*
                                           
        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0xFC, 0x94, 0x94,*/0x94,
        0x84, 0x00, 0x03, 0x01,  0x00, 0x01, 0x02, 0xFC
}; /*  P-D-IGBT = N-E-IGBT + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_p_d_igbt[(10 * 4) + 4] PROGMEM ={
  12,
   0,
  10,
  32,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x3E, 0x41, 0x41,*/ 0x41, 0x22, 0x00, 0x00,
        0x10, 0xB0, 0xF0, 0xF0,  0xF0, 0xF8,/* 0x0F, 0x07,

        0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
        0x00, 0xF8, 0xF8, 0x00,*/ 0xFE, 0xFE, 0x8C, 0x06,
        0x03, 0x01, 0x00, 0x00,  0x01, 0x03,/* 0x00, 0x00,

        0x00, 0x0C, 0x0C, 0x0C,  0x0C, 0x0C, 0x0C, 0x0C,
        0x0C, 0x0F, 0x0F, 0x00,*/ 0x7F, 0x7F, 0x31, 0x63,
        0xC6, 0xCC, 0xD8, 0xC0,  0xC0, 0x40,/* 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0xFC, 0x94, 0x94,*/ 0x94, 0x94, 0x00, 0x00,
        0x0F, 0x07, 0x03, 0x07,  0x0C, 0x18,/* 0xF0, 0xE0 */
}; /* P-D-IGBT = N-E-IGBT + UPDATE */

 #elif (ICON_TYPE == 3) /* thin icon update, Karl-Heinz */
 const unsigned char bmp_p_d_igbt[(8 * 4) + 4] PROGMEM ={
  14,
   0,
   8,
  32,
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x1E, 0x21,*/0x21, 0x21,
  0x12, 0x20, 0x60, 0xE0,  0xE0, 0xE0,/*0x10, 0x0F,
  
  0x00, 0x00, 0x00, 0xC0,  0x20, 0x20, 0x20, 0x40,
  0x00, 0x00, 0x00, 0xFC,  0x00, 0x00,*/0xFE, 0xFE,
  0x04, 0x02, 0x01, 0x00,  0x01, 0x03,/*0x00, 0x00,
  
  0x00, 0x20, 0x20, 0x23,  0x24, 0x25, 0x25, 0x23,
  0x20, 0x20, 0x20, 0x3F,  0x00, 0x00,*/0x7F, 0x7F,
  0x21, 0xC2, 0xC4, 0xC4,  0xC0, 0x40,/*0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0xFC, 0x94,*/0x94, 0x84,
  0x00, 0x07, 0x03, 0x01,  0x02, 0x04/*,0x08, 0xF0 */

}; /* P-D-IGBT = N-E-IGBT + UPDATE */

 #else
 const unsigned char bmp_p_d_igbt[(9 * 4) + 4] PROGMEM ={
        12,
        0,
	9, // The width of the bitmap.
	32, // The height of the bitmap.
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1e, 0x21, 0x21, */0xa1, 0x92, 0x00, 0x10, 
	0xb0, 0xf0, 0xf0, 0xf0,  0xf8, /*0x1c, 0x0f, 0x07, 

	0x00, 0x80, 0x80, 0x80,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0x00, */0xff, 0xff, 0x8e, 0x07, 
	0x03, 0x01, 0x00, 0x01,  0x03, /*0x00, 0x00, 0x00, 

	0xcf, 0xd0, 0xd4, 0xd4,  0xcd, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xff, 0xff, 0x00, */0xff, 0xff, 0x71, 0xe3, 
	0xc6, 0xcc, 0xc0, 0xc0,  0x40, /*0x00, 0x00, 0x00, 

	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0xfc, 0x94, 0x94, */0x95, 0x85, 0x00, 0x0f, 
	0x07, 0x03, 0x07, 0x0e,  0x1c, /*0x38, 0xf0, 0xe0, */
};

 #endif
#else
 extern const unsigned char bmp_p_d_igbt[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_p_e_mos
// Update for bmp_n_e_mos at location 9, 8
//
// Memory usage: 14 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_p_e_mos[(3 * 2) + 4] PROGMEM ={
 18,
  8,
  3,
 16,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0x21, 0x12,
        0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF,

        0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0xF8, 0x00, 0x00, 0xDE,
        0x84, 0x84,*/0xF4, 0xE4, 0xC4,/*0x84, 0x84, 0x07,

        0x00, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04,  0x07, 0x00, 0x00, 0x3D,
        0x10, 0x10,*/0x17, 0x13, 0x11,/*0x10, 0x1F, 0xF0,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x94, 0x94,
        0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF */
}; /*  P-E-MOS = N-E-MOS + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_p_e_mos[(3 * 2) + 4] PROGMEM ={
 17,
  8,
  3,
 16,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0xA1, 0x92,
        0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0xFF, 0xFF,

        0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xF8,  0xF8, 0x00, 0xEF, 0xEF,
        0x86,*/0xF6, 0xE6, 0xC6,/* 0x86, 0x86, 0x87, 0x07,
      
        0x00, 0x0C, 0x0C, 0x0C,  0x0C, 0x0C, 0x0C, 0x0C,
        0x0C, 0x0C, 0x0C, 0x0F,  0x0F, 0x00, 0xF7, 0xF7,
        0x61,*/0x6F, 0x67, 0x63,/* 0x61, 0x7F, 0xFF, 0xE0,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x95, 0x95,
        0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0xFF, 0xFF */
}; /* P-E-MOS = N-E-MOS + UPDATE */
 #elif (ICON_TYPE == 3) /* thin icon update from Karl-Heinz */
 const unsigned char bmp_p_e_mos[(3 * 2) + 4] PROGMEM ={
 17,
  8,
  3,
 16,
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x80, 0x3F, 0x21,
  0x21, 0x12, 0xC0, 0x00,  0x00, 0x00, 0x00, 0xFF,

  0x00, 0x00, 0x00, 0xF0,  0x08, 0x48, 0x48, 0xC8,
  0x00, 0x00, 0xFE, 0x00,  0x00, 0xE7, 0x81, 0x81,
  0x81,*/0xF1, 0xE1, 0xC1,/*0x81, 0x81, 0x81, 0x01,

  0x00, 0x20, 0x20, 0x20,  0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x3F, 0x00,  0x00, 0xF3, 0x40, 0x40,
  0x40,*/0x47, 0x43, 0x41,/*0x40, 0x40, 0x7F, 0xC0,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x48, 0x94,
  0x94, 0x94, 0x64, 0x00,  0x00, 0x00, 0x00, 0xFF */


}; /*  P-E-MOS = N-E-MOS + UPDATE */
 #else
 const unsigned char bmp_p_e_mos[(6 * 2) + 4] PROGMEM ={
        9,
        8,
	6, // The width of the bitmap.
	16, // The height of the bitmap.
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x3f, 0x21, 0x21, 0x21,  0x1e, 0x00, 0xff, 0xff, 

	0xe6, 0x16, 0x96, 0x96,  0xa6, 0x06, 0xfe, 0xfe, 
	0x00,*/0xdf, 0xdf, 0x06, 0xe6, 0xc6, 0x86, /*0x06, 
	0x06, 0x06, 0x06, 0x06,  0x06, 0x06, 0x07, 0x07, 

	0x01, 0x02, 0x02, 0x02,  0x01, 0x00, 0xff, 0xff, 
	0x00, */0xef, 0xef, 0x83, 0x9f, 0x8f, 0x87 /*,0x83, 
	0x83, 0x83, 0x83, 0x83,  0x83, 0x83, 0xff, 0xff, 

	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x01, 0x01, 
	0x00, 0x07, 0x07, 0x01,  0x01, 0x01, 0x01, 0x01, 
	0x49, 0x95, 0x95, 0x95,  0x65, 0x01, 0xff, 0xff, */
};

 #endif
#else
 extern const unsigned char bmp_p_e_mos[] PROGMEM ;
#endif

//*****************************************************************************
//
// The data for the bitmapbmp_n_d_mos
// update for the bitmap bmp_n_e_mos at location 9, 8
//
// Memory usage: 14 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_n_d_mos[(1 * 2) + 4] PROGMEM ={
 15,
  8,
  1,
 16,
 /*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0x21, 0x12,
  0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF,

  0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0xF8, 0x00, 0x00, */
                                             0xFE, /*
  0x84, 0x84, 0xC4, 0xE4,  0xF4, 0x84, 0x84, 0x07,

  0x00, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x04,
  0x04, 0x04, 0x04, 0x04,  0x07, 0x00, 0x00, */
                                             0x3F, /*
  0x10, 0x10, 0x11, 0x13,  0x17, 0x10, 0x1F, 0xF0,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x94, 0x94,
  0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF */
}; /* N-D-MOS = N-E-MOS + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_n_d_mos[(2 * 2) + 4] PROGMEM ={
 14,
  8,
  2,
 16,
     /* 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x3F, 0x21, 0xA1, 0x92,
        0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,

        0x00, 0x3C, 0x42, 0x52, 0x52, 0x34, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xF8, 0xF8, 0x00,*/ 0xFF, 0xFF,
     /* 0x86, 0xC6, 0xE6, 0xF6, 0x86, 0x86, 0x87, 0x07,
      
        0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
        0x0C, 0x0C, 0x0C, 0x0F, 0x0F, 0x00,*/ 0xFF, 0xFF,
     /* 0x61, 0x63, 0x67, 0x6F, 0x61, 0x7F, 0xFF, 0xE0,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x48, 0x94, 0x95, 0x95,
        0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF */
}; /* N-D-MOS = N-E-MOS + UPDATE */

 #elif (ICON_TYPE == 3) /* Thin icon update , Karl-Heinz*/
 const unsigned char bmp_n_d_mos[(1 * 2) + 4] PROGMEM ={
 13,
  8,
  1,
 16,
 /* code 002 N-D-MOS thin from Karl-Heinz */
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x80, 0x3F, 0x21,
  0x21, 0x12, 0x0C, 0x00,  0x00, 0x00, 0x00, 0xFF,

  0x00, 0x00, 0x00, 0xF0,  0x08, 0x48, 0x48, 0xC8,
  0x00, 0x00, 0xFE, 0x00,  0x00,*/0xFF,/*0x81, 0x81,
  0x81, 0xF1, 0xE1, 0xC1,  0x81, 0x81, 0x81, 0x01,

  0x00, 0x20, 0x20, 0x20,  0x21, 0x21, 0x21, 0x20,
  0x20, 0x20, 0x3F, 0x00,  0x00,*/0xFF/*0x40, 0x40,
  0x40, 0x47, 0x43, 0x41,  0x40, 0x40, 0x7F, 0xC0,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x48, 0x94,
  0x94, 0x94, 0x64, 0x00,  0x00, 0x00, 0x00, 0xFF */
};

 #else
 const unsigned char bmp_n_d_mos[(6 * 2) + 4] PROGMEM ={
        9,
        8,
	6, // The width of the bitmap.
	16, // The height of the bitmap.
/*	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x3f, 0x21, 0x21, 0x21,  0x1e, 0x00, 0xff, 0xff, 

	0xe6, 0x16, 0x96, 0x96,  0xa6, 0x06, 0xfe, 0xfe, 
	0x00,*/0xff, 0xff, 0x06,  0x86, 0xc6, 0xe6, /*0x06, 
	0x06, 0x06, 0x06, 0x06,  0x06, 0x06, 0x07, 0x07, 

	0x01, 0x02, 0x02, 0x02,  0x01, 0x00, 0xff, 0xff, 
	0x00,*/0xff, 0xff, 0x83,  0x87, 0x8f, 0x9f /*, 0x83, 
	0x83, 0x83, 0x83, 0x83,  0x83, 0x83, 0xff, 0xff, 

	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x01, 0x01, 
	0x00, 0x07, 0x07, 0x01,  0x01, 0x01, 0x01, 0x01, 
	0x49, 0x95, 0x95, 0x95,  0x65, 0x01, 0xff, 0xff,  */
};

 #endif
#else
 extern const unsigned char bmp_n_d_mos[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_p_d_mos
// update for The bitmap bmp_n_e_mos at location 9,8
//
// Memory usage: 14 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_p_d_mos[(6 * 2) + 4] PROGMEM ={
 15,
  8,
  6,
 16,
 /*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0x21, 0x12,
  0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF,

  0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0xF8, 0x00, 0x00,*/0xFE,
  0x84, 0x84, 0xF4, 0xE4,  0xC4,/*0x84, 0x84, 0x07,

  0x00, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x04,
  0x04, 0x04, 0x04, 0x04,  0x07, 0x00, 0x00,*/0x3F,
  0x10, 0x10, 0x17, 0x13,  0x11,/*0x10, 0x1F, 0xF0,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x94, 0x94,
  0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF */
}; /* P-D-MOS = N-E-MOS + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_p_d_mos[(6 * 2) + 4] PROGMEM ={
 14,
  8,
  6,
 16,
     /* 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x3F, 0x21, 0xA1, 0x92,
        0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,

        0x00, 0x3C, 0x42, 0x52, 0x52, 0x34, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xF8, 0xF8, 0x00,*/ 0xFF, 0xFF,
        0x86, 0xF6, 0xE6, 0xC6,/* 0x86, 0x86, 0x87, 0x07,

        0x00, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
        0x0C, 0x0C, 0x0C, 0x0F, 0x0F, 0x00,*/ 0xFF, 0xFF,
        0x61, 0x6F, 0x67, 0x63,/* 0x61, 0x7F, 0xFF, 0xE0,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x48, 0x94, 0x95, 0x95,
        0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF */

}; /* P-D-MOS = N-E-MOS + UPDATE */
 #elif (ICON_TYPE == 3) /* Thin icon update Karl-Heinz */
 const unsigned char bmp_p_d_mos[(7 * 2) + 4] PROGMEM ={
       13,
        8,
	7, // The width of the bitmap.
	16, // The height of the bitmap.
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x80, 0x3F, 0x21,
  0x21, 0x12, 0x0C, 0x00,  0x00, 0x00, 0x00, 0xFF,

  0x00, 0x00, 0x00, 0xF0,  0x08, 0x48, 0x48, 0xC8,
  0x00, 0x00, 0xFE, 0x00,  0x00,*/0xFF, 0x81, 0x81,
  0x81, 0xF1, 0xE1, 0xC1,/*0x81, 0x81, 0x81, 0x01,

  0x00, 0x20, 0x20, 0x20,  0x21, 0x21, 0x21, 0x20,
  0x20, 0x20, 0x3F, 0x00,  0x00,*/0xFF, 0x40, 0x40,
  0x40, 0x47, 0x43, 0x41,/*0x40, 0x40, 0x7F, 0xC0,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x48, 0x94,
  0x94, 0x94, 0x64, 0x00,  0x00, 0x00, 0x00, 0xFF */
};

 #else
 const unsigned char bmp_p_d_mos[(6 * 2) + 4] PROGMEM ={
        9,
        8,
	6, // The width of the bitmap.
	16, // The height of the bitmap.
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x3f, 0x21, 0x21, 0x21,  0x1e, 0x00, 0xff, 0xff, 

	0xe6, 0x16, 0x96, 0x96,  0xa6, 0x06, 0xfe, 0xfe, 
	0x00,*/0xff, 0xff, 0x06,  0xe6, 0xc6, 0x86,/*0x06, 
	0x06, 0x06, 0x06, 0x06,  0x06, 0x06, 0x07, 0x07, 

	0x01, 0x02, 0x02, 0x02,  0x01, 0x00, 0xff, 0xff, 
	0x00,*/0xff, 0xff, 0x83,  0x9f, 0x8f, 0x87/*,0x83, 
	0x83, 0x83, 0x83, 0x83,  0x83, 0x83, 0xff, 0xff, 

	0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x01, 0x01, 
	0x00, 0x07, 0x07, 0x01,  0x01, 0x01, 0x01, 0x01, 
	0x49, 0x95, 0x95, 0x95,  0x65, 0x01, 0xff, 0xff, */
};

 #endif
#else
 extern const unsigned char bmp_p_d_mos[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_p_jfet
// update the bmp_n_jfet to p_jfet at location 6,16
//
// Memory usage: 12 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_p_jfet[(3 * 2) + 4] PROGMEM ={
 9,
 8,
 3,
16,
 /*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0x21, 0x12,
  0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF,
                                           
  0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
  0x00,*/0x80, 0xC0, 0xE0,/*0x00, 0x00, 0xFC, 0xFC,
  0x08, 0x08, 0x08, 0x08,  0x08, 0x08, 0x08, 0x0F,
                                           
  0x00, 0x01, 0x01, 0x01,  0x01, 0x01, 0x01, 0x01,
  0x01,*/0x03, 0x07, 0x0F,/*0x01, 0x01, 0x7F, 0x7F,
  0x20, 0x20, 0x20, 0x20,  0x20, 0x20, 0x20, 0xE0,
                                           
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x94, 0x94,
  0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFF */
}; /* P-JFET = N-JFET + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_p_jfet[(3 * 2) + 4] PROGMEM ={
  9,
  8,
  3,
 16,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x3F, 0x21, 0x21, 0x12,
        0x0C, 0x00, 0x00, 0x00,  0x00, 0x00, 0xFF, 0xFF,

        0x00, 0x3C, 0x42, 0x52,  0x52, 0x34, 0x00, 0x00,
        0x00,*/0x80, 0xC0, 0xE0,/* 0x00, 0x00, 0xFF, 0xFF,
        0x0C, 0x0C, 0x0C, 0x0C,  0x0C, 0x0C, 0x0F, 0x0F,

        0x00, 0x03, 0x03, 0x03,  0x03, 0x03, 0x03, 0x03,
        0x03,*/0x07, 0x0F, 0x1F,/* 0x03, 0x03, 0xFF, 0xFF,
        0x60, 0x60, 0x60, 0x60,  0x60, 0x60, 0xE0, 0xE0,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x48, 0x94, 0x95, 0x95,
        0x64, 0x00, 0x00, 0x00,  0x00, 0x00, 0xFF, 0xFF */
}; /* P-JFET = N-JFET + UPDATE */

 #elif (ICON_TYPE == 3) /* thin icon update for Karl-Heinz */
 const unsigned char bmp_p_jfet[(3 * 1) + 4] PROGMEM ={
 9,
 16,
 3,
 8,
 /* code 003 P-JFET thin from Karl-Heinz */
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x3F, 0x21, 0x21, 0x12,  0x0C, 0x00, 0x00, 0xFF,

  0x00, 0x00, 0x00, 0xF0,  0x08, 0x48, 0x48, 0xD0,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0xFE, 0xFE,
  0x04, 0x04, 0x04, 0x04,  0x04, 0x04, 0x04, 0x07,

  0x00, 0x08, 0x08, 0x08,  0x09, 0x09, 0x09, 0x08,
  0x08,*/0x1C, 0x3E, 0x7F,/*0x08, 0x08, 0x7F, 0x7F,
  0x20, 0x20, 0x20, 0x20,  0x20, 0x20, 0x20, 0xE0,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x48, 0x94, 0x94, 0x94,  0x64, 0x00, 0x00, 0xFF */
};

 #else
 const unsigned char bmp_p_jfet[(5 * 2) + 4] PROGMEM ={
        5,
        16,
	5, // The width of the bitmap.
	16, // The height of the bitmap.
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x80,  0x80, 0x00, 0x00, 0x3f, 
	0x21, 0x21, 0x21, 0x1e,  0x00, 0xff, 0xff, 0x00, 

	0xc0, 0x20, 0x20, 0x20,  0x40, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff,  0xff, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06,  0x06, 0x07, 0x07, 0x00, 

	0x63, 0x64, 0x65, 0x65,  0x63,*/0xf0, 0xf8, 0xfc, 
	0x60, 0x60,/*0x60, 0xff,  0xff, 0x60, 0x60, 0x60, 
	0x60, 0x60, 0x60, 0x60,  0x60, 0xe0, 0xe0, 0x00, 

	0x00, 0x00, 0x00, 0x00,  0x00,*/0x00, 0x01, 0x03, 
	0x00, 0x00 /*,0x00, 0x01,  0x01, 0x00, 0x00, 0x48, 
	0x94, 0x94, 0x94, 0x64,  0x00, 0xff, 0xff, 0x00,  */
};

 #endif
#else
 extern const unsigned char bmp_p_jfet[] PROGMEM ;
#endif



//*****************************************************************************
//
// The data for the bitmapbmp_pnp
//  update for bitmap bmp_npn  at location 14,16
//
// Memory usage: 8 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #if (ICON_TYPE == 1) /* Nick's thin icon update */
 const unsigned char bmp_pnp[(7 * 2) + 4] PROGMEM ={
 16,
 16,
  7,
 16,
 /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,  0x1E, 0x21, 0x21, 0x21,
    0x12, 0x00, 0x00, 0x00,  0x00, 0x80, 0x40, 0x3F,

    0x00, 0x7E, 0x4A, 0x4A,  0x4A, 0x34, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFC,
    0x10, 0x08, 0x04, 0x02,  0x01, 0x00, 0x00, 0x00,

    0x00, 0x01, 0x01, 0x01,  0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01,  0x01, 0x01, 0x01, 0x7F, */
    0x10, 0x20, 0xC0, 0xC0,  0xC0, 0xC0, 0x40,/*0x00,

    0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,  0xFC, 0x94, 0x94, 0x94, */
    0x84, 0x00, 0x07, 0x03,  0x01, 0x02, 0x04,/*0xF8 */
}; /* PNP = NPN + UPDATE */

 #elif (ICON_TYPE == 2) /* Nick's bold icon update */
 const unsigned char bmp_pnp[(6 * 2) + 4] PROGMEM ={
 14,
 16,
  6,
 16,
     /* 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x1E, 0x21, 0x21, 0x21,
        0x12, 0x00, 0x00, 0x00,  0x80, 0xC0, 0xFF, 0x7F,

        0x00, 0x7E, 0x4A, 0x4A,  0x4A, 0x34, 0x00, 0x00,
        0x00, 0x00, 0xFC, 0xFC,  0x80, 0xC0, 0xE0, 0x70,
        0x38, 0x1C, 0x0E, 0x07,  0x03, 0x01, 0x00, 0x00,

        0x00, 0x03, 0x03, 0x03,  0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x7F, 0x7F,  0x07, 0x0F,*/ 0xFC, 0xF8,
        0x78, 0xF8, 0xD8, 0x88,/* 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0xFC, 0x94,*/ 0x95, 0x94,
        0x84, 0x00, 0x01, 0x03,/* 0x07, 0x0E, 0xFC, 0xF8 */
}; /*  PNP = NPN + Update */
 #elif (ICON_TYPE == 3) /* Thin icon update for Karl-Heinz */
 const unsigned char bmp_pnp[(7 * 2) + 4] PROGMEM ={
 16,
 16,
  5,
  8,
/*0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x1E, 0x21, 0x21, 0x21,  0x12, 0x00, 0x80, 0x7F,

  0x00, 0x00, 0x00, 0x7E,  0x4A, 0x4A, 0x4A, 0x34,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0xFC, 0x40,
  0x20, 0x10, 0x08, 0x04,  0x02, 0x01, 0x00, 0x00,

  0x00, 0x01, 0x01, 0x01,  0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01,  0x01, 0x01, 0x7F, 0x04,*/
  0xF8, 0x78, 0x38, 0x58, 0x88/*,0x00, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0xFC,
  0x94, 0x94, 0x84, 0x00,  0x00, 0x01, 0x02, 0xFC */
}; /* PNP = NPN + UPDATE */
 #else
 const unsigned char bmp_pnp[(6 * 1) + 4] PROGMEM ={
        14,
        16,
	6, // The width of the bitmap.
	8, // The height of the bitmap.
    /*  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x00, 0x1e, 0x21, 0x21,
        0x21, 0x12, 0x00, 0x80,  0xc0, 0xe0, 0x7f, 0x3f,

        0x80, 0x80, 0x80, 0x80,  0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0xfe, 0xfe,  0xc0, 0xe0, 0x70, 0x38,
        0x1c, 0x0e, 0x07, 0x03,  0x01, 0x00, 0x00, 0x00,

        0xfd, 0x95, 0x95, 0x95,  0x69, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x7f, 0x7f,  0x03, 0x07,*/0xfe, 0x7c, 
	0x3c, 0x7c, 0xec, 0xc4,/*0x80, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,  0x00, 0xfc, 0x94, 0x94,
        0x94, 0x84, 0x00, 0x01,  0x03, 0x07, 0xfe, 0xfc, */

};

#endif
#else
 extern const unsigned char bmp_pnp[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_one
//
// Memory usage: 7 bytes
//*****************************************************************************
#if defined (MAIN_C)
 #ifdef INVERSE_TP
  #define TP_DATA_COUNT 7
 #else
  #define TP_DATA_COUNT 5
 #endif
 const unsigned char bmp_one_data[(TP_DATA_COUNT * 1) + 2] PROGMEM ={
	TP_DATA_COUNT, /* The width of the bitmap. */
	8, /* The height of the bitmap. */
 #ifdef INVERSE_TP
        0xff, 0xff, 0xf7, 0xfb, 0x81, 0xff, 0xff
 #else
  #ifdef BIG_TP
        0x00, 0x04, 0x02, 0xff, 0x00
  #else
	0x00, 0x08, 0x04, 0x7e, 0x00
  #endif
 #endif
};
#else
 extern const unsigned char bmp_one_data[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_two
//
// Memory usage: 7 bytes
//*****************************************************************************
#if defined (MAIN_C)
 const unsigned char bmp_two_data[(TP_DATA_COUNT * 1) + 2] PROGMEM ={
	TP_DATA_COUNT, /* The width of the bitmap. */
	8, /* The height of the bitmap. */
 #ifdef INVERSE_TP
        0xff, 0xbb, 0x9d, 0xad, 0xad, 0xb3, 0xff
 #else
  #ifdef BIG_TP
        0xc2, 0xa1, 0x91, 0x89, 0x86
  #else
	0x44, 0x62, 0x52, 0x52, 0x4c
  #endif
 #endif
};
#else
 extern const unsigned char bmp_two_data[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_three
//
// Memory usage: 7 bytes
//*****************************************************************************
#if defined (MAIN_C)
 const unsigned char bmp_three_data[(TP_DATA_COUNT * 1) + 2] PROGMEM ={
	TP_DATA_COUNT, /* The width of the bitmap. */
	8, /* The height of the bitmap. */
 #ifdef INVERSE_TP
        0xff, 0xdb, 0xbd, 0xb5, 0xb5, 0xcb, 0xff
 #else
  #ifdef BIG_TP
        0x42, 0x81, 0x89, 0x89, 0x76
  #else
	0x24, 0x42, 0x4a, 0x4a, 0x34
  #endif
 #endif
};
#else
 extern const unsigned char bmp_three_data[] PROGMEM ;
#endif



//*****************************************************************************
//
// The data for the bitmapbmp_vakdiode
//
// Memory usage: 34 bytes
//*****************************************************************************
#if defined (MAIN_C)
 const unsigned char bmp_vakdiode[(8 * 4) + 4] PROGMEM ={
        24,
        0,
	8, // The width of the bitmap.
	32, // The height of the bitmap.
 #if (ICON_TYPE == 1)
	0x04, 0x04, 0x04, 0x04, 0xFC, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x60, 0xE0, 0xFF, 0xE0, 0x60, 0x20,
	0x00, 0x02, 0x02, 0x02, 0xFF, 0x02, 0x02, 0x02,
	0x20, 0x20, 0x20, 0x20, 0x3F, 0x00, 0x00, 0x00,

 #else
	0x06, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0x00, 0x00,
	0x20, 0x60, 0xE0, 0xFF, 0xFF, 0xE0, 0x60, 0x20,
	0x06, 0x06, 0x06, 0xFF, 0xFF, 0x06, 0x06, 0x06,
	0x60, 0x60, 0x60, 0x7F, 0x7F, 0x00, 0x00, 0x00, 
 #endif
};
#else
 extern const unsigned char bmp_vakdiode[] PROGMEM ;
#endif


//*****************************************************************************
//
// The data for the bitmap bmp_inductor
//
// Memory usage: 18 bytes
//*****************************************************************************
#if defined (MAIN_C)
 const unsigned char bmp_inductor_data[(16 * 1) + 2] PROGMEM ={
        16 , // The width of the bitmap.
         8, // The height of the bitmap.
	0x40, 0x7e, 0x01, 0x01,  0x3e, 0x01, 0x01, 0x3e, 
	0x01, 0x01, 0x3e, 0x01,  0x01, 0x7e, 0x40, 0x40, 
};
#else
 extern const unsigned char bmp_inductor_data[] PROGMEM ;
#endif

#if (LCD_ST_TYPE == 7920)
 #if defined (MAIN_C)
  const unsigned char set_msk[] PROGMEM = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
  const unsigned char clear_msk[] PROGMEM = { 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
 #else
  extern const unsigned char set_msk[] PROGMEM ;
  extern const unsigned char clear_msk[] PROGMEM ;
 #endif
#endif

