#ifndef TREASUREHUNTQL_H
#define TREASUREHUNTQL_H

#include "qlearning.h"
#include <vector>

/*
 * std::vector<std::vector<char>> map 代表了二维网格地图
 * 图例：
 * 'X' ---- 障碍物
 * 'O' ---- 可通行区域
 * 'T' ---- 宝藏
 * 'S' ---- 出发点
*/

class TreasureHuntQL : public QLearning
{
private:
    std::vector<std::vector<char>> map;
    unsigned int xMax;
    unsigned int yMax;
    void stateToXY(unsigned int state, int &x, int &y);
    unsigned int XYToState(int x, int y);
    bool isPositionValid(int x, int y);
public:
    TreasureHuntQL(unsigned int action_size,
                   unsigned int state_size,
                   float learning_reate,
                   float epsilon,
                   float gamma);
    void setMap(std::vector<std::vector<char>>& map);
    virtual unsigned int transferFunction(unsigned int state, unsigned int action) override;
    virtual float rewardFunction(unsigned int state) override;
};

#endif // TREASUREHUNTQL_H
