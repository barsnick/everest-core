/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6 */

#ifndef PB_YETI_PB_H_INCLUDED
#define PB_YETI_PB_H_INCLUDED
#include <everest/3rd_party/nanopb/pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _CpState { 
    CpState_STATE_A = 0, 
    CpState_STATE_B = 1, 
    CpState_STATE_C = 2, 
    CpState_STATE_D = 3, 
    CpState_STATE_E = 4, 
    CpState_STATE_F = 5 
} CpState;

typedef enum _ResetReason { 
    ResetReason_USER = 0, 
    ResetReason_WATCHDOG = 1 
} ResetReason;

typedef enum _PpState { 
    PpState_STATE_NC = 0, 
    PpState_STATE_13A = 1, 
    PpState_STATE_20A = 2, 
    PpState_STATE_32A = 3, 
    PpState_STATE_70A = 4, 
    PpState_STATE_FAULT = 5 
} PpState;

typedef enum _LockState { 
    LockState_UNDEFINED = 0, 
    LockState_UNLOCKED = 1, 
    LockState_LOCKED = 2 
} LockState;

/* Struct definitions */
typedef struct _ErrorFlags { 
    bool diode_fault;
    bool rcd_selftest_failed;
    bool rcd_triggered;
    bool ventilation_not_available;
    bool connector_lock_failed;
    bool cp_signal_fault;
} ErrorFlags;

typedef struct _FirmwareUpdate { 
    bool invoke_rom_bootloader;
} FirmwareUpdate;

typedef struct _KeepAlive { 
    uint32_t time_stamp;
    uint32_t hw_type;
    uint32_t hw_revision;
    char sw_version_string[51];
} KeepAlive;

typedef struct _KeepAliveLo { 
    uint32_t time_stamp;
    uint32_t hw_type;
    uint32_t hw_revision;
    uint32_t protocol_version_major;
    uint32_t protocol_version_minor;
    char sw_version_string[51];
    float hwcap_max_current;
    float hwcap_min_current;
    uint32_t hwcap_max_phase_count;
    uint32_t hwcap_min_phase_count;
    bool supports_changing_phases_during_charging;
} KeepAliveLo;

typedef struct _PowerMeter { 
    uint32_t time_stamp;
    float vrmsL1;
    float vrmsL2;
    float vrmsL3;
    float irmsL1;
    float irmsL2;
    float irmsL3;
    float irmsN;
    float wattHrL1;
    float wattHrL2;
    float wattHrL3;
    float totalWattHr;
    float tempL1;
    float tempL2;
    float tempL3;
    float tempN;
    float wattL1;
    float wattL2;
    float wattL3;
    float freqL1;
    float freqL2;
    float freqL3;
    bool phaseSeqError;
} PowerMeter;

typedef struct _Telemetry { 
    uint32_t cp_voltage_hi;
    uint32_t cp_voltage_lo;
} Telemetry;

/* This container message is send from EVerest to MCU and may contain any allowed message in that direction. */
typedef struct _EverestToMcu { 
    pb_size_t which_payload;
    union {
        /* Needs to remain the same to allow firmware updates of older versions */
        FirmwareUpdate firmware_update;
        /* Other IDs are 100+ to avoid compatibility issues with older firmware versions */
        KeepAlive keep_alive;
        bool connector_lock; /* false: unlock, true: lock */
        uint32_t pwm_duty_cycle; /* in 0.01 %, 0 = State F, 10000 = X1 */
        bool allow_power_on;
        bool reset;
    } payload;
} EverestToMcu;

/* This container message is send from MCU to EVerest and may contain any allowed message in that direction. */
typedef struct _McuToEverest { 
    pb_size_t which_payload;
    union {
        /* Needs to remain the same to allow firmware updates of older versions */
        KeepAliveLo keep_alive;
        /* Other IDs are 100+ to avoid compatibility issues with older firmware versions */
        ResetReason reset;
        CpState cp_state;
        bool relais_state; /* false: relais are off, true: relais are on */
        ErrorFlags error_flags;
        Telemetry telemetry;
        PpState pp_state;
        LockState lock_state;
        PowerMeter power_meter;
    } payload;
} McuToEverest;


