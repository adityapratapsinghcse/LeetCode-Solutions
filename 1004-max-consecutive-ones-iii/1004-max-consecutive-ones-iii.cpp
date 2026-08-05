class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,max_window=-1;
        while(j<nums.size())
        {
            if(nums[j] == 0)
            {
                k--;
            }
            while(k == -1)
            {
                if(nums[i] == 0)
                {
                    k++;
                }
                i++;
            }
            int current_window = (j-i+1);
            max_window = max(current_window,max_window);
            j++;
        }
        return max_window;
    }
};