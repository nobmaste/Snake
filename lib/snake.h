#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>
#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  // for Position

#include <vector>
#include <utility> // for std::pair

class snake {
public:
    snake();
    void init() ;
    void snake::set_direction(Direction new_direction);
    void move();
    bool check_collision() ;
    bool check_wall_collision(int game_width, int game_height) ;
    void draw(N5110 &lcd);

private:
    std::vector<std::vector<int>> body;
    Direction direction;
};
#endif