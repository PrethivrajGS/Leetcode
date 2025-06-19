class Solution {
public:
    
    string intToRoman(int num) {
        pair<int, string> roman[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        for (auto &[value, symbol] : roman) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }

    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int prevValue = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int currValue = roman[s[i]];
            if (currValue < prevValue) {
                result -= currValue; 
            } else {
                result += currValue;
            }
            prevValue = currValue;
        }

        return result;
    }
};
