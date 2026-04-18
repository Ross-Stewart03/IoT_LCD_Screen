// For all screens, buttons and texts
#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

float FloatVarScaling = 10.0;

/*
 *
  Back Button
 *
 */
// Button Handler
void ButtonHandler_Back_Button (void) {
  ChangeMenuFlag = 1; // Set flag to change menus
  /*
  Serial.print("Back Button Pressed, Current: ");
  Serial.print(Current_Menu_Screen);
  Serial.print(", Going back to: ");
  Serial.println(Previous_Menu_Screen);
  */
  LCD_Menu Temp_Menu_Screen = Current_Menu_Screen;

  Current_Menu_Screen = Previous_Menu_Screen;
  Previous_Menu_Screen = Temp_Menu_Screen;
}

// Button
Adafruit_GFX_Button GFX_Button_Back;
LCD_Button Back_Button = {
  "Back",
  ButtonHandler_Back_Button,
  GFX_Button_Back,
  {BUTTON_BACK_X,BUTTON_BACK_Y},
  {BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT},
  BUTTON_BACK_BACKGROUND_COLOUR,
  BUTTON_BACK_TEXT_COLOUR,
  BUTTON_BACK_BORDER_COLOUR,
  BUTTON_BACK_WIDTH_SACLE,
  BUTTON_BACK_HEIGHT_SACLE
};
/*
 *
  Back Button
 *
 */


/*
 *
  Main Menu Screen
 *
 */
