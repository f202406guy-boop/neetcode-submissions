class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int curr=0;int ans=0;
        vector<int> prfx(h.begin(),h.end());
        vector<int> maxi(h.begin(),h.end());
        for(int i=n-2;i>=0;i--) maxi[i]=max(maxi[i],maxi[i+1]);
        for(int i=1;i<n;i++) prfx[i]+=prfx[i-1];
        int t=1;
        while(t<n&&curr<n)
        {
            if(h[t]>=h[curr])
            {
               int temp =h[curr]*(t-curr-1)-(prfx[t-1]-prfx[curr]);
               ans+=h[curr]*(t-curr-1)-(prfx[t-1]-prfx[curr]);
               curr=t;
               cout<<temp<<" ";
               
            }
            else if(h[curr]>maxi[curr+1]) {
                int val=maxi[curr+1];
                int init=curr;
                while(h[curr]!=val) curr++;
                ans+=val*(curr-init-1)-(prfx[curr-1]-prfx[init]);
                t=curr;
            }
            t++;
            
        }   
        return ans;
        }
        
    };