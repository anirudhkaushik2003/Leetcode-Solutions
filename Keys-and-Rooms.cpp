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
    // void dfs(int node, vector<vi> &graph, vector<bool> &visited)
    // {
    //     if (!visited[node])
    //     {
    //         visited[node] = true;
    //         for (auto it : graph[node])
    //         {
    //             dfs(it, graph, visited);
    //         }
    //     }
    //     else
    //     {
    //         return;
    //     }
    // }
    // iterative method for dfs using stack
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {

        int n = rooms.size();

        vector<bool> visited(n, false);
        stack<int> to_visit;
        to_visit.push(0);
        while (!to_visit.empty())
        {
            int node = to_visit.top();
            to_visit.pop();
            if (!visited[node])
            {
                visited[node] = true;

                for (auto it : rooms[node])
                {
                    if (!visited[it])
                    {
                        to_visit.push(it);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                return false;
            }
        }
        return true;
    }
};