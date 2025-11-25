class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        bool negative = num < 0;
        num = abs(num);

        string result = "";
        while (num > 0) {
            result.push_back('0' + (num % 7));
            num /= 7;
        }

        if (negative) result.push_back('-');

        reverse(result.begin(), result.end());
        return result;
    }
};
