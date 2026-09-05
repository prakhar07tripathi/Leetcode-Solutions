class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tar = target;
        int mindiffsum = 1e4;
        int mindiff = INT_MAX;
        for(int i = 0; i < n; i++){
            int l = i + 1;
            int r = n - 1; 
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == tar)return target;
                else if(sum < tar){
                    if(tar - sum < mindiff){
                        mindiff = tar - sum;
                        mindiffsum = sum;
                    }
                    l++;
                }
                else{
                    if(sum - tar < mindiff){
                        mindiff = sum - tar;
                        mindiffsum = sum;
                    }
                    r--;
                }
            }
        }
        return mindiffsum;
    }
};