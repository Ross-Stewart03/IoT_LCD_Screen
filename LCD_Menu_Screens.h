// For all screens, buttons and texts

/*
  Need to make enum for the menu system, make sure to have defaults in place.
  struct that has all data about the menu, NO. Buttons, Array of all buttons, screen background colour, ....
  struct for buttons to have all data about them stored, background/text colour, position, size, message, being shown?, ....
  struct for text to have all data about them stored, background/text colour, position, size, message, variables, ....
*/

#ifndef  LCD_MENU_SCREENS_H_
#define LCD_MENU_SCREENS_H_

#include <stdint.h>
#include "LCD_Main.h"

// Extra spacing for positioning of objects
#define SPACING_5_PIXELS   5
#define SPACING_10_PIXELS  10
#define SPACING_15_PIXELS  15
#define SPACING_20_PIXELS  20

/*
 *
 Back Button
 *
*/
/* LCD_Button */
#define BUTTON_BACK_X                  30
#define BUTTON_BACK_Y                  12
#define BUTTON_BACK_WIDTH              60
#define BUTTON_BACK_HEIGHT             24
#define BUTTON_BACK_BACKGROUND_COLOUR  ILI9341_BLUE
#define BUTTON_BACK_TEXT_COLOUR        ILI9341_WHITE
#define BUTTON_BACK_BORDER_COLOUR      ILI9341_BLUE
#define BUTTON_BACK_WIDTH_SACLE        1
#define BUTTON_BACK_HEIGHT_SACLE       1

// Button Handlers
void ButtonHandler_Back_Button (void);
/*
 *
 Back Button
 *
 */

// TODO: Need to be able to hav a "pop-up" that lets user know they can't access/change a value until they unlock the device


//  Macro naming convension: [Object]_[Menu screen name]_[Specified name]_[Atribute], e.g. [BUTTON]_[MAIN_MENU]_[DATA_SCREEN]_[X]

/*
 *
 Main Menu Screen
 *
 */
/* Indexes */
// Buttons
#define BUTTON_MAIN_MENU_DATA_SELECT_ARRAY_INDEX              0
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_ARRAY_INDEX   1
#define BUTTON_MAIN_MENU_ARRAY_NUM                            2
// Texts
#define TEXT_MAIN_MENU_TITLE_SELECT_ARRAY_INDEX   0
#define TEXT_MAIN_MENU_ARRAY_NUM                  1 
// Rectangles
//#define RECTANGLE_MAIN_MENU_[Specified name here]_ARRAY_INDEX   [Value here]
#define RECTANGLE_MAIN_MENU_ARRAY_NUM  0
//#define RECTANGLE_MAIN_MENU_[Specified name here]_[Colour 1]    [Value here]
//#define RECTANGLE_MAIN_MENU_[Specified name here]_INDEX         [Value here]
// Circles
//#define CIRCLE_MAIN_MENU_[Specified name here]_ARRAY_INDEX  [Value here]
#define CIRCLE_MAIN_MENU_ARRAY_NUM  0
//#define CIRLCE_MAIN_MENU_[Specified name here]_[Colour 1]   [Value here]
//#define CIRCLE_MAIN_MENU_[Specified name here]_INDEX        [Value here]

/* LCD_Button */
// Data
#define BUTTON_MAIN_MENU_DATA_SELECT_X                  100
#define BUTTON_MAIN_MENU_DATA_SELECT_Y                  70
#define BUTTON_MAIN_MENU_DATA_SELECT_WIDTH              100
#define BUTTON_MAIN_MENU_DATA_SELECT_HEIGHT             40
#define BUTTON_MAIN_MENU_DATA_SELECT_BACKGROUND_COLOUR  ILI9341_BLUE
#define BUTTON_MAIN_MENU_DATA_SELECT_TEXT_COLOUR        ILI9341_WHITE
#define BUTTON_MAIN_MENU_DATA_SELECT_BORDER_COLOUR      ILI9341_BLUE
#define TEXT_MAIN_MENU_DATA_SELECT_WIDTH_SACLE          2
#define TEXT_MAIN_MENU_DATA_SELECT_HEIGHT_SACLE         2
// Limits Settings
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_X                  100
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_Y                  130
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH              100
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT             40
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BACKGROUND_COLOUR  ILI9341_BLUE
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_TEXT_COLOUR        ILI9341_WHITE
#define BUTTON_MAIN_MENU_LIMITS_SETTINGS_SELECT_BORDER_COLOUR      ILI9341_BLUE
#define TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_WIDTH_SACLE          2
#define TEXT_MAIN_MENU_LIMITS_SETTINGS_SELECT_HEIGHT_SACLE         2

/* LCD_Text */
// Title
#define TEXT_MAIN_MENU_TITLE_DEFAULT_FLOAT_VAL  0 // Stored value is x10 of actual
#define TEXT_MAIN_MENU_TITLE_X                  30
#define TEXT_MAIN_MENU_TITLE_Y                  5
#define TEXT_MAIN_MENU_TITLE_BACKGROUND_COLOUR  ILI9341_BLACK
#define TEXT_MAIN_MENU_TITLE_TEXT_COLOUR        ILI9341_WHITE
#define TEXT_MAIN_MENU_TITLE_DEFAULT_INT_VAL    0
#define TEXT_MAIN_MENU_TITLE_FONT_SIZE          3

/* LCD_Rectangle */
// Rectangle 1
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_X       [Value here]
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_Y       [Value here]
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_WIDTH   [Value here]
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_HEIGHT  [Value here]

/* LCD_Circle */
// Circle 1
//#define CIRCLE_MAIN_MENU_[Circle name here]_X       [Value here]
//#define CIRCLE_MAIN_MENU_[Circle name here]_Y       [Value here]
//#define CIRCLE_MAIN_MENU_[Circle name here]_RADIUS  [Value here]

// LCD_Screen_Data
#define SCREEN_MAIN_MENU_BACKGROUND_COLOUR    ILI9341_BLACK

// Global Varibles/Structs
extern LCD_Screen_Data ScreenData_MainMenu;

// Button Handlers
void ButtonHandler_MainMenu_DataScreenSelect (void);
void ButtonHandler_MainMenu_LimitsSettingsScreenSelect (void);

// Update Screen Logic
//void UpdateScreenLogic_MainMenu (void);
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
/* Indexes */
// Buttons
#define BUTTON_DATA_BACK_BUTTON_ARRAY_INDEX   0
#define BUTTON_DATA_ARRAY_NUM                 1
// Texts
#define TEXT_DATA_TITLE_ARRAY_INDEX   0
#define TEXT_DATA_ARRAY_NUM           1 
// Rectangles
//#define RECTANGLE_DATA_[Specified name here]_ARRAY_INDEX      [Value here]
#define RECTANGLE_DATA_ARRAY_NUM  0
//#define RECTANGLE_DATA_MENU_[Specified name here]_ARRAY_[Colour 1]  [Value here]
//#define RECTANGLE_DATA_MENU_[Specified name here]_ARRAY_NUM       [Value here]
// Circles
#define CIRCLE_DATA_HEATER_ARRAY_INDEX  0
#define CIRCLE_DATA_ARRAY_NUM           1
#define CIRCLE_DATA_HEATER_ARRAY_RED_INDEX    0
#define CIRCLE_DATA_HEATER_ARRAY_GREEN_INDEX  1
#define CIRCLE_DATA_HEADER_ARRAY_NUM          2

/* LCD_Button */
// [Button Name]
/*#define BUTTON__DATA_[Button Name]_X                100
#define BUTTON_DATA_[Button Name]_Y                   70
#define BUTTON_DATA_[BUTTON Name]_WIDTH               100
#define BUTTON_DATA_[BUTTON Name]_HEIGHT              40
#define BUTTON_DATA_[BUTTON Name]_BACKGROUND_COLOUR   ILI9341_BLUE
#define BUTTON_DATA_[BUTTON Name]_TEXT_COLOUR         ILI9341_WHITE
#define BUTTON_DATA_[BUTTON Name]_BORDER_COLOUR       ILI9341_BLUE
#define BUTTON_DATA_[BUTTON Name]_WIDTH_SACLE         2
#define BUTTON_DATA_[BUTTON Name]_HEIGHT_SACLE        2 */

/* LCD_Text */
// Title
#define TEXT_DATA_TITLE_DEFAULT_FLOAT_VAL   0 // Stored value is x10 of actual
#define TEXT_DATA_TITLE_X                   BUTTON_BACK_X + BUTTON_BACK_WIDTH + SPACING_15_PIXELS
#define TEXT_DATA_TITLE_Y                   5
#define TEXT_DATA_TITLE_BACKGROUND_COLOUR   ILI9341_BLACK
#define TEXT_DATA_TITLE_TEXT_COLOUR         ILI9341_WHITE
#define TEXT_DATA_TITLE_DEFAULT_INT_VAL     0
#define TEXT_DATA_TITLE_FONT_SIZE           3
// Heater
#define TEXT_DATA_HEATER_DEFAULT_FLOAT_VAL  0 // Stored value is x10 of actual
#define TEXT_DATA_HEATER_X                  100
#define TEXT_DATA_HEATER_Y                  70
#define TEXT_DATA_HEATER_BACKGROUND_COLOUR  ILI9341_BLACK
#define TEXT_DATA_HEATER_TEXT_COLOUR        ILI9341_WHITE
#define TEXT_DATA_HEATER_DEFAULT_INT_VAL    0
#define TEXT_DATA_HEATER_FONT_SIZE          2
// Humidity
#define TEXT_DATA_HEATER_DEFAULT_FLOAT_VAL    0 // Stored value is x10 of actual
#define TEXT_DATA_HUMIDITY_X                  100
#define TEXT_DATA_HUMIDITY_Y                  100
#define TEXT_DATA_HUMIDITY_BACKGROUND_COLOUR  ILI9341_BLACK
#define TEXT_DATA_HUMIDITY_TEXT_COLOUR        ILI9341_WHITE
#define TEXT_DATA_HUMIDITY_DEFAULT_INT_VAL    0
#define TEXT_DATA_HUMIDITY_FONT_SIZE          2

/* LCD_Rectangle */
// Rectangle 1
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_X       [Value here]
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_Y       [Value here]
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_WIDTH   [Value here]
//#define RECTANGLE_MAIN_MENU_[Rectangle name here]_HEIGHT  [Value here]

/* LCD_Circle */
// Heater
#define CIRCLE_DATA_HEATER_ON_OFF_LED_X       200
#define CIRCLE_DATA_HEATER_ON_OFF_LED_Y       150
#define CIRCLE_DATA_HEATER_ON_OFF_LED_RADIUS  20

// LCD_Screen_Data
#define SCREEN_DATA_BACKGROUND_COLOUR    ILI9341_BLACK

// Global Variables
extern LCD_Screen_Data ScreenData_Data;
extern uint8_t HeaterState;
extern uint8_t Temperature;
extern uint8_t Humidity;

// Button Handlers
//void ButtonHandler_Data_[Button Handler Name] (void);

// Update Screen Logic
void UpdateScreenLogic_MainMenu (void);
/*
 *
 Data Screen
 *
 */


/*
 *
 Limits Settings Screen
 *
 */
// TODO: User needs to be asked for a password before they are able to enter this menu
// Button sizes
#define BUTTON_LIMITS_SETTINGS_INCREMENT_WIDTH  40
#define BUTTON_LIMITS_SETTINGS_INCREMENT_HEIGHT 40
#define BUTTON_LIMITS_SETTINGS_DECREMENT_WIDTH  40
#define BUTTON_LIMITS_SETTINGS_DECREMENT_HEIGHT 40
#define BUTTON_LIMITS_SETTINGS_KEYPAD_WIDTH     80
#define BUTTON_LIMITS_SETTINGS_KEYPAD_HEIGHT    40

// Button positions
#define BUTTON_LIMITS_SETTINGS_INCREMENT_X  40
#define BUTTON_LIMITS_SETTINGS_INCREMENT_Y  40
#define BUTTON_LIMITS_SETTINGS_DECREMENT_X  BUTTON_INCREMENT_X + (BUTTON_INCREMENT_WIDTH / 2) + SPACING_5_PIXELS
#define BUTTON_LIMITS_SETTINGS_DECREMENT_Y  BUTTON_INCREMENT_Y
#define BUTTON_LIMITS_SETTINGS_KEYPAD_X     BUTTON_DECREMENT_X + (BUTTON_DECREMENT_WIDTH / 2) + SPACING_15_PIXELS
#define BUTTON_LIMITS_SETTINGS_KEYPAD_Y     BUTTON_INCREMENT_Y + (BUTTON_INCREMENT_HEIGHT / 2) + SPACING_5_PIXELS

// Text positions
#define TEXT_LIMITS_SETTINGS_COUNTER_LIMIT_X  BUTTON_DECREMENT_X + (BUTTON_COUNTER_WIDTH/2) + SPACING_10_PIXELS
#define TEXT_LIMITS_SETTINGS_COUNTER_LIMIT_Y  BUTTON_DECREMENT_Y - SPACING_5_PIXELS

// Button indexes
#define BUTTONS_LIMITS_SETTINGS_ARRAY_INDEX_COUNTER_LIMIT 0
#define BUTTONS_LIMITS_SETTINGS_ARRAY_INDEX_BACK          1
#define BUTTONS_LIMITS_SETTINGS_ARRAY_NUM                 2

// Text indexes
#define TEXT_LIMITS_SETTINGS_BUTTONS_ARRAY_INDEX_TITLE    0
#define TEXT_LIMITS_SETTINGS_BUTTONS_ARRAY_INDEX_COUNTER  1
#define TEXT_LIMITS_SETTINGS_BUTTONS_ARRAY_NUM            2

// Global Variables Initalisation Value
#define INIT_VALUE_SETTINGS_BUTTONS_COUNTER_LIMIT 30

// Global Variables
extern LCD_Screen_Data ScreenData_LimitsSettings;
extern uint8_t CounterLimit;
/*
 *
 Limits Settings Screen
 *
 */

/*
 *
 Keypad Screen
 *
 */
// Button sizes
#define BUTTON_KEYPAD_NUMBERS_WIDTH   60
#define BUTTON_KEYPAD_NUMBERS_HEIGHT  60
#define BUTTON_KEYPAD_CLEAR_WIDTH     80
#define BUTTON_KEYPAD_CLEAR_HEIGHT    60
#define BUTTON_KEYPAD_DELETE_WIDTH    80
#define BUTTON_KEYPAD_DELETE_HEIGHT   60
#define BUTTON_KEYPAD_ENTER_WIDTH     80
#define BUTTON_KEYPAD_ENTER_HEIGHT    60

// Button positions
#define BUTTON_KEYPAD_NUMBERS_X  60
#define BUTTON_KEYPAD_NUMBERS_Y  60
#define BUTTON_KEYPAD_CLEAR_X    BUTTON_NUMBERS_X + (3 * (BUTTON_NUMBERS_WIDTH / 2))
#define BUTTON_KEYPAD_CLEAR_Y    BUTTON_NUMBERS_Y
#define BUTTON_KEYPAD_DELETE_X   BUTTON_NUMBERS_X + (3 * (BUTTON_NUMBERS_WIDTH / 2))
#define BUTTON_KEYPAD_DELETE_Y   BUTTON_NUMBERS_Y + (BUTTON_NUMBERS_HEIGHT / 2)
#define BUTTON_KEYPAD_ENTER_X    BUTTON_NUMBERS_X + (3 * (BUTTON_NUMBERS_WIDTH / 2))
#define BUTTON_KEYPAD_ENTER_Y    BUTTON_NUMBERS_Y + (2 * (BUTTON_NUMBERS_HEIGHT / 2))

// Text positions
#define TEXT_KEYPAD_USER_NUMBER_X  60
#define TEXT_KEYPAD_USER_NUMBER_Y  45

// Button indexes
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_0    0
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_1    1
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_2    2
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_3    3
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_4    4
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_5    5
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_6    6
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_7    7
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_8    8
#define BUTTONS_KEYPAD_ARRAY_INDEX_NUM_9    9
#define BUTTONS_KEYPAD_ARRAY_INDEX_CLEAR    10
#define BUTTONS_KEYPAD_ARRAY_INDEX_DELETE   11
#define BUTTONS_KEYPAD_ARRAY_INDEX_ENTER    12
#define BUTTONS_KEYPAD_ARRAY_INDEX_BACK     13
#define BUTTONS_KEYPAD_ARRAY_NUM            14

// Text indexes
#define TEXT_KEPAD_ARRAY_INDEX_TITLE    0
#define TEXT_KEPAD_ARRAY_INDEX_COUNTER  1
#define TEXT_KEPAD_ARRAY_NUM            2

// Global variables
extern LCD_Screen_Data ScreenData_Keypad;
extern uint16_t UserNumber;
/*
 *
 Keypad Screen
 *
 */

#endif // LCD_MENU_SCREENS_H_