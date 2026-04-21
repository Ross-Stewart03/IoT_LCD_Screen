// For the general program use
#include "LCD_Menu_Screens.h"
#include "LCD_Main.h"

// Initalises all the buttons from all screens
void Buttons_Init(void) {
  Screen_Buttons_Init(&ScreenData_MainMenu);
  Screen_Buttons_Init(&ScreenData_Data);
  Screen_Buttons_Init(&ScreenData_Settings);
  Screen_Buttons_Init(&ScreenData_Keypad);
}

// Initialises all the buttons for a given screen
void Screen_Buttons_Init(LCD_Screen_Data *Screen) {
  for (uint8_t i = 0; i < Screen->ButtonsNum; i++) {
    // All attributes of the button
    Screen->ButtonsArr[i].gfx.initButton(&tft,
                                         Screen->ButtonsArr[i].Position.x, Screen->ButtonsArr[i].Position.y,
                                         Screen->ButtonsArr[i].Size.Width, Screen->ButtonsArr[i].Size.Height,
                                         Screen->ButtonsArr[i].BorderColour, Screen->ButtonsArr[i].BackgroundColour, Screen->ButtonsArr[i].TextColour,
                                         const_cast<char*>(Screen->ButtonsArr[i].Text), Screen->ButtonsArr[i].TextWidthScale, Screen->ButtonsArr[i].TextHeightScale);
    //Serial.print("Text Length: ");
    //Serial.println(strlen(Screen->ButtonsArr[i].Text));
  }
}

