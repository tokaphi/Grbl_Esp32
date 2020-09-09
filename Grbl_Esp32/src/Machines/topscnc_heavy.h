#define MACHINE_NAME "topscnc_heavy"

#define USE_GANGED_AXES // allow two motors on an axis

#define X_STEP_PIN      GPIO_NUM_12
#define X2_STEP_PIN     GPIO_NUM_22      // ganged motor
//#define X_AXIS_SQUARING

#define Y_STEP_PIN      GPIO_NUM_14
#define Y2_STEP_PIN     GPIO_NUM_21     // ganged motor
#define Y_AXIS_SQUARING

#define Z_STEP_PIN      GPIO_NUM_27

#define X_DIRECTION_PIN GPIO_NUM_26
#define X2_DIRECTION_PIN X_DIRECTION_PIN
#define Y_DIRECTION_PIN GPIO_NUM_25
#define Y2_DIRECTION_PIN Y_DIRECTION_PIN
#define Z_DIRECTION_PIN GPIO_NUM_33


#define  HOMING_CYCLE_0 ( 1 << Z_AXIS) // OBLIGATOIRE: Déplacez d'abord Z pour dégager l'espace de travail.
//# define  HOMING_CYCLE_1 (( 1 << X_AXIS) | ( 1 << Y_AXIS))   // X et Y ensemble
#define  HOMING_CYCLE_1 ( 1 << X_AXIS)
#define  HOMING_CYCLE_2 ( 1 << Y_AXIS)
// OK to comment out to use pin for other features
//#define STEPPERS_DISABLE_PIN GPIO_NUM_13

// Note: if you use PWM rather than relay, you could map GPIO_NUM_2 to mist or flood
#define USE_SPINDLE_RELAY

#ifdef USE_SPINDLE_RELAY
    #define SPINDLE_TYPE SPINDLE_TYPE_RELAY
    #define SPINDLE_OUTPUT_PIN GPIO_NUM_2
#else
    #define SPINDLE_TYPE SPINDLE_TYPE_PWM
    #define SPINDLE_OUTPUT_PIN GPIO_NUM_16

    #define SPINDLE_ENABLE_PIN GPIO_NUM_32
#endif

// Note: Only uncomment this if USE_SPINDLE_RELAY is commented out.
// Relay can be used for spindle or either coolant
//#define COOLANT_FLOOD_PIN     GPIO_NUM_2
//#define COOLANT_MIST_PIN      GPIO_NUM_2


#define X_LIMIT_PIN             GPIO_NUM_17
#define Y_LIMIT_PIN             GPIO_NUM_4
#define Z_LIMIT_PIN             GPIO_NUM_15
#define LIMIT_MASK              B111


#ifndef ENABLE_SOFTWARE_DEBOUNCE   // V1P2 does not have R/C filters
    #define ENABLE_SOFTWARE_DEBOUNCE
#endif


#define PROBE_PIN               GPIO_NUM_35

// The default value in config.h is wrong for this controller
#ifdef INVERT_CONTROL_PIN_MASK
    #undef INVERT_CONTROL_PIN_MASK
#endif

#define INVERT_CONTROL_PIN_MASK B1110


#define CONTROL_RESET_PIN           GPIO_NUM_34  // needs external pullup
#define CONTROL_FEED_HOLD_PIN       GPIO_NUM_36  // needs external pullup
#define CONTROL_CYCLE_START_PIN     GPIO_NUM_39  // needs external pullup


#define DEFAULT_STEP_PULSE_MICROSECONDS     3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME      255 //  255 = Keep steppers on
#define DEFAULT_STEPPING_INVERT_MASK    0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK   0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE        0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS       1 // boolean
#define DEFAULT_INVERT_PROBE_PIN        0 // boolean

#define DEFAULT_STATUS_REPORT_MASK      1

#define DEFAULT_JUNCTION_DEVIATION  0.01 // mm
#define DEFAULT_ARC_TOLERANCE       0.002 // mm
#define DEFAULT_REPORT_INCHES       0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 0  // false

#define DEFAULT_HOMING_ENABLE           1  // false
//#define DEFAULT_HOMING_DIR_MASK         3 // move positive dir Z,negative X,Y
#define DEFAULT_HOMING_FEED_RATE        100.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        200.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          2.0 // mm

#ifdef USE_SPINDLE_RELAY
    #define DEFAULT_SPINDLE_RPM_MAX 1.0 // must be 1 so PWM duty is alway 100% to prevent relay damage
#else
    #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // can be change to your spindle max
#endif

#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm

#define DEFAULT_LASER_MODE 0 // laser-mode enable,bolean

#define DEFAULT_X_STEPS_PER_MM 800.0 //X-axis travel resolution, step/mm
#define DEFAULT_Y_STEPS_PER_MM 800.0 //Y-axis travel resolution, step/mm
#define DEFAULT_Z_STEPS_PER_MM 800.0 //Z-axis travel resolution, step/mm

#define DEFAULT_X_MAX_RATE 3000.00 // mm/min
#define DEFAULT_Y_MAX_RATE 3000.00 // mm/min
#define DEFAULT_Z_MAX_RATE 2000.00 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // X-axis accleration, mm/sec^2
#define DEFAULT_Y_ACCELERATION 200.0 // Y-axis accleration, mm/sec^2
#define DEFAULT_Z_ACCELERATION 200.0 // Z-axis accleration, mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 1110.0 // X-axis maximum travel. millimeters
#define DEFAULT_Y_MAX_TRAVEL 858.0 // Y-axis maximum travel. millimeters
#define DEFAULT_Z_MAX_TRAVEL 96.0 // Z-axis maximum travel. millimeters
