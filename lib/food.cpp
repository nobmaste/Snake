#include "food.h"

 food::food(){}

Position2D food::get_position() {
    printf("Food: Get position at %d, %d\n", food_position.x, food_position.y);
        return food_position;
    }

void food::generate() {
    food_position.x = getRand(1, 41) * 2;
    food_position.y = getRand(1, 23) * 2;
    printf("Food: Generated at %d, %d\n", food_position.x, food_position.y);
}
    

void food::draw(N5110 &lcd) {  
        lcd.drawRect(food_position.x, food_position.y, 2, 2, FILL_BLACK);
}

// 初始化随机数生成器
void food::initRand() {
    srand(time(0));
}

