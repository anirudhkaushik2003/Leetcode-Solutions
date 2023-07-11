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
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        if (n == 1)
            return 0;
        int s1;
        int s2;
        int s3;
        int s4;
        s1 = -prices[0];
        s2 = INT_MIN;
        s3 = INT_MIN;
        s4 = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1 + prices[i]);
            s3 = max(s3, s2 - prices[i]);
            s4 = max(s4, s3 + prices[i]);
        }
        return s4;
    }
};

int main()
{
    Solution s;
    vi prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int ans = s.maxProfit(prices);
    cout << ans << endl;
}