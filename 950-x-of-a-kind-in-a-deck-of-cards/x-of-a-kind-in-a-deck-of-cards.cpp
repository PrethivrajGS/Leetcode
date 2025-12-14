class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card : deck) {
            freq[card]++;
        }

        int g = 0;
        for (auto &p : freq) {
            g = gcd(g, p.second);
        }
        return g >= 2;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
