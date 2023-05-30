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
    string shortestPalindrome(string s)
    {
        int n = s.size();
        if (!n)
            return "";
        int j = n - 1, i = 0;
        while (j >= 0)
        {
            if (s[j] == s[i])
            {
                i++;
            }
            j--;
        }
        if (i == n)
        {
            return s;
        }
        else
        {
            string ans = s.substr(i);
            reverse(ans.begin(), ans.end());
            return ans + shortestPalindrome(s.substr(0, i)) + s.substr(i);
        }
    }
};
int main()
{
    string ss = "abcd";
    Solution s;
    string ans = s.shortestPalindrome(ss);
    cout << ans << endl;
}