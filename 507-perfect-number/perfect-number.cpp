class Solution {
public:
    bool checkPerfectNumber(int num) {
         if (num <= 1) return false; 

    int sum = 1; // 
    int root = sqrt(num);

    for (int i = 2; i <= root; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) sum += num / i; // add the complementary divisor
        }
    }

    return sum == num;
    }
};