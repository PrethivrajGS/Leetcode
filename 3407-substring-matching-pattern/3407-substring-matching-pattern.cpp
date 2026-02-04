class Solution {
public:
    bool hasMatch(string s, string p) {
        int starPos = p.find('*');

        string left = p.substr(0, starPos);
        string right = p.substr(starPos + 1);

        int n = s.length();

        // Try every possible start for left part
        for (int i = 0; i + left.size() <= n; i++) {
            if (s.substr(i, left.size()) != left) continue;

            // Try every possible start for right part after left
            for (int j = i + left.size(); j + right.size() <= n; j++) {
                if (s.substr(j, right.size()) == right) {
                    return true;
                }
            }
        }
        return false;
    }
};
