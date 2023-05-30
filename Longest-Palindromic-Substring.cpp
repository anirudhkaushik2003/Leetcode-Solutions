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
    string longestPalindrome(string s)
    {
        string rs = s;
        reverse(rs.begin(), rs.end());

        if(s == rs)
        {
            return s;
        }
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, end = 0, max_len = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            if(i+1<n)
            {
                dp[i][i+1] = (s[i] == s[i+1]);
                if(dp[i][i+1] == true && max_len < 2)
                {
                    max_len = 2;
                    start = i;
                    end = i+1;
                }
            }

        }
        int i, j;
        int len = 2;
        while( len < n-1)
        {
            for(int i = 0;i <n;i++)
            {
                if(i+len>=n)
                {
                    break;
                }
                else{
                    dp[i][i+len] = dp[i+1][i+len-1] && (s[i] == s[i+len]);
                    if(dp[i][i+len] == true&& max_len < (len+1) )
                    {
                        max_len = len+1;
                        start = i;
                        end = i+len;
                    }
                } 
            }
            len++;
        }
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    string ss = "aaaaaa";
    Solution s;
    string ans = s.longestPalindrome(ss);
    cout << ans << endl;
}