#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
class Solution {
public:
    int fib(int n) {
        if(n == 0 )
        {
            return 0;
        }
        if(n== 1)
        {
            return 1;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        int sum = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    int n;
    Solution s;
    int ans = s.fib(n);
    cout << ans << endl;
}