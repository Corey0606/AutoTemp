Attribute VB_Name = "ag8612x_Defs"
' Copyright (C) 2001 Agilent Technologies
' VXIplug&play Instrument Driver for the ag8612x
' Driver Version A.00.00  March 07, 2001.

' ============================================================================
' Microsoft Visual SourceSafe Header
' $Logfile: /Connectivity/Source/ag8612x_Visa/Ag8612x.bas $
' $Date: 8/29/01 3:54p $
' $Revision: 6 $
' $Author: Mikefitz $
' ============================================================================

' =============================================================================
' Global Constants
' =============================================================================

' -----------------------------------------------------------------------------
'  Returned error status values
'  Agilent Common Error numbers start at BFFC0D00
Enum AG_eInstrErr_t
    AG_eInstrErr_Parameter1 = &HBFFC0D02
    AG_eInstrErr_Parameter2
    AG_eInstrErr_Parameter3
    AG_eInstrErr_Parameter4
    AG_eInstrErr_Parameter5
    AG_eInstrErr_Parameter6
    AG_eInstrErr_Parameter7
    AG_eInstrErr_Parameter8
    AG_eInstrErr_Parameter9
    AG_eInstrErr_Parameter10
    AG_eInstrErr_Parameter11
    AG_eInstrErr_Parameter12
    AG_eInstrErr_Parameter13
    AG_eInstrErr_Parameter14
    AG_eInstrErr_Parameter15
    AG_eInstrErr_Parameter16
    AG_eInstrErr_Parameter17
    AG_eInstrErr_Parameter18

    AG_eInstrErr_NullPtr = &HBFFC0D20
    AG_eInstrErr_ResetFailed
    AG_eInstrErr_Unexpected
    AG_eInstrErr_InvSession
    AG_eInstrErr_Lookup
    AG_eInstrErr_Detected
    AG_eInstrErr_NoLastComma
    AG_eInstrErr_OSError
    AG_eInstrErr_FileExists
    AG_eInstrErr_NotImplemented
    AG_eInstrErr_BadDataRead
    AG_eInstrErr_DllLoadLib
    AG_eInstrErr_DllLoadProcAddr
    AG_eInstrErr_FileNotFound
    AG_eInstrErr_BufferOverlow
    AG_eInstrErr_BufferSendNotComplete
    AG_eInstrErr_MemoryAllocation
    AG_eInstrErr_OutOfRange
    AG_eInstrErr_UndefinedHeader
    AG_eInstrErr_InvalidCharacter
    AG_eInstrErr_ParamNotAllowed
    AG_eInstrErr_ParamMissing
    AG_eInstrErr_ConfigError


    '* Start the instrument specific errors with the following enum *
    AG_eInstrErr_SENTINEL = &HBFFC0D50
End Enum


'        ***************************************************
'        *  Constants used by function ag8612x_timeOut     *
'        ***************************************************
Global Const ag8612x_TIMEOUT_MAX = 2147483647
Global Const ag8612x_TIMEOUT_MIN = 0&

Global Const ag8612x_CMDINT16ARR_Q_MIN = 1&
Global Const ag8612x_CMDINT16ARR_Q_MAX = 2147483647

Global Const ag8612x_CMDINT32ARR_Q_MIN = 1&
Global Const ag8612x_CMDINT32ARR_Q_MAX = 2147483647

Global Const ag8612x_CMDREAL64ARR_Q_MIN = 1&
Global Const ag8612x_CMDREAL64ARR_Q_MAX = 2147483647


' =============================================================================
' Function Declarations
' =============================================================================

'        ***************************************************
'        *  Required plug and play functions from VPP-3.1  *
'        ***************************************************

Declare Function ag8612x_init Lib "ag8612x_32.dll" ( _
     ByVal resourceName As String, _
     ByVal idQuery As Integer, _
     ByVal resetDevice As Integer, _
    vi As Long) As Long

