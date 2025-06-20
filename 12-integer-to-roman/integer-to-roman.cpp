class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };
        
        string result;
        for (auto &pair : values) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        return result;
    }
};