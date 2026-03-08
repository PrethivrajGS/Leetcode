
class Solution {
public:
    int minTimeToType(string word) {
        char current = 'a';
        int time = 0;

        for(char c : word) {
            int diff = abs(c - current);
            time += min(diff, 26 - diff); // move
            time += 1;                    // type
            current = c;
        }

        return time;
    }
};