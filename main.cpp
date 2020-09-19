#include <iostream>
#include "treasurehuntql.h"
#include <vector>
#include <string>
using namespace std;

void testTreasureHunt(std::string filename)
{
    float learning_rate = 1.0f;
    float gamma = 0.8;
    float epsilon = 1.0;
    TreasureHuntQL treasureHuntQL(filename,
                                  learning_rate,
                                  epsilon,
                                  gamma);
    std::cout << "#Params "
              << " learning_rate : " << learning_rate
              << " gamma : " << gamma 
              << " epsilon : " << epsilon
              << std::endl;
    std::cout << "#Episode Steps AverageLoss" << std::endl;
    for(int i = 0; i < 1000; ++i){
        std::cout << i << " ";
        treasureHuntQL.run(treasureHuntQL.start_state);
    }
}

int main()
{
    testTreasureHunt("./tests/treasurehunt_map.txt");
    return 0;
}
