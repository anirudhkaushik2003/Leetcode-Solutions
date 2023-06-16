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
        int cur_price = prices[0];
        int profit = 0;
        int max_profit = 0;
        for(int i = 1; i<n;i++)
        {
            if(prices[i] > prices[i-1] )
            {
                profit = prices[i] - cur_price;
            }
            else{
                cur_price = prices[i];
                max_profit +=  profit;
                profit = 0;
            }
        }
        max_profit += profit;
        return max_profit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1,2,3,4,5};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}