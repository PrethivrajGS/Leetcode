class Solution {
public:
    // Helper function to check if a number is self-dividing
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0)
                return false;
            temp /= 10;
        }
        return true;
    }

    // Main function to get all self-dividing numbers in range
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i))
                result.push_back(i);
        }
        return result;
    }
};
