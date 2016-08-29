//*****************************************************************************
//
// bq27510g3.c - Prototypes for the TI BQ27441G1 Battery Fuel Guage 
//               driver.
//
// Copyright (c) 2013-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the Tiva Firmware Development Package.
//
// File copied and rename bq27441g1 - 
// Driver for TI BQ27441G1 Battery Fuel Gauge
//
//*****************************************************************************

#ifndef __SENSORLIB_BQ27441G1_H__
#define __SENSORLIB_BQ27441G1_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// The structure that defines the internal state of the BQ27441G1 driver.
//
//*****************************************************************************
typedef struct
{
    //
    // The pointer to the I2C master interface instance used to communicate
    // with the BQ27441G1.
    //
    tI2CMInstance *psI2CInst;

    //
    // The I2C address of the BQ27441G1.
    //
    uint8_t ui8Addr;

    //
    // The state of the state machine used while accessing the BQ27441G1.
    //
    uint8_t ui8State;

    //
    // The data buffer used for sending/receiving data to/from the BQ27441G1.
    //
    uint8_t pui8Data[32];

    //
    // The function that is called when the current request has completed
    // processing.
    //
    tSensorCallback *pfnCallback;

    //
    // The pointer provided to the callback function.
    //
    void *pvCallbackData;

    //
    // A union of structures that are used for read, write and
    // read-modify-write operations.  Since only one operation can be active at
    // a time, it is safe to re-use the memory in this manner.
    //
    union
    {
        //
        // A buffer used to store the write portion of a register read.
        //
        uint8_t pui8Buffer[4];

        //
        // The read state used to read register values.
        //
        tI2CMRead16BE sReadState;

        //
        // The write state used to write register values.
        //
        tI2CMWrite16BE sWriteState;

        //
        // The read-modify-write state used to modify register values.
        //
        tI2CMReadModifyWrite16 sReadModifyWriteState;
    }
    uCommand;
}
tBQ27441G1;

//*****************************************************************************
//
// Function prototypes.
//
//*****************************************************************************
extern uint_fast8_t BQ27441G1Init(tBQ27441G1 *psInst, tI2CMInstance *psI2CInst,
                                  uint_fast8_t ui8I2CAddr,
                                  tSensorCallback *pfnCallback,
                                  void *pvCallbackData);
extern uint_fast8_t BQ27441G1Read(tBQ27441G1 *psInst, uint_fast8_t ui8Reg,
                                  uint16_t *pui16Data, uint_fast16_t ui16Count,
                                  tSensorCallback *pfnCallback,
                               void *pvCallbackData);
extern uint_fast8_t BQ27441G1Write(tBQ27441G1 *psInst, uint_fast8_t ui8Reg,
                                   const uint16_t *pui16Data,
                                   uint_fast16_t ui16Count,
                                   tSensorCallback *pfnCallback,
                                   void *pvCallbackData);
extern uint_fast8_t BQ27441G1ReadModifyWrite(tBQ27441G1 *psInst,
                                             uint_fast8_t ui8Reg,
                                             uint_fast16_t ui16Mask,
                                             uint_fast16_t ui16Value,
                                             tSensorCallback *pfnCallback,
                                             void *pvCallbackData);
extern uint_fast8_t BQ27441G1DataRead(tBQ27441G1 *psInst,
                                      tSensorCallback *pfnCallback,
                                      void *pvCallbackData);

extern void BQ27441G1DataTemperatureBatteryGetRaw(tBQ27441G1 *psInst,
                                                  int16_t *pui16Data);
extern void BQ27441G1DataTemperatureBatteryGetFloat(tBQ27441G1 *psInst,
                                                    float *pfData);
extern void BQ27441G1DataVoltageBatteryGetRaw(tBQ27441G1 *psInst,
                                              int16_t *pui16Data);
extern void BQ27441G1DataVoltageBatteryGetFloat(tBQ27441G1 *psInst,
                                                float *pfData);
extern void BQ27441G1DataCapacityNominalAvailableGetRaw(tBQ27441G1 *psInst,
                                                        int16_t *pui16Data);
extern void BQ27441G1DataCapacityNominalAvailalbeGetFloat(tBQ27441G1 *psInst,
                                                          float *pfData);
extern void BQ27441G1DataCapacityFullAvailableGetRaw(tBQ27441G1 *psInst,
                                                     int16_t *pui16Data);
extern void BQ27441G1DataCapacityFullAvailableGetFloat(tBQ27441G1 *psInst,
                                                       float *pfData);
extern void BQ27441G1DataCapacityRemainingGetRaw(tBQ27441G1 *psInst,
                                                 int16_t *pui16Data);
extern void BQ27441G1DataCapacityRemainingGetFloat(tBQ27441G1 *psInst,
                                                   float *pfData);
extern void BQ27441G1DataCapacityFullChargeGetRaw(tBQ27441G1 *psInst,
                                                  int16_t *pui16Data);
extern void BQ27441G1DataCapacityFullChargeGetFloat(tBQ27441G1 *psInst,
                                                    float *pfData);
extern void BQ27441G1DataCurrentAverageGetRaw(tBQ27441G1 *psInst,
                                              int16_t *pui16Data);
extern void BQ27441G1DataCurrentAverageGetFloat(tBQ27441G1 *psInst,
                                                float *pfData);
extern void BQ27441G1DataCurrentStandbyGetRaw(tBQ27441G1 *psInst,
                                              int16_t *pui16Data);
extern void BQ27441G1DataCurrentStandbyGetFloat(tBQ27441G1 *psInst,
                                                float *pfData);
extern void BQ27441G1DataCurrentMaxLoadGetRaw(tBQ27441G1 *psInst,
                                              int16_t *pui16Data);
extern void BQ27441G1DataCurrentMaxLoadGetFloat(tBQ27441G1 *psInst,
                                                float *pfData);
extern void BQ27441G1DataPowerAverageGetRaw(tBQ27441G1 *psInst,
                                              int16_t *pui16Data);
extern void BQ27441G1DataPowerAverageGetFloat(tBQ27441G1 *psInst,
                                                float *pfData);
extern void BQ27441G1DataHealthGetRaw(tBQ27441G1 *psInst, int16_t *pui16Data);
extern void BQ27441G1DataHealthGetFloat(tBQ27441G1 *psInst, float *pfData);
extern void BQ27441G1DataChargeStateGetRaw(tBQ27441G1 *psInst,
                                           int16_t *pui16Data);
extern void BQ27441G1DataChargeStateGetFloat(tBQ27441G1 *psInst,
                                             float *pfData);
extern void BQ27441G1DataTemperatureInternalGetRaw(tBQ27441G1 *psInst,
                                                   int16_t *pui16Data);
extern void BQ27441G1DataTemperatureInternalGetFloat(tBQ27441G1 *psInst,
                                                     float *pfData);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __SENSORLIB_BQ27441G1_H__