// Buttons
Adafruit_GFX_Button GFX_Button_Main_Menu_Screen;
Adafruit_GFX_Button GFX_Button_Limits_Settings_Screen;
LCD_Button ButtonsArr_MainMenuScreen[BUTTON_MAIN_MENU_ARRAY_NUM] = { 
  { // Data Select
    "Data",
    ButtonHandler_MainMenu_DataScreenSelect,
    GFX_Button_Main_Menu_Screen,
    {BUTTON_MAIN_MENU_DATA_SELECT_X,BUTTON_MAIN_MENU_DATA_SELECT_Y},
    {BUTTON_MAIN_MENU_DATA_SELECT_WIDTH, BUTTON_MAIN_MENU_DATA_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_DATA_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_DATA_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_DATA_SELECT_BORDER_COLOUR,
    TEXT_MAIN_MENU_DATA_SELECT_WIDTH_SACLE,
    TEXT_MAIN_MENU_DATA_SELECT_HEIGHT_SACLE
  },
  { // Limits Setting Select
    "Limits",
    ButtonHandler_MainMenu_LimitsSettingsScreenSelect,
    GFX_Button_Limits_Settings_Screen,
    {BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_X, BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_Y},
    {BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH, BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BORDER_COLOUR,
    TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH_SACLE,
    TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT_SACLE
  }
};

// Texts
LCD_Text TextArr_MainMenuScreen[TEXT_DATA_ARRAY_NUM] = {
  { // Title
    "Main Menu",
    nullptr, // No text variable being used
    TEXT_MAIN_MENU_TITLE_DEFAULT_FLOAT_VAL,
    {TEXT_MAIN_MENU_TITLE_X, TEXT_MAIN_MENU_TITLE_Y},
    TEXT_MAIN_MENU_TITLE_BACKGROUND_COLOUR,
    TEXT_MAIN_MENU_TITLE_TEXT_COLOUR,
    TEXT_MAIN_MENU_TITLE_DEFAULT_INT_VAL,
    TEXT_MAIN_MENU_TITLE_FONT_SIZE,
    TEXT_MAIN_MENU_TITLE_VAR_TYPE
  }
};

// Rectangle colours
/* No rectangles are drawn therefore no colours needed
uint16_t RectangleColours_MainMenuScreen = { 
  { // Rectangle 1
    [Macro Colour 1], // Index 0 is default colour
    [Macro Colour 2],
    [Macro Colour n]
  },
  { // Rectangle 2
    [Macro Colour 1], // Index 0 is default colour
    [Macro Colour 2],
    [Macro Colour n]
  }
};*/

// Rectangle shapes
/* No rectangles are drawn here
LCD_Rectangle RectanglesArr_MainMenuScreen[RECTANGLE_MAIN_MENU_ARRAY_NUM] = {
  RectangleColours_MainMenuScreen,
  {RECTANGLE_MAIN_MENU_[Rectangle name here]_X, RECTANGLE_MAIN_MENU_[Rectangle name here]_Y},
  {RECTANGLE_MAIN_MENU_[Rectangle name here]_WIDTH, RECTANGLE_MAIN_MENU_[Rectangle name here]_HEIGHT},
  0 // Default colour
};*/

// Circle colours
/* No circles are drawn therefore no colours needed
uint16_t CircleColours_MainMenuScreen = { 
  // Index 0 is default colour
  { // Circle 1
    [Macro Colour 1],
    [Macro Colour 2],
    [Macro Colour n]
  }
  { // Circle 2
    [Macro Colour 1],
    [Macro Colour 2],
    [Macro Colour n]
  }
};*/

// Circle shapes
/* No Cirlces are drawn here
LCD_Circle CirclesArr_MainMenuScreen[CIRCLE_MAIN_MENU_ARRAY_NUM] = {
  CircleColours_MainMenuScreen,
  {CIRCLE_MAIN_MENU_[Circle name here]_X, CIRCLE_MAIN_MENU_[Circle name here]_Y},
  CIRCLE_MAIN_MENU_[Circle name here]_RADIUS,
  0 // Default colour
};*/

// Screen Data
LCD_Screen_Data ScreenData_MainMenu = {
  ButtonsArr_MainMenuScreen,
  TextArr_MainMenuScreen,
  nullptr, // No rectangles to be drawn
  nullptr, // No circles to be drawn
  nullptr, // No screen logic needs updating
  SCREEN_MAIN_MENU_BACKGROUND_COLOUR,
  BUTTON_MAIN_MENU_ARRAY_NUM,
  TEXT_MAIN_MENU_ARRAY_NUM,
  RECTANGLE_MAIN_MENU_ARRAY_NUM,
  CIRCLE_MAIN_MENU_ARRAY_NUM,
  ENUM_MENU_MAIN_MENU_SCREEN
};

// Button Hanlders
// Takes user to the Data screen
void ButtonHandler_MainMenu_DataScreenSelect (void) {
  ChangeMenuFlag = 1; // Set flag to change menus
  /*
  Serial.print("Data button pressed, Current: ");
  Serial.print(Current_Menu_Screen);
  */
  Previous_Menu_Screen = Current_Menu_Screen;
  Current_Menu_Screen = ENUM_MENU_DATA_SCREEN;
  /*
  Serial.print(",  Previous: ");
  Serial.print(Previous_Menu_Screen);
  Serial.print(",  Going to: ");
  Serial.println(Current_Menu_Screen);
  */
}
// Takes user to the Limits Settings screen
void ButtonHandler_MainMenu_LimitsSettingsScreenSelect (void) {
  ChangeMenuFlag = 1; // Set flag to change menus

  Serial.println("Limits Setting Button pressed");
  Previous_Menu_Screen = Current_Menu_Screen;
  Current_Menu_Screen = ENUM_MENU_LIMITS_SETTINGS_SCREEN;
}

/* Updates the logic for the screen
void UpdateScreenLogic_MainMenuScreen(void) {
  // Do nothing, Main Menu has no non button related logic
}*/
/*
 *
  Main Menu Screen
 *
 */


/*
 *
  Data Screen
 *
 */
// Buttons
LCD_Button ButtonsArr_DataScreen[BUTTON_DATA_ARRAY_NUM] = {
  { // Back Button
    Back_Button
  }
};

/* Texts*/
// Stores text of both states of the heater
char HeaterOnOffTextArr[2][8] = {
  "Off", // Default text
  "On " // 
};
char HeaterModeTextArr[2][8] = {
  "Auto  ", // Default text
  "Manual"
};
char TEXT_DATA_HEATER_ON_OFF_DEFAULT_TEXT_VAL[] = "Off";
char TEXT_DATA_HEATER_MODE_DEFAULT_TEXT_VAL[] = "Auto";
LCD_Text TextArr_DataScreen[TEXT_DATA_ARRAY_NUM] = {
  { // Title
    "Data",
    nullptr, // No text variable being used
    TEXT_DATA_TITLE_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_TITLE_X, TEXT_DATA_TITLE_Y},
    TEXT_DATA_TITLE_BACKGROUND_COLOUR,
    TEXT_DATA_TITLE_TEXT_COLOUR,
    TEXT_DATA_TITLE_DEFAULT_INT_VAL,
    TEXT_DATA_TITLE_FONT_SIZE,
    LCD_TEXT_VAR_TYPE_NONE
  },
  { // Temperature
    "Temperature: ",
    nullptr, // No text variable being used
    TEXT_DATA_TEMPERATURE_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_TEMPERATURE_X, TEXT_DATA_TEMPERATURE_Y},
    TEXT_DATA_TEMPERATURE_BACKGROUND_COLOUR,
    TEXT_DATA_TEMPERATURE_TEXT_COLOUR,
    TEXT_DATA_TEMPERATURE_DEFAULT_INT_VAL,
    TEXT_DATA_TEMPERATURE_FONT_SIZE,
    LCD_TEXT_VAR_TYPE_FLOAT
  },
  { // Humidity
    "Humidity: ",
    nullptr, // No text variable being used
    TEXT_DATA_HUMIDITY_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_HUMIDITY_X, TEXT_DATA_HUMIDITY_Y},
    TEXT_DATA_HUMIDITY_BACKGROUND_COLOUR,
    TEXT_DATA_HUMIDITY_TEXT_COLOUR,
    TEXT_DATA_HUMIDITY_DEFAULT_INT_VAL,
    TEXT_DATA_HUMIDITY_FONT_SIZE,
    TEXT_DATA_HUMIDITY_VAR_TYPE
  },
  { // Heater On/Off
    "Heater: ",
    TEXT_DATA_HEATER_ON_OFF_DEFAULT_TEXT_VAL,
    TEXT_DATA_HEATER_ON_OFF_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_HEATER_ON_OFF_X, TEXT_DATA_HEATER_ON_OFF_Y},
    TEXT_DATA_HEATER_ON_OFF_BACKGROUND_COLOUR,
    TEXT_DATA_HEATER_ON_OFF_TEXT_COLOUR,
    TEXT_DATA_HEATER_ON_OFF_DEFAULT_INT_VAL,
    TEXT_DATA_HEATER_ON_OFF_FONT_SIZE,
    TEXT_DATA_HEATER_ON_OFF_VAR_TYPE
  },
  { // Heater Mode
    "Heater Mode: ",
    TEXT_DATA_HEATER_MODE_DEFAULT_TEXT_VAL,
    TEXT_DATA_HEATER_MODE_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_HEATER_MODE_X, TEXT_DATA_HEATER_MODE_Y},
    TEXT_DATA_HEATER_MODE_BACKGROUND_COLOUR,
    TEXT_DATA_HEATER_MODE_TEXT_COLOUR,
    TEXT_DATA_HEATER_MODE_DEFAULT_INT_VAL,
    TEXT_DATA_HEATER_MODE_FONT_SIZE,
    TEXT_DATA_HEATER_MODE_VAR_TYPE
  }
};

