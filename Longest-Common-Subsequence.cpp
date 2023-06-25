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
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        text1 = " " + text1;
        text2 = " " + text2;

        if (n < m)
        {
            swap(n, m);
            swap(text1, text2);
        }

        vi prev(n + 1, 0);
        vi cur(n+1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[j] == text2[i])
                {
                    cur[j] = prev[j-1] + 1;
                }
                else
                {
                    cur[j] = max(prev[j - 1], max(cur[j - 1], prev[j]));
                }
            }
            prev = cur;
        }
        return cur[n];
    }
};