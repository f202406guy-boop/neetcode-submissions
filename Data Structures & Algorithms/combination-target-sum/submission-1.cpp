class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num=1;
        int n=pow(2,nums.size());
        string s;
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i=1;i<n;i++)
        {
            vector<int> temp;
           s=bitset<32>(num).to_string();
           for(int j=s.size()-1;j>=0;j--)
           {
            if(s[j]=='1') temp.push_back(nums[s.size()-j-1]);
           }
           num++;
           ans.push_back(temp);
        }
        return ans;
    }
};
