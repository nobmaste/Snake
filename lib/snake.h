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

#define DEBUG

class snake {
public:
    snake();
    void init() ;
    void set_direction(Direction new_direction);
    void move(food &f,Joystick &joystick);
    bool check_collision() ;
    bool check_wall_collision(int game_width, int game_height) ;
    void draw(N5110 &lcd);
    std::pair<int, int> get_head() const {
        std::vector<int> head = body.back();
        if (head.size() >= 2) {
         printf("get_head:%d, %d\n", head[0], head[1]);
         return std::make_pair(head[0], head[1]);
        } else {
         printf("get head error\n");
          return std::make_pair(-1, -1);  // 返回一个默认值
        }
    }
    unsigned char get_score() ;

private:
    std::vector<std::vector<int>> body;//snake身体
    Direction direction;
    Direction last_direction = RIGHT; // 默认初始方向为右
    unsigned char score = 0;
};
#endif