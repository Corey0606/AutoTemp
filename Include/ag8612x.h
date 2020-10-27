/*********************************************************************/
/* $Workfile: ag8612x.h $ */
/* Copyright (C) 2001 Agilent Technologies */
/* VISA Vxi Plug&Play Driver from Agilent Jumpstart Kit B.00.02 */
/*********************************************************************/
/* Microsoft Visual SourceSafe Header */
/* $Logfile: /Connectivity/Source/ag8612x_Visa/ag8612x.h $ */
/* $Date: 10/22/01 4:03p $ */
/* $Revision: 8 $ */
/* $Author: Mikefitz $ */
/*********************************************************************/
/* VISA Vxi Plug&Play Driver created from Agilent Jumpstart Kit B.00.02 */
/*********************************************************************/

/*#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@# --------------------------------------------#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@# DEVELOPER: Modify this file for your driver #@#@#@#@#@#@#@#@#@#@#@#@#
#@#@# --------------------------------------------#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#*/

/* ================================================================= */
/* ---- #include files --------------------------------------------- */
/* ================================================================= */

#include <cvidef.h>
/* This file is in $(NI_CVIPATH)\Include */

#include <vpptype.h>
/* This file is in $(VXIPNPPATH)\WinXX\include */

#define ag8612x_PEXCURSION_MIN    1
#define ag8612x_PEXCURSION_MAX    30
#define ag8612x_PEXCURSION_DEF    15

#define ag8612x_PTHRESHOLD_MIN    0
#define ag8612x_PTHRESHOLD_MAX    40
#define ag8612x_PTHRESHOLD_DEF    10

#define ag8612x_WLIM_WAV_MIN    1270.0
#define ag8612x_WLIM_WAV_MAX   	1650.0


#define ag8612x_SENS_ELEV_MIN    0
#define ag8612x_SENS_ELEV_MAX    5000

#define ag8612x_SENS_OFFS_MIN    -40.0
#define ag8612x_SENS_OFFS_MAX    40.0


#define ag8612x_DELTA_METERS_MIN  0 
#define ag8612x_DELTA_METERS_MAX  10
#define ag8612x_DELTA_METERS_DEF  0.1


#define ag8612x_REFWAVELENGTH_MIN  700.0
#define ag8612x_REFWAVELENGTH_MAX  1650.0

#define ag8612x_REFPOWER_MIN  -40.0
#define ag8612x_REFPOWER_MAX  10.0

#define ag8612x_DELTAGRID_200  0
#define ag8612x_DELTAGRID_100  1
#define ag8612x_DELTAGRID_50   2

#define ag8612x_ANA_SIGNALTONOISE_START_MIN  		10
#define ag8612x_ANA_SIGNALTONOISE_START_MAX 	 	900
#define ag8612x_ANA_SIGNALTONOISE_START_DEF     	100

#define ag8612x_ANA_SIGNALTONOISE_DONE_TRUE 		1
#define ag8612x_ANA_SIGNALTONOISE_DONE_FALSE 		0

#define ag8612x_MAXTABLE					 		300 
#define ag8612x_TRACKING_DELTA					 	0.1e-9
													
#define ag8612x_UPDATE_MIN							1
#define ag8612x_UPDATE_MAX							0

/*****************************************************************************/
/*****************************************************************************/
/* PASSTHROUGH and COMMON COMMANDS */
/* These commands are provided in agPass.DLL. */
/*****************************************************************************/
/*****************************************************************************/

ViStatus _VI_FUNC ag8612x_reset (ViSession vi);


ViStatus _VI_FUNC ag8612x_self_test (
	ViSession vi,
	ViPInt16 selfTestResult,
	ViChar _VI_FAR  selfTestMessage[]);

ViStatus _VI_FUNC ag8612x_error_query (
	ViSession vi,
	ViPStatus plErrCode,
	ViChar _VI_FAR  acErrMsg[]);

ViStatus _VI_FUNC ag8612x_error_message (
	ViSession vi,
	ViStatus errStatus,
	ViChar _VI_FAR  acErrMsg[]);

ViStatus _VI_FUNC ag8612x_revision_query (
	ViSession vi,
	ViChar _VI_FAR  instrumentDriverRevision[],
	ViChar _VI_FAR  firmwareRevision[]);

ViStatus _VI_FUNC ag8612x_timeOut (
	ViSession vi,
	ViInt32 setTimeOut);

ViStatus _VI_FUNC ag8612x_timeOut_Q (
	ViSession vi,
	ViPInt32 timeOut);

ViStatus _VI_FUNC ag8612x_errorQueryDetect (
	ViSession vi,
	ViBoolean setErrorQueryDetect);

