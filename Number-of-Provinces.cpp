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
    void make_set(ll v, vll &parent, vll &rank)
    {
        parent[v] = v;
        rank[v] = 0;
    }

    ll find_set(ll v, vll &parent)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v], parent);
    }

    void union_sets(ll a, ll b, vll &parent, vll &rank)
    {
        a = find_set(a, parent);
        b = find_set(b, parent);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        if (n == 1)
            return 1;
        vll parent(n, 0);
        vll rank(n, 0);
        for (int i = 0; i < n; i++)
        {
            make_set(i, parent, rank);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    union_sets(i, j, parent, rank);
                }
            }
        }
        set<int> provinces;
        for (int i = 0; i < n; i++)
        {

            provinces.insert(find_set(i, parent));
        }
        return provinces.size();
    }
};