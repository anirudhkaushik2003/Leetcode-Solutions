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
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        int i = 0;
        int top;
        int area;
        int max_area = 0;
        while (i < n)
        {
            if (s.empty() || heights[s.top()] < heights[i])
            {
                s.push(i++);
            }
            else
            {
                top = s.top();
                s.pop();
                area = heights[top] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(area, max_area);
            }
        }
        while (!s.empty())
        {
            top = s.top();
            s.pop();
            area = heights[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(area, max_area);

        }
        return max_area;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {1,2,3,4,5};
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}