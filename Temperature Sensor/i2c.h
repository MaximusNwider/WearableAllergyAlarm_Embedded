#ifndef __I2C_H
#define __I2C_H

/* PIC18 I2C peripheral library header */

/* SSPCON1 REGISTER */
#define   SSPENB    0x20  /* Enable serial port and configures
                             SCK, SDO, SDI                      */
#define   SLAVE_7   6     /* I2C Slave mode, 7-bit address      */
#define   SLAVE_10  7     /* I2C Slave mode, 10-bit address     */
#define   MASTER    8     /* I2C Master mode                    */

/* SSPSTAT REGISTER */
#define   SLEW_OFF  0xC0  /* Slew rate disabled for 100kHz mode */
#define   SLEW_ON   0x00  /* Slew rate enabled for 400kHz mode  */


/* FUNCTION PROTOTYPES */

#define PARAM_SCLASS auto


/* These devices have two I2C modules */
#if defined(__18F64J15) || defined(__18F65J10) || defined(__18F65J15) || \
    defined(__18F66J10) || defined(__18F66J15) || defined(__18F67J10) || \
    defined(__18F84J15) || defined(__18F85J10) || defined(__18F85J15) || \
    defined(__18F86J10) || defined(__18F86J15) || defined(__18F87J10) || \
    defined(__18F6627)  || defined(__18F6722)  || \
    defined(__18F8627)  || defined(__18F8722)

/* ***** I2C1 ***** */

/* StopI2C1
 * Generate bus stop condition
 */
#define StopI2C1()  SSP1CON2bits.PEN=1
#define StopI2C StopI2C1

/* StartI2C1
 * Generate bus start condition
 */
#define StartI2C1()  SSP1CON2bits.SEN=1
#define StartI2C StartI2C1 

/* RestartI2C1
 * Generate bus restart condition
 */
#define RestartI2C1()  SSP1CON2bits.RSEN=1
#define RestartI2C RestartI2C1

/* NotAckI2C1
 * Generate bus Not ACK condition
 */
#define NotAckI2C1()     SSP1CON2bits.ACKDT=1, SSP1CON2bits.ACKEN=1
#define NotAckI2C NotAckI2C1

/* AckI2C1
 * Generate bus ACK condition
 */
#define AckI2C1()        SSP1CON2bits.ACKDT=0, SSP1CON2bits.ACKEN=1
#define AckI2C AckI2C1

/* Idle I2C1
 * Test if I2C1 module is idle
 */
#define IdleI2C1()    while ((SSP1CON2 & 0x1F) | (SSP1STATbits.R_W))
#define IdleI2C IdleI2C1

/* CloseI2C1
 * Disable SPI module
 */
#define CloseI2C1()  SSP1CON1 &=0xDF
#define CloseI2C CloseI2C1

/* OpenI2C1
 * Configure SSP module for use with I2C1 EEPROM or I2C1 bus device.
 */
void OpenI2C1( PARAM_SCLASS unsigned char sync_mode, PARAM_SCLASS unsigned char slew );
#define OpenI2C OpenI2C1

/* DataRdyI2C1
 * Test if SSPBUF register is full
 */
#define DataRdyI2C1()    (SSP1STATbits.BF)
#define DataRdyI2C DataRdyI2C1

/* ReadI2C1
 * Read byte from SSP1BUF register
 */
unsigned char ReadI2C1( void );
#define ReadI2C ReadI2C1

/* GetcI2C1
 * Read byte from SSP1BUF register
 */
#define  getcI2C1  ReadI2C1
#define  getcI2C getcI2C1

/* WriteI2C1
 * Write byte to SSP1BUF register
 */
unsigned char WriteI2C1( PARAM_SCLASS unsigned char data_out );
#define WriteI2C WriteI2C1

/* putcI2C1
 * Write byte to SSP1BUF register
 */
#define  putcI2C1  WriteI2C1
#define  putcI2C putcI2C1

/* getsI2C1
 * Read in a string from I2C1 module
 */
unsigned char getsI2C1( PARAM_SCLASS unsigned char *rdptr, PARAM_SCLASS unsigned char length );
#define getsI2C getsI2C1

