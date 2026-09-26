class Solution {
public:
    string largestOddNumber(string num) {
        int right = num.size() - 1;
        while(right >= 0 && num[right] % 2 == 0){
            right--;
        }
        return num.substr(0, right+1);
    }
};