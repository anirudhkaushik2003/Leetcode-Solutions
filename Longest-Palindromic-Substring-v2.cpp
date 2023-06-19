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
    int LPS(string &s, int l, int r)
    {
        if (l < r)
        {
            if (s[l] == s[r])
                return 2 + LPS(s, l + 1, r - 1);
            else
                return max(LPS(s, l + 1, r), LPS(s, l, r - 1));
        }
        else if (l == r)
        {
            return 1;
        }
        else
            return 0;
    }
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();

        int i = 0, j = n - 1;
        return LPS(s, i, j);
    }
};

int main()
{
    string s = "bbbab";

    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;
}