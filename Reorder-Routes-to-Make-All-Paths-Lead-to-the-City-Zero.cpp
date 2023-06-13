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
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pii>> adj(n, vector<pii>()); // first -> node, second -> direction
        int correct = 0;
        for (int i = 0; i < n - 1; i++)
        {
            adj[connections[i][0]].pb(mp(connections[i][1], 1));
            adj[connections[i][1]].pb(mp(connections[i][0], -1)); // direction is opposite to actual direction
        }
        // dfs from 0 , add 1 for every edge that is not in the right direction (from 0 to some other path)
        stack<int> s;
        s.push(0);
        int incorrect = 0;
        vector<bool> visited(n, false);

        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!visited[node])
            {
                int children = 0;
                visited[node] = true;
                for (auto it : adj[node])
                {
                    int neighbour = it.first;
                    int direction = it.second;
                    if (!visited[neighbour])

                    {

                        if (direction == 1)
                        {
                            incorrect++;
                        }
                        s.push(neighbour);
                    }
                }
            }
        }
        return incorrect;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    // int ans = s.minReorder(6, connections);
    cout << s.minReorder(6, connections);
}