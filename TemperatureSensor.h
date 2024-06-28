#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <string>

#include "Sensor.h"

class TemperatureSensor : public Sensor {
 public:
  explicit TemperatureSensor(int id, bool active);
  ~TemperatureSensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  void printData() const override;
  std::string stringStatus() const;
  void collectAndPrint();

  friend std::ostream& operator<<(std::ostream& os,
                                  const TemperatureSensor& sensor);
};

#endif  // TEMPERATURESENSOR_H