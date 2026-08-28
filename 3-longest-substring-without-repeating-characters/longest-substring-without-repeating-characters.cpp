class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // create a checklist for each char if is is present in the substring or not
        int arr[256] = {0};
        string sub = "";
        //initiate a start of the substring initially set to 0.
        int left = 0;
        int i = 0;
        int maxsize = 0;
        //sub.size() - left gives the length of the required substring it should be less than the s.size().
        while(sub.size() - left < s.size() && i < s.size()){
            //if substr is empty append it directly
            if(!sub.size()){
                arr[s[i]] = 1;
                }
            // else if the current element is not present in the substring append
            else if(!arr[s[i]]){
                arr[s[i]] = 1;
            }
            // else if the element is present reset the checklist and start a new subarray from the current element 
            else{
                while(s[left] != s[i]){
                    arr[s[left]] = 0;
                    left++;
                }
                left++;
                arr[s[i]] = 1;
            }
            sub.push_back(s[i]);
            //store the max of such subarrays 
            if(sub.size() - left > maxsize)maxsize = sub.size() - left;
            i++;
        }
        return maxsize;
    }
};