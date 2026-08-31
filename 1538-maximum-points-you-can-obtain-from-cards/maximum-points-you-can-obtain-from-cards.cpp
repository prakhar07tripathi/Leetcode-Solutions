class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = n - k; i < n; i++){
            sum += cardPoints[i];
        }
        int l = n - k;
        int r = n - 1;
        int maxsum = sum;
        while(r < n + k - 1){
            sum -= cardPoints[l%n];
            l++;
            r++;
            sum += cardPoints[r%n];
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};