class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // create a checklist for each char if is is present in the substring or not
        vector<int> check(256, -1);
        string sub = "";
        //initiate a start of the substring initially set to 0.
        int left = 0;
        int r = 0;
        int maxsize = 0;
        //sub.size() - left gives the length of the required substring it should be less than the s.size().
        while(r < s.size()){
            //if substr is empty append it directly
            if(!sub.size()){
                check[s[r]] = r;
                }
            // else if the current element is not present in the substring append
            else if(check[s[r]] == -1){
                check[s[r]] = r;
            }
            // else if the element is present reset the checklist and start a new subarray from the current element 
            else{
                if(left < check[s[r]] + 1)left = check[s[r]] + 1;
                check[s[r]] = r;
            }
            sub.push_back(s[r]);
            //store the max of such subarrays 
            if(r - left + 1 > maxsize)maxsize = r - left + 1;
            r++;
        }
        return maxsize;
    }
};