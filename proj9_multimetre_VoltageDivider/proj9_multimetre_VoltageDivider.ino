
#include <Adafruit_ST7735.h> 

#if defined(ARDUINO_FEATHER_ESP32) 
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32

#else

  #define TFT_CS        10
  #define TFT_RST        8 
  #define TFT_DC         9
#endif

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

  
int sensor1 = A2;
int raw1 = 0;
int Vin1 = 4.377;
float Vout1 = 0;
float R1 = 1172;
float R2 = 0;
float buffer1 = 0;

int sensor2 = A4;
int raw2 = 0;
int Vin2 = 4.377;
float Vout2 = 0;
float R3 = 1181;
float R4 = 0;
float buffer2 = 0;

void setup(){
Serial.begin(9600);

tft.initR(INITR_BLACKTAB);      
tft.setRotation (1);


}

void loop(){
  raw1 = analogRead(sensor1);
  raw2 = analogRead(sensor2);

    buffer1 = raw1 * Vin1;
    Vout1 = (buffer1)/1024.0;

    buffer2 = raw2 * Vin2;
    Vout2 = (buffer2)/1024.0; 
    
    buffer1 = (Vin1/Vout1) - 1;
    R2= R1 * buffer1;

    buffer2 = (Vin2/Vout2) - 1;
    R4= R3 * buffer2;
        
    Serial.print("Vout1: ");
    Serial.println(Vout1);
    Serial.print("R2: ");
    Serial.println(R2);
    Serial.println(".......................................");
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 50);
    tft.setTextSize(2);
    tft.print(" Vout1: ");
    tft.println(Vout1);
    tft.print(" R2: ");
    tft.println(R2);
    delay(2500);

    
    Serial.print("Vout2: ");
    Serial.println(Vout2);
    Serial.print("R4: ");
    Serial.println(R4);
    Serial.println(".......................................");
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 50);
    tft.setTextSize(2);
    tft.print(" Vout2: ");
    tft.println(Vout2);
    tft.print(" R4: ");
    tft.println(R4);
    delay(2500);

}
