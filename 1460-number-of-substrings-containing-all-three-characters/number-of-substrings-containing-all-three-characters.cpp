class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        unordered_map<char, int>mpp;
        while(r < s.size()){
            mpp[s[r]] = r;
            if(mpp.size() == 3){
                cnt += min({mpp['a'], mpp['b'], mpp['c']}) + 1;
            }
            r++;
        }
        return cnt;
    }
};