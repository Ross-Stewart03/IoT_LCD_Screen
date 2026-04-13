// For the general program use
#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

// Initalises all the buttons from all screens
void Buttons_Init(void) {
  Screen_Buttons_Init(ScreenData_MainMenu);
  Screen_Buttons_Init(ScreenData_TestButtons);
  Screen_Buttons_Init(ScreenData_Keypad);
}

// Initialises all the buttons for a given screen
void Screen_Buttons_Init(LCD_Screen_Data Screen) {
  for (uint8_t i = 0; i < Screen.ButtonsNum; i++) {
    // All attributes of the button
    Screen.ScreenButtonsArr[i].gfx.initButton(&tft,
                                              Screen.ScreenButtonsArr[i].Position.x, Screen.ScreenButtonsArr[i].Position.y,
                                              Screen.ScreenButtonsArr[i].Size.Width, Screen.ScreenButtonsArr[i].Size.Height,
                                              Screen.ScreenButtonsArr[i].BorderColour, Screen.ScreenButtonsArr[i].TextColour, Screen.ScreenButtonsArr[i].FillColour,
                                              Screen.ScreenButtonsArr[i].Text, Screen.ScreenButtonsArr[i].TextWidthScale, Screen.ScreenButtonsArr[i].TextHeightScale);
  // Doesn't draw the button
  Screen.ScreenButtonsArr[i].gfx.drawButton(false);
  }
}

// Initalises the menu for main menu on start
void Menu_Init(void) {
  Previous_Menu_Screen  = ENUM_MENU_MAIN_MENU_SCREEN;
  Current_Menu_Screen   = ENUM_MENU_MAIN_MENU_SCREEN;
  LCDScreenData_Current = &ScreenData_MainMenu; 

  /*
  // TODO:

  Set CurrentButtonsArr to Main menu ones

  anything else need init for menu stuff?
  */
}

void Adafruit_Screen_Init(void) {  
  // start the touchscreen and the tft screen and make the screen black
  ts.begin();
  tft.begin();
  tft.setRotation(1);
  Print_Diagnostics();
  tft.fillScreen(ILI9341_BLACK);
}