Declare Function ag8612x_close Lib "ag8612x_32.dll" (ByVal vi As Long) As Long

Declare Function ag8612x_reset Lib "ag8612x_32.dll" (ByVal vi As Long) As Long

Declare Function ag8612x_self_test Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
    selfTestResult As Integer, _
     ByVal selfTestMessage As String) As Long

Declare Function ag8612x_error_query Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
    errorCode As Long, _
     ByVal errorMessage As String) As Long

Declare Function ag8612x_error_message Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal statusCode As Long, _
     ByVal message As String) As Long

Declare Function ag8612x_revision_query Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal instrumentDriverRevision As String, _
     ByVal firmwareRevision As String) As Long

'        ***************************************************
'        *  Agilent standard utility functions             *
'        ***************************************************

Declare Function ag8612x_timeOut Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal setTimeOut As Long) As Long

Declare Function ag8612x_timeOut_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
    timeOut As Long) As Long

Declare Function ag8612x_errorQueryDetect Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal setErrorQueryDetect As Integer) As Long

Declare Function ag8612x_errorQueryDetect_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
    errorQueryDetect As Integer) As Long

Declare Function ag8612x_dcl Lib "ag8612x_32.dll" ( ByVal vi As Long) As Long

Declare Function ag8612x_opc_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
    instrumentReady As Integer) As Long

'        ***************************************************
'        *  Agilent standard status functions              *
'        ***************************************************

Declare Function ag8612x_readStatusByte_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
    statusByte As Integer) As Long

'        ***************************************************
'        *  Agilent standard command passthrough functions *
'        ***************************************************

Declare Function ag8612x_cmd Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal sendStringCommand As String) As Long

Declare Function ag8612x_cmdString_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal queryStringCommand As String, _
     ByVal stringSize As Long, ByVal stringResult As String) As Long

Declare Function ag8612x_cmdInt Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal sendIntegerCommand As String, _
     ByVal sendInteger As Long) As Long

Declare Function ag8612x_cmdInt16_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal queryI16Command As String, _
    i16Result As Integer) As Long

Declare Function ag8612x_cmdInt32_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal queryI32Command As String, _
    i32Result As Long) As Long

Declare Function ag8612x_cmdInt16Arr_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal queryI16ArrayCommand As String, _
     ByVal i16ArraySize As Long, _
     i16ArrayResult As Integer, _
     i16ArrayCount As Long) As Long

Declare Function ag8612x_cmdInt32Arr_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal queryI32ArrayCommand As String, _
     ByVal i32ArraySize As Long, _
     i32ArrayResult As Long, _
     i32ArrayCount As Long) As Long

Declare Function ag8612x_cmdReal Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal sendRealCommand As String, _
     ByVal sendReal As Double) As Long

Declare Function ag8612x_cmdReal64_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal queryRealCommand As String, _
     realResult As Double) As Long

Declare Function ag8612x_cmdReal64Arr_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal realArrayCommand As String, _
     ByVal realArraySize As Long, _
     realArrayResult As Double, _
     realArrayCount As Long) As Long

Declare Function ag8612x_clearEventsReg Lib "ag8612x_32.dll" ( _
     ByVal vi As Long) As Long

Declare Function ag8612x_eventEnableReg Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal mask as integer) as long

Declare Function ag8612x_eventEnableReg_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByRef mask as integer) as long

Declare Function ag8612x_eventStatusReg_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByRef mask as integer) as long

Declare Function ag8612x_serviceEnableReg Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByVal mask as integer) as long

Declare Function ag8612x_serviceEnableReg_Q Lib "ag8612x_32.dll" ( _
     ByVal vi As Long, _
     ByRef mask as integer) as long

'* End of Agilent standard declarations */
'*---------------------------------------------------------------------------*

'*****************************************************************************
'*  INSTRUMENT SPECIFIC SECTION                                              *
'*  Constants and function prototypes for instrument specific functions.     *
'*****************************************************************************


'        ***************************************************
'        *  Instrument specific constants                  *
'        ***************************************************

