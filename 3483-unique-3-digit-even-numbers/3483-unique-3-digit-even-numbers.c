int totalNumbers(int* digits, int digitsSize) {
    int freq[10] = {0};

    for (int i = 0; i < digitsSize; i++) {
        freq[digits[i]]++;
    }

    int ans = 0;

    for (int num = 100; num <= 999; num++) {

        // Must be even
        if (num % 2 != 0)
            continue;

        int ones = num % 10;
        int tens = (num / 10) % 10;
        int hundreds = num / 100;

        int need[10] = {0};

        need[hundreds]++;
        need[tens]++;
        need[ones]++;

        int possible = 1;

        for (int d = 0; d <= 9; d++) {
            if (need[d] > freq[d]) {
                possible = 0;
                break;
            }
        }

        if (possible)
            ans++;
    }

    return ans;
}