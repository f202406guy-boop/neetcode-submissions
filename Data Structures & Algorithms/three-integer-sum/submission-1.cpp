class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set <tuple<int,int,int>>s;
        for(int i=0;i<n;i++)
        {
            int l=0,r=n-1;
            int sm=-nums[i];
            while(l<r)
            {
               if(l==i) l++;if(r==i) r--;
               if(l>=r) break;
               if(nums[l]+nums[r]>sm) r--;
               else if(nums[l]+nums[r]<sm) l++;
               else if(nums[l]+nums[r]==sm) {
                vector<int> v({nums[i],nums[l],nums[r]});
                sort(v.begin(),v.end());
                s.insert({v[0],v[1],v[2]});
                l++;r--;
               }

            }
            
        }
        for(auto &[i,j,k]:s) cout<<i<<" "<<j<<" "<<k<<" ";
        cout<<endl;
        vector<vector<int>>v;
        for(auto& [i,j,k]:s) v.push_back({i,j,k});
        return v;
    }
};
