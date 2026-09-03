class Solution {
    private:
    int subarrayslessthanK(vector<int> nums, int k){
        int l = 0;
        int r = 0;
        int oddcnt = 0;
        int cnt = 0;
        while(r < nums.size()){
            if(nums[r] % 2 != 0)oddcnt++;
            while(oddcnt > k){
                if(nums[l] % 2 != 0)oddcnt--;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrayslessthanK(nums, k) - subarrayslessthanK(nums, k-1);
    }
};