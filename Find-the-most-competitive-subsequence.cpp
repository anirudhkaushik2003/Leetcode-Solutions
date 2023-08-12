#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> s;
        int left = k;
        for(int i = 0;i < n;i++)
        {
            while(n-i >= left && left <= k )
            {
                if(!s.empty() && s.top() > nums[i] && n-i > left) 
                {
                    s.pop();
                    left++;
                }
                else {
                    if(left > 0)
                    {
                        s.push(nums[i]);
                        left--;
                    }
                    break;
                };
            }   
            
        }
        vector<int> ans(k);
        int j = k-1;
        while(!s.empty())
        {
            ans[j] = s.top();
            s.pop();
            j--;
        }
        return ans;
    }
};