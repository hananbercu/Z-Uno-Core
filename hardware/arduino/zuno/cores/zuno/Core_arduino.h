
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef __code void (*VOID_FUNC_POINTER_VOID) (void);
typedef __code void (*VOID_FUNC_POINTER_BYTE) (BYTE value);
typedef __code void (*VOID_FUNC_POINTER_DW0RD) (DWORD value);
typedef __code BYTE (*BYTE_FUNC_POINTER_VOID) (void);
typedef __code WORD (*WORD_FUNC_POINTER_VOID) (void);
typedef __code DWORD (*DWORD_FUNC_POINTER_VOID) (void);
typedef __code void * GENERIC_POINTER;
typedef struct _SERIAL_DESCRIPTOR
{
	VOID_FUNC_POINTER_VOID begin;
	VOID_FUNC_POINTER_VOID 	end;
	BYTE_FUNC_POINTER_VOID 	available;
	BYTE_FUNC_POINTER_VOID 	read;
	VOID_FUNC_POINTER_BYTE 	write;
} SERIAL_DESCRIPTOR;

typedef struct _ZUNO_CHANNEL_PROPERTIES_DESCRIPTION
{
	BYTE channel_cmd_class;
	BYTE channel_sensor_type;
	BYTE channel_multilevel_properties;
	GENERIC_POINTER getter;
	GENERIC_POINTER setter;
} ZUNO_CHANNEL_PROPERTIES_DESCRIPTION;


typedef struct _ZUNO_ASSOCIATION_PROPERTIES_DESCRIPTION
{
	BYTE association_type;
	BYTE association_param;
} ZUNO_ASSOCIATION_PROPERTIES_DESCRIPTION;

typedef struct _ZUNO_SLEEPING_MODE_PROPERTIES_DESCRIPTION
{
	BYTE current_mode;
	BYTE parameter;
	GENERIC_POINTER handler;
} ZUNO_SLEEPING_MODE_PROPERTIES_DESCRIPTION;

//#define XBYTE  _xdata BYTE /* External data byte */

#define ZUNO_CORES_SW_VERSION_MAJOR 		0
#define ZUNO_CORES_SW_VERSION_MINOR 		45 			


#define ZUNO_PIN_STATE_HIGH 				1
#define ZUNO_PIN_STATE_LOW 	 				0
#define ZUNO_SWITCHED_ON 					0xFF
#define ZUNO_SWITCHED_OFF 					0

#define HIGH 								ZUNO_PIN_STATE_HIGH
#define LOW 								ZUNO_PIN_STATE_LOW

#define ZUNO_STACK_SIZE 		50
#define ZUNO_STACK_ADDRESS 		8001
#define ZUNO_STACK_TOP_ADDRESS 	8000
#define ZUNO_DELAY_SAFE_STACK_ADDRESS 	8052
#define ZUNO_DELAY_USER_STACK_POINTER_ADDRESS 		0x6E
#define ZUNO_CHANNEL_SETUP_ARRAY_ADDRESS 			(0x8020)

#define ZUNO_PIN_MODE_OUTPUT 				0
#define ZUNO_PIN_MODE_INPUT  				1
#define ZUNO_PIN_MODE_INPUT_WITH_PULLUP  	2
#define OUTPUT 								ZUNO_PIN_MODE_OUTPUT
#define INPUT 								ZUNO_PIN_MODE_INPUT
#define NULL 								0

enum {
	ZUNO_FUNC_PIN_MODE,
	ZUNO_FUNC_DIGITAL_WRITE,
	ZUNO_FUNC_DIGITAL_READ,
	ZUNO_FUNC_UNSOLICITED_REPORT,
	ZUNO_FUNC_ASSOCIATION_SEND,
	ZUNO_FUNC_DELAY_MS,
	ZUNO_FUNC_ANALOG_READ,
	ZUNO_FUNC_ANALOG_WRITE,
	ZUNO_FUNC_SERIAL0_BEGIN,
	ZUNO_FUNC_SERIAL0_END,
	ZUNO_FUNC_SERIAL0_AVAILABLE,
	ZUNO_FUNC_SERIAL0_READ,
	ZUNO_FUNC_SERIAL0_WRITE,
	ZUNO_FUNC_GO_SLEEP,
};

