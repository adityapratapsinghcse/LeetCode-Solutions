class Solution {
    bool is_possible(vector<int> ranks , long long mid , int cars){
        long long car = 0;
        
        for(int i=0 ; i< ranks.size() ; i++){

            long long n = (long long) sqrt((double) mid / ranks[i]);

             while ((long long) ranks[i] * (n + 1) * (n + 1) <= mid) n++;
             while (n > 0 && (long long) ranks[i] * n * n > mid) n--;

             car += n;
            if(car >= cars){
                return true;
            }
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long start=1;
        int max=0;
        long long ans;
        for(int i=0 ; i< ranks.size() ; i++){
            if(ranks[i] > max){
                max = ranks[i];
            }
        }
        long long end = (long long)max * cars * cars;

        while(start <= end){
            long long mid = (start + end) /2;

            if(is_possible(ranks,mid,cars)){
                ans= mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};