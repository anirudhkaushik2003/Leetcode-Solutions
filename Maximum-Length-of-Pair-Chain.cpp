#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {

        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), sortcol);

        vi left(n);
        vi right(n);

        vi dp(n, 1);
        int max_so_far = 1;
        for (int i = 0; i < n; i++)
        {
            left[i] = pairs[i][0];
            right[i] = pairs[i][1];

        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (right[j] < left[i])
                {
                    // cout << pairs[j][0] << " " << pairs[j][1] << " " << pairs[i][0] << " " << pairs[i][1] << endl;
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_so_far = max(max_so_far, dp[i]);
        }
        return max_so_far;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution ob;

    vector<vector<int>> v = {{1, 7}, {2, 3}, {3, 4}};

    cout << ob.findLongestChain(v) << endl;

    return 0;
}