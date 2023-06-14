#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

// find minimum spanning tree
// for each vertice, if it contains no edges other than the ones present in the minimum spanning tree, you can remove it

class Solution
{
public:
    void dfsBR(int u, int p, vi &low, vi &disc, vector<vi> &adj, int Time, vector<vi> &br)
    {
        low[u] = disc[u] = ++Time;
        for (int &v : adj[u])
        {
            if (v == p)
                continue; // we don't want to go back through the same path.
                          // if we go back is because we found another way back
            if (!disc[v])
            {                                      // if V has not been discovered before
                dfsBR(v, u, low, disc, adj, Time, br); // recursive DFS call
                if (disc[u] < low[v])              // condition to find a bridge
                {
                    br.push_back({});
                    br.back().push_back(u);
                    br.back().push_back(v);
                }
                low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
            }
            else                               // if v was already discovered means that we found an ancestor
                low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<vi> graph(n, vi());
        vector<vll> cycle_edges;
        vector<vi> critical_connections;
        for (int i = 0; i < connections.size(); i++)
        {
            if (connections[i][0] > connections[i][1])
            {
                swap(connections[i][0], connections[i][1]);
            }

            graph[connections[i][0]].pb(connections[i][1]);
            graph[connections[i][1]].pb(connections[i][0]);
        }
        // find bridges
        vi low(n, 0), disc(n, 0);
        int Time = 0;
        for (int u = 0; u < n; u++)
            if (!disc[u])
                dfsBR(u, u, low, disc, graph, Time, critical_connections);

        return critical_connections;
    }
};

int main()
{
    Solution s;
    // connections = [[0,1],[1,2],[2,0],[1,3],[3,4],[4,5],[5,3]]
    vector<vi> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}, {4, 5}, {5, 3}};
    vector<vi> critical_connections = s.criticalConnections(6, connections);
        for (auto connection : critical_connections)
        {
            for (auto node : connection)
            {
                cout << node << " ";
            }
            cout << endl;
        }
}