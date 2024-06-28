#ifndef SWITCHHARDWARE_H
#define SWITCHHARDWARE_H
#include "Hardware.h"

class SwitchHardware : public Hardware {
 public:
  explicit SwitchHardware(bool active);
  ~SwitchHardware() override;

  int askInput() override;
  void displayOutput() const override;

 private:
  void translateInput(int input);
};

#endif  // SWITCHHARDWARE_H