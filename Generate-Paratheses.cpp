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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m1 = nums1.size();
        int m2 = nums2.size();
        int m = m1+m2;


        if(m1 > m2) return findMedianSortedArrays(nums2,nums1);

        if (m1 == 0){
            return m2%2? nums2[m2/2] : (nums2[m2/2] + nums2[m2/2-1])/2.0;
        }
        if (m2 == 0){
            return m1%2? nums1[m1/2] : (nums1[m1/2] + nums1[m1/2-1])/2.0;
        }


        int c1  = m1/2;

        int c2 = (m+1)/2 - c1;


        // int u1 = upper_bound(nums1.begin(), nums1.end(), nums2[c2]) - nums1.begin();
        // int u2 = lower_bound(nums2.begin(), nums2.end(), nums1[c1]) - nums2.begin();
   
        int l1, l2, r1, r2;
        int left1 = 0, right1 = m1;
        while(left1 <= right1)
        {
            l1 = c1 <= 0? INT_MIN:nums1[c1-1];
            l2 = c2 <=0 ? INT_MIN:nums2[c2-1];

            r1 = c1 >=m1?INT_MAX:nums1[c1];
            r2 = c2 >=m2?INT_MAX:nums2[c2];

            if(l1 <= r2 && l2 <= r1){
                return (m%2)?max(l1,l2) : (max(l1,l2) + min(r1,r2))/2.0;
            }

            if(l1 > r2)
            {
                right1 = c1-1;
            }
            else{
                left1 = c1+1;
            }

            c1 = (left1+right1)/2;
            c2 = (m+1)/2 - c1;

        }
        return 0.0;
    }
};

int main()
{
    vi nums1 {};
    vi nums2 {2,3};
    Solution s;
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
}