#ifndef CONFIG_H
#define CONFIG_H

// v1 == breadboard pcb
// 2 == 0.9 pcb :)
#define HWVERSION 2

// remove define to enable ;)
//#define DISABLE_ACCEL
#define USE_MDNS

// 192.168.4.1 is the IP it always has in softAP mode
const bool forceAPMode = false;

// VERBOSE, INFO, WARNING, ERROR
int DEBUG_LEVEL = VERBOSE;

/*
const char *jsonLastAP =
//"{\"ssid\":\"PACIFIC\", \"pwd\":\"AllesR0ger\"}";
//"{\"ssid\":\"wizard23\", \"pwd\":\"lolinternets\"}";
"{\"ssid\":\"wizme\", \"pwd\":\"lolinternets\"}";

const char *jsonAPList = "{\"list\": [\
{\"ssid\":\"metalab\", \"pwd\":\"\"},\
{\"ssid\":\"wizard23\", \"pwd\":\"lolinternets\"},\
{\"ssid\":\"wizme\", \"pwd\":\"lolinternets\"}\
]}";

const char *jsonSoftAP = "{\"ssid\":\"MagicShifter3000\", \"pwd\":\"\"}";
*/

#define CONNECTION_TIMEOUT 8000

#define SPI_FREQUENCY 20000000
#define POV_TIME_MICROSECONDS 1

#define VERSION 0.1

//#define LEDS 48
#define LEDS 16


#define PIN_LED_ENABLE 15

// PIN_LED_DATA an PIN_LED_CLOCK can not be changed since we use the hardware SPI
#define PIN_LED_DATA  13
#define PIN_LED_CLOCK 14

// double features as bootloader button
#define PIN_BUTTON1   0

#define PIN_I2C_DATA 5 // 5 //blau // labeled 5 on esp12E!!!
#define PIN_I2C_CLOCK 4 //lila


#if (HWVERSION >= 2)
  //#define PIN_I2C_DATA 4 // 5 //blau // labeled 5 on esp12E!!!
  //#define PIN_I2C_CLOCK 5 //lila

  #define PWMGT_PIN 16
#else
  //#define PIN_I2C_DATA 4 // 5 //blau // labeled 5 on esp12E!!!
  //#define PIN_I2C_CLOCK 2 //lila
#endif

#define MIN_TIME_CLICK 10000
//#define MIN_TIME_LONG_CLICK 500000
//const int MIN_TIME_CLICK = 10000;
const int MIN_TIME_LONG_CLICK = 500000;

//#define MMA8452_ADDRESS 0x1D  // 0x1D if SA0 is high, 0x1C if low
#define MMA8452_ADDRESS 0x1C

#define FILENAME_SIZE 40

#endif
