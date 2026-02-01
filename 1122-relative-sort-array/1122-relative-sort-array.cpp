class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        
        for (int x : arr1) {
            freq[x]++;
        }
        
        vector<int> result;
        
        for (int x : arr2) {
            while (freq[x] > 0) {
                result.push_back(x);
                freq[x]--;
            }
        }
        
        for (int i = 0; i <= 1000; i++) {
            while (freq[i] > 0) {
                result.push_back(i);
                freq[i]--;
            }
        }
        
        return result;
    }
};
