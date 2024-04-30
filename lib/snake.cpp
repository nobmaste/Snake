#include "snake.h"

snake::snake(){}

void snake::init() {
    printf("Snake: Init\n");
    body.clear();
    body.push_back({20, 20}); // tail
    body.push_back({22, 20}); // middle part
    body.push_back({24, 20}); // head
#ifdef DEBUG
    std::pair<int, int> head_init = get_head(); // Get the current head position
    std::vector<int> _head_init = {head_init.first, head_init.second};
    printf("Snake init\n Head: Initialised at %d, %d\n", _head_init[0], _head_init[1]);
#endif

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
    //如果方向为CENTER，使用上一次的方向
    if (direction == CENTRE) {
        direction = last_direction;
    } else {
        //否则，更新上一次的方向
        last_direction = direction;
    }
    //根据移动方向计算新位置
    switch (direction) {
        case UP:
            head.second=head.second+2;
            break;
        case DOWN:
            head.second=head.second-2;
            break;
        case LEFT:
            head.first=head.first-2;
            break;
        case RIGHT:
            head.first=head.first+2;
            break;
    }

    // 添加新蛇头
    std::vector<int> head_vec = {head.first, head.second};
    body.push_back(head_vec);
    printf("Snake: Moved to %d, %d\n", head.first, head.second);
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
        printf("Snake: Removed tail\n");
    }else {
        // 如果吃到食物，重置isEaten为false
        f.isEaten = false;
        printf("Snake: Ate food\n");
    }
}

//检测自身碰撞
bool snake::check_collision() {
    printf("\n");
    std::pair<int, int> head_pair = get_head(); // Get the current head position
    std::vector<int> head = {head_pair.first, head_pair.second};
    // Check if the head has collided with the body
    for (int i = 0; i < body.size() -1; i++) {
#ifdef DEBUG
        printf("check body positin:%d, %d\n", body[i][0], body[i][1]);
#endif
        if (body[i] == head) {
            printf("collisin interupt, body position:%d, %d\n", body[i][0], body[i][1]);
            printf("Snake: Collision with body\n");
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
        printf("Snake: Collision with wall\n");
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

