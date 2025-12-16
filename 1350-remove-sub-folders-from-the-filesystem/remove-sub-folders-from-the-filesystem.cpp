class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort folders
        sort(folder.begin(), folder.end());

        vector<string> result;
        string prev = "";

        for (string& curr : folder) {
            if (prev.empty() || curr.find(prev + "/") != 0) {
                result.push_back(curr);
                prev = curr;
            }
        }
        return result;
    }
};
