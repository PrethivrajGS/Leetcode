class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        unsigned int n = num;  
        string hexChars = "0123456789abcdef";
        string res = "";

        while (n > 0) {
            int digit = n & 0xf;        
            res.push_back(hexChars[digit]);
            n >>= 4;                      
        }

        reverse(res.begin(), res.end());
        return res;
    }
};