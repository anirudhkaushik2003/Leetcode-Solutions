#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        if(p.length() >=2 && p[1] == '*')
        {
            
            return ((isMatch(s, p.substr(2, p.size()))) || (first_match && isMatch(s.substr(1,s.size()), p))); // first part is to match prefix substrings of length 0 (* matches for length 0 or more)
        }   
        else{
            return (first_match && isMatch(s.substr(1,s.size()), p.substr(1,p.size())));
        }
        
    }
};

int main()
{
    string s, p;
    s = "";
    p = "";
    Solution S;
    bool ans = S.isMatch(s,p);
    cout << ans << endl;
}