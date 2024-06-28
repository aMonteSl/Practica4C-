#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H
#include <string>

#include "Sensor.h"

class AirQualitySensor : public Sensor {
 public:
  explicit AirQualitySensor(int id, bool active);
  ~AirQualitySensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  void printData() const override;
  void collectAndPrint();
  std::string stringStatus() const;

  friend std::ostream& operator<<(std::ostream& os,
                                  const AirQualitySensor& sensor);
};

#endif  // AIRQUALITYSENSOR_H