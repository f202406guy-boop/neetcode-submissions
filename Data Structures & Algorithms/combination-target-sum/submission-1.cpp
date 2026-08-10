class Solution {
public:
    vector<vector<int>> ret;

    void dp(int x, vector<int> &nums, vector<int> &temp, int idx) {
        if(x == 0) {
            ret.push_back(temp);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {   
            if(x - nums[i] >= 0) {
                temp.push_back(nums[i]);

                dp(x - nums[i], nums, temp, i);   

                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        dp(target, nums, temp, 0);   
        return ret;
    }
};
