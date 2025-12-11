class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (auto &t : timePoints) {
            int hh = stoi(t.substr(0, 2));
            int mm = stoi(t.substr(3));
            minutes.push_back(hh * 60 + mm);
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;

        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }

        int wrapDiff = 1440 - minutes.back() + minutes[0];
        minDiff = min(minDiff, wrapDiff);

        return minDiff;
    }
};
