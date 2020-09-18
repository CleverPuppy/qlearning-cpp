#include "qlearning.h"
#include <cfloat>
#include <ctime>
#include <random>
#include <algorithm>
#include <iostream>

void QLearning::run(unsigned int initState)
{
    unsigned int nextState = initState;
    unsigned int action;
    float reward;
    float total_loss = 0.0;
    unsigned int step = 0;
    while (!isTerminate(initState)) {
        action = epsilonGreedy(initState);
        nextState = transferFunction(initState, action);
        reward = rewardFunction(nextState);
        float _step_loss = 0.0f;
        update(initState,action,reward,nextState, _step_loss);
        total_loss += _step_loss;
        step ++;
        initState = nextState;
    }
    std::cout << step << " " << total_loss / step << std::endl;
}

inline void QLearning::update(unsigned int state, unsigned int action, float reward, unsigned int next_state)
{
    qtable[state][action] = (1 - learning_rate) * qtable[state][action] +  learning_rate * (
                reward + gamma * *std::max_element(qtable[next_state].begin(), qtable[next_state].end()));
}

inline void QLearning::update(unsigned int state, unsigned int action, float reward, unsigned int next_state, float &loss)
{
    float prev = qtable[state][action];
    qtable[state][action] = (1 - learning_rate) * qtable[state][action] +  learning_rate * (
                reward + gamma * *std::max_element(qtable[next_state].begin(), qtable[next_state].end()));
    loss = fabs(qtable[state][action] - prev);
}

unsigned int QLearning::bestAction(unsigned int state)
{
    unsigned int ret = 0;
    float tmp = -FLT_MAX;
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
    if(flag(engine) < epsilon){
        return bestAction(state);
    }else{
        return randomAction(engine);
    }
}

QLearning::QLearning(unsigned int action_size, unsigned int state_size, float learning_rate, float epsilon, float gamma):
    action_size(action_size),state_size(state_size),learning_rate(learning_rate), epsilon(epsilon), gamma(gamma)
{
    initQTable(action_size,state_size);
}

QLearning::QLearning(float learning_rate, float epsilon, float gamma)
    :learning_rate(learning_rate),epsilon(epsilon),gamma(gamma)
{

}

void QLearning::initQTable(unsigned int action_size, unsigned int state_size)
{
    this->action_size = action_size;
    this->state_size = state_size;
    qtable.resize(state_size,std::vector<float>(action_size, 0.0f));  // 初始化为0
    initRandomEngine();
}

void QLearning::initRandomEngine()
{
    engine.seed(time(nullptr));
    flag = std::uniform_real_distribution<float>(0.0f,1.0f);
    randomAction = std::uniform_int_distribution<unsigned int>(0, action_size - 1);
}
