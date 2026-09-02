class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int ,int>prefsum;
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            prefsum[sum]++;
            sum += nums[i];
            if(prefsum.find(sum - goal) != prefsum.end()){
                cnt += prefsum[sum - goal];
            }
        }
        return cnt;
    }
};