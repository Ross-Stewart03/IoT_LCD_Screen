// For all screens, buttons and texts
#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

//TODO: below needs to be seprate handlers for each button. Need to make struct take these functions so they can be called if user touches the button
/*
  Main Menu Screen
*/
// TODO: Populate with what Main Menu actually needs, just name swapped definitions

// Button Hanlders
// Takes user to the Data screen
void ButtonHandler_MainMenu_DataScreenSelect (void) {
  Serial.println("Data Button Hanlder");
  Previous_Menu_Screen = Current_Menu_Screen;
  Current_Menu_Screen = ENUM_MENU_DATA_SCREEN;
}
// Takes user to the Limits Settings screen
void ButtonHandler_MainMenu_LimitsSettingScreenSelect (void) {
  Serial.println("Limits Setting Button Hanlder");
  Previous_Menu_Screen = Current_Menu_Screen;
  Current_Menu_Screen = ENUM_MENU_LIMITS_SETTINGS_SCREEN;
}

// Updates the logic for the screen
void UpdateScreenLogic_MainMenu (void) {
  // Do nothing, Main Menu has no non button related logic
}

// Buttons
Adafruit_GFX_Button GFX_Button_Main_Menu_Screen;
Adafruit_GFX_Button GFX_Button_Limits_Settings_Screen;
LCD_Button ButtonsArr_MainMenuScreen[BUTTONS_DATA_ARRAY_NUM] = { 
  { // Data Select
    "Data",
    &ButtonHandler_MainMenu_DataScreenSelect,
    GFX_Button_Main_Menu_Screen,
    {BUTTON_MAIN_MENU_DATA_SELECT_X,BUTTON_MAIN_MENU_DATA_SELECT_Y},
    {BUTTON_MAIN_MENU_DATA_SELECT_WIDTH, BUTTON_MAIN_MENU_DATA_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_DATA_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_DATA_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_DATA_SELECT_BORDER_COLOUR,
    TEXT_MAIN_MENU_DATA_SELECT_WIDTH_SACLE,
    TEXT_MAIN_MENU_DATA_SELECT_HEIGHT_SACLE,
  },
  { // Limits Setting Select
    "Limits",
    &ButtonHandler_MainMenu_LimitsSettingScreenSelect,
    GFX_Button_Main_Menu_Screen,
    {BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_X,BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_Y},
    {BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH, BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BORDER_COLOUR,
    TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH_SACLE,
    TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT_SACLE,
  }
};

// Texts
LCD_Text TextArr_MainMenuScreen[TEXT_DATA_ARRAY_NUM] = {
  { // Title
    "Main Menu",
    TEXT_MAIN_MENU_TITLE_DEFAULT_FLOAT_VAL,
    {TEXT_MAIN_MENU_TITLE_X, TEXT_MAIN_MENU_TITLE_Y},
    TEXT_MAIN_MENU_TITLE_BACKGROUND_COLOUR,
    TEXT_MAIN_MENU_TITLE_TEXT_COLOUR,
    TEXT_MAIN_MENU_TITLE_DEFAULT_INT_VAL,
    TEXT_MAIN_MENU_TITLE_FONT_SIZE,
    LCD_TEXT_VAR_TYPE_NONE
  }
};

// Rectangle colours
/* No rectangles are drawn therefore no colours needed uint16_t RectangleColours_MainMenuScreen = { 
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
/* No rectangles are drawn here LCD_Rectangle RectanglesArr_MainMenuScreen[RECTANGLE_MAIN_MENU_ARRAY_NUM] = {
  &RectangleColours_MainMenuScreen,
  {RECTANGLE_MAIN_MENU_[Rectangle name here]_X, RECTANGLE_MAIN_MENU_[Rectangle name here]_Y},
  {RECTANGLE_MAIN_MENU_[Rectangle name here]_WIDTH, RECTANGLE_MAIN_MENU_[Rectangle name here]_HEIGHT},
  0 // Default colour
};*/

// Circle colours
/* No circles are drawn therefore no colours needed uint16_t CircleColours_MainMenuScreen =
// Index 0 is default colour
{ 
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
/* No Cirlces are drawn here LCD_Circle CirclesArr_MainMenuScreen[CIRCLE_MAIN_MENU_ARRAY_NUM] = {
  &RectangleColours_MainMenuScreen,
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
/*
  Main Menu Screen
*/



/*
  Data Screen
*/
// TODO: Populate with what Data actually needs, just name swapped definitions
// Need to define all limits of Min and Max for all setting limits(e.g. Thermostat threshold can't be more than 100C)
// Need to add special buttons to allow user click on the value so they can manually enter the value through the keypad, The button should be same colour as the background and no text
// Both of the above need to be added to the general structs, to allow a generic format 

// Possible colours for on screen LED
uint16_t LCDLEDColoursArr[LCD_LED_COLOURS_NUM] = {
  ILI9341_RED,
  ILI9341_GREEN
};
/*
  Data Screen
*/


/*
  Unlock/lock Screen
*/
 //TODO: Populate with what Unlock/lock actually needs, just name swapped definitions
/*
  Unlock/lock Screen
*/

/*
  Keypad Screen
*/
 //TODO: Populate with what Keypad actually needs, just name swapped definitions
 // The "Back" button here needs to be "Cancel"

/*
  Keypad Screen
*/