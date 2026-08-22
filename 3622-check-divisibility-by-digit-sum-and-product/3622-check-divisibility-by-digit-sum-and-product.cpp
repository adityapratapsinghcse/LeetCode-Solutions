class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ;
        int prod =1;
        int total = 0;
        int copy = n;
        while(n > 0){
            int digit = n  % 10;
            sum += digit;
            prod *= digit;
            n = n / 10;
        }
        total = sum + prod;
        if(copy % total == 0){
            return true;
        }
        return false;
    }
};