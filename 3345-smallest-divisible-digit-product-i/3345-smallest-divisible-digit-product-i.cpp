class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            int copy = i;
            int prod = 1;
            while( copy > 0){
                int digit = copy % 10;
                prod = prod * digit;
                copy = copy / 10;
            }
            if(prod % t == 0){
                return i;
            }
            i++;
        }
    }
};