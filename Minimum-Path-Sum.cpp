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
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vi prev(n, 0);
        vi cur(n, 0);

        cur[0] = grid[0][0];
        prev[0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            // cur[i] = cur[i-1] + grid[0][i];
            prev[i] = prev[i - 1] + grid[0][i];
        }
        if(m == 1)
        {
            return prev[n-1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cur[j] = min((j > 0) ? cur[j - 1] : INT_MAX, prev[j]) + grid[i][j];
            }
            prev = cur;
        }
        return cur[n - 1];
    }
};

int main()
{
    vector<vi> grid;
    Solution s;
    int ans = s.minPathSum(grid);
    cout << ans << endl;
}