enum {
	ZUNO_SENSOR_BINARY_GETTER,
	ZUNO_SENSOR_MULTILEVEL_GETTER,
	ZUNO_SWITCH_BINARY_GETTER,
	ZUNO_SWITCH_BINARY_SETTER,
	ZUNO_SWITCH_MULTILEVEL_GETTER,
	ZUNO_SWITCH_MULTILEVEL_SETTER,
	ZUNO_METER_GETTER,
};

enum {
	ZUNO_JUMP_TABLE_SETUP, 			//0
	ZUNO_JUMP_TABLE_LOOP, 			//1
	ZUNO_JUMP_TABLE_CALLBACK,		//2
	ZUNO_GET_CHANNELS_ADDRESS, 		//3
	ZUNO_GET_ASSOCIATIONS_ADDRESS,  //4
	ZUNO_GET_SLEEPING_MODE, 		//5
};

enum {
	ZUNO_SWITCH_BINARY_CHANNEL_NUMBER = 1, 				//0x01
	ZUNO_SWITCH_MULTILEVEL_CHANNEL_NUMBER, 			//0x02
	ZUNO_SENSOR_BINARY_CHANNEL_NUMBER, 				//0x03
	ZUNO_SENSOR_MULTILEVEL_CHANNEL_NUMBER, 			//0x04
	ZUNO_END_OF_SUPPORTED_CC_NUM,
};

//Sensor Binary types
#define ZUNO_SENSOR_BINARY_TYPE_GENERAL_PURPOSE 		0x01
#define ZUNO_SENSOR_BINARY_TYPE_SMOKE 					0x02
#define ZUNO_SENSOR_BINARY_TYPE_CO 						0x03
#define ZUNO_SENSOR_BINARY_TYPE_CO2 					0x04
#define ZUNO_SENSOR_BINARY_TYPE_HEAT 					0x05
#define ZUNO_SENSOR_BINARY_TYPE_WATER 					0x06
#define ZUNO_SENSOR_BINARY_TYPE_FREEZE 					0x07
#define ZUNO_SENSOR_BINARY_TYPE_TAMPER 					0x08
#define ZUNO_SENSOR_BINARY_TYPE_AUX 					0x09
#define ZUNO_SENSOR_BINARY_TYPE_DOOR_WINDOW 			0x0a
#define ZUNO_SENSOR_BINARY_TYPE_TILT 					0x0b
#define ZUNO_SENSOR_BINARY_TYPE_MOTION 					0x0c
#define ZUNO_SENSOR_BINARY_TYPE_GLASSBREAK 				0x0d
#define ZUNO_SENSOR_BINARY_TYPE_DEFAULT 				0xff

