class Solution {
public:
    int nextGreaterElement(int n) {
        
    vector<int> digits;
    int temp = n;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    reverse(digits.begin(), digits.end());

    int length = digits.size();
    int i = length - 2;
    while (i >= 0 && digits[i] >= digits[i + 1])
        i--;

    if (i < 0)
        return -1;

    int j = length - 1;
    while (digits[j] <= digits[i])
        j--;
    swap(digits[i], digits[j]);
    reverse(digits.begin() + i + 1, digits.end());

    long long result = 0;
    for (int d : digits) {
        result = result * 10 + d;
        if (result > INT_MAX) 
            return -1;
    }

    return (int)result;
    }
};