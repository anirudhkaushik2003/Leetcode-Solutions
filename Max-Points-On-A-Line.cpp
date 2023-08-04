class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;
        vector<pair<float,float>> eq;

        for (int i =0;i < n;i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j<n;j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if((x2-x1) == 0) 
                {
                    float m = 1e5;
                    float c = float(x1);

                    eq.push_back(make_pair(m,c));
                }
                else
                {
                    float m = ((float)(y2-y1))/((float)(x2-x1));
                    float c = (float)y1 - ((float)m*x1);

                    eq.push_back(make_pair(m,c));
                }
            }
        }

        int count = 1;
        int ans = 1;
        float m,c;
        int p = eq.size();
        if(p > 0)
        {
            sort(eq.begin(), eq.end());
            c = eq[0].second;
            m = eq[0].first;
            for(int i = 1; i<p;i++)
            {
                if((abs(eq[i].first - m) < 1e-4) && (abs(eq[i].second - c) < 1e-4))
                {
                    count++;
                }
                else{
                    ans = max(ans, count);
                    m = eq[i].first;
                    c = eq[i].second;
                    count = 1;
                }
            }
            ans = max(ans, count);
        }
        cout << ans << endl;


        if(ans == 1)
        {
            ans = 2;
        }
        else if(ans >3)
        {
            int l = 0;
            int r = ans -1;
            int mid;
            while(l<=r)
            {
                mid = (l+r) >> 1;
                if(mid*(mid-1) == (2*ans))
                {
                    ans = mid;
                    break;
                }
                else if(mid*(mid-1) > (2*ans)){
                    r = mid-1;
            
                }
                else{
                    l = mid+1;
                }
            }
        }

        return ans;
    }
};
