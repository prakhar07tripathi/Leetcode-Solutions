class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gindex = 0;
        int sindex = 0;
        int content = 0;
        while(gindex < g.size() && sindex < s.size()){
            if(s[sindex] >= g[gindex]){
                content++;
                gindex++;
            }
            sindex++;
        }
        return content;
    }
};