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
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vi> dp(m, vi(n, 0));

        int cur_max = 0;
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            if (cur_max < dp[0][i])
                cur_max = dp[0][i];
        }
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            if (cur_max < dp[i][0])
                cur_max = dp[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int to_add = min(dp[i - 1][j], dp[i][j - 1]);

                    while (to_add)
                    {
                        if (matrix[i - to_add][j - to_add] == '1')
                        {
                            break;
                        }
                        to_add--;
                    }
                    dp[i][j] = to_add + 1;
                    if (cur_max < dp[i][j])
                        cur_max = dp[i][j];
                }
            }
        }
        return cur_max * cur_max;
    }
};

int main()
{
    vector<vector<char>> matrix;
    Solution s;
    int ans = s.maximalSquare(matrix);
    cout << ans << endl;
}