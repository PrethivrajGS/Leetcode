class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev = 1, curr = 1; 
        
        for (int i = 1; i < n; i++) {
            int temp = 0;

            if (s[i] != '0') {
                temp = curr;
            }

            int twoDigit = stoi(s.substr(i-1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                temp += prev;
            }

            // Update dp values
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};