/* putsI2C1
 * Write a string to I2C1 module
 */
unsigned char putsI2C1( PARAM_SCLASS unsigned char *wrptr );
#define putsI2C putsI2C1

/* EEAckPolling1
 */
unsigned char EEAckPolling1( PARAM_SCLASS unsigned char control );
#define EEAckPolling EEAckPolling1

/* EEByteWrite1
 */
unsigned char EEByteWrite1( PARAM_SCLASS unsigned char control,
                           PARAM_SCLASS unsigned char address,
                           PARAM_SCLASS unsigned char data );
#define EEByteWrite EEByteWrite1

/* EECurrentAddRead1
 */
unsigned int  EECurrentAddRead1( PARAM_SCLASS unsigned char control );
#define EECurrentAddRead EECurrentAddRead1

/* EEPageWrite1
 */
unsigned char EEPageWrite1( PARAM_SCLASS unsigned char control,
                           PARAM_SCLASS unsigned char address,
                           PARAM_SCLASS unsigned char *wrptr );
#define EEPageWrite EEPageWrite1

/* EERandomRead1
 */
unsigned int  EERandomRead1( PARAM_SCLASS unsigned char control, PARAM_SCLASS unsigned char address );
#define EERandomRead EERandomRead1

/* EESequentialRead1
 */
unsigned char EESequentialRead1( PARAM_SCLASS unsigned char control,
                                PARAM_SCLASS unsigned char address,
                                PARAM_SCLASS unsigned char *rdptr,
                                PARAM_SCLASS unsigned char length );
#define EESequentialRead EESequentialRead1

/* ***** I2C2 ***** */

/* StopI2C2
 * Generate bus stop condition
 */
#define StopI2C2()  SSP2CON2bits.PEN=1

/* StartI2C2
 * Generate bus start condition
 */
#define StartI2C2()  SSP2CON2bits.SEN=1

/* RestartI2C2
 * Generate bus restart condition
 */
#define RestartI2C2()  SSP2CON2bits.RSEN=1

/* NotAckI2C2
 * Generate bus Not ACK condition
 */
#define NotAckI2C2()     SSP2CON2bits.ACKDT=1, SSP2CON2bits.ACKEN=1

/* AckI2C2
 * Generate bus ACK condition
 */
#define AckI2C2()        SSP2CON2bits.ACKDT=0, SSP2CON2bits.ACKEN=1

/* Idle I2C2
 * Test if I2C2 module is idle
 */
#define IdleI2C2()    while ((SSP2CON2 & 0x1F) | (SSP2STATbits.R_W))

/* CloseI2C2
 * Disable SPI module
 */
#define CloseI2C2()  SSP2CON1 &=0xDF

/* OpenI2C2
 * Configure SSP module for use with I2C2 EEPROM or I2C2 bus device.
 */
void OpenI2C2( PARAM_SCLASS unsigned char sync_mode, PARAM_SCLASS unsigned char slew );

/* DataRdyI2C2
 * Test if SSPBUF register is full
 */
#define DataRdyI2C2()    (SSP2STATbits.BF)

/* ReadI2C2
 * Read byte from SSP2BUF register
 */
unsigned char ReadI2C2( void );

/* GetcI2C2
 * Read byte from SSP2BUF register
 */
#define  getcI2C2  ReadI2C2

/* WriteI2C2
 * Write byte to SSP2BUF register
 */
unsigned char WriteI2C2( PARAM_SCLASS unsigned char data_out );

/* putcI2C2
 * Write byte to SSP2BUF register
 */
#define  putcI2C2  WriteI2C2

/* getsI2C2
 * Read in a string from I2C2 module
 */
unsigned char getsI2C2( PARAM_SCLASS unsigned char *rdptr, PARAM_SCLASS unsigned char length );

/* putsI2C2
 * Write a string to I2C2 module
 */
unsigned char putsI2C2( PARAM_SCLASS unsigned char *wrptr );

/* EEAckPolling2
 */
unsigned char EEAckPolling2( PARAM_SCLASS unsigned char control );

/* EEByteWrite2
 */
unsigned char EEByteWrite2( PARAM_SCLASS unsigned char control,
                           PARAM_SCLASS unsigned char address,
                           PARAM_SCLASS unsigned char data );

