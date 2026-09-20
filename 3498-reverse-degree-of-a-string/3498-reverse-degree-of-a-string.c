int reverseDegree(char* s) {
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Reverse alphabet value
        int value = 26 - (c - 'a');

        // Position is 1-indexed
        total += (i + 1) * value;
    }

    return total;
}