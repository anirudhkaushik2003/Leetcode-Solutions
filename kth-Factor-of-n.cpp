#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

class Solution
{
public:
    vector<bool> sieve(int n)
    {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (is_prime[i] && (long long)i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        return is_prime;
    }
    int kthFactor(int n, int k)
    {

        vector<int> factors;
        // vector<bool> is_prime = sieve(n);
        
            for (int i = 1; i < sqrt(n); ++i)
                if (n % i == 0 && --k == 0)
                    return i;
            for (int i = (int)sqrt(n); i >= 1; --i)
                if (n % (n / i) == 0 && --k == 0)
                    return n / i;
            return -1;
    }
};

int main()
{
    int n = 12, k = 3;
    Solution s;
    int ans = s.kthFactor(n, k);
    cout << ans << endl;
}
