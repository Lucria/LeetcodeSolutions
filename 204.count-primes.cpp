/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    // * Really bad runtime personal solution
    // int countPrimes(int n) {
    //     if (n == 3) return 1;
    //     if (n <= 2) return 0;

    //     int ans = 2;
    //     for (int i = 4; i < n; i++) {
    //         if (isPrime(i)) {
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }

    // * Faster solution online
    // * Sieve of Eratosthenes
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if (i>upper) continue;
                for (int j=i*i; j<n; j+=i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }

private:
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

