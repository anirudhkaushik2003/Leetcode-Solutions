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
    // declare a vector of size 101 and initialize it with -1
    vector<int> dp = vector<int>(101, -1);

public:
    int numDecodings(string s)
    {
        return s.empty() ? 0 : numDecodings(0, s);
    }

    int numDecodings(int p, string s)
    {
        int n = s.size();
        if (dp[p] == -1)
        {
            if (p == n)
            {
                dp[p] = 1;
                return 1;
            };
            if (s[p] == '0')
            {
                dp[p] = 0;
                return 0; // invalid string starting with 0
            }
            int res = numDecodings(p + 1, s);
            if (p + 1 < s.length())
            {
                if (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7'))
                {
                    res += numDecodings(p + 2, s);
                }
            }
            dp[p] = res;
            return res;
        }
        else
        {
            return dp[p];
        }
    }
};

int main()
{
    string S;
    cin >> S;
    Solution s;
    int ans = s.numDecodings(S);
    cout << ans << endl;
}