/* Helper constants for enums */
#define _CpState_MIN CpState_STATE_A
#define _CpState_MAX CpState_STATE_F
#define _CpState_ARRAYSIZE ((CpState)(CpState_STATE_F+1))

#define _ResetReason_MIN ResetReason_USER
#define _ResetReason_MAX ResetReason_WATCHDOG
#define _ResetReason_ARRAYSIZE ((ResetReason)(ResetReason_WATCHDOG+1))

#define _PpState_MIN PpState_STATE_NC
#define _PpState_MAX PpState_STATE_FAULT
#define _PpState_ARRAYSIZE ((PpState)(PpState_STATE_FAULT+1))

#define _LockState_MIN LockState_UNDEFINED
#define _LockState_MAX LockState_LOCKED
#define _LockState_ARRAYSIZE ((LockState)(LockState_LOCKED+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define EverestToMcu_init_default                {0, {FirmwareUpdate_init_default}}
#define McuToEverest_init_default                {0, {KeepAliveLo_init_default}}
#define ErrorFlags_init_default                  {0, 0, 0, 0, 0, 0}
#define KeepAliveLo_init_default                 {0, 0, 0, 0, 0, "", 0, 0, 0, 0, 0}
#define KeepAlive_init_default                   {0, 0, 0, ""}
#define Telemetry_init_default                   {0, 0}
#define PowerMeter_init_default                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define FirmwareUpdate_init_default              {0}
#define EverestToMcu_init_zero                   {0, {FirmwareUpdate_init_zero}}
#define McuToEverest_init_zero                   {0, {KeepAliveLo_init_zero}}
#define ErrorFlags_init_zero                     {0, 0, 0, 0, 0, 0}
#define KeepAliveLo_init_zero                    {0, 0, 0, 0, 0, "", 0, 0, 0, 0, 0}
#define KeepAlive_init_zero                      {0, 0, 0, ""}
#define Telemetry_init_zero                      {0, 0}
#define PowerMeter_init_zero                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define FirmwareUpdate_init_zero                 {0}

/* Field tags (for use in manual encoding/decoding) */
#define ErrorFlags_diode_fault_tag               1
#define ErrorFlags_rcd_selftest_failed_tag       2
#define ErrorFlags_rcd_triggered_tag             3
#define ErrorFlags_ventilation_not_available_tag 4
#define ErrorFlags_connector_lock_failed_tag     5
#define ErrorFlags_cp_signal_fault_tag           6
#define FirmwareUpdate_invoke_rom_bootloader_tag 1
#define KeepAlive_time_stamp_tag                 1
#define KeepAlive_hw_type_tag                    2
#define KeepAlive_hw_revision_tag                3
#define KeepAlive_sw_version_string_tag          6
#define KeepAliveLo_time_stamp_tag               1
#define KeepAliveLo_hw_type_tag                  2
#define KeepAliveLo_hw_revision_tag              3
#define KeepAliveLo_protocol_version_major_tag   4
#define KeepAliveLo_protocol_version_minor_tag   5
#define KeepAliveLo_sw_version_string_tag        6
#define KeepAliveLo_hwcap_max_current_tag        7
#define KeepAliveLo_hwcap_min_current_tag        8
#define KeepAliveLo_hwcap_max_phase_count_tag    9
#define KeepAliveLo_hwcap_min_phase_count_tag    10
#define KeepAliveLo_supports_changing_phases_during_charging_tag 11
#define PowerMeter_time_stamp_tag                1
#define PowerMeter_vrmsL1_tag                    2
#define PowerMeter_vrmsL2_tag                    3
#define PowerMeter_vrmsL3_tag                    4
#define PowerMeter_irmsL1_tag                    5
#define PowerMeter_irmsL2_tag                    6
#define PowerMeter_irmsL3_tag                    7
#define PowerMeter_irmsN_tag                     8
#define PowerMeter_wattHrL1_tag                  9
#define PowerMeter_wattHrL2_tag                  10
#define PowerMeter_wattHrL3_tag                  11
#define PowerMeter_totalWattHr_tag               12
#define PowerMeter_tempL1_tag                    13
#define PowerMeter_tempL2_tag                    14
#define PowerMeter_tempL3_tag                    15
#define PowerMeter_tempN_tag                     16
#define PowerMeter_wattL1_tag                    17
#define PowerMeter_wattL2_tag                    18
#define PowerMeter_wattL3_tag                    19
#define PowerMeter_freqL1_tag                    20
#define PowerMeter_freqL2_tag                    21
#define PowerMeter_freqL3_tag                    22
#define PowerMeter_phaseSeqError_tag             23
#define Telemetry_cp_voltage_hi_tag              1
#define Telemetry_cp_voltage_lo_tag              2
#define EverestToMcu_firmware_update_tag         16
#define EverestToMcu_keep_alive_tag              100
#define EverestToMcu_connector_lock_tag          102
#define EverestToMcu_pwm_duty_cycle_tag          103
#define EverestToMcu_allow_power_on_tag          104
#define EverestToMcu_reset_tag                   105
#define McuToEverest_keep_alive_tag              3
#define McuToEverest_reset_tag                   101
#define McuToEverest_cp_state_tag                102
#define McuToEverest_relais_state_tag            103
#define McuToEverest_error_flags_tag             104
#define McuToEverest_telemetry_tag               105
#define McuToEverest_pp_state_tag                106
#define McuToEverest_lock_state_tag              107
#define McuToEverest_power_meter_tag             108