ViStatus _VI_FUNC ag8612x_errorQueryDetect_Q (
	ViSession vi,
	ViPBoolean errorQueryDetect);

ViStatus _VI_FUNC ag8612x_dcl (ViSession vi);

ViStatus _VI_FUNC ag8612x_opc_Q(
	ViSession vi,
	ViPBoolean pbOpComplete);

ViStatus _VI_FUNC ag8612x_readStatusByte_Q (
	ViSession vi,
	ViPUInt16 pStatusByte);

ViStatus _VI_FUNC ag8612x_operEvent_Q (
	ViSession vi,
	ViPInt32 pOpEventReg);

ViStatus _VI_FUNC ag8612x_operCond_Q (
	ViSession vi,
	ViPInt32 pOpConditionReg);

ViStatus _VI_FUNC ag8612x_quesEvent_Q (
	ViSession vi,
	ViPInt32 plQuestionableEventRegister );

ViStatus _VI_FUNC ag8612x_quesCond_Q(
	ViSession vi,
	ViPInt32 plQuestionableConditionRegister);

ViStatus _VI_FUNC ag8612x_cmd(
	ViSession vi,
	ViString strlSendCmd);

ViStatus _VI_FUNC ag8612x_cmdString_Q (
	ViSession vi,
	ViString strQueryCmd,
	ViInt32 lStringSize,
	ViChar _VI_FAR  pstrResult[]);

ViStatus _VI_FUNC ag8612x_cmdInt(
	ViSession vi,
	ViString strlSendIntCmd,
	ViInt32 lSendInt);

ViStatus _VI_FUNC ag8612x_cmdInt16_Q(
	ViSession vi,
	ViString strQueryInt16Cmd,
	ViPInt16 aiResult);

ViStatus _VI_FUNC ag8612x_cmdInt32_Q(
	ViSession vi,
	ViString strQueryInt32Cmd,
	ViPInt32 plInt32Result);

ViStatus _VI_FUNC ag8612x_cmdInt16Arr_Q(
	ViSession vi,
	ViString strQueryInt16ArrCmd,
	ViInt32 lInt16ArrSize,
	ViInt16 _VI_FAR  aiResult[],
	ViPUInt32 plArrCount);

ViStatus _VI_FUNC ag8612x_cmdInt32Arr_Q(
	ViSession vi,
	ViString strQueryInt32ArrCmd,
	ViInt32 lInt32ArrSize,
	ViInt32 _VI_FAR  alInt32Result[],
	ViPUInt32 plArrCount);

ViStatus _VI_FUNC ag8612x_cmdReal(
	ViSession vi,
	ViString strSendRealCmd,
	ViReal64 dSendReal);

ViStatus _VI_FUNC ag8612x_cmdReal64_Q(
	ViSession vi,
	ViString strQueryRealCmd,
	ViPReal64 pdResult);

#if 0
/* These functions are NOT SUPPORTED in Agilent VEE */
ViStatus _VI_FUNC ag8612x_cmdReal32_Q(
	ViSession vi,
	ViString strQueryRealCmd,
	ViPReal32 pfResult);

ViStatus _VI_FUNC ag8612x_cmdReal32Arr_Q(
	ViSession vi,
	ViString strRealArrCmd,
	ViInt32 lRealArrSize,
	ViReal32 _VI_FAR  afResult[],
	ViPUInt32 plArrCount);
#endif

ViStatus _VI_FUNC ag8612x_cmdReal64Arr_Q(
	ViSession vi,
	ViString strRealArrCmd,
	ViInt32 lRealArrSize,
	ViReal64 _VI_FAR  adResult[],
	ViPUInt32 plArrCount);

/*****************************************************************************/
/*****************************************************************************/
/* REQUIRED COMMANDS */
/*****************************************************************************/
/*****************************************************************************/

ViStatus _VI_FUNC ag8612x_init (
	ViRsrc resourceName,
	ViBoolean bDoIDN,
    ViBoolean resetDevice,
	ViPSession pvi);

ViStatus _VI_FUNC ag8612x_close (
	ViSession vi);


/*#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@# ---------------------- @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@# DEVELOPER INSTRUCTIONS @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@# ---------------------- @#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@#
#@#@# To implement your Function Tree, add your driver functions here
#@#@#
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#*/
ViStatus _VI_FUNC ag8612x_peakLimitConfiguration (
	ViSession instrumentHandle,
	ViReal64 excursionLimit,
	ViReal64 thresholdLimit);

ViStatus _VI_FUNC ag8612x_peakLimitConfiguration_Q (
	ViSession instrumentHandle,
	ViPReal64 excursionLimit,
	ViPReal64 thresholdLimit);

