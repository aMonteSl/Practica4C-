#ifndef ALARMSENSORS_H
#define ALARMSENSORS_H

// Declaracion anticipada de cada uno de los sensores
class TemperatureSensor;
class AirQualitySensor;
class HydrometerSensor;
class PressureSensor;
class LightSensor;
class PhSensor;

class AlarmSensors {
 public:
  // Constructor con las declaraciones antincipadas
  explicit AlarmSensors(TemperatureSensor *temp, AirQualitySensor *air,
                        HydrometerSensor *hyd, PressureSensor *pres,
                        LightSensor *light, PhSensor *ph);
  // Destructor
  ~AlarmSensors();

  // Mostrar estado de la alarma
  void displayAlarmStatus();
  // Tambien debemos de dar la opcion de mostrar los datos de todos los sensores
  // Mostrar los datos de todos los sensores
  void displayAllSensorsData();
  // Opcion de poder apagar o encender el sistema
  void turnOnOffSystem(int input);

 private:
  TemperatureSensor *temp_;
  AirQualitySensor *air_;
  HydrometerSensor *hyd_;
  PressureSensor *pres_;
  LightSensor *light_;
  PhSensor *ph_;

  // El sistema de alarma tiene que chequear todos los sensores
  int checkSensors();
  // El sistema que todos los sensores no tienen el valor por defecto de -1
  bool SensorsIniticialized();

  bool status_ = true;
};

#endif  // ALARMSENSORS_H