#ifndef SENSOR_H
#define SENSOR_H
#include <string>

class Sensor {
 public:
  enum Types {
    NONE,
    TEMPERATURE,
    AIR_QUALITY,
    HYDROMETER,
    PRESSURE,
    LIGHT_SENSOR,
    PH_SENSOR,
  };

  Sensor();
  explicit Sensor(int id, Types type, bool active);
  virtual ~Sensor();

  // Estas funciones se van a poder modificiar en las clases derivadas gracias a
  // la palabra virtual
  virtual void collectData();

  bool isActive() const;
  void turnOff();
  void turnOn();
  float getData() const;
  void setData(float data);
  int getId() const;
  void setId(int newid);
  std::string getType() const;
  void setType(std::string newtype);

  // chekea, cambia state_ y devuelve el valor de state_
  // No tengo un setState() porque cuando chequeas el sensor primero debes de
  // ver el estado del sensor
  virtual bool checkAllgood() const;

  bool operator<(const Sensor &Sensor) const;
  bool operator>(const Sensor &Sensor) const;
  bool operator==(const Sensor &Sensor) const;
  friend std::ostream &operator<<(std::ostream &os, const Sensor &Sensor);
  friend std::istream &operator>>(std::istream &is, Sensor &Sensor);

  virtual void printData() const;

 private:
  int id_;
  Types type_;
  bool active_;
  float data_;

  Types stringToType(const std::string &type) const;
  std::string typeToString(Types type) const;
};

#endif  // SENSOR_H
