#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H
#include <string>

#include "Sensor.h"

class PressureSensor : public Sensor {
 public:
  explicit PressureSensor(int id, bool active);
  ~PressureSensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  void printData() const override;
  std::string stringStatus() const;
  void collectAndPrint();

  friend std::ostream& operator<<(std::ostream& os,
                                  const PressureSensor& sensor);
};

#endif  // PRESSURESENSOR_H