#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

// weighed breadth first search
class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {

        queue<pii> q;

        q.push(mp(headID, 0));
        vector<bool> visited(n, false);

        vector<vi> managers(n, vi());

        for(int i = 0; i<n;i++)
        {
            if(manager[i] == -1)
            {
                continue;
            }
            
            managers[manager[i]].pb(i);
        }

        int max_time = 0;

        while (!q.empty())
        {
            auto it = q.front();

            int head = it.first;
            int time = it.second;

            visited[head] = true;
            q.pop();

            for (auto employee: managers[head])
            {
                    if (!visited[employee])
                    {
                        q.push(mp(employee, time + informTime[head]));
                        max_time = max(max_time, time + informTime[head]);
                    }
            }
        }
        return max_time;
    }
};