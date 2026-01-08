class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> freqS(10, 0), freqG(10, 0);

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freqS[secret[i] - '0']++;
                freqG[guess[i] - '0']++;
            }
        }

        for (int d = 0; d < 10; d++) {
            cows += min(freqS[d], freqG[d]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