/* Struct field encoding specification for nanopb */
#define EverestToMcu_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,firmware_update,payload.firmware_update),  16) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,keep_alive,payload.keep_alive), 100) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,connector_lock,payload.connector_lock), 102) \
X(a, STATIC,   ONEOF,    UINT32,   (payload,pwm_duty_cycle,payload.pwm_duty_cycle), 103) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,allow_power_on,payload.allow_power_on), 104) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,reset,payload.reset), 105)
#define EverestToMcu_CALLBACK NULL
#define EverestToMcu_DEFAULT NULL
#define EverestToMcu_payload_firmware_update_MSGTYPE FirmwareUpdate
#define EverestToMcu_payload_keep_alive_MSGTYPE KeepAlive

#define McuToEverest_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,keep_alive,payload.keep_alive),   3) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,reset,payload.reset), 101) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,cp_state,payload.cp_state), 102) \
X(a, STATIC,   ONEOF,    BOOL,     (payload,relais_state,payload.relais_state), 103) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,error_flags,payload.error_flags), 104) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,telemetry,payload.telemetry), 105) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,pp_state,payload.pp_state), 106) \
X(a, STATIC,   ONEOF,    UENUM,    (payload,lock_state,payload.lock_state), 107) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,power_meter,payload.power_meter), 108)
#define McuToEverest_CALLBACK NULL
#define McuToEverest_DEFAULT NULL
#define McuToEverest_payload_keep_alive_MSGTYPE KeepAliveLo
#define McuToEverest_payload_error_flags_MSGTYPE ErrorFlags
#define McuToEverest_payload_telemetry_MSGTYPE Telemetry
#define McuToEverest_payload_power_meter_MSGTYPE PowerMeter

#define ErrorFlags_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     diode_fault,       1) \
X(a, STATIC,   SINGULAR, BOOL,     rcd_selftest_failed,   2) \
X(a, STATIC,   SINGULAR, BOOL,     rcd_triggered,     3) \
X(a, STATIC,   SINGULAR, BOOL,     ventilation_not_available,   4) \
X(a, STATIC,   SINGULAR, BOOL,     connector_lock_failed,   5) \
X(a, STATIC,   SINGULAR, BOOL,     cp_signal_fault,   6)
#define ErrorFlags_CALLBACK NULL
#define ErrorFlags_DEFAULT NULL

#define KeepAliveLo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, UINT32,   hw_type,           2) \
X(a, STATIC,   SINGULAR, UINT32,   hw_revision,       3) \
X(a, STATIC,   SINGULAR, UINT32,   protocol_version_major,   4) \
X(a, STATIC,   SINGULAR, UINT32,   protocol_version_minor,   5) \
X(a, STATIC,   SINGULAR, STRING,   sw_version_string,   6) \
X(a, STATIC,   SINGULAR, FLOAT,    hwcap_max_current,   7) \
X(a, STATIC,   SINGULAR, FLOAT,    hwcap_min_current,   8) \
X(a, STATIC,   SINGULAR, UINT32,   hwcap_max_phase_count,   9) \
X(a, STATIC,   SINGULAR, UINT32,   hwcap_min_phase_count,  10) \
X(a, STATIC,   SINGULAR, BOOL,     supports_changing_phases_during_charging,  11)
#define KeepAliveLo_CALLBACK NULL
#define KeepAliveLo_DEFAULT NULL