// Rectangle colours
/* No rectangles are drawn therefore no colours needed
uint16_t RectangleColours_MainMenuScreen = { 
  { // Rectangle 1
    [Macro Colour 1], // Index 0 is default colour
    [Macro Colour 2],
    [Macro Colour n]
  }
  { // Rectangle 2
    [Macro Colour 1], // Index 0 is default colour
    [Macro Colour 2],
    [Macro Colour n]
  }
};*/

// Rectangle shapes
/* No rectangles are drawn here
LCD_Rectangle RectanglesArr_MainMenuScreen[RECTANGLE_MAIN_MENU_ARRAY_NUM] = {
  RectangleColours_MainMenuScreen,
  {RECTANGLE_MAIN_MENU_[Rectangle name here]_X, RECTANGLE_MAIN_MENU_[Rectangle name here]_Y},
  {RECTANGLE_MAIN_MENU_[Rectangle name here]_WIDTH, RECTANGLE_MAIN_MENU_[Rectangle name here]_HEIGHT},
  0 // Default colour
};*/

// Circle colours
uint16_t CircleColours_DataScreen[2] = { 
  // Heater on/off LED
  ILI9341_RED,
  ILI9341_GREEN
};

// Circle shapes
LCD_Circle CirclesArr_DataScreen[CIRCLE_DATA_ARRAY_NUM] = {
  { // Heater on/off LED
    CircleColours_DataScreen,
    {CIRCLE_DATA_HEATER_ON_OFF_LED_X, CIRCLE_DATA_HEATER_ON_OFF_LED_Y},
    CIRCLE_DATA_HEATER_ON_OFF_LED_RADIUS,
    CIRCLE_DATA_HEATER_ON_OFF_LED_ARRAY_INDEX // Default colour
  }
};

// Screen Data
LCD_Screen_Data ScreenData_Data = {
  ButtonsArr_DataScreen,
  TextArr_DataScreen,
  nullptr, // No rectangles to be drawn
  CirclesArr_DataScreen,
  UpdateScreenLogic_DataScreen,
  SCREEN_DATA_BACKGROUND_COLOUR,
  BUTTON_DATA_ARRAY_NUM,
  TEXT_DATA_ARRAY_NUM,
  RECTANGLE_DATA_ARRAY_NUM,
  CIRCLE_DATA_ARRAY_NUM,
  ENUM_MENU_DATA_SCREEN
};

