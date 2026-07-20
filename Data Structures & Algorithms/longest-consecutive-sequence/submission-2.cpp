
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set s(nums.begin(),nums.end());
        vector<int> v;
        for(auto i:s){v.push_back(i);}
        int n=v.size();
        int cnt=0;int temp=1;
        for(int i=1;i<n;i++)
        {
           if(v[i]==v[i-1]+1){temp++;}
           else{cnt=max(temp,cnt);temp=1;}
        }cnt=max(cnt,temp);
        for(auto i:v) cout<<i<<" ";
        cout<<n<<" ";
        if(n==0) return 0;
        return cnt;
 }
};