Global Const ag8612x_PEXCURSION_MIN = 1
Global Const ag8612x_PEXCURSION_MAX = 30
Global Const ag8612x_PEXCURSION_DEF = 15

Global Const ag8612x_PTHRESHOLD_MIN = 0
Global Const ag8612x_PTHRESHOLD_MAX = 40
Global Const ag8612x_PTHRESHOLD_DEF = 10

Global Const ag8612x_WL_OFF = 0
Global Const ag8612x_WL_ON = 1

Global Const ag8612x_WLIM_WAV_MIN = 1270
Global Const ag8612x_WLIM_WAV_MAX = 1650

Global Const ag8612x_SENS_DEV_NARROW = 0
Global Const ag8612x_SENS_DEV_BROAD = 1

Global Const ag8612x_SENS_ELEV_MIN = 0
Global Const ag8612x_SENS_ELEV_MAX = 5000

Global Const ag8612x_SENS_OFFS_MIN = -40
Global Const ag8612x_SENS_OFFS_MAX = 40

Global Const ag8612x_SENS_MED_AIR = 0
Global Const ag8612x_SENS_MED_VAC = 1

Global Const ag8612x_DELTA_METERS_MIN = 0
Global Const ag8612x_DELTA_METERS_MAX = 10
Global Const ag8612x_DELTA_METERS_DEF = 0.1

Global Const ag8612x_MEAS_RESET_OFF = 0
Global Const ag8612x_MEAS_RESET_ON = 1

Global Const ag8612x_REFWAVELENGTH_MIN = 700
Global Const ag8612x_REFWAVELENGTH_MAX = 1650

Global Const ag8612x_REFPOWER_MIN = -40
Global Const ag8612x_REFPOWER_MAX = 10

Global Const ag8612x_DELTAGRID_200 = 0
Global Const ag8612x_DELTAGRID_100 = 1
Global Const ag8612x_DELTAGRID_50 = 2

Global Const ag8612x_ANA_SIGNALTONOISE_START_MIN = 10
Global Const ag8612x_ANA_SIGNALTONOISE_START_MAX = 900
Global Const ag8612x_ANA_SIGNALTONOISE_START_DEF = 100

Global Const ag8612x_ANA_SIGNALTONOISE_DONE_TRUE = 1
Global Const ag8612x_ANA_SIGNALTONOISE_DONE_FALSE = 0

Global Const ag8612x_MAXTABLE = 300
                                                    
Global Const ag8612x_UPDATE_MIN = 1
Global Const ag8612x_UPDATE_MAX = 0



'        ***************************************************
'        *  Instrument specific functions                  *
'        ***************************************************

Declare Function ag8612x_peakLimitConfiguration Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal excursionLimit As Double, _
                                     ByVal thresholdLimit As Double) As Long
                                                   
Declare Function ag8612x_peakLimitConfiguration_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                         excursionLimit As Double, _
                                         thresholdLimit As Double) As Long
                                           
Declare Function ag8612x_wavelengthLimitConfiguration Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal stat As Integer, _
                                     ByVal startWavelength As Double, _
                                     ByVal stopWavelength As Double) As Long

Declare Function ag8612x_wavelengthLimitConfiguration_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                        stat As Integer, _
                                        startWavelength As Double, _
                                        stopWavelength As Double) As Long

Declare Function ag8612x_deviceConfiguration Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                      ByVal device As Integer) As Long
                                      
Declare Function ag8612x_deviceConfiguration_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     device As Integer) As Long
                                     
Declare Function ag8612x_measurementConfiguration Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                      ByVal rate As Long, _
                                      ByVal elevation As Long, _
                                      ByVal powerOffset As Double, _
                                      ByVal medium As Integer) As Long
 
Declare Function ag8612x_measurementConfiguration_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                         device As Integer, _
                                         rate As Long, _
                                         elevation As Long, _
                                         powerOffset As Double, _
                                         medium As Long) As Long

                '***************************************************
                '*  Action/Status Class functions                  *
                '***************************************************
        
