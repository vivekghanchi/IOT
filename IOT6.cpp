#include "mbed.h"
#include "nRF24L01P.h"
Serial pc(USBTX, USBRX);
//NRF connections to mbed
nRF24L01P my_nrf24l01p(PTD2, PTD3, PTD1, PTD0, PTD5, PTD4); 
// mosi, miso,sck, csn, ce, irq

DigitalOut RedLED(LED1);
AnalogIn pot(PTB0);
AnalogIn ldr(PTB1);
int main()
{
float potval;
char potc;
float ldrval;
char ldrc;
char count[2];
char TxDataCnt;
char temp;
int k = 255;
//waking up NRF
my_nrf24l01p.powerUp();
//setting frequency of NRF
my_nrf24l01p.setRfFrequency(2410);
//display default settings of NRF
pc.printf( "nRF24L01+ Frequency : %d MHz\r\n",
my_nrf24l01p.getRfFrequency() );
pc.printf( "nRF24L01+ Output power : %d dBm\r\n",
my_nrf24l01p.getRfOutputPower() );
pc.printf( "nRF24L01+ Data Rate : %d kbps\r\n",
my_nrf24l01p.getAirDataRate() );
pc.printf( "nRF24L01+ TX Address : 0x%010llX\r\n",
my_nrf24l01p.getTxAddress() );
pc.printf( "nRF24L01+ RX Address : 0x%010llX\r\n",
my_nrf24l01p.getRxAddress() );
pc.printf( "Simple Transmitter \r\n");
TxDataCnt = 2;
//set packet size of NRF
my_nrf24l01p.setTransferSize(TxDataCnt);
//enabling radio of NRF
my_nrf24l01p.enable();
//sending test count value
//count[0] = 0x01;
//count[1] = 0x01;
while (1) {

potval = pot.read();
potc = potval*k;
ldrval = ldr.read();
ldrc = ldrval*k;

count[0] = potc;
count[1] = ldrc;
//Send the Transmit buffer via the nRF24L01+
temp = my_nrf24l01p.write( NRF24L01P_PIPE_P0,count, TxDataCnt );

//print how many bytes sent
pc.printf( "Sending %d -pot - %d ldr -
%d\r\n",temp,count[0],count[1]);
//toggle debug led
RedLED = !RedLED;
//update count
//count[0]++;
wait(0.5);
}
}