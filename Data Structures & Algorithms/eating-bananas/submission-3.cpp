class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;

        while(left < right){
            int mid = (left + right) / 2;
            long long cost_hours=0;
            for(int pile: piles){
                cost_hours += (pile + mid -1) / mid;
            }
            if (cost_hours <= h){
                right = mid;
            }else {
                left = mid +1;
            }
        }
        return  left;
    }
};
