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

        for (auto it : hashmap)
        {
            cout << it.first << " ";
            for (auto str : it.second)
            {
                cout << str << " ";
            }
            cout << endl;
        }
        int m = s.size();
        vi dp(m, -1);
        len_sort c;
        sort(wordDict.begin(), wordDict.end(), c);

        int last_ind = 0;
        for (int i = m-1; i >= 0; i--)
        {
            int cur_len = i + 1 - last_ind;
            // cout << m -last_ind +  dp[last_ind-1] << endl;
            if (hashmap.find(cur_len) == hashmap.end())
                continue;

            for (auto it : hashmap[cur_len])
            {
                cout << "length: " << cur_len << endl;
                cout << "substring: " << s.substr(last_ind, cur_len) << " "
                     << "iterator: " << it << " matched: " << (s.substr(last_ind, cur_len) == it) << endl;
                if (s.substr(last_ind, cur_len) == it)
                {
                    dp[i] = cur_len;
                    last_ind = i + 1;
                }
            }
        }
        // cout << "last_ind: " << last_ind << endl;
        return (last_ind == m) ? true : false;
    }
};

int main()
{
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaaa", "aaa"};

    Solution S;
    cout << S.wordBreak(s, wordDict) << endl;
}