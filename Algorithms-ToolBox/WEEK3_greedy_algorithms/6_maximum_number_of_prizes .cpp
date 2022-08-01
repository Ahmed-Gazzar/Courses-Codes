#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int i = 1;
    int rest = n;
    while (true) {

        summands.push_back(i);
        rest = rest - i;
        if (summands[i - 1] >= rest) {
            summands[i - 1] += rest;
            break;
        }
        else {
            i++;
        }

    }

    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