#define KeepAlive_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, UINT32,   hw_type,           2) \
X(a, STATIC,   SINGULAR, UINT32,   hw_revision,       3) \
X(a, STATIC,   SINGULAR, STRING,   sw_version_string,   6)
#define KeepAlive_CALLBACK NULL
#define KeepAlive_DEFAULT NULL

#define Telemetry_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   cp_voltage_hi,     1) \
X(a, STATIC,   SINGULAR, UINT32,   cp_voltage_lo,     2)
#define Telemetry_CALLBACK NULL
#define Telemetry_DEFAULT NULL

#define PowerMeter_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, FLOAT,    vrmsL1,            2) \
X(a, STATIC,   SINGULAR, FLOAT,    vrmsL2,            3) \
X(a, STATIC,   SINGULAR, FLOAT,    vrmsL3,            4) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsL1,            5) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsL2,            6) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsL3,            7) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsN,             8) \
X(a, STATIC,   SINGULAR, FLOAT,    wattHrL1,          9) \
X(a, STATIC,   SINGULAR, FLOAT,    wattHrL2,         10) \
X(a, STATIC,   SINGULAR, FLOAT,    wattHrL3,         11) \
X(a, STATIC,   SINGULAR, FLOAT,    totalWattHr,      12) \
X(a, STATIC,   SINGULAR, FLOAT,    tempL1,           13) \
X(a, STATIC,   SINGULAR, FLOAT,    tempL2,           14) \
X(a, STATIC,   SINGULAR, FLOAT,    tempL3,           15) \
X(a, STATIC,   SINGULAR, FLOAT,    tempN,            16) \
X(a, STATIC,   SINGULAR, FLOAT,    wattL1,           17) \
X(a, STATIC,   SINGULAR, FLOAT,    wattL2,           18) \
X(a, STATIC,   SINGULAR, FLOAT,    wattL3,           19) \
X(a, STATIC,   SINGULAR, FLOAT,    freqL1,           20) \
X(a, STATIC,   SINGULAR, FLOAT,    freqL2,           21) \
X(a, STATIC,   SINGULAR, FLOAT,    freqL3,           22) \
X(a, STATIC,   SINGULAR, BOOL,     phaseSeqError,    23)
#define PowerMeter_CALLBACK NULL
#define PowerMeter_DEFAULT NULL

#define FirmwareUpdate_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     invoke_rom_bootloader,   1)
#define FirmwareUpdate_CALLBACK NULL
#define FirmwareUpdate_DEFAULT NULL

extern const pb_msgdesc_t EverestToMcu_msg;
extern const pb_msgdesc_t McuToEverest_msg;
extern const pb_msgdesc_t ErrorFlags_msg;
extern const pb_msgdesc_t KeepAliveLo_msg;
extern const pb_msgdesc_t KeepAlive_msg;
extern const pb_msgdesc_t Telemetry_msg;
extern const pb_msgdesc_t PowerMeter_msg;
extern const pb_msgdesc_t FirmwareUpdate_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define EverestToMcu_fields &EverestToMcu_msg
#define McuToEverest_fields &McuToEverest_msg
#define ErrorFlags_fields &ErrorFlags_msg
#define KeepAliveLo_fields &KeepAliveLo_msg
#define KeepAlive_fields &KeepAlive_msg
#define Telemetry_fields &Telemetry_msg
#define PowerMeter_fields &PowerMeter_msg
#define FirmwareUpdate_fields &FirmwareUpdate_msg

/* Maximum encoded size of messages (where known) */
#define ErrorFlags_size                          12
#define EverestToMcu_size                        73
#define FirmwareUpdate_size                      2
#define KeepAliveLo_size                         106
#define KeepAlive_size                           70
#define McuToEverest_size                        124
#define PowerMeter_size                          121
#define Telemetry_size                           12

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif