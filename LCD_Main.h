// For the general program use
#ifndef  LCD_MENU_MAIN_H_
#define LCD_MENU_MAIN_H_

#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>
#include <Adafruit_GFX.h>
#include <stdint.h>
#include <Wire.h>
#include <SPI.h>

// LCD touch screen pins
#define ARDUINO_PIN_TFT_DC  6
#define ARDUINO_PIN_TFT_CS  7

// LCD size
#define LCD_WIDTH   320
#define LCD_HEIGHT  240
// update inveralS time(ms)
#define GRAPHICS_UPDATE_INTERVAL    100
#define MENUS_LOGIC_UPDATE_INTERVAL 100

// Maximum number of chars in text related to buttons
#define MAX_BUTTON_TEXT_LENGTH  16 

// Maximum number of chars in general text shown on LCD screen
#define MAX_LCD_TEXT_LENGTH 20

// Maximum number of buttons availble on the screen
#define MAX_NUM_BUTTONS 12

// Maximum number of different texts availble on the screen
#define MAX_NUM_TEXT  8

// LCD Text variable types enum defines
typedef enum LCD_Text_Var_Type {
  LCD_TEXT_VAR_TYPE_NONE  = 0,
  LCD_TEXT_VAR_TYPE_INT   = 1,
  LCD_TEXT_VAR_TYPE_FLOAT = 2
}LCD_Text_Var_Type;

// Menu enum defines
typedef enum LCD_Menu {
  ENUM_MENU_MAIN_MENU_SCREEN        = 0,
  ENUM_MENU_DATA_SCREEN     = 1,
  ENUM_MENU_LIMITS_SETTINGS_SCREEN  = 2,
  ENUM_MENU_KEYPAD_SCREEN           = 3
}LCD_Menu;

typedef struct X_Y_Position {
  uint16_t x;
  uint16_t y;
}X_Y_Position;

typedef struct W_H_Size {
  uint16_t Width;
  uint16_t Height;
}W_H_Size;

typedef struct LCD_Rectangle {
  uint16_t      *Colours;
  X_Y_Position  Position;
  W_H_Size      Size;
  uint8_t       CurrentColourIndex;
}LCD_Rectangle;

typedef struct LCD_Circle {
  uint16_t      *Colours;
  X_Y_Position  Position;
  uint16_t      Radius;
  uint8_t       CurrentColourIndex;
}LCD_Circle;

// struct data about the button
// init button structure -> initButton(Adafruit_GFX *gfx, int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t outline, , uint16_t textcolor, uint16_t fill, char *label, uint8_texsize_x,  uint8_texsize_y)
typedef struct LCD_Button {
  const char            *Text;
  void                  (*ButtonHandler)(void);
  Adafruit_GFX_Button   gfx;
  X_Y_Position          Position;
  W_H_Size              Size;
  uint16_t              BackgroundColour;
  uint16_t              TextColour;
  uint16_t              BorderColour;
  uint8_t               TextWidthScale;
  uint8_t               TextHeightScale;
}LCD_Button;

// Data about the text
typedef struct LCD_Text {
  const char        *Text; // Adafuit limits this based on text width visually in pixels
  float             FloatVar;
  X_Y_Position      Position;
  uint16_t          BackgroundColour;
  uint16_t          TextColour;
  int16_t           IntVar;
  uint8_t           FontSize;
  LCD_Text_Var_Type VarType; // 0 = Non, 1 = Int, 2 = Float
}LCD_Text;

// Data about the screen being shown
typedef struct LCD_Screen_Data {
  LCD_Button    *ButtonsArr;
  LCD_Text      *TextArr;
  LCD_Rectangle *RectanglesArr;
  LCD_Circle    *CirclesArr;
  void          (*UpdateScreenLogic)(void);
  uint16_t      BackgroundColour;
  uint8_t       ButtonsNum;
  uint8_t       TextsNum;
  uint8_t       RectanglesNum;
  uint8_t       CirclesNum;
  LCD_Menu      LCDScreenMenuEnum;
}LCD_Screen_Data;

// Global varibles/structs
extern LCD_Button       *CurrentButtonsArr[MAX_NUM_BUTTONS];
extern LCD_Screen_Data  *LCDScreenData_Current;
extern X_Y_Position     LCD_Touch_Position;
extern LCD_Menu         Previous_Menu_Screen;
extern LCD_Menu         Current_Menu_Screen;
extern uint32_t         PreviousGraphicsTime;
extern uint32_t         PreviousLogicTime;
extern uint32_t         CurrentTime;
extern Adafruit_ILI9341 tft;
extern Adafruit_FT6206  ts;

// Functions
void LCD_Print_Float(const char *Text, uint16_t x, uint16_t y, float FloatVar, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize);
void LCD_Print_Int(const char *Text, uint16_t x, uint16_t y, uint16_t IntVar, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize);
void LCD_Print_Text(const char *Text, uint16_t x, uint16_t y, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize);
void Config_New_Menu_Screen (LCD_Screen_Data *Screen);
void Screen_Buttons_Init(LCD_Screen_Data *Screen);
void Touch_Position_Update_Buttons(void);
void Update_Menu_Change_Config(void);
void Update_Screen_Graphics(void);
void Adafruit_Screen_Init(void);
void Update_Screen_Logic(void);
void Print_Diagnostics(void);
void Update_Menu_Logic(void);
void Buttons_Init(void);
void Menu_Init(void);

#endif // LCD_MENU_MAIN_H_