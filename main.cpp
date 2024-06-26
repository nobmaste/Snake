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
#include "mbed.h"
#include "Joystick.h"
#include "N5110.h"  
#include "snake.h"
#include "food.h"
#include "Utils.h"
///////////// defines /////////////////////
#define PADDLE_WIDTH 2
#define PADDLE_HEIGHT 8
#define BALL_SIZE 2
#define BALL_SPEED 3

///////////// objects ///////////////////
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_1, PC_0);
DigitalIn buttonA(BUTTON1); //onboard user button
snake _snake;
food _food;

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
    
    bool lives = true;   // display lives on LEDs
    
    while (lives == true) {  // keep looping while lives remain
        printf("lives\n");
       _snake.move(_food,joystick);  
        if(_snake.check_collision() || _snake.check_wall_collision(WIDTH, HEIGHT)) {
                lives=false;
        }
        render();                     // draw frame on screen
        thread_sleep_for(1000/fps);         // and wait for one frame period - ms
        printf("*******************Next Loop*******************");
    }   
    game_over();
}

void init() {
    lcd.init(LPH7366_1);
    lcd.setContrast(0.5);
    joystick.init();
    _snake.init();
    _food.generate();
}

void render() {  // clear screen, re-draw and refresh
    lcd.clear();  
    lcd.drawLine(0,0,WIDTH-1,0,1);  // bottom
    lcd.drawLine(WIDTH-1,0,WIDTH-1,HEIGHT-1,1);  // right
    lcd.drawLine(0,HEIGHT-1,WIDTH-1,HEIGHT-1,1); // top
    lcd.drawLine(0,0,0,HEIGHT-1,1);  // top
    _snake.draw(lcd);
    _food.draw(lcd);
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
    printf("Game Start\n");
}

void game_over() { // splash screen 
    char str[10];
    unsigned char num = _snake.get_score();
    sprintf(str, "%d", num);
    // N5110::printString(str, x, y);
    while (1) {
        lcd.clear();
        lcd.printString("  Game Over ",0,2);  
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        lcd.clear();
        lcd.printString("  Score: ",0,2);
        lcd.printString(str, 8, 2);
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        printf("\n");
        printf("Game Over\n");
        printf("Score: %d\n", num);
    }
}
