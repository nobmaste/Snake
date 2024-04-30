#include "food.h"
void initRand();
int getRand(int min, int max);

 food::food(){}

Position2D food::get_position() {
        return food_position;
    }

void food::generate() {
       food_position.x=getRand(2, 82);
       food_position.y=getRand(2, 46);
       
    }
    

void food::draw(N5110 &lcd) {  
        lcd.drawRect(food_position.x, food_position.y, 2, 2, FILL_BLACK);
}

// 初始化随机数生成器
void initRand() {
    srand(time(0));
}

// 生成在[min, max]范围内的随机数
int getRand(int min, int max) {
    return min + rand() % (max - min + 1);
}