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

// Back Button
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
  BUTTON_BACK_HEIGHT_SACLE,
  BUTTON_BACK_DEFAULT_AVAILABLE
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
Adafruit_GFX_Button GFX_Button_Settings_Screen;
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
    BUTTON_MAIN_MENU_DATA_SELECT_WIDTH_SACLE,
    BUTTON_MAIN_MENU_DATA_SELECT_HEIGHT_SACLE,
    BUTTON_MAIN_MENU_DATA_SELECT_DEFAULT_AVAILABLE
  },
  { // Settings Select
    "Settings",
    ButtonHandler_MainMenu_SettingsScreenSelect,
    GFX_Button_Settings_Screen,
    {BUTTON_MAIN_MENU_SETTINGS_SELECT_X, BUTTON_MAIN_MENU_SETTINGS_SELECT_Y},
    {BUTTON_MAIN_MENU_SETTINGS_SELECT_WIDTH, BUTTON_MAIN_MENU_SETTINGS_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_SETTINGS_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_SETTINGS_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_SETTINGS_SELECT_BORDER_COLOUR,
    BUTTON_MAIN_MENU_SETTINGS_SELECT_WIDTH_SACLE,
    BUTTON_MAIN_MENU_SETTINGS_SELECT_HEIGHT_SACLE,
    BUTTON_MAIN_MENU_SETTINGS_SELECT_DEFAULT_AVAILABLE
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
// Takes user to the Settings screen
void ButtonHandler_MainMenu_SettingsScreenSelect (void) {
  ChangeMenuFlag = 1; // Set flag to change menus

  //Serial.println("Settings Button pressed");
  Previous_Menu_Screen = Current_Menu_Screen;

  // Change this back to KEYPAD, temporally  using settings to get screen working first 
  Current_Menu_Screen = ENUM_MENU_SETTINGS_SCREEN;
  // TODO: Need to set previous to Settings screen, then current to keypad to ask for password
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
Adafruit_GFX_Button GFX_Button_Data_Heater_On_Off;
Adafruit_GFX_Button GFX_Button_Data_HeaterMode;
LCD_Button ButtonsArr_DataScreen[BUTTON_DATA_ARRAY_NUM] = {
  { // Back Button
    Back_Button
  },
  { // Heater On/Off (Invisible)
    "",
    ButtonHandler_Data_HeaterOnOff,
    GFX_Button_Data_Heater_On_Off,
    {BUTTON_DATA_HEATER_ON_OFF_X,BUTTON_DATA_HEATER_ON_OFF_Y},
    {BUTTON_DATA_HEATER_ON_OFF_WIDTH, BUTTON_DATA_HEATER_ON_OFF_HEIGHT},
    BUTTON_DATA_HEATER_ON_OFF_BACKGROUND_COLOUR,
    BUTTON_DATA_HEATER_ON_OFF_TEXT_COLOUR,
    BUTTON_DATA_HEATER_ON_OFF_BORDER_COLOUR,
    BUTTON_DATA_HEATER_ON_OFF_WIDTH_SACLE,
    BUTTON_DATA_HEATER_ON_OFF_HEIGHT_SACLE,
    BUTTON_DATA_HEATER_ON_OFF_DEFAULT_AVAILABLE
  },
    { // Heater Mode, doesn't show value
    "",
    ButtonHandler_Data_HeaterMode,
    GFX_Button_Data_HeaterMode,
    {BUTTON_DATA_HEATER_MODE_X,BUTTON_DATA_HEATER_MODE_Y},
    {BUTTON_DATA_HEATER_MODE_WIDTH, BUTTON_DATA_HEATER_MODE_HEIGHT},
    BUTTON_DATA_HEATER_MODE_BACKGROUND_COLOUR,
    BUTTON_DATA_HEATER_MODE_TEXT_COLOUR,
    BUTTON_DATA_HEATER_MODE_BORDER_COLOUR,
    BUTTON_DATA_HEATER_MODE_WIDTH_SACLE,
    BUTTON_DATA_HEATER_MODE_HEIGHT_SACLE,
    BUTTON_DATA_HEATER_MODE_DEFAULT_AVAILABLE
  }
};

/* Texts */
// Stores text of both states of the heater
char HeaterOnOffTextArr[2][8] = {
  "Off", // Default text
  "On " // 
};
// Stores text of both states of Heater Mode
char HeaterModeTextArr[2][7] = {
  " Auto ",
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
    TEXT_DATA_TITLE_VAR_TYPE
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
    TEXT_DATA_TEMPERATURE_VAR_TYPE
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
    "Heater Mode:",
    TEXT_DATA_HEATER_MODE_DEFAULT_TEXT_VAL,
    TEXT_DATA_HEATER_MODE_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_HEATER_MODE_X, TEXT_DATA_HEATER_MODE_Y},
    TEXT_DATA_HEATER_MODE_BACKGROUND_COLOUR,
    TEXT_DATA_HEATER_MODE_TEXT_COLOUR,
    TEXT_DATA_HEATER_MODE_DEFAULT_INT_VAL,
    TEXT_DATA_HEATER_MODE_FONT_SIZE,
    TEXT_DATA_HEATER_MODE_VAR_TYPE
  },
  { // Heater Mode Value, only shows the value in seprate place so it can be placed ontop of the button
    "",
    HeaterModeTextArr[TEXT_DATA_HEATER_MODE_TEXT_AUTO_INDEX], // "Auto" as default value
    TEXT_DATA_HEATER_MODE_VALUE_DEFAULT_FLOAT_VAL,
    {TEXT_DATA_HEATER_MODE_VALUE_X, TEXT_DATA_HEATER_MODE_VALUE_Y},
    TEXT_DATA_HEATER_MODE_VALUE_BACKGROUND_COLOUR,
    TEXT_DATA_HEATER_MODE_VALUE_TEXT_COLOUR,
    TEXT_DATA_HEATER_MODE_VALUE_DEFAULT_INT_VAL,
    TEXT_DATA_HEATER_MODE_VALUE_FONT_SIZE,
    TEXT_DATA_HEATER_MODE_VALUE_VAR_TYPE
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
void ButtonHandler_Data_HeaterOnOff(void) {
  // Allows user to turn the heater on/off (Only in manual mode)
  //Serial.println("Heater On Off button pressed");
  HeaterOnOffState = !HeaterOnOffState;
  ScreenData_Data.TextArr[BUTTON_DATA_HEATER_ON_OFF_ARRAY_INDEX].TextVar = HeaterOnOffTextArr[HeaterOnOffState];
  //Serial.print("HeaterOnOffState: ");
  //Serial.println(HeaterOnOffState);
  //Serial.print("HeaterOnOffState(LCD): ");
  //Serial.println(ScreenData_Data.TextArr[BUTTON_DATA_HEATER_ON_OFF_ARRAY_INDEX].TextVar);
}
void ButtonHandler_Data_HeaterMode(void) {
  // TODO: When clicked, latch between "Auto" and "Manual"
  
  HeaterMode = !HeaterMode;  // Switch to other mode
  
  ScreenData_Data.TextArr[TEXT_DATA_HEATER_MODE_VALUE_INDEX].TextVar = HeaterModeTextArr[HeaterMode]; // Update LCD text
  
  ScreenData_Data.ButtonsArr[BUTTON_DATA_HEATER_ON_OFF_ARRAY_INDEX].Available = HeaterMode; // Update Data Screen Heater On Off button available

  // TODO: Also need to allow user to turn heater on/off when in manual mode
}
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
    //Serial.print("Heater State: ");
    //Serial.println(HeaterOnOffState);
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
  Settings Screen
 *
 */
 // TODO: User needs to be asked for a password before they are able to enter this menu(opens up keypad)
 // Need to add special buttons to allow user click on the value so they can manually enter the value through the keypad, The button should be same colour as the background and no text
 // Above need to be added to the general structs, to allow a generic format 
 // Need to have heater target limits, e.g min = 10C, max = 50C
 // User to be able to set heater target temperature
 // User able to switch between manual/auto mode for heater.
 // Use in logic function Heater Mode ScreenData_Settings.TextArr[TEXT_DATA_HEATER_MODE_INDEX].TextVar = HeaterOnOffTextArr[HeaterMode];
// Buttons
Adafruit_GFX_Button GFX_Button_Settings_H_T_T_Value;
Adafruit_GFX_Button GFX_Button_Settings_H_T_T_Value_Up;
Adafruit_GFX_Button GFX_Button_Settings_H_T_T_Value_Down;
Adafruit_GFX_Button GFX_Button_Settings_HeaterMode;

LCD_Button ButtonsArr_SettingsScreen[BUTTON_SETTINGS_ARRAY_NUM] = {
  { // Back Button
    Back_Button
  },
  { // Heater target temperature value button (Invisible button)
    "",
    ButtonHandler_Settings_H_T_T_Value,
    GFX_Button_Settings_H_T_T_Value,
    {BUTTON_SETTINGS_H_T_T_VALUE_X,BUTTON_SETTINGS_H_T_T_VALUE_Y},
    {BUTTON_SETTINGS_H_T_T_VALUE_WIDTH, BUTTON_SETTINGS_H_T_T_VALUE_HEIGHT},
    BUTTON_SETTINGS_H_T_T_VALUE_BACKGROUND_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_TEXT_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_BORDER_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_WIDTH_SACLE,
    BUTTON_SETTINGS_H_T_T_VALUE_HEIGHT_SACLE,
    BUTTON_SETTINGS_H_T_T_VALUE_DEFAULT_AVAILABLE
  },
  { // Heater target temperature up button
    "/\\", // "/\" but have to add extra '\'
    ButtonHandler_Settings_H_T_T_Value_Up,
    GFX_Button_Settings_H_T_T_Value_Up,
    {BUTTON_SETTINGS_H_T_T_VALUE_UP_X,BUTTON_SETTINGS_H_T_T_VALUE_UP_Y},
    {BUTTON_SETTINGS_H_T_T_VALUE_UP_WIDTH, BUTTON_SETTINGS_H_T_T_VALUE_UP_HEIGHT},
    BUTTON_SETTINGS_H_T_T_VALUE_UP_BACKGROUND_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_UP_TEXT_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_UP_BORDER_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_UP_WIDTH_SACLE,
    BUTTON_SETTINGS_H_T_T_VALUE_UP_HEIGHT_SACLE,
    BUTTON_SETTINGS_H_T_T_VALUE_UP_DEFAULT_AVAILABLE
  },
  { // Heater target temperature down button
    "\\/", // "\/" but have to add extra '\'
    ButtonHandler_Settings_H_T_T_Value_Down,
    GFX_Button_Settings_H_T_T_Value_Down,
    {BUTTON_SETTINGS_H_T_T_VALUE_DOWN_X,BUTTON_SETTINGS_H_T_T_VALUE_DOWN_Y},
    {BUTTON_SETTINGS_H_T_T_VALUE_DOWN_WIDTH, BUTTON_SETTINGS_H_T_T_VALUE_DOWN_HEIGHT},
    BUTTON_SETTINGS_H_T_T_VALUE_DOWN_BACKGROUND_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_DOWN_TEXT_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_DOWN_BORDER_COLOUR,
    BUTTON_SETTINGS_H_T_T_VALUE_DOWN_WIDTH_SACLE,
    BUTTON_SETTINGS_H_T_T_VALUE_DOWN_HEIGHT_SACLE,
    BUTTON_SETTINGS_H_T_T_VALUE_DOWN_DEFAULT_AVAILABLE
  }
};

/* Texts */
LCD_Text TextArr_SettingsScreen[TEXT_SETTINGS_ARRAY_NUM] = {
  { // Title
    "Settings",
    nullptr, // No text variable being used
    TEXT_SETTINGS_TITLE_DEFAULT_FLOAT_VAL,
    {TEXT_SETTINGS_TITLE_X, TEXT_DATA_TITLE_Y},
    TEXT_SETTINGS_TITLE_BACKGROUND_COLOUR,
    TEXT_SETTINGS_TITLE_TEXT_COLOUR,
    TEXT_SETTINGS_TITLE_DEFAULT_INT_VAL,
    TEXT_SETTINGS_TITLE_FONT_SIZE,
    TEXT_SETTINGS_TITLE_VAR_TYPE
  },
  { // Heater target temperature: pt1 (H_T_T_PT1)
    "Heater",
    nullptr, // No text variable being used
    TEXT_SETTINGS_H_T_T_PT1_DEFAULT_FLOAT_VAL,
    {TEXT_SETTINGS_H_T_T_PT1_X, TEXT_SETTINGS_H_T_T_PT1_Y},
    TEXT_SETTINGS_H_T_T_PT1_BACKGROUND_COLOUR,
    TEXT_SETTINGS_H_T_T_PT1_TEXT_COLOUR,
    TEXT_SETTINGS_H_T_T_PT1_DEFAULT_INT_VAL,
    TEXT_SETTINGS_H_T_T_PT1_FONT_SIZE,
    TEXT_SETTINGS_H_T_T_PT1_VAR_TYPE
  },
  { // Heater target temperature: pt2 (H_T_T_PT2)
    "target",
    nullptr, // No text variable being used
    TEXT_SETTINGS_H_T_T_PT2_DEFAULT_FLOAT_VAL,
    {TEXT_SETTINGS_H_T_T_PT2_X, TEXT_SETTINGS_H_T_T_PT2_Y},
    TEXT_SETTINGS_H_T_T_PT2_BACKGROUND_COLOUR,
    TEXT_SETTINGS_H_T_T_PT2_TEXT_COLOUR,
    TEXT_SETTINGS_H_T_T_PT2_DEFAULT_INT_VAL,
    TEXT_SETTINGS_H_T_T_PT2_FONT_SIZE,
    TEXT_SETTINGS_H_T_T_PT2_VAR_TYPE
  },
  { // Heater target temperature: pt3 (H_T_T_PT3)
    "temperature",
    nullptr, // No text value to use
    TEXT_SETTINGS_H_T_T_PT3_DEFAULT_FLOAT_VAL,
    {TEXT_SETTINGS_H_T_T_PT3_X, TEXT_SETTINGS_H_T_T_PT3_Y},
    TEXT_SETTINGS_H_T_T_PT3_BACKGROUND_COLOUR,
    TEXT_SETTINGS_H_T_T_PT3_TEXT_COLOUR,
    TEXT_SETTINGS_H_T_T_PT3_DEFAULT_INT_VAL,
    TEXT_SETTINGS_H_T_T_PT3_FONT_SIZE,
    TEXT_SETTINGS_H_T_T_PT3_VAR_TYPE
  },
  { // Heater target temperature: pt4 (H_T_T_PT4). This contains the value for Heater Target Temperature
    ":",
    nullptr, // No text value to use
    TEXT_SETTINGS_H_T_T_PT4_DEFAULT_FLOAT_VAL,
    {TEXT_SETTINGS_H_T_T_PT4_X, TEXT_SETTINGS_H_T_T_PT4_Y},
    TEXT_SETTINGS_H_T_T_PT4_BACKGROUND_COLOUR,
    TEXT_SETTINGS_H_T_T_PT4_TEXT_COLOUR,
    TEXT_SETTINGS_H_T_T_PT4_DEFAULT_INT_VAL,
    TEXT_SETTINGS_H_T_T_PT4_FONT_SIZE,
    TEXT_SETTINGS_H_T_T_PT4_VAR_TYPE
  }
};

// Rectangle colours
/* No rectangles are drawn therefore no colours needed
uint16_t RectangleColours_SettingsScreen[] = { 
  // Heater target temperature value highlight (H_T_T_VAL)
  ILI9341_DARKGREY // Index 0 is default colour
};

// Rectangle shapes
LCD_Rectangle RectanglesArr_SettingsScreen[RECTANGLE_SETTINGS_ARRAY_NUM] = {
  RectangleColours_SettingsScreen,
  {RECTANGLE_SETTINGS_H_T_T_VALUE_X, RECTANGLE_SETTINGS_H_T_T_VALUE_Y},
  {RECTANGLE_SETTINGS_H_T_T_VALUE_WIDTH, RECTANGLE_SETTINGS_H_T_T_VALUE_HEIGHT},
  RECTANGLE_SETTINGS_H_T_T_VALUE_ARRAY_GREY_INDEX // Default colour
};*/

// Circle colours
/* No circles are drawn therefore no colours needed
uint16_t CircleColours_SettingsScreen[2] = { 
};

// Circle shapes
/* No circles are drawn
LCD_Circle CirclesArr_DataScreen[CIRCLE_DATA_ARRAY_NUM] = {
  { // Heater on/off LED
    CircleColours_DataScreen,
    {CIRCLE_SETTINGS_[Circle name here]_X, CIRCLE_SETTINGS_[Circle name here]_Y},
    CIRCLE_SETTINGS_[Circle name here]_RADIUS,
    CIRCLE_SETTINGS_[Circle name here]_ARRAY_INDEX // Default colour
  }
};*/

// Screen Data
LCD_Screen_Data ScreenData_Settings = {
  ButtonsArr_SettingsScreen,
  TextArr_SettingsScreen,
  nullptr, // No rectangles to be drawn
  nullptr, // No circles to be drawn
  UpdateScreenLogic_SettingsScreen,
  SCREEN_SETTINGS_BACKGROUND_COLOUR,
  BUTTON_SETTINGS_ARRAY_NUM,
  TEXT_SETTINGS_ARRAY_NUM,
  RECTANGLE_SETTINGS_ARRAY_NUM,
  CIRCLE_SETTINGS_ARRAY_NUM,
  ENUM_MENU_SETTINGS_SCREEN
};

// Limits for Heater
Limits_Float  HeaterLimits = {
  LIMITS_HIGH_H_T_T,
  LIMITS_LOW_H_T_T
};

// Button Hanlders
void ButtonHandler_Settings_H_T_T_Value (void) {
  // TODO: Needs to call call keybaord to get a value
  // Check user entered value against limits and set the value
  // Use HeaterTargetTemperature = Check_Heater_Target_Temperature_Limits([keypad function here]);
  //Serial.println("Heater Target Temperature Value button pressed");
}
void ButtonHandler_Settings_H_T_T_Value_Up (void) {
  // TODO: Check new value against limits and set the value
  //Serial.println("Heater Target Temperature Up button pressed");
  HeaterTargetTemperature = Check_Heater_Target_Temperature_Limits(HeaterTargetTemperature + 0.1);
  TextArr_SettingsScreen[TEXT_SETTINGS_H_T_T_PT4_INDEX].FloatVar = (uint16_t)(HeaterTargetTemperature * FloatVarScaling); // Update screen value and scale x10
  //Serial.println(TextArr_SettingsScreen[TEXT_SETTINGS_H_T_T_PT4_INDEX].FloatVar);
}
void ButtonHandler_Settings_H_T_T_Value_Down (void) {
  // TODO: Check new value against limits and set the value
  //Serial.println("Heater Target Temperature Down button pressed");
  HeaterTargetTemperature = Check_Heater_Target_Temperature_Limits(HeaterTargetTemperature - 0.1);
  TextArr_SettingsScreen[TEXT_SETTINGS_H_T_T_PT4_INDEX].FloatVar = (uint16_t)(HeaterTargetTemperature * FloatVarScaling);
}
// Updates the logic for the screen
void UpdateScreenLogic_SettingsScreen(void) {
}
/*
 *
  Settings Screen
 *
 */


/*
 *
  Keypad Screen
 *
 */
// Buttons
Adafruit_GFX_Button GFX_Button_Keypad_Cancel;
Adafruit_GFX_Button GFX_Button_Keypad_Num_0;
Adafruit_GFX_Button GFX_Button_Keypad_Num_1;
Adafruit_GFX_Button GFX_Button_Keypad_Num_2;
Adafruit_GFX_Button GFX_Button_Keypad_Num_3;
Adafruit_GFX_Button GFX_Button_Keypad_Num_4;
Adafruit_GFX_Button GFX_Button_Keypad_Num_5;
Adafruit_GFX_Button GFX_Button_Keypad_Num_6;
Adafruit_GFX_Button GFX_Button_Keypad_Num_7;
Adafruit_GFX_Button GFX_Button_Keypad_Num_8;
Adafruit_GFX_Button GFX_Button_Keypad_Num_9;
Adafruit_GFX_Button GFX_Button_Keypad_Delete;
Adafruit_GFX_Button GFX_Button_Keypad_Enter;
LCD_Button ButtonsArr_KeypadScreen[BUTTON_KEYPAD_ARRAY_NUM] = {
  { // Cancel Button
    "Cancel",
    ButtonHandler_Keypad_Cancel,
    GFX_Button_Keypad_Cancel,
    {BUTTON_KEYPAD_CANCEL_X,BUTTON_KEYPAD_CANCEL_Y},
    {BUTTON_KEYPAD_CANCEL_WIDTH, BUTTON_KEYPAD_CANCEL_HEIGHT},
    BUTTON_KEYPAD_CANCEL_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_CANCEL_TEXT_COLOUR,
    BUTTON_KEYPAD_CANCEL_BORDER_COLOUR,
    BUTTON_KEYPAD_CANCEL_WIDTH_SACLE,
    BUTTON_KEYPAD_CANCEL_HEIGHT_SACLE,
    BUTTON_KEYPAD_CANCEL_DEFAULT_AVAILABLE
  },
  { // Num 0 Button
    "0",
    ButtonHandler_Keypad_Num_0,
    GFX_Button_Keypad_Num_0,
    {BUTTON_KEYPAD_NUM_0_X,BUTTON_KEYPAD_NUM_0_Y},
    {BUTTON_KEYPAD_NUM_0_WIDTH, BUTTON_KEYPAD_NUM_0_HEIGHT},
    BUTTON_KEYPAD_NUM_0_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_0_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_0_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_0_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_0_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_0_DEFAULT_AVAILABLE
  },
  { // Num 1 Button
    "1",
    ButtonHandler_Keypad_Num_1,
    GFX_Button_Keypad_Num_1,
    {BUTTON_KEYPAD_NUM_1_X,BUTTON_KEYPAD_NUM_1_Y},
    {BUTTON_KEYPAD_NUM_1_WIDTH, BUTTON_KEYPAD_NUM_1_HEIGHT},
    BUTTON_KEYPAD_NUM_1_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_1_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_1_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_1_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_1_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_1_DEFAULT_AVAILABLE
  },
  { // Num 2 Button
    "2",
    ButtonHandler_Keypad_Num_2,
    GFX_Button_Keypad_Num_2,
    {BUTTON_KEYPAD_NUM_2_X,BUTTON_KEYPAD_NUM_2_Y},
    {BUTTON_KEYPAD_NUM_2_WIDTH, BUTTON_KEYPAD_NUM_2_HEIGHT},
    BUTTON_KEYPAD_NUM_2_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_2_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_2_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_2_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_2_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_2_DEFAULT_AVAILABLE
  },
  { // Num 3 Button
    "3",
    ButtonHandler_Keypad_Num_3,
    GFX_Button_Keypad_Num_3,
    {BUTTON_KEYPAD_NUM_3_X,BUTTON_KEYPAD_NUM_3_Y},
    {BUTTON_KEYPAD_NUM_3_WIDTH, BUTTON_KEYPAD_NUM_3_HEIGHT},
    BUTTON_KEYPAD_NUM_3_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_3_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_3_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_3_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_3_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_3_DEFAULT_AVAILABLE
  },
  { // Num 4 Button
    "4",
    ButtonHandler_Keypad_Num_4,
    GFX_Button_Keypad_Num_4,
    {BUTTON_KEYPAD_NUM_4_X,BUTTON_KEYPAD_NUM_4_Y},
    {BUTTON_KEYPAD_NUM_4_WIDTH, BUTTON_KEYPAD_NUM_4_HEIGHT},
    BUTTON_KEYPAD_NUM_4_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_4_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_4_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_4_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_4_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_4_DEFAULT_AVAILABLE
  },
  { // Num 5 Button
    "5",
    ButtonHandler_Keypad_Num_5,
    GFX_Button_Keypad_Num_5,
    {BUTTON_KEYPAD_NUM_5_X,BUTTON_KEYPAD_NUM_5_Y},
    {BUTTON_KEYPAD_NUM_5_WIDTH, BUTTON_KEYPAD_NUM_5_HEIGHT},
    BUTTON_KEYPAD_NUM_5_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_5_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_5_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_5_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_5_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_5_DEFAULT_AVAILABLE
  },
  { // Num 6 Button
    "6",
    ButtonHandler_Keypad_Num_6,
    GFX_Button_Keypad_Num_6,
    {BUTTON_KEYPAD_NUM_6_X,BUTTON_KEYPAD_NUM_6_Y},
    {BUTTON_KEYPAD_NUM_6_WIDTH, BUTTON_KEYPAD_NUM_6_HEIGHT},
    BUTTON_KEYPAD_NUM_6_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_6_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_6_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_6_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_6_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_6_DEFAULT_AVAILABLE
  },
  { // Num 7 Button
    "7",
    ButtonHandler_Keypad_Num_7,
    GFX_Button_Keypad_Num_7,
    {BUTTON_KEYPAD_NUM_7_X,BUTTON_KEYPAD_NUM_7_Y},
    {BUTTON_KEYPAD_NUM_7_WIDTH, BUTTON_KEYPAD_NUM_7_HEIGHT},
    BUTTON_KEYPAD_NUM_7_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_7_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_7_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_7_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_7_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_7_DEFAULT_AVAILABLE
  },
  { // Num 8 Button
    "8",
    ButtonHandler_Keypad_Num_8,
    GFX_Button_Keypad_Num_8,
    {BUTTON_KEYPAD_NUM_8_X,BUTTON_KEYPAD_NUM_8_Y},
    {BUTTON_KEYPAD_NUM_8_WIDTH, BUTTON_KEYPAD_NUM_8_HEIGHT},
    BUTTON_KEYPAD_NUM_8_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_8_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_8_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_8_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_8_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_8_DEFAULT_AVAILABLE
  },
  { // Num 9 Button
    "9",
    ButtonHandler_Keypad_Num_9,
    GFX_Button_Keypad_Num_9,
    {BUTTON_KEYPAD_NUM_9_X,BUTTON_KEYPAD_NUM_9_Y},
    {BUTTON_KEYPAD_NUM_9_WIDTH, BUTTON_KEYPAD_NUM_9_HEIGHT},
    BUTTON_KEYPAD_NUM_9_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_NUM_9_TEXT_COLOUR,
    BUTTON_KEYPAD_NUM_9_BORDER_COLOUR,
    BUTTON_KEYPAD_NUM_9_WIDTH_SACLE,
    BUTTON_KEYPAD_NUM_9_HEIGHT_SACLE,
    BUTTON_KEYPAD_NUM_9_DEFAULT_AVAILABLE
  },
  { // Delete Button
    "DEL",
    ButtonHandler_Keypad_Delete,
    GFX_Button_Keypad_Delete,
    {BUTTON_KEYPAD_DELETE_X,BUTTON_KEYPAD_DELETE_Y},
    {BUTTON_KEYPAD_DELETE_WIDTH, BUTTON_KEYPAD_DELETE_HEIGHT},
    BUTTON_KEYPAD_DELETE_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_DELETE_TEXT_COLOUR,
    BUTTON_KEYPAD_DELETE_BORDER_COLOUR,
    BUTTON_KEYPAD_DELETE_WIDTH_SACLE,
    BUTTON_KEYPAD_DELETE_HEIGHT_SACLE,
    BUTTON_KEYPAD_DELETE_DEFAULT_AVAILABLE
  },
  { // Enter Button
    "Enter",
    ButtonHandler_Keypad_Enter,
    GFX_Button_Keypad_Enter,
    {BUTTON_KEYPAD_ENTER_X,BUTTON_KEYPAD_ENTER_Y},
    {BUTTON_KEYPAD_ENTER_WIDTH, BUTTON_KEYPAD_ENTER_HEIGHT},
    BUTTON_KEYPAD_ENTER_BACKGROUND_COLOUR,
    BUTTON_KEYPAD_ENTER_TEXT_COLOUR,
    BUTTON_KEYPAD_ENTER_BORDER_COLOUR,
    BUTTON_KEYPAD_ENTER_WIDTH_SACLE,
    BUTTON_KEYPAD_ENTER_HEIGHT_SACLE,
    BUTTON_KEYPAD_ENTER_DEFAULT_AVAILABLE
  }
};

/* Texts */
LCD_Text TextArr_KeypadScreen[TEXT_KEYPAD_ARRAY_NUM] = {
  { // Title
    "", // No default text as it depends on what calls it
    nullptr, // No text variable being used
    TEXT_KEYPAD_TITLE_DEFAULT_FLOAT_VAL,
    {TEXT_KEYPAD_TITLE_X, TEXT_DATA_TITLE_Y},
    TEXT_KEYPAD_TITLE_BACKGROUND_COLOUR,
    TEXT_KEYPAD_TITLE_TEXT_COLOUR,
    TEXT_KEYPAD_TITLE_DEFAULT_INT_VAL,
    TEXT_KEYPAD_TITLE_FONT_SIZE,
    TEXT_KEYPAD_TITLE_VAR_TYPE
  },
  { // User's value
    "", 
    nullptr, // No text variable being used
    TEXT_KEYPAD_USER_VALUE_DEFAULT_FLOAT_VAL,
    {_X, TEXT_KEYPAD_USER_VALUE_Y},
    TEXT_KEYPAD_USER_VALUE_BACKGROUND_COLOUR,
    TEXT_KEYPAD_USER_VALUE_TEXT_COLOUR,
    TEXT_KEYPAD_USER_VALUE_DEFAULT_INT_VAL,
    TEXT_KEYPAD_USER_VALUE_FONT_SIZE,
    TEXT_KEYPAD_USER_VALUE_VAR_TYPE
  }
};

// Rectangle colours
/* No rectangles are drawn therefore no colours needed
uint16_t RectangleColours_SettingsScreen[] = { 
  // Heater target temperature value highlight (H_T_T_VAL)
  ILI9341_DARKGREY // Index 0 is default colour
};

// Rectangle shapes
LCD_Rectangle RectanglesArr_SettingsScreen[RECTANGLE_SETTINGS_ARRAY_NUM] = {
  RectangleColours_SettingsScreen,
  {RECTANGLE_SETTINGS_H_T_T_VALUE_X, RECTANGLE_SETTINGS_H_T_T_VALUE_Y},
  {RECTANGLE_SETTINGS_H_T_T_VALUE_WIDTH, RECTANGLE_SETTINGS_H_T_T_VALUE_HEIGHT},
  RECTANGLE_SETTINGS_H_T_T_VALUE_ARRAY_GREY_INDEX // Default colour
};*/

// Circle colours
/* No circles are drawn therefore no colours needed
uint16_t CircleColours_SettingsScreen[2] = { 
};

// Circle shapes
/* No circles are drawn
LCD_Circle CirclesArr_DataScreen[CIRCLE_DATA_ARRAY_NUM] = {
  { // Heater on/off LED
    CircleColours_DataScreen,
    {CIRCLE_SETTINGS_[Circle name here]_X, CIRCLE_SETTINGS_[Circle name here]_Y},
    CIRCLE_SETTINGS_[Circle name here]_RADIUS,
    CIRCLE_SETTINGS_[Circle name here]_ARRAY_INDEX // Default colour
  }
};*/

// Screen Data
LCD_Screen_Data ScreenData_Keypad = {
  ButtonsArr_KeypadScreen,
  TextArr_KeypadScreen,
  nullptr, // No rectangles to be drawn
  nullptr, // No circles to be drawn
  UpdateScreenLogic_KeypadScreen,
  SCREEN_KEYPAD_BACKGROUND_COLOUR,
  BUTTON_KEYPAD_ARRAY_NUM,
  TEXT_KEYPAD_ARRAY_NUM,
  RECTANGLE_KEYPAD_ARRAY_NUM,
  CIRCLE_KEYPAD_ARRAY_NUM,
  ENUM_MENU_KEYPAD_SCREEN
};

// Button Hanlders
void ButtonHandler_Keypad_Cancel(void) {
}
void ButtonHandler_Keypad_Num_0(void) {
}
void ButtonHandler_Keypad_Num_1(void) {
}
void ButtonHandler_Keypad_Num_2(void) {
}
void ButtonHandler_Keypad_Num_3(void) {
}
void ButtonHandler_Keypad_Num_4(void) {
}
void ButtonHandler_Keypad_Num_5(void) {
}
void ButtonHandler_Keypad_Num_6(void) {
}
void ButtonHandler_Keypad_Num_7(void) {
}
void ButtonHandler_Keypad_Num_8(void) {
}
void ButtonHandler_Keypad_Num_9(void) {
}
void ButtonHandler_Keypad_Delete(void) {
}
void ButtonHandler_Keypad_Enter(void) {
}

// Updates the logic for the screen
void UpdateScreenLogic_KeypadScreen(void) {
}
/*
 *
  Keypad Screen
 *
 */