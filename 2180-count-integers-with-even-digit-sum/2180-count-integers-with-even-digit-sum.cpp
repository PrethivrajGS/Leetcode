class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int countEven(int num) {
        int s = digitSum(num);

        if (s % 2 == 0)
            return num / 2;
        else
            return (num - 1) / 2;
    }
};