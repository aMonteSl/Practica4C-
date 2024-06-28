#ifndef PH_SENSOR_H
#define PH_SENSOR_H
#include <string>

#include "Sensor.h"

class PhSensor : public Sensor {
 public:
  explicit PhSensor(int id, bool active);
  ~PhSensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  std::string qualifyPh() const;
  void printData() const override;
  std::string stringStatus() const;
  void collectAndPrint();

  friend std::ostream& operator<<(std::ostream& os, const PhSensor& sensor);
};

#endif  // PH_SENSOR_H