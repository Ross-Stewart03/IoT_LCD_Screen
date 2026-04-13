// Main needs to handle swapping all data into the current menu version

#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

// create display and touchscreen objects
Adafruit_ILI9341 tft(ARDUINO_PIN_TFT_CS, ARDUINO_PIN_TFT_DC);
Adafruit_FT6206 ts ;

// Init Global Variables/Structs
// General
LCD_Button        *CurrentButtonsArr[MAX_NUM_BUTTONS] = {nullptr};
LCD_Screen_Data*  LCDScreenData_Current;
X_Y_Position      LCD_Touch_Position;
LCD_Menu          Previous_Menu_Screen;
LCD_Menu          Current_Menu_Screen;
uint32_t  PreviousTime  = 0;
uint32_t  CurrentTime   = 0;
// Main Menu
LCD_Screen_Data ScreenData_MainMenu;
// Test Buttons
LCD_Screen_Data ScreenData_TestButtons;
uint8_t LEDState  = 0;
uint8_t Counter   = 0;
// Limits Settings
LCD_Screen_Data ScreenData_LimitsSettings;
uint8_t CounterLimit = INIT_VALUE_SETTINGS_BUTTONS_COUNTER_LIMIT;
// Keypad
LCD_Screen_Data ScreenData_Keypad;
uint16_t UserNumber = 0;



void setup() {
  // Inits for the system
  Adafruit_Screen_Init();
  Menu_Init();
  Buttons_Init();
}

void loop() {
  CurrentTime = millis();

  Touch_Position_Update_Buttons();

  if (CurrentTime - PreviousTime >= GRAPHICS_UPDATE_INTERVAL) {
    PreviousTime = CurrentTime;
    Update_Screen_Graphics();
  }
}
