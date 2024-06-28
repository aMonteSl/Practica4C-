#ifndef KEYBOARDHARDWARE_H
#define KEYBOARDHARDWARE_H
#include "Hardware.h"

class KeyboardHardware : public Hardware {
 public:
  explicit KeyboardHardware(bool active);
  ~KeyboardHardware() override;

  int askInput() override;
  std::string stringInput();
  void displayOutput() const override;

 private:
  int data_;
  std::string stringData_;
};

#endif  // KEYBOARDHARDWARE_H
