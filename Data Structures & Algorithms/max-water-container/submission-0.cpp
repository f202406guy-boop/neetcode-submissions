class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int l=0,r=n-1;
        int mx=0;
        while(l<r)
        {
           int tmp=min(h[l],h[r])*(r-l);
           mx=max(mx,tmp);
           if(h[l]<h[r]) l++;
           else if(h[r]<h[l]) r--;
           else l++,r--;
        }
        return mx;
    }
};
