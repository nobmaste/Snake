#ifndef FOOD_H
#define FOOD_H
#include<iostream>
#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  // for Position

#include <vector>
#include <utility> // for std::pair


class food {
public:
    food();
    void draw(N5110 &lcd);

    Position2D get_position();
    void generate() ;//生成食物
    void destroy();//消灭食物

private:
   
};
#endif