// Sensor Multilevel types
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TEMPERATURE		                                   	0x01
#define ZUNO_SENSOR_MULTILEVEL_TYPE_GENERAL_PURPOSE_VALUE		                        0x02
#define ZUNO_SENSOR_MULTILEVEL_TYPE_LUMINANCE		                                    0x03
#define ZUNO_SENSOR_MULTILEVEL_TYPE_POWER		                                        0x04
#define ZUNO_SENSOR_MULTILEVEL_TYPE_RELATIVE_HUMIDITY		                            0x05
#define ZUNO_SENSOR_MULTILEVEL_TYPE_VELOCITY		                                    0x06
#define ZUNO_SENSOR_MULTILEVEL_TYPE_DIRECTION		                                    0x07
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ATMOSPHERIC_PRESSURE		                        0x08
#define ZUNO_SENSOR_MULTILEVEL_TYPE_BAROMETRIC_PRESSURE		                           	0x09
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SOLAR_RADIATION		                               	0x0A
#define ZUNO_SENSOR_MULTILEVEL_TYPE_DEW_POINT		                                    0x0B
#define ZUNO_SENSOR_MULTILEVEL_TYPE_RAIN_RATE		                                    0x0C
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TIDE_LEVEL		                                    0x0D
#define ZUNO_SENSOR_MULTILEVEL_TYPE_WEIGHT		                                        0x0E
#define ZUNO_SENSOR_MULTILEVEL_TYPE_VOLTAGE		                                       	0x0F
#define ZUNO_SENSOR_MULTILEVEL_TYPE_CURRENT		                                       	0x10
#define ZUNO_SENSOR_MULTILEVEL_TYPE_CO2_LEVEL		                                    0x11
#define ZUNO_SENSOR_MULTILEVEL_TYPE_AIR_FLOW		                                    0x12
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TANK_CAPACITY		                                0x13
#define ZUNO_SENSOR_MULTILEVEL_TYPE_DISTANCE		                                    0x14
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ANGLE_POSITION		                                0x15
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ROTATION                                            0x16
#define ZUNO_SENSOR_MULTILEVEL_TYPE_WATER_TEMPERATURE                                   0x17
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SOIL_TEMPERATURE                                    0x18
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SEISMIC_INTENSITY                                   0x19
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SEISMIC_MAGNITUDE                                   0x1A
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ULTRAVIOLET                                         0x1B
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ELECTRICAL_RESISTIVITY                              0x1C
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ELECTRICAL_CONDUCTIVITY                             0x1D
#define ZUNO_SENSOR_MULTILEVEL_TYPE_LOUDNESS                                            0x1E
#define ZUNO_SENSOR_MULTILEVEL_TYPE_MOISTURE                                            0x1F
#define ZUNO_SENSOR_MULTILEVEL_TYPE_FREQUENCY                                           0x20
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TIME                                                0x21


//Sensor Multilevel scales,sizes,precisions
#define SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS 									0x00
#define SENSOR_MULTILEVEL_PRECISION_ONE_DECIMAL 									0x01
#define SENSOR_MULTILEVEL_PRECISION_TWO_DECIMALS 									0x02

#define SENSOR_MULTILEVEL_SIZE_ONE_BYTE 											0x01
#define SENSOR_MULTILEVEL_SIZE_TWO_BYTES 											0x02
#define SENSOR_MULTILEVEL_SIZE_FOUR_BYTES 											0x04

// Air temperature
#define SENSOR_MULTILEVEL_SCALE_CELSIUS 											0x00 

//General purpose
#define SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE									0x00 

//Luminance
#define SENSOR_MULTILEVEL_SCALE_LUX													0x01

//Power
#define SENSOR_MULTILEVEL_SCALE_WATT												0x00
#define SENSOR_MULTILEVEL_SCALE_BTU_PER_HOUR										0x01

//Humidity
#define SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE									0x00 





//Sensor Multilevel Properties
#define SENSOR_MULTILEVEL_PROPERTIES_SIZE_MASK                                      0x07
#define SENSOR_MULTILEVEL_PROPERTIES_SCALE_SHIFT                                    0x03
#define SENSOR_MULTILEVEL_PROPERTIES_SCALE_MASK                                     0x18
#define SENSOR_MULTILEVEL_PROPERTIES_PRECISION_SHIFT                                0x05
#define SENSOR_MULTILEVEL_PROPERTIES_PRECISION_MASK                                 0xE0
#define SENSOR_MULTILEVEL_PROPERTIES_COMBINER(SCALE,SIZE,PRECISION) \
			(SIZE & SENSOR_MULTILEVEL_PROPERTIES_SIZE_MASK) | \
			((SCALE << SENSOR_MULTILEVEL_PROPERTIES_SCALE_SHIFT) & SENSOR_MULTILEVEL_PROPERTIES_SCALE_MASK) | \
			((PRECISION << SENSOR_MULTILEVEL_PROPERTIES_PRECISION_SHIFT) & SENSOR_MULTILEVEL_PROPERTIES_PRECISION_MASK)

#define MACRO_CAST_POINTER_TO_VOID(FUNCTION) 										((VOID_FUNC_POINTER_VOID) FUNCTION)

