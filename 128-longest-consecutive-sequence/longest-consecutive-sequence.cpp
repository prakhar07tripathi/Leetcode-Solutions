class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // edge case when array is empty
        if (n == 0) return 0;
        // initialize the min consecutive sequence size
        int longest = 1;
        // we insert the elements into an unordered set to be able to use the .find() function of it and it also eliminates duplicates
        unordered_set<int> start;
        for (int i = 0; i < n; i++){
            start.insert(nums[i]);
        }

        int cnt = 1;
        for (auto it : start){
            // first we find the start point by checking for each elements its predecessor that is (it - 1) is present or not
            // .find() function helps us do this in constant time
            if(start.find(it-1) == start.end())
            {
                int cnt = 1;
                int x = it;
                // now simply we increase cnt till the sequence is continuous
                while (start.find(x+1) != start.end()){
                    x++;
                    cnt++;
                }   
                // we can have multiple continuous sequences (often times of length one and the max) so we keep a track of the max length until now. 
                longest = max(longest,cnt);
            }  
        }
        // the max value is then returned
        return longest;
    }
};