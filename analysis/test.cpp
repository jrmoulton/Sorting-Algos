
#include <chrono>
#include <random>

#include "bubble.h"
#include "insertion.h"
#include "quick.h"
#include "selection.h"
#define N 100000
using namespace std;
int main() {
    int i, seed, nums[N];
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 999);
    for (i = 0; i < N; i++) {
        nums[i] = distribution(generator);
    }
    // Bubble <int> s(nums, N);
    // Selection <int> s(nums, N);
    Insertion<int> s(nums, N);
    // Quick<int> s(nums, N);
    s.print(nums, N);
    return 0;
}