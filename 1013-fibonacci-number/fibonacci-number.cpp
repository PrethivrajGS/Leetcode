class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;       // Base cases: F(0)=0, F(1)=1
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;              // F(n) = F(n-1) + F(n-2)
        a = b;                  // move forward
        b = c;
    }
    return b; 
    }
};