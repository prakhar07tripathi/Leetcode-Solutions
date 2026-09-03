class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0];
        int oddcnt = 0;
        for(int i = 0; i < nums1.size(); i++){
            mini = min(mini, nums1[i]);
            if(nums1[i] % 2 != 0)oddcnt++;
        }
        if(mini % 2 != 0 || !oddcnt)return true;
        return false;
    }
};