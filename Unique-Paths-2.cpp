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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vi cur(n, 0);
        vi prev(n, 0);

        prev[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        cur[0] = prev[0];
        for (int i = 1; i < n; i++)
        {
            if (obstacleGrid[0][i] == 1)
            {
                prev[i] = 0;
                cur[i] = 0;
            }
            else
            {
                prev[i] = prev[i - 1];
                cur[i] = prev[i];
            }
        }

        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                cur[0] = 0;
            else
                cur[0] = prev[0];
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    cur[j] = 0;
                else
                // cur[j] = ((obstacleGrid[i - 1][j] == 1) ? 0 : prev[j]) + ((obstacleGrid[i][j - 1] == 1) ? 0 : cur[j - 1]);
                {
                    cur[j] = prev[j] + cur[j - 1];
                }
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
    int ans = s.uniquePathsWithObstacles(grid);
    cout << ans << endl;
}