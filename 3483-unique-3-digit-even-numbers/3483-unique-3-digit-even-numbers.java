class Solution {
    public int totalNumbers(int[] digits) {
        int[] freq = new int[10];

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int num = 100; num <= 999; num++) {

            if (num % 2 != 0)
                continue;

            int ones = num % 10;
            int tens = (num / 10) % 10;
            int hundreds = num / 100;

            // Check each digit directly
            if (freq[hundreds] == 0)
                continue;

            // Temporarily use hundreds
            freq[hundreds]--;

            if (freq[tens] == 0) {
                freq[hundreds]++;
                continue;
            }

            // Temporarily use tens
            freq[tens]--;

            if (freq[ones] > 0)
                ans++;

            // Restore
            freq[tens]++;
            freq[hundreds]++;
        }

        return ans;
    }
}