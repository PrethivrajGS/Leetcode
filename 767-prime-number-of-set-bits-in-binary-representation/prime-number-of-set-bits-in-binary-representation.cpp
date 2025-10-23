class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        vector<bool> isPrime(65, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p * p <= 64; ++p)
            if (isPrime[p])
                for (int q = p * p; q <= 64; q += p)
                    isPrime[q] = false;

        int ans = 0;
        for (int x = left; x <= right; ++x) {
            int bits = __builtin_popcount(x);            
            if (isPrime[bits]) ++ans;
        }
        return ans;
    }
};