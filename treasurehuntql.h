#ifndef TREASUREHUNTQL_H
#define TREASUREHUNTQL_H

#include "qlearning.h"
#include <vector>
#include <string>

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
public:
    std::vector<std::vector<char>> map;
    unsigned int start_state;
    unsigned int xMax;
    unsigned int yMax;
    void stateToXY(unsigned int state, int &x, int &y);
    unsigned int XYToState(int x, int y);
    bool isPositionValid(int x, int y);
    TreasureHuntQL(std::string mapfile,
                   float learning_reate,
                   float epsilon,
                   float gamma);
    virtual unsigned int transferFunction(unsigned int state, unsigned int action) override;
    virtual float rewardFunction(unsigned int state) override;
    virtual bool isTerminate(unsigned int state) override;
};

#endif // TREASUREHUNTQL_H