// Button Hanlders
// No button handlers are needed for Data screen
// Buttons
// No buttons(apart from back button) are needed for Data screen

// Updates the logic for the screen
void UpdateScreenLogic_DataScreen(void) {
  // TODO: 
  // Need to update temperature and humidity from adafruit sensors
  // Need to show if the heater is auto or manual mode
  // Check what needs to be done for the PIR sensor? Lights or intrudor?

  // Temporary until adafruit sensor implemented
  float TempPotValue_Temperature = 100.0 * (analogRead(ARDUINO_PIN_POT_TEMPERATURE) / 1023.0);
  float TempPotValue_Humidity = 100.0 * (analogRead(ARDUINO_PIN_POT_HUMIDITY) / 1023.0);

  // Get Sensor values
  ScreenData_Data.TextArr[TEXT_DATA_TEMPERATURE_INDEX].FloatVar = (uint16_t)(TempPotValue_Temperature * FloatVarScaling); // TODO: Integrate this value with the actual sensor (Remember x10 scaling)
  ScreenData_Data.TextArr[TEXT_DATA_HUMIDITY_INDEX].FloatVar = (uint16_t)(TempPotValue_Humidity * FloatVarScaling);// TODO: Integrate this value with the actual sensor (Remember x10 scaling)

  float Temperature = (float)ScreenData_Data.TextArr[TEXT_DATA_TEMPERATURE_INDEX].FloatVar / FloatVarScaling;
  float Humidity = (float)ScreenData_Data.TextArr[TEXT_DATA_HUMIDITY_INDEX].FloatVar / FloatVarScaling;
  /*
  Serial.print("Temperature: ");
  Serial.println(Temperature, 1);
  Serial.print("\nTemperature Target: ");
  Serial.println(HeaterTargetTemperature);
  Serial.print("Humidity: ");
  Serial.println(Humidity, 1);
  */

  if (!HeaterMode) {
    // Heater in Automatic mode. Applys a hysteresis whether heater is on/off, this stops heater rapidly switching on/off 
    if (!HeaterOnOffState) {
      // Heater is off
      HeaterOnOffState = (Temperature < (HeaterTargetTemperature - HEATER_TARGET_TEMPERATURE_HYSTERESIS)) ? HEATER_ON : HEATER_OFF; // Temperature below (target - Hysteresis)? - Yes, turn on. No, turn off
    }
    else {
      // Heater is on
      HeaterOnOffState = (Temperature > (HeaterTargetTemperature + HEATER_TARGET_TEMPERATURE_HYSTERESIS)) ? HEATER_OFF : HEATER_ON; // Temperature above (target + Hysteresis)? - Yes, turn off. No, turn on
    }
    Serial.print("Heater State: ");
    Serial.println(HeaterOnOffState);
  }
  ScreenData_Data.CirclesArr[CIRCLE_DATA_HEATER_ON_OFF_LED_ARRAY_INDEX].CurrentColourIndex = HeaterOnOffState; // Updates LCD LED colour
  ScreenData_Data.TextArr[TEXT_DATA_HEATER_ON_OFF_INDEX].TextVar = HeaterOnOffTextArr[HeaterOnOffState]; // Updates Text of Heater On/Off
  digitalWrite(ARDUINO_PIN_HEATER, HeaterOnOffState);
}
/*
 *
  Data Screen
 *
 */


/*
 *
  Limits Settings
 *
 */
 // TODO: User needs to be asked for a password before they are able to enter this menu(opens up keypad)
 // Need to add special buttons to allow user click on the value so they can manually enter the value through the keypad, The button should be same colour as the background and no text
 // Above need to be added to the general structs, to allow a generic format 
 // Need to have heater target limits, e.g min = 10C, max = 50C
 // User to be able to set upper/lower limits
 // User able to switch between manual/auto mode for heater.
 // Use in logic function Heater Mode ScreenData_LimitsSettings.TextArr[TEXT_DATA_HEATER_MODE_INDEX].TextVar = HeaterOnOffTextArr[HeaterMode];

/*
 *
  Limits Settings
 *
 */

/*
 *
  Keypad Screen
 *
 */
 // TODO: Populate with what Keypad actually needs, just name swapped definitions
 // The "Back" button here needs to be "Cancel". Don't include Back button
/*
 *
  Keypad Screen
 *
 */