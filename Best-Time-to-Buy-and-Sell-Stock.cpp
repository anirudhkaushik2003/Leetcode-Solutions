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
        int min_price = prices[0];
        int money = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            min_price= min(prices[i], min_price);
            money = max(prices[i] - min_price, money);
        }
        return money;
    }
};