class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        long long coins = mid * (mid + 1) / 2;
        if (coins == n)
            return mid;
        if (coins < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
    }
};