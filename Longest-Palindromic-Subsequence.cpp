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
    int LPS(string &s, int l, int r, vector<vector<int>> &memoized)
    {

        if (l < r)
        {
            if (memoized[l][r] != -1)
                return memoized[l][r];
            if (s[l] == s[r])
            {
                memoized[l][r] = 2 + LPS(s, l + 1, r - 1, memoized);
                return memoized[l][r];
            }
            else
            {
                memoized[l][r] = max(LPS(s, l + 1, r, memoized), LPS(s, l, r - 1, memoized));
                return memoized[l][r];
            }
        }
        else if (l == r)
        {
            return memoized[l][r];

        }
        else
            return 0;
    }
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();

        vector<vector<int>> memoized(n, vi(n, -1));
        for (int i = 0; i < n; i++)
        {
            memoized[i][i] = 1;
        }
        return LPS(s, 0, n - 1, memoized);
    }
};

int main()
{
    string s = "bbbab";

    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;
}