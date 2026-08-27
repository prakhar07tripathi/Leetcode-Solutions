class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mpp;
        int i;
        int j;
        for(i = 0; i < nums.size(); i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                j = mpp[target - nums[i]];
                break;
            }
            mpp[nums[i]] = i;
        }
        return {i,j};
    }
};