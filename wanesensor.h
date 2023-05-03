#ifndef WS_WANESENDOR
#define WS_WANESENDOR

#include <Wire.h>
#include <AS5601.h>
#include <Arduino.h>
#include "common.h"
#include "filtering.h"

class WSWane : public SensorBase {
private:
	TwoWire* i2c_wire;
	AS5601*  as_sensor;
	Filtered<uint32_t> value_adc;
	float    value_deg;
	uint32_t offset;

public:
	WSWane();
	~WSWane();
	void CalibrateToRaw(uint16_t raw_pos);
	void CalibrateToCurrentPos();
	uint16_t GetCalibratedOffset();
	int Handle();
	char* Serialize();
	char* SerializeJSON();
};


#endif