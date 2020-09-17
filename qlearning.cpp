#include "qlearning.h"
#include <cfloat>
#include <ctime>
#include <random>
#include <algorithm>
void QLearning::run(unsigned int initState, bool (*isTerminate)(unsigned int state))
{
    unsigned int nextState = initState;
    unsigned int action;
    float reward;
    while (isTerminate(initState)) {
        action = epsilonGreedy(initState);
        nextState = transferFunction(initState, action);
        reward = rewardFunction(nextState);
        update(initState,action,reward,nextState);
        initState = nextState;
    }
}

inline void QLearning::update(unsigned int state, unsigned int action, float reward, unsigned int next_state)
{
    qtable[state][action] = reward + gamma * *std::max_element(qtable[next_state].begin(), qtable[next_state].end());
}

unsigned int QLearning::bestAction(unsigned int state)
{
    unsigned int ret = 0;
    float tmp = FLT_MIN;
    auto& action_reward = qtable[state];
    for(int i = 0; i < action_size; ++i)
    {
        if(action_reward[i] > tmp){
            ret = i;
            tmp = action_reward[i];
        }
    }
    return ret;
}

unsigned int QLearning::epsilonGreedy(unsigned int state)
{
    static std::default_random_engine engine(time(NULL));
    static std::uniform_real_distribution<double> flag(0.0,1.0);
    static std::uniform_int_distribution<int> randomAction(0,action_size);
    if(flag(engine) < epsilon){
        return bestAction(state);
    }else{
        return randomAction(engine);
    }
}

QLearning::QLearning(unsigned int action_size, unsigned int state_size, float learning_reate, float epsilon, float gamma):
    action_size(action_size),state_size(state_size),learning_reate(learning_reate), epsilon(epsilon), gamma(gamma)
{
    qtable.resize(state_size,std::vector<float>(action_size, 0.0f));  // 初始化为0
}