Declare Function ag8612x_startSweep Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long) As Long

Declare Function ag8612x_startSignalToNoiseAverage Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal numberMeasurements As Long) As Long
                                                  
Declare Function ag8612x_signalToNoiseAverageStatus_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                         averageDone As Integer) As Long

                '***************************************************
                '*  Data Class functions                           *
                '***************************************************

Declare Function ag8612x_averageWavelength_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           Power As Double, _
                                           Wavelength As Double) As Long
                                          
Declare Function ag8612x_numberLines_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           points As Long) As Long
                                                
Declare Function ag8612x_wavelengthList_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal wavelengths As Double) As Long
                                            
Declare Function ag8612x_powerList_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal powers As Double) As Long
                                       
Declare Function ag8612x_signalToNoiseList Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal signalToNoiseRatios As Double) As Long

Declare Function ag8612x_frecuencyList_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal signalToNoiseRatios As Double, _
                                           Wavelength As Double) As Long
                                           
Declare Function ag8612x_peakWavelength_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           Power As Double, _
                                           Wavelength As Double) As Long
                               
Declare Function ag8612x_signalToNoiseAverage_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           signalToNoise As Double, _
                                           Power As Double, _
                                           Wavelength As Double, _
                                           points As Long) As Long

   '***************************************************
   '*  Analysis Class functions                       *
   '***************************************************
        
        
                '***************************************************
                '*  Configure Class functions                      *
                '***************************************************
        
Declare Function ag8612x_analysisSetupSignalTrack Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal deltaMeters As Double) As Long
                                                    
                '***************************************************
                '*   Action/Status Class functions                 *
                '***************************************************
        
        
Declare Function ag8612x_analysisMeasure Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal resetData As Integer, _
                                           points As Long, _
                                           pointsInTable As Long) As Long
                           
      
                '***************************************************
                '*  Data Class functions                           *
                '***************************************************



Declare Function ag8612x_analysisLines_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           points As Long) As Long
      
Declare Function ag8612x_analysisCounts_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           sampleCountsArray As Double, _
                                           points As Long) As Long

Declare Function ag8612x_analysisPeaks_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           wavelengths As Double, _
                                           powers As Double, _
                                           points As Long) As Long
                                          
Declare Function ag8612x_analysisWavelengths_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           lastWavelengths As Double, _
                                           points As Long) As Long
                                                
Declare Function ag8612x_analysisPowers_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           lastPowers As Double, _
                                           points As Long) As Long
                                          
Declare Function ag8612x_analysisSignalToNoise_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           wavelengths As Double, _
                                           powers As Double, _
                                           signalToNoise As Double, _
                                           points As Long) As Long
                                                  
Declare Function ag8612x_analysisDriftWavelength_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           minimumWavelength As Double, _
                                           maximumWavelength As Double, _
                                           points As Long) As Long

Declare Function ag8612x_analysisDriftPower_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           minimumPower As Double, _
                                           maximumPower As Double, _
                                           points As Long) As Long
                                               
Declare Function ag8612x_analysisDelta_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal referenceWavelength As Double, _
                                     ByVal referencePower As Double, _
                                           Wavelength As Double, _
                                           Power As Double, _
                                           points As Long) As Long
                                          
Declare Function ag8612x_analysisDeltaChannel_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                           wavelengths As Double, _
                                           powers As Double, _
                                           signalToNoise As Double, _
                                           points As Long) As Long

Declare Function ag8612x_analysisDeltaGrid_Q Lib "ag8612x_32.dll" _
                                    (ByVal instrumentHandle As Long, _
                                     ByVal grid As Integer, _
                                     ByVal referencePower As Double, _
                                           Wavelength As Double, _
                                           Power As Double, _
                                           points As Long) As Long
                                                   
'------------------------------------------------------------------------------
' Instrument specifics functions
'------------------------------------------------------------------------------

' End of instrument specific functions
