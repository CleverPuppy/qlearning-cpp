#ifndef QLEARNING_H
#define QLEARNING_H
#include <vector>

class QLearning
{
private:
    float learning_reate;
    float epsilon;
    float gamma;
    unsigned int action_size;
    unsigned int state_size;
    std::vector<std::vector<float>> qtable; // STATE-ACTION
    virtual unsigned int transferFunction(unsigned int state, unsigned int action) = 0;  // 状态转移方程
    virtual float rewardFunction (unsigned int state) = 0;           // 即时奖励
    virtual void run(unsigned int initState, bool (*isTerminate)(unsigned int state));
    virtual void update(unsigned int state, unsigned int action, float reward, unsigned int next_state);
    virtual unsigned int bestAction(unsigned int state);
    virtual unsigned int epsilonGreedy(unsigned int state);
public:
    QLearning(unsigned int action_size, unsigned int state_size, float learning_reate, float epsilon, float gamma);
    ~QLearning() = default;
};

#endif // QLEARNING_H
