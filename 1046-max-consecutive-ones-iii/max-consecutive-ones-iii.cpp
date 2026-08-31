class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cnt;
        int maxone = 0;
        if(nums[l] == 0)cnt = 1;
        else cnt = 0;
        while(r < nums.size()){
            if(cnt <= k){
                maxone = max(maxone, r-l+1);
            }
            else{
                while(cnt > k){
                    if(nums[l] == 0)cnt--;
                    l++;
                }
            }
            r++;
            if(r < nums.size() && nums[r] == 0){
                cnt++;
            }
        }
        return maxone;
    }
};