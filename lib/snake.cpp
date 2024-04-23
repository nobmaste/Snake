#include "snake.h"

snake::snake(){}

void snake::init() {
    printf("Snake: Init\n");
    body.clear();
    body.push_back(std::make_pair(0, 5)); // tail
    body.push_back(std::make_pair(1, 5)); // middle part
    body.push_back(std::make_pair(2, 5)); // head
    direction = RIGHT; // initial direction
}

void snake::set_direction(Direction new_direction) {
    if (new_direction != CENTRE) {
        direction = new_direction;
    }
}

void snake::move() {
    //获取蛇头位置
    std::pair<int, int> head = body.back();

    //根据移动方向计算新位置
    switch (direction) {
        case UP:
            head.second++;
            break;
        case DOWN:
            head.second--;
            break;
        case LEFT:
            head.first--;
            break;
        case RIGHT:
            head.first++;
            break;
    }

    // 添加新蛇头
    body.push_back(head);

    // 如果没有吃到食物，删除尾部
    if (!ate_food) {
        body.erase(body.begin());
    }
}

//检测自身碰撞
bool snake::check_collision() {
    std::pair<int, int> head = body.back(); // Get the current head position

    // Check if the head has collided with the body
    for (int i = 0; i < body.size() - 1; i++) {
        if (body[i] == head) {
            return true;
        }
    }

    return false;
}
//检测墙壁碰撞
bool snake::check_wall_collision(int game_width, int game_height) {
    std::pair<int, int> head = body.back(); // Get the current head position

    // Check if the head has collided with the wall
    if (head.first < 0 || head.first >= game_width || head.second < 0 || head.second >= game_height) {
        return true;
    }

    return false;
}

//画出蛇
void snake::draw(N5110 &lcd) {
    for (auto &part : body) {
        lcd.drawRect(part.first, part.second, 2, 2, FILL_BLACK);
    }
}