ViStatus _VI_FUNC ag8612x_wavelengthLimitConfiguration (
	ViSession instrumentHandle,
	ViInt16 stat,
	ViReal64 startWavelength,
	ViReal64 stopWavelength);

ViStatus _VI_FUNC ag8612x_wavelengthLimitConfiguration_Q (
	ViSession instrumentHandle,
	ViPInt16 stat,
	ViPReal64 startWavelength,
	ViPReal64 stopWavelength);

ViStatus _VI_FUNC ag8612x_deviceConfiguration (
	ViSession instrumentHandle,
	ViInt16 device);

ViStatus _VI_FUNC ag8612x_deviceConfiguration_Q (
	ViSession instrumentHandle,
	ViPInt16 device);

ViStatus _VI_FUNC ag8612x_measurementConfiguration (
	ViSession instrumentHandle,
	ViInt16 rate,
	ViInt32 elevation,
	ViReal64 powerOffset,
	ViInt16 medium);

ViStatus _VI_FUNC ag8612x_measurementConfiguration_Q (
	ViSession instrumentHandle,
	ViPInt16 device,
	ViPInt32 rate,
	ViPInt32 elevation,
	ViPReal64 powerOffset,
	ViPInt32 medium);

ViStatus _VI_FUNC ag8612x_startSweep (ViSession instrumentHandle);

ViStatus _VI_FUNC ag8612x_startSignalToNoiseAverage (
	ViSession instrumentHandle,
	ViInt32 numberMeasurements);

ViStatus _VI_FUNC ag8612x_signalToNoiseAverageStatus_Q (
	ViSession instrumentHandle,
	ViPInt16 averageDone);

ViStatus _VI_FUNC ag8612x_averageWavelength_Q (
	ViSession instrumentHandle,
	ViPReal64 power,
	ViPReal64 wavelength);

ViStatus _VI_FUNC ag8612x_numberLines_Q (
	ViSession instrumentHandle,
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_wavelengthList_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  wavelengths[]);

ViStatus _VI_FUNC ag8612x_powerList_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  powers[]);

ViStatus _VI_FUNC ag8612x_signalToNoiseList (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  signalToNoiseRatios[]);

ViStatus _VI_FUNC ag8612x_frecuencyList_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  signalToNoiseRatios[],
	ViPReal64 wavelength);

ViStatus _VI_FUNC ag8612x_peakWavelength_Q (
	ViSession instrumentHandle,
	ViPReal64 power,
	ViPReal64 wavelength);

ViStatus _VI_FUNC ag8612x_signalToNoiseAverage_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  signalToNoiseAverage[],
	ViReal64 _VI_FAR  powers[],
	ViReal64 _VI_FAR  wavelengths[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisSetupSignalTrack (
	ViSession instrumentHandle,
	ViReal64 deltaMeters);

ViStatus _VI_FUNC ag8612x_analysisMeasure (
	ViSession instrumentHandle,
	ViInt16 resetData, 
	ViPInt32 points,
	ViPInt32 pointsInTable);

ViStatus _VI_FUNC ag8612x_analysisLines_Q (
	ViSession instrumentHandle,
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisCounts_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  sampleCountsArray[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisPeaks_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  wavelengths[],
	ViReal64 _VI_FAR  powers[], 
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisWavelengths_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  lastWavelengths[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisPowers_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  lastPowers[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisSignalToNoise_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  wavelengths[],
	ViReal64 _VI_FAR  powers[],
	ViReal64 _VI_FAR  signalToNoise[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisDriftWavelength_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  minimumWavelength[],
	ViReal64 _VI_FAR  maximumWavelength[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisDriftPower_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  minimumPower[],
	ViReal64 _VI_FAR  maximumPower[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisDelta_Q (
	ViSession instrumentHandle,
	ViReal64 referenceWavelength,
	ViReal64 referencePower,
	ViReal64 _VI_FAR  wavelength[],
	ViReal64 _VI_FAR  power[], 
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisDeltaChannel_Q (
	ViSession instrumentHandle,
	ViReal64 _VI_FAR  wavelengths[],
	ViReal64 _VI_FAR  powers[],
	ViReal64 _VI_FAR  signalToNoise[],
	ViPInt32 points);

ViStatus _VI_FUNC ag8612x_analysisDeltaGrid_Q (
	ViSession instrumentHandle,
	ViInt16 grid,
	ViReal64 referencePower,
	ViReal64 _VI_FAR  wavelength[],
	ViReal64 _VI_FAR  power[],
	ViPInt32 points);

/*#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@
#@# END DEVELOPER INSTRUCTIONS #@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#
#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#*/

/* ================================================================= */
/* End of File: $Workfile: ag8612x.h $ */


