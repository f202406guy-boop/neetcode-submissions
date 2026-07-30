class Solution {
public:
    vector<int> mem;
    int dp(int idx,vector<int>&n){
        if (idx==n.size()-1) return 1000;
        if(idx>n.size()-1) return -1;
        if(n[idx]==0 && idx!=n.size()-1) return -1;
        if(mem[idx]!=-5) return mem[idx];
        int mx=0;
        for(int i=1;i<=n[idx];i++)
        {
            mx=max(mx,dp(i+idx,n));
        }
        return mem[idx]=mx;
    }
    bool canJump(vector<int>&nums) {
        mem.assign(nums.size(),-5);
        if(dp(0,nums)==1000) {return true;}
        else return false;
    }
};
