#include <p18cxxx.h> // This code is developed for PIC18F2550

/** PRIVATE PROTOTYPES *********************************************/
void i2c_init(void);
void i2c_start(void);
void i2c_repStart(void);
void i2c_stop(void);
unsigned char i2c_write( unsigned char i2cWriteData );
unsigned char i2c_read( unsigned char ack );


void i2c_init(void) {
 TRISBbits.TRISB0 = 1; // Digital Output (make it input only when reading data)
 TRISBbits.TRISB1 = 1; // Digital Output
 SSPCON1 = 0x28; // enable I2C Master mode
 SSPCON2 = 0x00; // clear control bits
 SSPSTAT = 0x80; // disable slew rate control; disable SMBus
 SSPADD = 19; // set baud rate to 100 kHz (Fosc = 48 MHz)
 PIR1bits.SSPIF = 0;
 PIR2bits.BCLIF = 0;
 SSPCON2bits.SEN = 0; // force idle condition
}

void i2c_start(void) {
 PIR1bits.SSPIF = 0; //clear flag
 while (SSPSTATbits.BF ); // wait for idle condition
 SSPCON2bits.SEN = 1; // initiate START condition
 while (!PIR1bits.SSPIF) ; // wait for a flag to be set
 PIR1bits.SSPIF = 0; // clear flag
} 

void i2c_repStart(void) {
 PIR1bits.SSPIF = 0; // clear flag
 while ( SSPSTATbits.BF ) ; // wait for idle condition
 SSPCON2bits.RSEN = 1; // initiate Repeated START condition
 while (!PIR1bits.SSPIF) ; // wait for a flag to be set
 PIR1bits.SSPIF = 0; // clear flag
}

void i2c_stop(void) {
 PIR1bits.SSPIF = 0; // clear flag
 while ( SSPSTATbits.BF ) ; // wait for idle condition
 SSPCON2bits.PEN = 1; // Initiate STOP condition
 while (!PIR1bits.SSPIF) ; // wait for a flag to be set
 PIR1bits.SSPIF = 0; // clear flag
}


unsigned char i2c_write( unsigned char i2cWriteData ) {
 PIR1bits.SSPIF = 0; // clear interrupt
 while ( SSPSTATbits.BF ) ; // wait for idle condition
 SSPBUF = i2cWriteData; // Load SSPBUF with i2cWriteData (the value to be transmitted)
 while (!PIR1bits.SSPIF) ; // wait for a flag to be set
 PIR1bits.SSPIF = 0; // clear flag
 return ( !SSPCON2bits.ACKSTAT ); // function returns '1' if transmission is acknowledged
}

unsigned char i2c_read( unsigned char ack ) {
 unsigned char i2cReadData;
 PIR1bits.SSPIF = 0;// clear interrupt
 while ( SSPSTATbits.BF ) ; // wait for idle condition
 SSPCON2bits.RCEN = 1; // enable receive mode
 while (!PIR1bits.SSPIF) ; // wait for a flag to be set
 PIR1bits.SSPIF = 0;// clear flag
 i2cReadData = SSPBUF; // Read SSPBUF and put it in i2cReadData
 if ( ack ) { // if ack=1
 SSPCON2bits.ACKDT = 0; // then transmit an Acknowledge
 } else {
 SSPCON2bits.ACKDT = 1; // otherwise transmit a Not Acknowledge
 }
 SSPCON2bits.ACKEN = 1; // send acknowledge sequence
 while (!PIR1bits.SSPIF) ; // wait for a flag to be set
 PIR1bits.SSPIF = 0;// clear flag
 return( i2cReadData ); // return the value read from SSPBUF
} 



