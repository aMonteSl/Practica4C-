#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H
#include <string>

#include "Sensor.h"

class LightSensor : public Sensor {
 public:
  explicit LightSensor(int id, bool active);
  ~LightSensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  void printData() const override;
  std::string stringStatus() const;
  void collectAndPrint();

  friend std::ostream& operator<<(std::ostream& os, const LightSensor& sensor);
};

#endif  // LIGHTSENSOR_H