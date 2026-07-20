#define ll long long ;
class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prfx(nums.begin(),nums.end());
        vector<int> sufx(nums.begin(),nums.end());
    
        for(int i=1;i<n;i++){ prfx[i]*=prfx[i-1]; }
        for(int i=n-2;i>=0;i--){sufx[i]*=sufx[i+1];}
        vector<int> ans(n);
        for(int i=1;i<n-1;i++)
        {
            ans[i]=prfx[i-1]*sufx[i+1];
        }
        ans[0]=sufx[1];
        ans[n-1]=prfx[n-2];
        return ans;
    }
};
