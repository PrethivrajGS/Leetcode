class Solution {
public:
    const long long MOD = 1000000007;

    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    int numPrimeArrangements(int n) {
        int primes = 0;

        // count primes ≤ n
        for (int i = 1; i <= n; i++) {
            if (isPrime(i))
                primes++;
        }

        long long factPrime = 1, factNonPrime = 1;

        // p!
        for (int i = 1; i <= primes; i++)
            factPrime = (factPrime * i) % MOD;

        // (n-p)!
        for (int i = 1; i <= (n - primes); i++)
            factNonPrime = (factNonPrime * i) % MOD;

        return (factPrime * factNonPrime) % MOD;
    }
};