// Initalises the menu for main menu on start
void Menu_Init(void) {
  Previous_Menu_Screen  = ENUM_MENU_MAIN_MENU_SCREEN;
  Current_Menu_Screen   = ENUM_MENU_MAIN_MENU_SCREEN;
  LCDScreenData_Current = &ScreenData_MainMenu;

  // TODO: Set currrent LCD screen data.butonsArr to Main menu ones, anything else need init for menu stuff?
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
void LCD_Print_Text(const char *Text, uint16_t x, uint16_t y, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(TextColour, BackgroundColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
}

// Prints text to the LCD screen with the addition of a text variable
void LCD_Print_Text_Var(const char *Text, uint16_t x, uint16_t y, const char *TextVar, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(TextColour, BackgroundColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
  tft.print(TextVar);
}

// Prints text to the LCD screen with the addition of an int variable
void LCD_Print_Int_Var(const char *Text, uint16_t x, uint16_t y, uint16_t IntVar, const char *Units, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(TextColour, BackgroundColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
  tft.print(IntVar);
  if (Units != nullptr) {
    tft.print(Units);
  }
}

// Prints text to the LCD screen with the addition of a float variable
void LCD_Print_Float_Var(const char *Text, uint16_t x, uint16_t y, uint16_t FloatVar, const char *Units, uint16_t BackgroundColour, uint16_t TextColour, uint8_t TextSize) {
  tft.setTextColor(TextColour, BackgroundColour);
  tft.setTextSize(TextSize);
  tft.setCursor(x, y);
  tft.print(Text);
  tft.print((float)FloatVar / FloatVarScaling, 1);
  if (Units != nullptr) {
    tft.print(Units);
  }
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
      LCDScreenData_Current->ButtonsArr[i].gfx.press(LCDScreenData_Current->ButtonsArr[i].gfx.contains(LCD_Touch_Position.x, LCD_Touch_Position.y)); // Checks if user's touch position matches the corresponding button position. Updates 'justPress()'
      // Checks if user pressed the button, then calls its handler

      if (LCDScreenData_Current->ButtonsArr[i].gfx.justPressed()) {
        if (LCDScreenData_Current->ButtonsArr[i].Available) { //Need to use new LCD_Button member "Available", need this for Heater manual mode. Remeber to make Default macros on availability for LCD_Button instances
          //Still need to add in button that will be hidden by default on Data screen for heater on/off in manual mode and its macros
          LCDScreenData_Current->ButtonsArr[i].ButtonHandler();
        }
      }
    }
  }
  else {
    for (int i = 0; i < LCDScreenData_Current->ButtonsNum; i++) {
      LCDScreenData_Current->ButtonsArr[i].gfx.press(false);
    }
  }
}

// Configures the menu screen when transitioning to a new screen
void Config_New_Menu_Screen(LCD_Screen_Data *Screen) {
  LCDScreenData_Current = Screen;

  // TODO: Make "invisible" buttons(not here, don't need to be drawn), allows user to click on a value to then enter value by keypad(Going to be used for limits, means I don't need extra button showing)
  // Put "Visiable" back in, allows means I don't even need to draw the button, just check for co-ordinates 

  tft.fillScreen(Screen->BackgroundColour); // Blanks everything from previous screen

  Update_Screen_Graphics();
  
  /*
  Serial.println("*************************");
  Serial.print("Number of Buttons: ");
  Serial.println(Screen->ButtonsNum);
  Serial.println("--------------------");
  */
  // Draws all buttons on new screen
  for (uint8_t i = 0; i < Screen->ButtonsNum; i++) {
    /*
    Serial.print("Drawing button: ");
    Serial.println(Screen->ButtonsArr[i].Text);
    */
    // TODO: Put if statement to check if they are visible
    Screen->ButtonsArr[i].gfx.drawButton(false);
  }
}

// Configures the Menu system when changing between menus
void Update_Menu_Change_Config(void) {
  switch(Current_Menu_Screen) {
    // Main Menu sceen
    case ENUM_MENU_MAIN_MENU_SCREEN:
      Config_New_Menu_Screen(&ScreenData_MainMenu);
      break;

    // Data screen
    case ENUM_MENU_DATA_SCREEN:
      Config_New_Menu_Screen(&ScreenData_Data);
      break;

    // Settings screen
    case ENUM_MENU_SETTINGS_SCREEN:
      Config_New_Menu_Screen(&ScreenData_Settings);
      break;
    /*
    // Keypad screen
    case ENUM_MENU_KEYPAD_SCREEN:
      Config_New_Menu_Screen(&ScreenData_Keypad);
      break;*/

    // Error, set to known state(Main Menu)
    default:
      Serial.print("Menu System error, enum = ");
      Serial.println(Current_Menu_Screen);
      Current_Menu_Screen = ENUM_MENU_MAIN_MENU_SCREEN;
      Previous_Menu_Screen = ENUM_MENU_MAIN_MENU_SCREEN;
      break;
  }
  Update_Screen_Graphics();
}

// Contains all the logic for the screens
void Update_Screen_Logic(void) {
  if ((CurrentTime - PreviousLogicTime >= MENUS_LOGIC_UPDATE_INTERVAL) && (LCDScreenData_Current->UpdateScreenLogic != nullptr)) {
    PreviousLogicTime = CurrentTime;
    LCDScreenData_Current->UpdateScreenLogic();
  }
}

// Updates all graphic on the screen(Text and shapes)
void Update_Screen_Graphics(void) {
// Which ever object is draw last will be on top.
  uint8_t i = 0;
 
  // Draws all rectangles on the screen
  if (LCDScreenData_Current->RectanglesArr != nullptr) {
    for (i = 0; i < LCDScreenData_Current->RectanglesNum; i++) {
      tft.fillRect(LCDScreenData_Current->RectanglesArr[i].Position.x, LCDScreenData_Current->RectanglesArr[i].Position.y,
                  LCDScreenData_Current->RectanglesArr[i].Size.Width, LCDScreenData_Current->RectanglesArr[i].Size.Height, 
                  LCDScreenData_Current->RectanglesArr[i].Colours[LCDScreenData_Current->RectanglesArr[i].CurrentColourIndex]);
    }
  }

  // Draws all circles on the screen
  if (LCDScreenData_Current->CirclesArr != nullptr) {
    for (i = 0; i < LCDScreenData_Current->CirclesNum; i++) {
      tft.fillCircle(LCDScreenData_Current->CirclesArr[i].Position.x, LCDScreenData_Current->CirclesArr[i].Position.y,
                    LCDScreenData_Current->CirclesArr[i].Radius,
                    LCDScreenData_Current->CirclesArr[i].Colours[LCDScreenData_Current->CirclesArr[i].CurrentColourIndex]); // Selects the colour from the array based on the index of the wanted colour
    }
  }

  // Updates all text on the screen
  if (LCDScreenData_Current->TextArr != nullptr) {
    for (i = 0; i < LCDScreenData_Current->TextsNum; i++) {
      switch (LCDScreenData_Current->TextArr[i].VarType) {
        case LCD_TEXT_VAR_TYPE_INT:
          LCD_Print_Int_Var(LCDScreenData_Current->TextArr[i].Text,
                            LCDScreenData_Current->TextArr[i].Position.x, LCDScreenData_Current->TextArr[i].Position.y,
                            LCDScreenData_Current->TextArr[i].IntVar,
                            LCDScreenData_Current->TextArr[i].TextVarUnits,
                            LCDScreenData_Current->TextArr[i].BackgroundColour,
                            LCDScreenData_Current->TextArr[i].TextColour,
                            LCDScreenData_Current->TextArr[i].FontSize);
          break;

        case LCD_TEXT_VAR_TYPE_FLOAT:
          LCD_Print_Float_Var(LCDScreenData_Current->TextArr[i].Text,
                              LCDScreenData_Current->TextArr[i].Position.x, LCDScreenData_Current->TextArr[i].Position.y,
                              (float)LCDScreenData_Current->TextArr[i].FloatVar,
                              LCDScreenData_Current->TextArr[i].TextVarUnits,
                              LCDScreenData_Current->TextArr[i].BackgroundColour,
                              LCDScreenData_Current->TextArr[i].TextColour,
                              LCDScreenData_Current->TextArr[i].FontSize);
          break;

        case LCD_TEXT_VAR_TYPE_TEXT:
          if (LCDScreenData_Current->TextArr != nullptr) {
            LCD_Print_Text_Var(LCDScreenData_Current->TextArr[i].Text,
                               LCDScreenData_Current->TextArr[i].Position.x, LCDScreenData_Current->TextArr[i].Position.y,
                               LCDScreenData_Current->TextArr[i].TextVar,
                               LCDScreenData_Current->TextArr[i].BackgroundColour,
                               LCDScreenData_Current->TextArr[i].TextColour,
                               LCDScreenData_Current->TextArr[i].FontSize);
          }
          break;

        default: // LCD_TEXT_VAR_TYPE_NON        
          LCD_Print_Text(LCDScreenData_Current->TextArr[i].Text,
                         LCDScreenData_Current->TextArr[i].Position.x, LCDScreenData_Current->TextArr[i].Position.y,
                         LCDScreenData_Current->TextArr[i].BackgroundColour,
                         LCDScreenData_Current->TextArr[i].TextColour,
                         LCDScreenData_Current->TextArr[i].FontSize);
          break;
      }
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

float Check_Heater_Target_Temperature_Limits(float Temperature) {
  //Serial.println(Temperature);
  if (Temperature < HeaterLimits.Low) {
    return HeaterLimits.Low;
  }
  else if (Temperature > HeaterLimits.High) {
    return HeaterLimits.High;
  }
  else {
    return Temperature;
  }
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