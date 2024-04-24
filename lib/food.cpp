#include "food.h"

 food::food(){}

Position2D food::get_position() {
        return food_position;
    }

void food::generate() {
       food_position.x=getRand(2, 82);
       food_position.y=getRand(2, 46);
       isEaten = false;
    }
    

void food::draw(N5110 &lcd) {  
        lcd.drawRect(food_position.x, food_position.y, 2, 2, FILL_BLACK);
}