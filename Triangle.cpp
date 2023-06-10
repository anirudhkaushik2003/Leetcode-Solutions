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
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vi prev = triangle[0];
        if (n == 1)
        {
            return prev[0];
        }
        vi cur = triangle[1];
        int cur_min = INT_MAX;
        for (int i = 0; i < triangle[1].size(); i++)
        {
            cur[i] += prev[0];
            cur_min = min(cur_min, cur[i]);
        }
        prev = cur;
        for (int i = 2; i < n; i++)
        {
            cur = triangle[i];
            cur[0] += prev[0];
            cur_min = cur[0];
            for (int j = 1; j < cur.size(); j++)
            {
                cur[j] += min(((j < prev.size()) ? prev[j] : INT_MAX), prev[j - 1]);
                cur_min = min(cur_min, cur[j]);
            }
            prev = cur;
        }
        return cur_min;
    }
};
int main()
{
    vector<vi> triangle{};
    Solution s;
    int ans = s.minimumTotal(triangle);
    cout << ans << endl;
}