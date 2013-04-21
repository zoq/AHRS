#include <RF12.h>

typedef struct Payload {
    int accelerometer_data[3];
    int gyro_data[3];
    int magnetometer_data[3];
} __attribute__ ((packed));

Payload data;

void setup()
{
  // Init serial output
  Serial.begin(115200);

  //nodeID freqBand netGroup  
  rf12_initialize(2, RF12_868MHZ, 5);    
}


/**
 * print received accelerometer data
 */
void print_raw_accel()
{
    Serial.print(data.accelerometer_data[0]);
    Serial.print(" ");
    Serial.print(data.accelerometer_data[1]);
    Serial.print(" ");
    Serial.println(data.accelerometer_data[2]);
}

/**
 * print received magnetometer data
 */
void print_raw_mag()
{   
    Serial.print(data.magnetometer_data[0]);
    Serial.print(" ");
    Serial.print(data.magnetometer_data[1]);
    Serial.print(" ");
    Serial.println(data.magnetometer_data[2]);
}

/**
 * print received gyroscope data
 */
void print_raw_gyro()
{
    Serial.print(data.gyro_data[0]);
    Serial.print(" ");
    Serial.print(data.gyro_data[1]);
    Serial.print(" ");
    Serial.println(data.gyro_data[2]);
}

/**
 * read incoming message and print the data
**/
void loop()
{
    if (rf12_recvDone() && rf12_crc == 0) {
        data = *(Payload*)rf12_data;

        print_raw_mag();
        print_raw_gyro();
        print_raw_accel();
    }
}