// Main needs to handle swapping all data into the current menu version

#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

// Create display and touchscreen objects
Adafruit_ILI9341 tft(ARDUINO_PIN_TFT_CS, ARDUINO_PIN_TFT_DC);
Adafruit_FT6206 ts ;

// Init Global Variables/Structs
// General
LCD_Screen_Data   *LCDScreenData_Current;
X_Y_Position      LCD_Touch_Position;
LCD_Menu          Previous_Menu_Screen;
LCD_Menu          Current_Menu_Screen;
uint32_t PreviousGraphicsTime  = 0;
uint32_t PreviousLogicTime = 0;
uint8_t ChangeMenuFlag = 0;
uint32_t CurrentTime = 0;
// Data screen
uint8_t HeaterTargetTemperature = DEFAULT_VAL_HEATER_TARGET_TEMPERATURE;
uint8_t HeaterOnOffState = 0;
uint8_t HeaterMode = 0; // Default Auto
// Limits Settings screen
// TODO: This should be
// Keypad screen
uint16_t UserNumber = 0;

void setup() {
  // Pins setup
  pinMode(ARDUINO_PIN_POT_TEMPERATURE, INPUT);
  pinMode(ARDUINO_PIN_POT_HUMIDITY, INPUT);
  pinMode(ARDUINO_PIN_HEATER, INPUT);


  // Inits for the system
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println("Serial Start");

  Adafruit_Screen_Init();
  Menu_Init();
  Buttons_Init();
  Config_New_Menu_Screen(&ScreenData_MainMenu);
  Update_Screen_Graphics();
}

void loop() {
  CurrentTime = millis();

  Touch_Position_Update_Buttons();

  if (ChangeMenuFlag) {
    ChangeMenuFlag = 0; // Reset flag
    Update_Menu_Change_Config();
  }

  Update_Screen_Logic();

  if (CurrentTime - PreviousGraphicsTime >= GRAPHICS_UPDATE_INTERVAL) {
    /*Serial.print("CurrentTime: ");
    Serial.print(CurrentTime);
    Serial.print("(");
    Serial.print(CurrentTime - PreviousGraphicsTime);
    Serial.println(")");*/

    PreviousGraphicsTime = CurrentTime;

    Update_Screen_Graphics();
  }  
  delay(10);
}