// Prints text to the LCD screen
void LCD_Print_Text(char *Text, uint16_t x, uint16_t y, uint16_t FillColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(FillColour, TextColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
}

// Prints text to the LCD screen with an integer variable
void LCD_Print_Int(char *Text, uint16_t x, uint16_t y, uint16_t IntVar, uint16_t FillColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(FillColour, TextColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
  tft.print(IntVar);
}

// Prints text to the LCD screen with a float variable
void LCD_Print_Float(char *Text, uint16_t x, uint16_t y, float FloatVar, uint16_t FillColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(FillColour, TextColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
  tft.print(FloatVar);
}

// Gets the coordinates of where the user touched the screen(If screen was touched)
void Touch_Position_Update_Buttons(void) {
  if (ts.touched()) {
    // Gets position of where user touched the screen
    TS_Point p = ts.getPoint();
    // Maps the position to be sideways
    LCD_Touch_Position.x = tft.width() - p.y;
    LCD_Touch_Position.y = p.x;

    for (int i = 0; i < LCDScreenData_Current->ButtonsNum; i++) {
      CurrentButtonsArr[i]->gfx.press(CurrentButtonsArr[i]->gfx.contains(LCD_Touch_Position.x, LCD_Touch_Position.y)); // Checks if user's touch position matches the corresponding button position. Updates 'justPress()'
      // Checks if user pressed the button, then calls its handler
      if (CurrentButtonsArr[i]->gfx.justPressed()) { 
        CurrentButtonsArr[i]->ButtonHandler();
      }
    }
  }
  else {
    for (int i = 0; i < MAX_NUM_BUTTONS; i++) {
      CurrentButtonsArr[i]->gfx.press(false);
    }
  }
}


// Updates all graphic on the screen(Text and shapes)
void Update_Screen_Graphics(void) {
// Which ever object is draw last will be on top.
  uint i = 0;
 
  // Updates all rectangles on the screen
  for (i = 0; i < LCDScreenData_Current->RectanglesNum; i++) {
    tft.fillRect(LCDScreenData_Current->RectanglesArr[i].Position.x, LCDScreenData_Current->RectanglesArr[i].Position.y,
                 LCDScreenData_Current->RectanglesArr[i].Size.Width, LCDScreenData_Current->RectanglesArr[i].Size.Height, 
                 LCDScreenData_Current->RectanglesArr[i].Colours[LCDScreenData_Current->RectanglesArr[i].CurrentColourIndex]);
  }

  // Updates all circles on the screen
  for (i = 0; i < LCDScreenData_Current->CirclesNum; i++) {
    tft.fillCircle(LCDScreenData_Current->CirclesArr[i].Position.x, LCDScreenData_Current->CirclesArr[i].Position.y,
                   LCDScreenData_Current->CirclesArr[i].Radius,
                   LCDScreenData_Current->CirclesArr[i].Colours[LCDScreenData_Current->CirclesArr[i].CurrentColourIndex]); // Selects the colour from the array based on the index of the wanted colour
  }

  // Updates all text on the screen
  for (i = 0; i < LCDScreenData_Current->TextsNum; i++) {
    switch (LCDScreenData_Current->ScreenTextArr[i].VarType) {
      case LCD_TEXT_VAR_TYPE_INT:
        LCD_Print_Int(LCDScreenData_Current->ScreenTextArr[i].Text,
                      LCDScreenData_Current->ScreenTextArr[i].Position.x, LCDScreenData_Current->ScreenTextArr[i].Position.y,
                      LCDScreenData_Current->ScreenTextArr[i].IntVar,
                      LCDScreenData_Current->ScreenTextArr[i].BackgroundColour,
                      LCDScreenData_Current->ScreenTextArr[i].TextColour,
                      LCDScreenData_Current->ScreenTextArr[i].FontSize);
        break;

      case LCD_TEXT_VAR_TYPE_FLOAT:
        LCD_Print_Float(LCDScreenData_Current->ScreenTextArr[i].Text,
                        LCDScreenData_Current->ScreenTextArr[i].Position.x, LCDScreenData_Current->ScreenTextArr[i].Position.y,
                        LCDScreenData_Current->ScreenTextArr[i].FloatVar,
                        LCDScreenData_Current->ScreenTextArr[i].BackgroundColour,
                        LCDScreenData_Current->ScreenTextArr[i].TextColour,
                        LCDScreenData_Current->ScreenTextArr[i].FontSize);
        break;

      default: // LCD_TEXT_VAR_TYPE_NON
        LCD_Print_Text(LCDScreenData_Current->ScreenTextArr[i].Text,
                       LCDScreenData_Current->ScreenTextArr[i].Position.x, LCDScreenData_Current->ScreenTextArr[i].Position.y,
                       LCDScreenData_Current->ScreenTextArr[i].BackgroundColour,
                       LCDScreenData_Current->ScreenTextArr[i].TextColour,
                       LCDScreenData_Current->ScreenTextArr[i].FontSize);
        break;
    }
  }
  /*
  UPDATE ON SCREEN TEXT, BUTTONS AND OBJECTS HERE

  Each screen needs to have its own set of bttons and on screen text that needs to contain their own coordinates and also their own colour and size.
  
  Ceate a struct for buttons and text that have the above.
  Each screen should have its own strct that contains all the buttons(In an array), All variables in another array.
  each screen in that struct with arrays of everything, including the handers 

  */
}

// Printing diagnotic infomation about the TFT LCD
void Print_Diagnostics(void) {
  uint8_t x = 0;

  x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display power mode: 0x");
  Serial.println(x, HEX);

  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL mode: 0x");
  Serial.println(x, HEX);

  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel format: 0x");
  Serial.println(x, HEX);

  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image format: 0x");
  Serial.println(x, HEX);

  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self diagnostic: 0x");
  Serial.println(x, HEX);
}