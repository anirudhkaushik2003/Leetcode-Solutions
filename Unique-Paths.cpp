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
    int uniquePaths(int m, int n)
    {
        vi prev(n,1);
        vi curr(n,1);
        for(int i= 1;i<m;i++)
        {
            for(int j = 1;j < n;j++ )
            {
                curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        return curr[n-1];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution s;
    int ans = s.uniquePaths(m, n);
    cout << ans << endl;
}