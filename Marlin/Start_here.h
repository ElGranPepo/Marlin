#pragma once
#define SHORT_BUILD_VERSION "2.0.x Build 476"
#define WEBSITE_URL         "http://www.geeetech.com/forum/viewtopic.php?f=20&t=69957"
#define SOURCE_CODE_URL     "https://github.com/Vertabreak/Marlin"
#define Patreon_URL         "https://www.patreon.com/vertabreaker"
#define Paypal_URL          "https://www.paypal.me/vertabreaker"
#define Youtube_URL         "https://www.youtube.com/channel/UCWK0iy2iyQYJoPrpA3RvbEw"
#define Discord_URL         "https://discord.gg/brq79WQ"

//----------------------------------
// =  disabled - remove // enabled | 
//Post flash initilize the eeprom  |
//Guides on my youtube channel     |
//Subscribe to support the channel |
//Not compatible with arduino ide  | 
//----------------------------------

//(Step 1) enable 1 base model
//GT2560 Boards - vscode: default_envs = megaatmega2560 in platformio.ini
#define GTA10       // A10 & Variants
//#define GTA20       // A20 & Variants
//#define MECREATOR2  // Mecreator2     
//#define I3PROA      // PI3A Pro  - testing
//#define I3PROB      // I3PROB    - testing
//#define I3PROC      // I3PROC    - testing
//#define I3PROW      // I3PROW    - testing
//#define I3PROX      // I3PROX    - testing

//GTM32 Boards - vscode: default_envs = STM32F103VE_GTM32 in platformio.ini
//#define GTA30       // A30 & Variants
//#define GTE180      // E180
//#define GTM201      // M201 - testing
//#define GTD200      // D200 - testing

//Melzi Boards - vscode: default_envs = melzi in platformio.ini
//#define ENDER3      // ENDER3 - testing 

//(Step 2) enable 1 driver timing set
//#define STOCK      // Enable A4988   all drivers (stock drivers)
//#define A5984      // Enable A5984   all drivers
//#define DRV8825    // Enable DRV8825 all drivers
//#define LV8729     // Enable LV8729  all drivers
//#define L6470      // Enable L6470   all drivers
//#define TB6560     // Enable TB6560  all drivers
//#define TB6600     // Enable TB6600  all drivers

//Trinamic Standalone
#define TMC2208S   // Enable TMC2208 Standalone all drivers
//#define TMC2209S   // Enable TMC2209 Standalone all drivers
//#define TMC2130S   // Enable TMC2130 Standalone all drivers
//#define TMC2160S   // Enable TMC2160 Standalone all drivers
//#define TMC26XS    // Enable TMC226X Standalone all drivers
//#define TMC2660S   // Enable TMC2660 Standalone all drivers
//#define TMC5130S   // Enable TMC5130 Standalone all drivers
//#define TMC5160S   // Enable TMC5160 Standalone all drivers

//Trinamic Uart/Spi
//#define TMC2208U   // Enable TMC2208 UART/SPI all drivers
//#define TMC2209U   // Enable TMC2209 UART/SPI all drivers
//#define TMC2130U   // Enable TMC2130 UART/SPI all drivers
//#define TMC2160U   // Enable TMC2160 UART/SPI all drivers
//#define TMC26XU    // Enable TMC226X UART/SPI all drivers
//#define TMC2660U   // Enable TMC2660 UART/SPI all drivers
//#define TMC5130U   // Enable TMC5130 UART/SPI all drivers
//#define TMC5160U   // Enable TMC5160 UART/SPI all drivers

//(Step 3) enable 1 if you have mixing or multi extruder
//#define MIX      // Enable Mixing    2 in 1 - 1 Virtual Stepper (M)
//#define CYCLOPS  // Enable Cyclops   2 in 1 - #Physical Stepper (C) 
//#define DUALEX   // 2 Extruders      2 in 2 - #Physical Stepper (D) 
//#define MIXT     // Enable Mixing    3 in 1 - 1 Virtual Stepper (T)
//#define CYCLOPST // Enable Cyclops   3 in 1 - #Physical Stepper (CT)
//#define TRIEX    // 3 Extruders      3 in 3 - #Physical Stepper (3E)
 
//(Step 4) enable 1 probe type or none for manual (stock) - GT2560 only
#define TOUCHPROBE  // Enable Touch Type Probe (Bltouch / 3Dtouch)
//#define FMP         // Enable Fixed Mounted Type Probe (Capacitive / Inductive)

//---------------------------
//Custom options & features |
//---------------------------

//Probe Options
//#define PROBE3X        // Probe 3X take the average - may effect accuracy +-
//#define PROBE5X        // Probe 5X take the average - may effect accuracy +-
//#define HEATERACCURACY // Disable heaters while probing - may effect accuracy +-
//#define HALFSPEED      // Reduce probing speed by 50% = 120 - may effect accuracy +-
//#define DOUBLESPEED    // Raise probing speed by 100% = 480 - may effect accuracy +-

//Optional features
//#define NOSCREEN   // Disable the screen and sdsupport - save alot of resources
//#define PLR        // Enabled power loss resume
//#define RUNOUT     // Enable filament runout sensor
//#define BEDCLIPS   // Enable to avoid bed clips (manual or probe)
//#define AUTO_REPORT// Enable auto report features SD & Temp

