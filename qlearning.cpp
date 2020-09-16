#include "qlearning.h"

QLearning::QLearning(unsigned int action_size, unsigned int state_size)
{
    qtable.resize(action_size,std::vector<float>(state_size, 0.0f));  // 初始化为0
}
