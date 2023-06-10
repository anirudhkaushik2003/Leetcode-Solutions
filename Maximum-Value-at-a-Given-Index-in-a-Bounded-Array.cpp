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
    ll getSum(ll value, ll index, ll n)
    {
        long long sum = 0;
        if (value > index)
        {
            sum += ((value + value - index) * (index + 1)) / 2;
        }
        else
        {
            sum += ((value + 1) * (value)) / 2;
            sum += (index - value + 1);
        }

        if (value > n - index)
        {
            sum += ((value + value - (n - index - 1)) * (n - index)) / 2;
        }
        else
        {
            sum += ((value + 1) * (value)) / 2;
            sum += (n - index - value);
        }

        sum -= value;
        return sum;
    }
    int maxValue(int n, int index, int maxSum)
    {
        int available = maxSum - n;

        int l = 1;
        int r = maxSum;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            ll cur_sum = getSum(mid, index, n);
            if (cur_sum <= maxSum)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main()
{
    int n, index, maxSum;
    Solution s;
    int ans = s.maxValue(n, index, maxSum);
    cout << ans << endl;
}