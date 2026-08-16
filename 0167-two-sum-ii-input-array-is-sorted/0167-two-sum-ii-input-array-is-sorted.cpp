class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        int curr_sum = 0;

        while (i <= j) {
            curr_sum = numbers[i] + numbers[j];

            if (curr_sum == target) {
                break;
            }
            if (curr_sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {i + 1, j + 1};
    }
};