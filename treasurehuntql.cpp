#include "treasurehuntql.h"
#include <iostream>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

inline void TreasureHuntQL::stateToXY(unsigned int state, int &x, int &y)
{
    int col_size = map[0].size();
    x = state / col_size;
    y = state % col_size;
}

inline unsigned int TreasureHuntQL::XYToState(int x, int y)
{
    int col_size = map[0].size();
    return x * col_size + y;
}

bool TreasureHuntQL::isPositionValid(int x, int y)
{
    if(x < 0 || x >= xMax || y < 0 || y >= yMax)
    {
        return false;
    }
    return true;
}

TreasureHuntQL::TreasureHuntQL(unsigned int action_size, unsigned int state_size, float learning_reate, float epsilon, float gamma)
    :QLearning(action_size,state_size,learning_reate,epsilon,gamma)
{

}

void TreasureHuntQL::setMap(std::vector<std::vector<char> > &map)
{
    if(map.empty() || map[0].empty()) return;
    this->map = map;
    xMax = map.size();
    yMax = map[0].size();
}

unsigned int TreasureHuntQL::transferFunction(unsigned int state, unsigned int action)
{
    int x;
    int y;
    stateToXY(state, x, y);
    switch (action) {
    case UP:
        // UP
        x -= 1;
        break;
    case DOWN:
        x += 1;
        break;
    case LEFT:
        y -= 1;
        break;
    case RIGHT:
        y += 1;
        break;
    default:
        std::cerr << "Wrong Action" << std::endl;
        break;
    }
    return isPositionValid(x,y) ? XYToState(x,y) : state;
}

float TreasureHuntQL::rewardFunction(unsigned int state)
{
    int x, y;
    stateToXY(state, x, y);
    if(map[x][y] == 'X'){
        return -5.0f;
    }
    if(map[x][y] == 'T'){
        return 10.0f;
    }
    return -1.0f;
}
