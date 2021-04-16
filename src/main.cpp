
#include <array>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

#include "bubble.h"
#include "insertion.h"
#include "quick.h"
#include "selection.h"
//#define N 100000
using namespace std;
int main() {
    int i, seed;
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    for (int selection = 0; selection < 4; selection++) {
        for (int size = 1000; size < std::pow(50, 3) + 1; size = size * 1.1) {
            int nums[size];
            auto start = std::chrono::high_resolution_clock::now();
            std::uniform_int_distribution<int> distribution(0, 999);
            for (i = 0; i < size; i++) {
                nums[i] = distribution(generator);
            }
            switch (selection) {
                case 0: {
                    Bubble<int> b(nums, size);
                    break;
                }
                case 1: {
                    Selection<int> s(nums, size);
                    break;
                }
                case 2: {
                    Insertion<int> i(nums, size);
                    break;
                }
                case 3: {
                    Quick<int> q(nums, size);
                    break;
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            std::cout << selection << "," << size << "," << duration.count()
                      << std::endl;
        }
    }
    return 0;
}