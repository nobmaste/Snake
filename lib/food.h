#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  // for Position
#include "snake.h"

#include <vector>
#include <utility> // for std::pair
#include <cstdlib>

class food {
public:
    food();
    void draw(N5110 &lcd);

    Position2D get_position();
    void generate() ;//生成食物
    bool isEaten = false;//食物是否被吃标志,flase表示未被吃
    
private:
    int getRand(int min, int max) {
        return ( rand() % (max - min + 1) ) + min ;
    }
    Position2D food_position//食物坐标
    

};
#endif