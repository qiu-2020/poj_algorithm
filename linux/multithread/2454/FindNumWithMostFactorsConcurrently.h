#include <iostream>
#include <string>
#include <thread>
#include <vector>

class FindNumWithMostFactorsConcurrently {
private:
    static FindNumWithMostFactorsConcurrently* instance;
    std::thread::id mainThreadName;
    int callCount;
    FindNumWithMostFactorsConcurrently() {
        mainThreadName = std::this_thread::get_id();
        callCount = 0;
    }

public:
    virtual ~FindNumWithMostFactorsConcurrently() {}
    static FindNumWithMostFactorsConcurrently* getInstance() {
        if (instance == NULL) {
            instance = new FindNumWithMostFactorsConcurrently();
        }
        return instance;
    }

    static void killInstance() {
        if (instance != NULL) {
            delete instance;
            instance = NULL;
        }
    }

    int getCallCount() {
        return callCount;
    }
    
    std::vector<int> searchRange(int start, int end) {
        std::vector<int> factors;
        if (mainThreadName == std::this_thread::get_id()) {
            return factors;
        }
        callCount++;
        factors.push_back(0);
        factors.push_back(0);
        for (int i = start; i <= end; i++) {
            int factorsCount = 0;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0)
                    factorsCount++;
            }
            if (factorsCount > factors[0] || factorsCount == factors[0] && i > factors[1]) {
                factors[0] = factorsCount;
                factors[1] = i;
            }
        }
        return factors;
    }
};
FindNumWithMostFactorsConcurrently* FindNumWithMostFactorsConcurrently::instance = NULL;