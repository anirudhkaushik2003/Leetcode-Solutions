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
    int uniquePaths(int m, int n)
    {
        vector<vi> dp(m, vi(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for(int i= 1;i<m;i++)
        {
            for(int j = 1;j < n;j++ )
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution s;
    int ans = s.uniquePaths(m, n);
    cout << ans << endl;
}