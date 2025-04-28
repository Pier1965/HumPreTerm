#include "humidex.h"
void printValues() {
  uint W = tft.width();
  uint H = tft.height();
  //tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);  // Adding a black background colour erases previous text automatically
  //tft.drawRect(0, 0, W, H, TFT_BLUE);
  //tft.drawCentreString("CONDIZIONI DELL\'ARIA",W/2,2,2);
  Serial.print("Temperature = ");
  float T = bme.readTemperature();
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  tft.drawString("Temperatura: ",5,1.5*HL);
  tft.drawString(String(T), W/2,1.5*HL);
  tft.drawString("*C",W-40,1.5*HL);
  // Convert temperature to Fahrenheit
  /*Serial.print("Temperature = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");*/

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  float P = bme.readPressure() / 100.0F;
  Serial.println(" hPa");
  tft.drawString("Pressione: ",5,2.5*HL);
  tft.drawString(String(P), W/2,2.5*HL);
  tft.drawString("hPa",W-40,2.5*HL);

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  float U = bme.readHumidity();
  tft.drawString("Umidita: ",5,3.5*HL);
  tft.drawString(String(U), W/2,3.5*HL);
  tft.drawString("%",W-40,3.5*HL);

  Serial.print("Humidex = ");
  float humidex = temp_humidex(T,U);
  Serial.print(humidex);
  Serial.println(" *C");
  tft.drawString("T percepita: ",5,4.5*HL);
  tft.drawString(String(humidex), W/2,4.5*HL);
  tft.drawString("*C",W-40,4.5*HL);

  Serial.println();
}