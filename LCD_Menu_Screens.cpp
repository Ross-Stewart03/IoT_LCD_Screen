// For all screens, buttons and texts
#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

//TODO: below needs to be seprate handlers for each button. Need to make struct take these functions so they can be called if user touches the button
/*
  Main Menu Screen
*/
// TODO: Populate with what Main Menu actually needs, just name swapped definitions

// Button Hanlders
// Takes user to the Test Buttons screen
void ButtonHandler_MainMenu_TestButtonsScreenSelect (void) {
  Previous_Menu_Screen = Current_Menu_Screen;
  Current_Menu_Screen = ENUM_MENU_TEST_BUTTONS_SCREEN;
}
// Takes user to the Limits Settings screen
void ButtonHandler_MainMenu_LimitsSettingScreenSelect (void) {
  Previous_Menu_Screen = Current_Menu_Screen;
  Current_Menu_Screen = ENUM_MENU_LIMITS_SETTINGS_SCREEN;
}

// Buttons
Adafruit_GFX_Button GFX_Button_Main_Menu_Screen;
Adafruit_GFX_Button GFX_Button_Limits_Settings_Screen;
LCD_Button ButtonsArr_MainMenuScreen[BUTTONS_TEST_BUTTONS_ARRAY_NUM] = { 
  { // Test Buttons Select
    "Test Buttons",
    &ButtonHandler_MainMenu_TestButtonsScreenSelect,
    GFX_Button_Main_Menu_Screen,
    {BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_X,BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_Y},
    {BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_WIDTH, BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_TEST_BUTTONS_SELECT_BORDER_COLOUR,
    TEXT_MAIN_MENU_TEST_BUTTONS_SELECT_WIDTH_SACLE,
    TEXT_MAIN_MENU_TEST_BUTTONS_SELECT_HEIGHT_SACLE,
    false // Don't show as default
  },
  { // Limits Setting Select
    "Limits Settings",
    &ButtonHandler_MainMenu_TestButtonsScreenSelect,
    GFX_Button_Main_Menu_Screen,
    {BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_X,BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_Y},
    {BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH, BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT},
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BACKGROUND_COLOUR,
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_TEXT_COLOUR,
    BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BORDER_COLOUR,
    TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH_SACLE,
    TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT_SACLE,
    false // Don't show as default
  }
};

// Texts
static const float TEXT_MAIN_MENU_TITLE_DEFAULT_FLOAT_VAL = 0.0f;
LCD_Text TextArr_MainMenuScreen[TEXT_TEST_BUTTONS_ARRAY_NUM] = {
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
LCD_Screen_Data ScreenData_MainMenuScreen = {
  ButtonsArr_MainMenuScreen,
  TextArr_MainMenuScreen,
  nullptr,  // No rectangles to be drawn
  nullptr,  // No Circles to be drawn
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
  Test Buttons Screen
*/
// TODO: Populate with what Test Buttons actually needs, just name swapped definitions

// Possible colours for on screen LED
uint16_t LCDLEDColoursArr[LCD_LED_COLOURS_NUM] = {
  ILI9341_RED,
  ILI9341_GREEN
};
/*
  Test Buttons Screen
*/


/*
  Keypad Screen
*/
// TODO: Populate with what Keypad actually needs, just name swapped definitions

/*
  Keypad Screen
*/