class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
    string prev = countAndSay(n - 1), result = "";
    int count = 1;
    for (size_t i = 1; i <= prev.length(); i++) {
        if (i == prev.length() || prev[i] != prev[i - 1]) {
            result += to_string(count) + prev[i - 1];
            count = 1;
        } else {
            count++;
        }
    }
    return result;
    }
};