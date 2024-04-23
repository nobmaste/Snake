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
    N,       // 1      
    E,       // 2
    S,       // 3
    W        // 4
     
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