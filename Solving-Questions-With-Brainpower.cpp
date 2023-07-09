#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vll dp(n, 0);
        dp[n - 1] = questions[n - 1][0];
        ll cur_max = dp[n - 1];
        for (int i = n - 2; i > -1; i--)
        {
            if (i + 1 + questions[i][1] < n)
            {

                dp[i] = max(cur_max, questions[i][0] + dp[i + 1 + questions[i][1]]);
            }
            else
            {
                dp[i] = max(cur_max, (ll)questions[i][0]);
            }
            cur_max = max(cur_max, dp[i]);
        }
        return cur_max;
    }
};

int main()
{
    Solution obj;
    // [[21,5],[92,3],[74,2],[39,4],[58,2],[5,5],[49,4],[65,3]]
    vector<vi> questions = {{21, 5}, {92, 3}, {74, 2}, {39, 4}, {58, 2}, {5, 5}, {49, 4}, {65, 3}};
    cout << obj.mostPoints(questions);
    return 0;
}