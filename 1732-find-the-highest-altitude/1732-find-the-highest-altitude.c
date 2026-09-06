int largestAltitude(int* gain, int gainSize) {
    int ans = 0;
    int alt_sum = 0;
    for (int i = 0; i < gainSize; i++) {
        alt_sum += gain[i];

        if (ans < alt_sum) {
            ans = alt_sum;
        }
    }
    return ans;
}