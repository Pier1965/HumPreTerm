/***********************************************
 Termometro - barometro - umidostato ambientale

  PPPC65 - http://pier.unirc.eu

************************************************/

// 07/07/2022 Rel. 0.0
// Fatto:   Rilevamento della temperatura, temperatura Humidex, umidità e pressione locali
// con BME280 i2C (allontanare sensore da cpu!!)
//
// Da fare: Andamento dei valori nel passato e simbolo grafico su TFT_BLACK
// DA fare: Aggiungere pulsante da gestire: 1) Cambio modalità: 
// locale / esterna / orologio / set SSID - PW - località (long press)
// Da fare: Gestione sw modalità di funzionmento.
//=================================================================================
#include "preproDefine.h"
#include "define.h"
#include "GlobalVar.h"
#include "includeLib.h"
#include "GlobalObject.h"
#include "includeFun.h"
//=================================================================================
void setup() {
  tft.init();
  tft.setRotation(3); // Pin su lato destro del tft
  Serial.begin(115200);
  Serial.println(F("BME280 test"));

  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  // Or else you will get a device not found error
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Default Test --");
  delayTime = 10000;
  uint W = tft.width();
  uint H = tft.height();
  tft.fillScreen(TFT_BLACK);
  tft.drawRect(0, 0, W, H, TFT_BLUE);
  tft.drawCentreString("CONDIZIONI DELL\'ARIA",W/2,2,2);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  Serial.println();
}
void loop() {
  printValues();
  delay(delayTime);
}

