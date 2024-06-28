#ifndef HYDROMETER_SENSOR_H
#define HYDROMETER_SENSOR_H
#include <string>

#include "Sensor.h"

class HydrometerSensor : public Sensor {
 public:
  explicit HydrometerSensor(int id, bool active);
  ~HydrometerSensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  void printData() const override;
  std::string stringStatus() const;
  void collectAndPrint();

  friend std::ostream& operator<<(std::ostream& os,
                                  const HydrometerSensor& sensor);
};

#endif  // HYDROMETER_SENSOR_H