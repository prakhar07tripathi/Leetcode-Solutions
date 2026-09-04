class Solution {
    private:
    vector<int> prefixmax(vector<int> nums){
        int n = nums.size();
        vector<int> prefmax(n);
        prefmax[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefmax[i] = max(prefmax[i-1], nums[i]); 
        }
        return prefmax;
    }
    vector<int> suffixmin(vector<int> nums){
        int n = nums.size();
        vector<int> suffmin(n);
        suffmin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suffmin[i] = min(suffmin[i+1], nums[i]); 
        }
        return suffmin;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int minstable = INT_MAX;
        vector<int>prefmax = prefixmax(nums);
        vector<int>suffmin = suffixmin(nums);
        for(int i = 0; i < nums.size(); i++){
            if(prefmax[i] - suffmin[i] <= k){
                minstable = min(minstable, i);
            }
        }
        if(minstable == INT_MAX)return -1;
        return minstable;
    }
};