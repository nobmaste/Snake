#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>
#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  // for Position
#include "food.h"
#include "Joystick.h"
#include <vector>
#include <utility> // for std::pair

class snake {
public:
    snake();
    void init() ;
    void snake::set_direction(Direction new_direction);
    void move(food &f,Joystick &joystick);
    bool check_collision() ;
    bool check_wall_collision(int game_width, int game_height) ;
    void draw(N5110 &lcd);
    std::pair<int, int> get_head() const {
        return body.back();
    }//获取蛇头位置

private:
    std::vector<std::vector<int>> body;//snake身体
    Direction direction;
};
#endif