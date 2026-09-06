class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>tmap1;
        int req = t.size();
        int arr[2] = {0,-1};
        int r = 0,l = 0, minlen = INT_MAX;
        for(int i = 0; i < t.size(); i++){
            tmap1[t[i]]++;
        }
        if(!tmap1.size())return "";
        while(r < s.size()){
            if(tmap1.find(s[r]) != tmap1.end()){
                if(tmap1[s[r]] > 0){
                req--;
                }
                tmap1[s[r]]--;
            }
            while(l <= r && req <= 0){
                if(minlen > (r-l+1)){
                arr[0] = l;
                arr[1] = r;
                minlen = (r-l+1);
                }
                if(tmap1.find(s[l]) != tmap1.end()){
                    if(tmap1[s[l]] >= 0){
                        req++;
                    }
                    tmap1[s[l]]++;
                    }
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? "" : s.substr(arr[0], arr[1]-arr[0] + 1);
    }
};