/* EECurrentAddRead2
 */
unsigned int  EECurrentAddRead2( PARAM_SCLASS unsigned char control );

/* EEPageWrite2
 */
unsigned char EEPageWrite2( PARAM_SCLASS unsigned char control,
                           PARAM_SCLASS unsigned char address,
                           PARAM_SCLASS unsigned char *wrptr );

/* EERandomRead2
 */
unsigned int  EERandomRead2( PARAM_SCLASS unsigned char control, PARAM_SCLASS unsigned char address );

/* EESequentialRead2
 */
unsigned char EESequentialRead2( PARAM_SCLASS unsigned char control,
                                PARAM_SCLASS unsigned char address,
                                PARAM_SCLASS unsigned char *rdptr,
                                PARAM_SCLASS unsigned char length );

#else    /* Parts with only one I2C */

/* StopI2C
 * Generate bus stop condition
 */
#define StopI2C()  SSPCON2bits.PEN=1

/* StartI2C
 * Generate bus start condition
 */
#define StartI2C()  SSPCON2bits.SEN=1

/* RestartI2C
 * Generate bus restart condition
 */
#define RestartI2C()  SSPCON2bits.RSEN=1

/* NotAckI2C
 * Generate bus Not ACK condition
 */
#define NotAckI2C()     SSPCON2bits.ACKDT=1, SSPCON2bits.ACKEN=1

/* AckI2C
 * Generate bus ACK condition
 */
#define AckI2C()        SSPCON2bits.ACKDT=0, SSPCON2bits.ACKEN=1

/* Idle I2C
 * Test if I2C module is idle
 */
#define IdleI2C()    while ((SSPCON2 & 0x1F) | (SSPSTATbits.R_W))

/* CloseI2C
 * Disable SPI module
 */
#define CloseI2C()  SSPCON1 &=0xDF

/* OpenI2C
 * Configure SSP module for use with I2C EEPROM or I2C bus device.
 */
void OpenI2C( PARAM_SCLASS unsigned char sync_mode, PARAM_SCLASS unsigned char slew );

/* DataRdyI2C
 * Test if SSPBUF register is full
 */
#define DataRdyI2C()    (SSPSTATbits.BF)

/* ReadI2C
 * Read byte from SSPBUF register
 */
unsigned char ReadI2C( void );

/* GetcI2C
 * Read byte from SSPBUF register
 */
#define  getcI2C  ReadI2C

/* WriteI2C
 * Write byte to SSPBUF register
 */
unsigned char WriteI2C( PARAM_SCLASS unsigned char data_out );

/* putcI2C
 * Write byte to SSPBUF register
 */
#define  putcI2C  WriteI2C

/* getsI2C
 * Read in a string from I2C module
 */
unsigned char getsI2C( PARAM_SCLASS unsigned char *rdptr, PARAM_SCLASS unsigned char length );

/* putsI2C
 * Write a string to I2C module
 */
unsigned char putsI2C( PARAM_SCLASS unsigned char *wrptr );

/* EEAckPolling
 */
unsigned char EEAckPolling( PARAM_SCLASS unsigned char control );

/* EEByteWrite
 */
unsigned char EEByteWrite( PARAM_SCLASS unsigned char control,
                           PARAM_SCLASS unsigned char address,
                           PARAM_SCLASS unsigned char data );

/* EECurrentAddRead
 */
unsigned int  EECurrentAddRead( PARAM_SCLASS unsigned char control );

/* EEPageWrite
 */
unsigned char EEPageWrite( PARAM_SCLASS unsigned char control,
                           PARAM_SCLASS unsigned char address,
                           PARAM_SCLASS unsigned char *wrptr );

/* EERandomRead
 */
unsigned int  EERandomRead( PARAM_SCLASS unsigned char control, PARAM_SCLASS unsigned char address );

/* EESequentialRead
 */
unsigned char EESequentialRead( PARAM_SCLASS unsigned char control,
                                PARAM_SCLASS unsigned char address,
                                PARAM_SCLASS unsigned char *rdptr,
                                PARAM_SCLASS unsigned char length );
#endif
#endif

