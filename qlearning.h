#ifndef QLEARNING_H
#define QLEARNING_H
#include <vector>
#include <ctime>
#include <random>

class QLearning
{
public:
    float learning_rate;
    float epsilon;
    float gamma;
    unsigned int action_size;
    unsigned int state_size;
    std::vector<std::vector<float>> qtable; // STATE-ACTION
    virtual unsigned int transferFunction(unsigned int state, unsigned int action) = 0;  // 状态转移方程
    virtual bool isTerminate(unsigned int state) = 0;                   // Episode停止条件
    virtual float rewardFunction (unsigned int state) = 0;              // 即时奖励
    virtual void run(unsigned int initState);
    virtual void update(unsigned int state, unsigned int action, float reward, unsigned int next_state);
    virtual unsigned int bestAction(unsigned int state);
    virtual unsigned int epsilonGreedy(unsigned int state);
    QLearning(unsigned int action_size, unsigned int state_size, float learning_reate, float epsilon, float gamma);
    QLearning(float learning_rate, float epsilon, float gamma);
    void initQTable(unsigned int action_size, unsigned int state_size);
    void initRandomEngine();
    ~QLearning() = default;
private:
    std::default_random_engine engine;
    std::uniform_real_distribution<float> flag;
    std::uniform_int_distribution<unsigned int> randomAction;
};

#endif // QLEARNING_H
