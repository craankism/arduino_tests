#include <Arduino.h>
#include <Arduino_Modulino.h>
#include <Arduino_LED_Matrix.h>
#include <ArduinoGraphics.h>

ModulinoThermo thermo;
ArduinoLEDMatrix matrix;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  //led matrix
  matrix.begin();

  // modulino
  Modulino.begin();
  thermo.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  int celsius = thermo.getTemperature();

  //led matrix

  uint32_t white = 0xFFFFFFFF;
  matrix.beginDraw();
  matrix.stroke(white);
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, white);
  matrix.print(celsius);
  matrix.print("°C");
  matrix.endText();
  matrix.endDraw();

  //serial monitor
  Serial.print("Temperatur (°C) is: ");
  Serial.println(celsius);

  delay(1000);
}
