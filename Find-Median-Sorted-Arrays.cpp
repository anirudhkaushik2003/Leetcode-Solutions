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
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
        {
            return {""};
        }
        vector<string> ans;

        vector<string> leftString = {""};
        vector<string> rightString = {"()"};

        vector<vector<string>> dp(n+1, vector<string>());
        dp[0].pb(leftString[0]);
        dp[1].pb(rightString[0]);

        for (int i = 2; i < n+1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (auto it1 : dp[j])
                {
                    for (auto it2 : dp[i - j - 1])
                    {
                        dp[i].push_back("(" + it1 + ")" + it2);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    int n;
    Solution s;
    vector<string> ans = s.generateParenthesis(n);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}