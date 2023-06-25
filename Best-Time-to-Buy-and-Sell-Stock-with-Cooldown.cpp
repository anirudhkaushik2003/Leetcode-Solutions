#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vi s1(n ), s2(n), s3(n);
        s1[0] = 0;
        s2[0] = -prices[0];
        s3[0] = 0;

        for(int i  = 1; i< n;i++)
        {
            s1[i] = max(s1[i-1], s3[i-1]);
            s2[i] = max(s1[i-1]-prices[i], s2[i-1]);
            s3[i] = s2[i-1] + prices[i];
        }
        return max(s1[n-1], s3[n-1]);


    }
};

int main()
{
    Solution a;
    vi input = {6,1,3,2,4,7};
    cout << a.maxProfit(input) << endl;
    return 0;
}