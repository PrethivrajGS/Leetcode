class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int rounds = n / 3;

        int left = 0;
        int right = n - 1;
        int result = 0;

        while (rounds--) {
            right--;               
            result += piles[right]; 
            right--;                
            left++;               
        }

        return result;
    }
};