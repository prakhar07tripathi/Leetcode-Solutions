class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] < 0)nums[j]*=-1;
        }
        sort(nums.begin(), nums.end());
        long long maxsum = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            if(i < nums.size()/2){
                maxsum -= nums[i]*nums[i];
            }
            else maxsum += nums[i]*nums[i];
        }
        return maxsum;
    }
};