//
#define ZUNO_SWITCH_BINARY(GETTER, SETTER)   								{ZUNO_SWITCH_BINARY_CHANNEL_NUMBER, 0, 0, GETTER, SETTER}
#define ZUNO_SWITCH_MULTILEVEL(GETTER, SETTER) 								{ZUNO_SWITCH_MULTILEVEL_CHANNEL_NUMBER, 0, 0, GETTER, SETTER}
#define ZUNO_SENSOR_BINARY(TYPE, GETTER) 									{ZUNO_SENSOR_BINARY_CHANNEL_NUMBER, TYPE, 0, GETTER, MACRO_CAST_POINTER_TO_VOID(0)}
#define ZUNO_SENSOR_MULTILEVEL(TYPE, SCALE, SIZE, PRECISION, GETTER) 		{ZUNO_SENSOR_MULTILEVEL_CHANNEL_NUMBER, TYPE, SENSOR_MULTILEVEL_PROPERTIES_COMBINER(SCALE, SIZE, PRECISION), GETTER, MACRO_CAST_POINTER_TO_VOID(0)}

#define ZUNO_SENSOR_MULTILEVEL_TEMPERATURE(GETTER) 							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_TEMPERATURE, SENSOR_MULTILEVEL_SCALE_CELSIUS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)	
#define ZUNO_SENSOR_MULTILEVEL_GENERAL_PURPOSE(GETTER) 						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_GENERAL_PURPOSE_VALUE, SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_LUMINANCE(GETTER) 							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_LUMINANCE, SENSOR_MULTILEVEL_SCALE_LUX, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_POWER(GETTER) 								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_POWER, SENSOR_MULTILEVEL_SCALE_WATT, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_HUMIDITY(GETTER) 							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_RELATIVE_HUMIDITY, SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
/*
TODO: finish all types
#define ZUNO_SENSOR_MULTILEVEL_VELOCITY(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_DIRECTION(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ATHMOSPHERIC_PRESSURE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_BAROMETRIC_PRESSURE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SOLAR_RADIATION(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_DEW_POINT(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_RAIN_RATE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TIDE_LEVEL(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_WEIGHT(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_VOLTAGE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_CURRENT(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_CO2_LEVEL(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_AIR_FLOW(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TANK_CAPACITY(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_DISTANCE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ANGLE_POSITION(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ROTATION(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_WATER_TEMPERATURE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SOIL_TEMPERATURE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SEISMIC_INTENSITY(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SEISMIC_MAGNITUDE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ULTRAVIOLET(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ELECTRICAL_RESISTIVITY(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ELECTRICAL_CONDUCTIVITY(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_LOUDNESS(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_MOISTURE(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_FREQUENCY(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TIME(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TARGET_TEMPERATURE(GETTER)
/**/

#define ZUNO_SETUP_CHANNELS(...) 	\
								__code ZUNO_CHANNEL_PROPERTIES_DESCRIPTION zunoChannelSetupArray[]= \
								{ \
									{0x42, 0x42, 0x42, 0x4242, 0x4242}, \
									__VA_ARGS__, \
									{0x43, 0x43, 0x43, 0x4343, 0x4343} \
								};





enum {
	ZUNO_ASSOC_BASIC_SET_NUMBER = 1, 						//0x01
	ZUNO_ASSOC_BASIC_SET_AND_DIM_NUMBER,				//0x02
	ZUNO_ASSOC_SCENE_ACTIVATION_NUMBER, 				//0x03
	ZUNO_END_OF_SUPPORTED_ASSOC_NUM,
};

#define ZUNO_ASSOC_NO_PARAMS 							0x00

#define ZUNO_ASSOCIATION_GROUP_SET_VALUE 				{ZUNO_ASSOC_BASIC_SET_NUMBER, ZUNO_ASSOC_NO_PARAMS}
#define ZUNO_ASSOCIATION_GROUP_SET_VALUE_AND_DIM 		{ZUNO_ASSOC_BASIC_SET_AND_DIM_NUMBER, ZUNO_ASSOC_NO_PARAMS}
#define ZUNO_ASSOCIATION_GROUP_SCENE_CONTROL 			{ZUNO_ASSOC_SCENE_ACTIVATION_NUMBER, ZUNO_ASSOC_NO_PARAMS}
//TODO #define ZUNO_ASSOCIATION_GROUP_COLOR_CONTROL 		 		{}
//TODO #define ZUNO_ASSOCIATION_GROUP_THERMOSTAT_CONTROL 		 	{}
//TODO #define ZUNO_ASSOCIATION_GROUP_DOOR_LOCK_CONTROL 		 	{}

