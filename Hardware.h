#ifndef HARDWARE_H
#define HARDWARE_H
#include <string>

// Clase hardware que luego tendra clases hijas, pantalla, teclado, microfono e
// interruptor
class Hardware {
 public:
  enum Types_Hardware { NONE, SCREEN, KEYBOARD, SWITCH };

  Hardware();
  explicit Hardware(bool active, Types_Hardware type);
  virtual ~Hardware();

  std::string getType() const;
  void setType(std::string newtype);

  bool isActive() const;
  void turnOn();
  void turnOff();
  std::string stringStatus() const;

  virtual int askInput();
  virtual void displayOutput() const;

 private:
  bool active_;
  Types_Hardware type_;

  std::string typeToString(Types_Hardware type) const;
  Types_Hardware stringToType(std::string type) const;
};

#endif  // HARDWARE_H