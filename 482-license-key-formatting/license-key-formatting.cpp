class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned = "";
        
        // Remove dashes and convert to uppercase
        for (char c : s) {
            if (c != '-') {
                cleaned += toupper(c);
            }
        }

        int n = cleaned.size();
        if (n == 0) return "";

        string result = "";
        int count = 0;

        // Build from right to left
        for (int i = n - 1; i >= 0; i--) {
            result += cleaned[i];
            count++;

            // Add dash after k characters (except at beginning)
            if (count == k && i != 0) {
                result += '-';
                count = 0;
            }
        }

        // Reverse to get correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
