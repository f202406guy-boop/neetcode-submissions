#define ll long long 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
    vector<int> prfx(n,0);int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)  cnt++;
        prfx[i]=cnt;
    }
    if(prfx[n-1]<goal) return 0;
    map<int,int> mp;
    for(auto i:prfx) mp[i]++;

    int mx=prfx[n-1]; int ans=0;
    if (goal>0){
    for(int i=0;i<=mx-goal;i++)
    {
      ans+=(i==0?(mp[i]+1)*mp[i+goal]:mp[i]*mp[i+goal]);
    }
    
    }
    else{ for(int i=0;i<=mx-goal;i++)
    {
      ans+=i==0 ? (mp[i]*(mp[i]+1))/2: (mp[i]*(mp[i]-1))/2;
      for(auto i:prfx) cout<<i<<" ";
      cout<<endl;
     
    }
    }
    return ans;
    }
};