#define ZUNO_SETUP_ASSOCIATIONS(...)	\
								__code ZUNO_ASSOCIATION_PROPERTIES_DESCRIPTION zunoAssociationSetupArray[]= \
								{ \
									{0x42, 0x42}, \
									__VA_ARGS__, \
									{0x43, 0x43} \
								};


enum {
	ZUNO_MODE_ALWAYS_LISTENING_NUMBER,				//0
	ZUNO_MODE_WAKE_UP_NUMBER,						//1
	ZUNO_MODE_FLIRS_NUMBER,							//2
};

#define ZUNO_SLEEPING_MODE_ALWAYS_AWAKE 			{ZUNO_MODE_ALWAYS_LISTENING_NUMBER, 0, 0}
#define ZUNO_SLEEPING_MODE_SLEEPING			 		{ZUNO_MODE_WAKE_UP_NUMBER, 0, 0}
#define ZUNO_SLEEPING_MODE_FREQUENTLY_AWAKE 		{ZUNO_MODE_FLIRS_NUMBER, 0, 0}
#define ZUNO_SETUP_SLEEPING_MODE(VALUE) 		\
								__code ZUNO_SLEEPING_MODE_PROPERTIES_DESCRIPTION zunoSleepingModeSetupStruct = VALUE;


#define ZUNO_MAX_MULTI_CHANNEL_NUMBER 					10





//Debug///
BYTE zunoPopByte(void);
WORD zunoPopWord(void);
DWORD zunoPopDWORD(void);
void zunoPushByte(BYTE value);
void zunoPushWord(WORD value);
void zunoPushDword(DWORD value);
void zunoCall(void);
//********************************
void pinMode(BYTE pin, BYTE mode);
BYTE digitalRead(BYTE pin);
void digitalWrite(BYTE pin, BYTE value);
void delay(DWORD value);
WORD analogRead(BYTE pin);
void analogWrite(BYTE pin, BYTE value);
void SerialBegin(void);
void SerialEnd(void);
BYTE SerialAvailable(void);
BYTE SerialRead(void);
void SerialWrite(BYTE value);
//**********************************************
void setup(void);
void loop(void);
void InitArduinoEnvironment(void);


#define ZUNO_REPORT_NO_IMMEDIATE_VALUE 		0xffff
#define zunoSendZWaveReport(CHANNEL)  zunoSendUncolicitedReport(CHANNEL,ZUNO_REPORT_NO_IMMEDIATE_VALUE)
void zunoSendUncolicitedReport(BYTE channel,WORD value);

#define ZUNO_DIMMING_UP				0
#define ZUNO_DIMMING_DOWN 			1
#define ZUNO_DIMMING_START			1
#define ZUNO_DIMMING_STOP 			0

#define zunoSendToGroupSetValueCommand(GROUP,VALUE) 					zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_BASIC_SET_NUMBER,VALUE,0)
#define zunoSendToGroupDimmingCommand(GROUP,DIRECTION,START_STOP) 		zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_BASIC_SET_AND_DIM_NUMBER,DIRECTION,START_STOP)
#define zunoSendToGroupScene(GROUP,SCENE_NUMBER) 						zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_SCENE_ACTIVATION_NUMBER,SCENE_NUMBER,0)

void zunoSendAssociationCommand(BYTE group, BYTE assoc_type, BYTE param1, BYTE param2);

void zunoSendTheDeviceToSleep(void);


/************************************************
			Variables
************************************************/
extern __code ZUNO_CHANNEL_PROPERTIES_DESCRIPTION zunoChannelSetupArray[];
extern __code ZUNO_ASSOCIATION_PROPERTIES_DESCRIPTION zunoAssociationSetupArray[];
extern __code ZUNO_SLEEPING_MODE_PROPERTIES_DESCRIPTION zunoSleepingModeSetupStruct;



/************************************************
			end of Variables
************************************************/
__sfr __at (0x81) SP;


