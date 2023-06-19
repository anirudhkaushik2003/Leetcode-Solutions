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
    struct len_sort
    {
        inline bool operator()(const string &s1, const string &s2) const
        {
            return s1.size() < s2.size();
        }
    };
    bool wordBreak(string s, vector<string> &wordDict)
    {

        int n = wordDict.size();
        map<int, vector<string>> hashmap;
        for (int i = 0; i < n; i++)
        {
            int key = wordDict[i].size();
            if (hashmap.find(key) != hashmap.end())
                hashmap[key].pb(wordDict[i]);
            else
            {
                hashmap[key] = vector<string>();
                hashmap[key].pb(wordDict[i]);
            }
        }
        int m = s.size();

        vector<bool> dp(m , false);
        if (hashmap.find(1) == hashmap.end())
        {
        }
        else
        {
            for (auto it : hashmap[1])
            {
                if (s.substr(0, 1) == it)
                {
                    dp[0] = true;
                    break;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            int len = i + 1;
            for (int j = len; j > 0; j--)
            {
                if (i-j < 0 || dp[i - j ] == true)
                {
                    int cond = 0;
                    if(hashmap.find(j) == hashmap.end()) continue;
                    for (auto it : hashmap[j])
                    {
                        // cout << it << endl;
                        if (s.substr(i - j + 1, j) == it)
                        {
                            // cout << s.substr(i - j + 1, j) << " " << it << endl;
                            cond = 1;
                            dp[i] = true;
                            break;
                        }
                    }
                    if (cond == 1)
                        break;
                }
            }
        }
        return dp[m - 1];
    }
};

int main()
{
    string s = "catsanddogs";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};

    Solution S;
    cout << S.wordBreak(s, wordDict) << endl;
}