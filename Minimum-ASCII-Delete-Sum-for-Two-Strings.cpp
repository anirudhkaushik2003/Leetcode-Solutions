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
    int minimumDeleteSum(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        s1 = " " + s1;
        s2 = " " + s2;
        if (n < m)
        {
            swap(n, m);
            swap(s1, s2);
        }

        vector<vi> dp(m + 1, vi(n + 1, 0));
        dp[0][0] = 0;

        // vector<vector<string>> ds(m + 1, vector<string>(n + 1, ""));
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = s1[i] + dp[0][i - 1];
            // ds[0][i] = ds[0][i - 1] + s1[i];
        }
        for (int j = 1; j <= m; j++)
        {
            dp[j][0] = s2[j] + dp[j - 1][0];
            // ds[j][0] = ds[j - 1][0] + s2[j];
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[j] == s2[i])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    // ds[i][j] = ds[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(s1[j] + dp[i][j - 1], min(s2[i] + dp[i - 1][j], s1[j] + s2[i] + dp[i - 1][j - 1]));
                    // if (min(s1[j] + dp[i][j - 1], min(s2[i] + dp[i - 1][j], s1[j] + s2[i] + dp[i - 1][j - 1])) == (s1[j] + s2[i] + dp[i - 1][j - 1]))
                    // {
                    //     ds[i][j] = ds[i - 1][j - 1] + s1.substr(j, 1) + s2.substr(i, 1);
                        
                    // }

                    // else if (min(s1[j] + dp[i][j - 1], min(s2[i] + dp[i - 1][j], s1[j] + s2[i] + dp[i - 1][j - 1])) == (s2[i] + dp[i - 1][j]))
                    // {
                    //     ds[i][j] = ds[i - 1][j] + s2.substr(i, 1);
                    //     // cout << i-1 << " " << j << " " << ds[i-1][j] << endl;
                    // }
                    // else if (min(s1[j] + dp[i][j - 1], min(s2[i] + dp[i - 1][j], s1[j] + s2[i] + dp[i - 1][j - 1])) == (s1[j] + dp[i][j - 1]))
                    // {
                    //     ds[i][j] = ds[i][j - 1] + s1.substr(j, 1);
                    //     // cout << i << " " << j-1 << " " << ds[i][j-1] << endl;
                    // }
                }
                // if(j == 1)
                // {
                //     // cout << i << " " << j << " " << dp[i][j] << " " << ds[i][j] << endl;
                //     // cout << "min value: " << min(s1[j] + dp[i][j - 1], min(s2[i] + dp[i - 1][j], s1[j] + s2[i] + dp[i - 1][j - 1])) << endl;
                //     // cout << "delete s1: " << s1[j] + dp[i][j - 1] << endl;
                //     // cout << "delete s2: " << s2[i] + dp[i - 1][j] << endl;
                //     // cout << "delete both: " << s1[j] + s2[i] + dp[i - 1][j - 1] << endl;
                // }
            }
        }
        // ds[0][0] = " ";

        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         cout << ds[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        return dp[m][n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    string s1, s2;
    s1 = "sea";
    s2 = "eat";

    cout << sol.minimumDeleteSum(s1, s2) << endl;
}