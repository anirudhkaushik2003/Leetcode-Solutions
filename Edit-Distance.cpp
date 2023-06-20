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
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        word1 = " " + word1;
        word2 = " " + word2;

        if (n < m)
        {
            swap(n, m);
        }

        int cost = 1;
        cout << "\t";
        for (int i = 0; i <= n; i++)
        {
            cout << word1[i] << "\t";
        }
        cout << endl;

        vector<vi> dp(m + 1, vi(n + 1, 0));
        dp[0][0] = 0; // both sequences are empty

        cout << "\t" << dp[0][0] << "\t";
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = i; // sequence 2 is empty
            cout << dp[0][i] << "\t";
        }
        cout << endl;

        for (int j = 1; j <= m; j++)
        {
            dp[j][0] = j;
        }

        for (int i = 1; i <= m; i++)
        {
            cout << word2[i] << "\t";
            cout << dp[i][0] << "\t";
            for (int j = 1; j <= n; j++)
            {
                if (((word1[j] == word2[i])))
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + cost;
                cout << dp[i][j] << "\t";

                // cout << ((word1[j] == word2[i]) ? 0 : cost) << endl;
            }
            cout << endl;
        }

        return dp[m][n];
    }
};

int main()
{
    string word1 = "zoologicoarchaeologist";
    string word2 = "zoogeologist";

    Solution s;
    cout << s.minDistance(word1, word2) << endl;
}