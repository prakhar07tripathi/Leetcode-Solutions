class Solution {
    private:
    bool stable(vector<int> nums, int i, int k){
        if(localmax(nums, i) - localmin(nums, i) <= k)return true;
        return false;
    }
    int localmax(vector<int> nums, int i){
        int maxi = -1;
        for(int j = 0; j <= i; j++){
            maxi = max(maxi, nums[j]);
        }
        return maxi;
    }
    int localmin(vector<int> nums, int i){
        int mini = nums[i];
        for(int j = i; j < nums.size(); j++){
            mini = min(mini, nums[j]);
        }
        return mini;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minstable = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(stable(nums, i, k)){
                minstable = min(minstable, i);
            }
        }
        if(minstable == INT_MAX)return -1;
        return minstable;
    }
};