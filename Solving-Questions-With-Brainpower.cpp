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
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vi dp(n, 0);
        int cur_max = 0;

        for (int i = n - 1; i > -1; i--)
        {
            if (i + questions[i][1] + 1 < n)
                dp[i] = questions[i][0] + dp[i + questions[i][1] + 1];
            else
                dp[i] = questions[i][0];
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