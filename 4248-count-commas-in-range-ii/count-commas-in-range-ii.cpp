class Solution {
public:
    long long countCommas(long long n) {
        int cntdig = 0;
        long long dup = n;
        int comma = 0;
        while(dup > 0){
            cntdig++;
            if(cntdig > 1 && (cntdig-1)%3 == 0)comma++;
            dup/=10;
        }
        long long commacnt = 0;
        if(cntdig <= 3)return commacnt;
        for(int i = 1; i <= comma; i++){
            if(i == comma){
                commacnt += (long long)((n - pow(1000, i)) + 1)*i;
            }
            else commacnt += (long long)(pow(1000, i+1) - pow(1000, i))*i;
        }
        return commacnt;
    }
};