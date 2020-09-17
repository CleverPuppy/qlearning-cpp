#include "treasurehuntql.h"
#include <iostream>
#include <fstream>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

inline void TreasureHuntQL::stateToXY(unsigned int state, int &x, int &y)
{
    x = state / yMax;
    y = state % yMax;
}

inline unsigned int TreasureHuntQL::XYToState(int x, int y)
{
    return x * yMax + y;
}

bool TreasureHuntQL::isPositionValid(int x, int y)
{
    if(x < 0 || x >= xMax || y < 0 || y >= yMax)
    {
        return false;
    }
    return true;
}

TreasureHuntQL::TreasureHuntQL(std::string mapfile, float learning_reate, float epsilon, float gamma)
    :QLearning(learning_reate, epsilon, gamma)
    {
    std::fstream in(mapfile);
    int row , col;
    in >> row >> col;
    map.resize(row + 2,
                std::vector<char>(col + 2, 'X'));
    xMax = map.size();
    yMax = map[0].size();
    for(int i = 1; i <= row; ++i)
    {
        for(int j = 1; j <= col; ++j)
        {
            char c;
            in >> c;
            if(c == 'S') start_state = XYToState(i,j);
            map[i][j] = c;
        }
    }
    initQTable(4, xMax*yMax);
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

bool TreasureHuntQL::isTerminate(unsigned int state)
{
    int x;
    int y;
    stateToXY(state, x, y);
    if(map[x][y] == 'X' || map[x][y] == 'T')
    {
        return true;
    }
    return false;
}
