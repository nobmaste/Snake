#include "snake.h"

snake::snake(){}

void snake::init() {
    printf("Snake: Init\n");
    body.clear();
    body.push_back({0, 5}); // tail
    body.push_back({1, 5}); // middle part
    body.push_back({2, 5}); // head
    direction = RIGHT; // initial direction
}

void snake::set_direction(Direction new_direction) {
    if (new_direction != CENTRE) {
        direction = new_direction;
    }
}

/*
根据方向移动蛇
检查是否吃下食物，吃下则生成一个新的食物并且蛇长+1
*/
void snake::move(food &f,Joystick &joystick) {
    //获取蛇头位置
    std::pair<int, int> head = get_head();
    //获取摇杆方向
    Direction direction=joystick.get_direction();
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
    std::vector<int> head_vec = {head.first, head.second};
    body.push_back(head_vec);

    // 获取食物位置
    Position2D food_position = f.get_position();
    // 检查蛇头是否与食物的位置重合
    if (head.first == food_position.x && head.second == food_position.y) {
        f.isEaten = true;
        f.generate();
    }

    // 如果没有吃到食物，删除尾部
    if (!f.isEaten) {
        body.erase(body.begin());
    }else {
        // 如果吃到食物，重置isEaten为false
        f.isEaten = false;
    }
}

//检测自身碰撞
bool snake::check_collision() {
    std::pair<int, int> head_pair = get_head(); // Get the current head position
    std::vector<int> head = {head_pair.first, head_pair.second};

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
    std::pair<int, int> head = get_head(); // Get the current head position

    // Check if the head has collided with the wall
    if (head.first < 0 || head.first >= game_width || head.second < 0 || head.second >= game_height) {
        return true;
    }

    return false;
}

//画出蛇
void snake::draw(N5110 &lcd) {
    for (auto &part : body) {
        if (part.size() >= 2) {
            lcd.drawRect(part[0], part[1], 2, 2, FILL_BLACK);
        } else {
            // Handle error here, for example, print an error message
            printf("Snake body part has less than 2 elements\n");
        }
    }
}

