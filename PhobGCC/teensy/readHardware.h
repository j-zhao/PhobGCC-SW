#ifndef READHARDWARE_H
#define READHARDWARE_H

//include this after the pins are defined in the Teensy board-specific headers

#include <ADC.h>
#include <VREF.h>
#include "../common/structsAndEnums.h"

void readButtons(const Pins &pin, Buttons &btn, HardwareButtons &hardware, const ControlConfig &controls) {
	btn.A = !digitalRead(pin.pinA);
	btn.B = !digitalRead(pin.pinB);
	btn.X = !digitalRead(controls.pinXSwappable);
	btn.Y = !digitalRead(controls.pinYSwappable);
	btn.Z = !digitalRead(controls.pinZSwappable);
	btn.S = !digitalRead(pin.pinS);
	btn.Du = !digitalRead(pin.pinDu);
	btn.Dd = !digitalRead(pin.pinDd);
	btn.Dl = !digitalRead(pin.pinDl);
	btn.Dr = !digitalRead(pin.pinDr);

	hardware.L = !digitalRead(pin.pinL);
	hardware.R = !digitalRead(pin.pinR);
	hardware.Z = !digitalRead(pin.pinZ);
	hardware.X = !digitalRead(pin.pinX);
	hardware.Y = !digitalRead(pin.pinY);
}

void readADCScale(float &_ADCScale, float &_ADCScaleFactor) {
#ifdef USEADCSCALE
	_ADCScale = _ADCScale*0.999 + _ADCScaleFactor/adc->adc1->analogRead(ADC_INTERNAL_SOURCE::VREF_OUT);
#endif
	// otherwise _ADCScale is 1
}

//these are 12 bit but we right shift to get 8 bit
uint8_t readLa(const Pins &pin) {
	return (adc->adc0->analogRead(pin.pinLa)) >> 4;
}
uint8_t readRa(const Pins &pin) {
	return (adc->adc0->analogRead(pin.pinRa)) >> 4;
}

//these are native 12-bit
int readAx(const Pins &pin) {
	return adc->adc0->analogRead(pin.pinAx);
}
int readAy(const Pins &pin) {
	return adc->adc0->analogRead(pin.pinAy);
}
int readCx(const Pins &pin) {
	return adc->adc0->analogRead(pin.pinCx);
}
int readCy(const Pins &pin) {
	return adc->adc0->analogRead(pin.pinCy);
}

#endif //READHARDWARE_H