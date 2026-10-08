class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        int start = 0;
        string res;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(depth > 0){
                    res.push_back(s[i]);
                }
                depth++;
                }
            else {
                depth--;
                if(depth > 0){
                    res.push_back(s[i]);
                }
                }
            if(depth == 0){
                start = i+1;
            }
        }
        return res;
    }
};