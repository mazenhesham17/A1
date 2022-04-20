#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class Testbed {
public:
    vector<int> generateRandomList(int min, int max, int size) {
        vector<int> random(size);
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            random[i] = min + rand() % (max - min + 1);
        }
        return random;
    }

    vector<int> generateReverseOrderedList(int min, int max, int size) {
        vector<int> random = generateRandomList(min, max, size);
        sort(random.begin(), random.end(), greater<>());
        return random;
    }

    double runOnce() {

    }
};

int main() {
    Testbed t1;
    vector<int> v = t1.generateReverseOrderedList(2, 10, 10);
    for (auto &it: v) {
        cout << it << ' ';
    }
    return 0;
}