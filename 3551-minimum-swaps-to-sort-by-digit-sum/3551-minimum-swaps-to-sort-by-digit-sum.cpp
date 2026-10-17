class Solution {
    int digitsum(int num){
        int sum = 0;
        while(num >0){
            int digit = num % 10;
            num = num / 10;
            sum += digit;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<pair<int , int>, int>> arr;

        for(int i = 0 ; i< nums.size() ; i++){
            arr.push_back({{digitsum(nums[i]) , nums[i]} , i});
        }

        sort(arr.begin(),arr.end());

        vector<bool> visited(nums.size(), false);
        int swaps = 0;  
        
        for(int i = 0; i< nums.size() ; i++){
            if(visited[i] || arr[i].second == i){
                continue;
            }
            
            int cycleSize = 0;
            int j = i;

            while(!visited[j]){
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
        return swaps;
    }
};