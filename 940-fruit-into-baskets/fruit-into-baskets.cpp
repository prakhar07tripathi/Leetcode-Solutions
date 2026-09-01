class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        unordered_map<int,int>mpp;
        int fruitcnt = 0;
        while(r < fruits.size()){
            mpp[fruits[r]]++;
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(!mpp[fruits[l]])mpp.erase(fruits[l]);
                    l++;
                }
                fruitcnt = max(fruitcnt, r-l+1);
                r++;
        }
        return fruitcnt;
    }
};