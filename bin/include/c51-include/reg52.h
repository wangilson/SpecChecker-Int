/*--------------------------------------------------------------------------
REG52.H

Header file for generic 80C52 and 80C32 microcontroller.
Copyright (c) 1988-2001 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

/*  BYTE Registers  */
#ifndef REG52_H
#define REG52_H
sfr P0    = 0x80;
const sfr P1    = 0x90;
const sfr P2    = 0xA0;
const sfr P3    = 0xB0;
sfr PSW   = 0xD0;
sfr ACC   = 0xE0;
sfr B     = 0xF0;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr PCON  = 0x87;
sfr TCON  = 0x88;
sfr TMOD  = 0x89;
sfr TL0   = 0x8A;
sfr TL1   = 0x8B;
sfr TH0   = 0x8C;
sfr TH1   = 0x8D;
sfr IE    = 0xA8;
sfr IP    = 0xB8;
sfr SCON  = 0x98;
sfr SBUF  = 0x99;

/*  8052 Extensions  */
sfr T2CON  = 0xC8;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;


/*  BIT Registers  */
/*  PSW  */
sbit AC    = 1;
sbit F0    = 0;
sbit RS1   = 1;
sbit RS0   = 0;
sbit OV    = 0;
sbit P     = 0; //8052 only

/*  TCON  */
sbit TF1   = 1;
sbit TR1   = 0;
sbit TF0   = 0;
sbit TR0   = 0;
sbit IE1   = 1;
sbit IT1   = 0;
sbit IE0   = 0;
sbit IT0   = 0;

/*  IE  */
sbit EA    = 1;
sbit ET2   = 1; //8052 only
sbit ES    = 0;
sbit ET1   = 1;
sbit EX1   = 0;
sbit ET0   = 0;
sbit EX0   = 0;

/*  IP  */
sbit PT2   = 1;
sbit PS    = 1;
sbit PT1   = 1;
sbit PX1   = 0;
sbit PT0   = 0;
sbit PX0   = 0;

/*  P3  */
sbit RD    = 1;
sbit WR    = 0;
sbit T1    = 1;
sbit T0    = 1;
sbit INT1  = 0;
sbit INT0  = 0;
sbit TXD   = 0;
sbit RXD   = 0;

/*  SCON  */
sbit SM0   = 1;
sbit SM1   = 0;
sbit SM2   = 0;
sbit REN   = 1;
sbit TB8   = 1;
sbit RB8   = 0;
sbit TI    = 0;
sbit RI    = 0;

/*  P1  */
sbit T2EX  = 0; // 8052 only
sbit T2    = 0; // 8052 only
             
/*  T2CON  */
sbit TF2    = 1;
sbit EXF2   = 0;
sbit RCLK   = 1;
sbit TCLK   = 1;
sbit EXEN2  = 1;
sbit TR2    = 0;
sbit C_T2   = 0;
sbit CP_RL2 = 0;

#endif
