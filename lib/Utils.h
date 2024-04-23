#ifndef UTILS_H
#define UTILS_H

struct Position2D {
  int x;
  int y;  
};

struct Food_modle//食物模型
{
    int x;
    int y;
    int size;
};


enum Direction {
    CENTRE,  // 0
    UP,       // 1      
    RIGHT,       // 2
    DOWN,       // 3
    LEFT        // 4
     
};

struct UserInput {
    Direction d;
    float mag;
};

struct Vector2D {
  float x;
  float y;  
};

struct Polar {
    float mag;
    float angle;
};

#endif