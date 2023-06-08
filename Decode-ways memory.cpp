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
    // bottom up approach
        vi cur = vi(3, 1);


public:
    int numDecodings(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size();
        cur[2] = 1;
        int i = n - 1;
        cur[1] = (s[i] == '0' ? 0 : cur[2]); // dp_i = number of ways to decode a string starting at i and ending at n
        i--;
        if (i >= 0)
        {
            cur[0] = (s[i] == '0') ? 0 : cur[1];
        }
        else
        {
            cur[0] = cur[1];
        }
        if (1 < n)
        {
            if (s[n - 2] == '1' || (s[n - 2] == '2' && s[n - 1] < '7'))
            {
                cur[0] += cur[2];
            }
        }

        for (i = n - 3; i >= 0; i--)
        {
            cur[2] = cur[1];
            cur[1] = cur[0];
            if (s[i] == '0')
            {
                cur[0] = 0;
            }
            else
            {
                cur[0] = cur[1];
                if (i + 1 < n)
                {
                    if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))
                    {
                        cur[0] += cur[2];
                    }
                }
            }

            // cout << i << " " << dp[i] << endl;
        }
        return cur[0]; // starting at 0 and ending at n
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