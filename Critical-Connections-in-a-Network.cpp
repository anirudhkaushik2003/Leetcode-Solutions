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
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<vi> graph(n, vi());
        vll parent(n);
        vll rank(n);
        for (auto it : connections)
        {
            graph[it[0]].pb(it[1]);
            graph[it[1]].pb(it[0]);
        }
        for (int i = 0; i < n; i++)
        {
            make_set(i, parent, rank);
        }
        vector<vi> minimum_spanning_tree(n, vi()); // edges for each  vertex in minimum spanning tree
        for (auto it : connections)
        {
            if (find_set(it[0], parent) != find_set(it[1], parent))
            {
                union_sets(it[0], it[1], parent, rank);
                minimum_spanning_tree[it[0]].pb(it[1]);
                minimum_spanning_tree[it[1]].pb(it[0]);
            }
        }
        vector<vi> critical_connections;
        vector<vi> new_graph(n, vi());
        // remove all vertices from the graph which belong to minimum spanning tree
        for (int i = 0; i < n; i++)
        {
            sort(minimum_spanning_tree[i].begin(), minimum_spanning_tree[i].end());
            sort(graph[i].begin(), graph[i].end());
            // remove all indices in the graph which are present in the minimum spanning tree

            int j = 0;
            int k = 0;
            for (j = 0; j < minimum_spanning_tree[i].size();)
            {
                if (minimum_spanning_tree[i][j] == graph[i][k])
                {
                    j++;
                    k++;
                }
                else if (minimum_spanning_tree[i][j] > graph[i][k])
                {
                    new_graph[i].pb(graph[i][k]);
                    new_graph[graph[i][k]].pb(i);
                    cout <<"edge: " << i << " " << graph[i][k] << endl;
                    k++;
                }
            }
            while (k < graph[i].size())
            {
                new_graph[i].pb(graph[i][k]);
                new_graph[graph[i][k]].pb(i);
                k++;
            }
        }
        vector<bool> visited(n, false);
        vector<bool> avoid(n, false);
        for (int i = 0; i < n; i++)
        {
            if (new_graph[i].size() != 0)
                avoid[i] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (new_graph[i].size() == 0)
            {
                if (visited[i])
                    continue;
                visited[i] = true;
                for (auto it : minimum_spanning_tree[i])
                {
                    if (visited[it] || avoid[it])
                        continue;
                    critical_connections.pb({i, it});
                    visited[it] = true;
                }
            }
        }
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