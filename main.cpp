#include <iostream>
#include "treasurehuntql.h"
#include <vector>
#include <string>
using namespace std;

void testTreasureHunt(std::string filename)
{
    float learning_rate = 0.01;
    float gamma = 0.8;
    float epsilon = 0.9;
    TreasureHuntQL treasureHuntQL(filename,
                                  learning_rate,
                                  epsilon,
                                  gamma);
    for(int i = 0; i < 1000; ++i){
        treasureHuntQL.run(treasureHuntQL.start_state);
    }
}

int main()
{
    testTreasureHunt("tests/treasurehunt_map.txt");
    return 0;
}
