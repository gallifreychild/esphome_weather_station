#include "esphome.h"

class weatherStation : public PollingComponent, public UARTDevice, public sensor::Sensor{
 public:
  weatherStation(UARTComponent *parent) : PollingComponent(1000), UARTDevice(parent) {}
  float wind_dir = 0;
  //float wind_current_speed = 0;
  //float wind_gust = 0;
  //float wind_gust_dir = 0;
  //float wind_spd_avg2m = 0;
  //float wind_dir_avg2m = 0;
  //float wind_gust_avg10m = 0;
  //float wind_gust_dir_avg10m = 0;
  //float rain_fall_1h =0;
  //float rain_fall_24h =0;
  
  void setup() override {
    // nothing to do here
  }
  
  void loop() override {
    while (available()) {
      String line = Serial.readStringUntil('\n');
      wind_dir = line.toFloat();
    }
  }
  
  void update() {
    publish_state(wind_dir);
  }
};
