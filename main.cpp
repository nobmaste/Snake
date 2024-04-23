/*   Pong Game
*    =========
*
*    Function:               Example pong game
*    Circuit Schematic No.:  9 and 14 : https://github.com/ELECXJEL2645/Circuit_Schematics
*    Required Libraries:     
*
*    Authored by:            Dr Craig Evans
*    Date:                   2021
*    Collaborators:          Andrew Knowles
*                            Dr Tim Amsdon 
*    Version:                1.0
*    Revision Date:          03/2023 
*    MBED Studio Version:    1.4.1
*    MBED OS Version:        6.12.0
*    Board:	                NUCLEO L476RG   */

///////////// includes /////////////////////

#include "Joystick.h"
#include "N5110.h"  
#include "PongEngine.h"
#include "Utils.h"
#include "mbed.h"
///////////// defines /////////////////////
#define PADDLE_WIDTH 2
#define PADDLE_HEIGHT 8
#define BALL_SIZE 2
#define BALL_SPEED 3

///////////// objects ///////////////////
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_1, PC_0);
DigitalIn buttonA(BUTTON1); //onboard user button
PongEngine pong;

///////////// prototypes ///////////////
void init();
void render();
void welcome();
void game_over();
////////////////////////////////////////


int main() {
    init();      // initialise devices and objects
    welcome();   // waiting for the user to start 
    render();    // first draw the initial frame 
    int fps = 10;
    thread_sleep_for(1000/fps);  // and wait for one frame period - millseconds
    
    int lives = 4;   // display lives on LEDs
    
    while (lives > 0) {  // keep looping while lives remain
        // read the joystick input and store in a struct
        UserInput input = {joystick.get_direction(),joystick.get_mag()};
        lives = pong.update(input);   // update the game engine based on input    
        render();                     // draw frame on screen
        thread_sleep_for(1000/fps);         // and wait for one frame period - ms
    }   
    game_over();
}

void init() {
    lcd.init(LPH7366_1);
    lcd.setContrast(0.5);
    joystick.init();
    pong.init(0,8,2,2,2);     // paddle x position, paddle_height,paddle_width,ball_size,speed
}

void render() {  // clear screen, re-draw and refresh
    lcd.clear();  
    pong.draw(lcd);
    lcd.refresh();
}

void welcome() { // splash screen
    lcd.printString("     Snake!    ",0,1);  
    lcd.printString("Press Nucleo",0,3);
    lcd.printString("Blue button",0,4);
    lcd.refresh();

        while (buttonA.read() == 1){

         ThisThread::sleep_for(100ms);
      
        }
}

void game_over() { // splash screen 
    while (1) {
        lcd.clear();
        lcd.printString("  Game Over ",0,2);  
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        lcd.clear();
        lcd.refresh();
        ThisThread::sleep_for(250ms);
    }
}