//Custome Driver Set
//#define CUSTOMDRIVERS     // Define Custom drivers
#if ENABLED (CUSTOMDRIVERS)
   //Driver selection
   #define X_DRIVER_TYPE  TMC2208_STANDALONE
   #define Y_DRIVER_TYPE  TMC2208_STANDALONE
   #define Z_DRIVER_TYPE  TMC2208_STANDALONE
   #define E0_DRIVER_TYPE A4988
   #define E1_DRIVER_TYPE A4988
   #define E2_DRIVER_TYPE A4988
   //Stepper inverting
    //#define INVERTE // Invert E direction disabe if wrong direction - M & T variants invert E (stock)
  #define INVERTXYZ   // Invert XYZ direction disable if wrong direction. adjust for custom
#endif

//Used to switch the default board of the model selected above
//#define CUSTOMBOARD // Enable Custom Board
#if ENABLED (CUSTOMBOARD)
  #define MOTHERBOARD BOARD_RAMPS_14_EFB
#endif

//Framework for adding a new printer to this config
//#define NEWMODEL // New model

//-----------------------------
//logic to reduce setup steps | 
//-----------------------------

//Multiextruder 
#if ANY(MIX, MIXT, CYCLOPS, CYCLOPST, DUALEX, TRIEX)
  #define MULTIEXTRUDER 
#endif

//TMC drivers
#if ANY(TMC2208S, TMC2209S, TMC2130S, TMC2160S, TMC26XS, TMC2660S, TMC5130S, TMC5160S) || ANY(TMC2208U, TMC2209U, TMC2130U, TMC2160U, TMC26XU, TMC2660U, TMC5130U, TMC5160U)
  #define TMCCHIPS
#endif

//Models with direct drive
#if ANY(MECREATOR2, I3PROA, I3PROB, I3PROC, I3PROW, I3PROX)
  #define DIRECTDRIVE
#endif

//GTM32 board models
#if ANY(GTA30, GTE180, GTM201, GTD200)
  #define GTM32
#endif

//GT2560 board models
#if ANY(GTA10, GTA20, MECREATOR2, I3PROA, I3PROB, I3PROC, I3PROW, I3PROX)
  #define GT2560
#endif

//Bed clip logic - use mesh inset or min probe edge to avoid clips not both
#if ENABLED (BEDCLIPS)
  #define MESH_INSET 10   // Move mesh in #mm from edge
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET) - 40 //PROBE OFFSET X - Workaround for preventing exceeding Max X in some cases
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#else
  #define MESH_INSET 0    // Move mesh in #mm from edge
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET) - 40 //PROBE OFFSET X - Workaround for preventing exceeding Max X in some cases
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

//Probe offset logic - suggest you mesure yours and adjust as needed. 
#if DISABLED (MULTIEXTRUDER) && ENABLED (TOUCHPROBE) || ENABLED (FMP)
  #define NOZZLE_TO_PROBE_OFFSET { -38, 5, 0 } // Nozzle To Probe offset XYZ A10/A20 - this is what it is on my test machines yours could differ
#elif ENABLED (MULTIEXTRUDER) && ENABLED (TOUCHPROBE) || ENABLED (FMP)
  #define NOZZLE_TO_PROBE_OFFSET { -40, 0, 0 }  // Nozzle To Probe offset XYZ A10M+T/A20M+T - this is what it is on my test machines yours could differ
#endif

//Bed offset logic - distance from endstop to bed, nozzle on front left bed edge should = X0 Y0
#if ENABLED (GTA20) && ENABLED (MIXT) || ENABLED (CYCLOPST) || ENABLED (GTA10) && ENABLED (MIXT) || ENABLED (CYCLOPST)
  #define X_MIN_POS -1   //- this is what it is on my test machines yours could differ
  #define Y_MIN_POS -7   //- this is what it is on my test machines yours could differ
#elif ENABLED (GTA10) || ENABLED (GTA30)
  #define X_MIN_POS -10  //- this is what it is on my test machines yours could differ
  #define Y_MIN_POS -5   //- this is what it is on my test machines yours could differ
#elif ENABLED (GTA20)
  #define X_MIN_POS -10  //- this is what it is on my test machines yours could differ 
  #define Y_MIN_POS 0    //- this is what it is on my test machines yours could differ
#elif ENABLED (NEWMODEL) 
  #define X_MIN_POS 0        
  #define Y_MIN_POS 0  
 #else
  #define X_MIN_POS 0        
  #define Y_MIN_POS 0      
#endif

//Steps selection logic
#if DISABLED (MULTIEXTRUDER) 
  #define DEFAULT_AXIS_STEPS_PER_UNIT  { 80, 80, 400, 95 }  // ungeared extruder found on a10/a20/a30/i3pro
  //#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 800, 95 } 
  //#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 2560, 95 } // M8 Z rod steps 2560 found on old I3pro
  #else
    #define DEFAULT_AXIS_STEPS_PER_UNIT  { 80, 80, 400, 430 } // geared extruder found on M & T variants
    //#define DEFAULT_AXIS_STEPS_PER_UNIT  { 80, 80, 800, 430 } 
    //#define DEFAULT_AXIS_STEPS_PER_UNIT  { 80, 80, 2560, 430 } // M8 Z rod steps 2560 found on old I3pro
#endif

//Motor direction logic
#if ENABLED (TMCCHIPS) && DISABLED (MULTIEXTRUDER) || DISABLED (TMCCHIPS) && ENABLED (MULTIEXTRUDER)
  #define INVERTE     // Invert E direction disabe if wrong direction - Geared exturders invert E (stock)
#endif

#if ENABLED (TMCCHIPS)
  #define INVERTXYZ   // Invert XYZ direction disable if wrong direction. 
#endif
