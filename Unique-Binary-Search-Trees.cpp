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

class Solution {
public:
    int numTrees(int n) {
        vi G(n+1, 0);

        G[0] = 1;
        G[1] = 1;

        for(int i = 2; i <= n;i++)
        {
            for(int j = 0; j < i; j++)
            {
                G[i] += G[j]*G[i-j-1];
            }
        }      

        return G[n];
    }
};