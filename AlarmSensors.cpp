#include "AlarmSensors.h"

#include <iostream>

#include "AirQualitySensor.h"
#include "HydrometerSensor.h"
#include "LightSensor.h"
#include "PhSensor.h"
#include "PressureSensor.h"
#include "TemperatureSensor.h"
using namespace std;

// Constructor con las declaraciones antincipadas
AlarmSensors::AlarmSensors(TemperatureSensor *temp, AirQualitySensor *air,
                           HydrometerSensor *hyd, PressureSensor *pres,
                           LightSensor *light, PhSensor *ph)
    : temp_(temp), air_(air), hyd_(hyd), pres_(pres), light_(light), ph_(ph) {}

AlarmSensors::~AlarmSensors() {}

bool AlarmSensors::SensorsIniticialized() {
  return temp_->getData() != -1 && air_->getData() != -1 &&
         hyd_->getData() != -1 && pres_->getData() != -1 &&
         light_->getData() != -1 && ph_->getData() != -1;
}

int AlarmSensors::checkSensors() {
  if (!SensorsIniticialized()) {
    return -1;
  } else {
    if (temp_->checkAllgood() && air_->checkAllgood() && hyd_->checkAllgood() &&
        pres_->checkAllgood() && light_->checkAllgood() &&
        ph_->checkAllgood()) {
      return 1;
    } else {
      return 0;
    }
  }
}

void AlarmSensors::displayAlarmStatus() {
  if (status_) {
    if (checkSensors() == 1) {
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|         All sensors are in good status          |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    } else if (checkSensors() == 0) {
      // Dibujar el logo de alarma, el triangulo con la exclamacion en el medio
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|  ¡¡One or more sensors are not in good status¡¡ |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    } else if (checkSensors() == -1) {
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|  ¡¡One or more sensors are not initialized¡¡    |" << endl;
      cout << "|    do a collect of data to initialize them      |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    } else {
      cout << "---------------------------------------------------" << endl;
      cout << "|                                                 |" << endl;
      cout << "|            ¡¡Error in the system¡¡              |" << endl;
      cout << "|                                                 |" << endl;
      cout << "---------------------------------------------------" << endl;
    }
  } else {
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                 The system its off              |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
  }
}

void AlarmSensors::displayAllSensorsData() {
  temp_->collectAndPrint();
  air_->collectAndPrint();
  hyd_->collectAndPrint();
  pres_->collectAndPrint();
  light_->collectAndPrint();
  ph_->collectAndPrint();
}

void AlarmSensors::turnOnOffSystem(int input) {
  // Si el input es igual a true entonces encender todos los sensores
  if (input == 1) {
    temp_->turnOn();
    air_->turnOn();
    hyd_->turnOn();
    pres_->turnOn();
    light_->turnOn();
    ph_->turnOn();
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                 System turned on                |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
    status_ = true;
  } else {
    temp_->turnOff();
    air_->turnOff();
    hyd_->turnOff();
    pres_->turnOff();
    light_->turnOff();
    ph_->turnOff();
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|                 System turned off               |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
    status_ = false;
  }
}