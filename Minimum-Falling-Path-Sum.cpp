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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] += min(matrix[i-1][j], min(((j > 0) ? matrix[i-1][ j - 1] : INT_MAX), ((j < n - 1) ? matrix[i-1][j+1] : INT_MAX)));
            }
        }

        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};

int main()
{
    vector<vi> matrix;
    Solution s;
    int ans = s.minFallingPathSum(matrix);
    cout << ans << endl;
}