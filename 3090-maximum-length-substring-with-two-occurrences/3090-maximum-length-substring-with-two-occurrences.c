int maximumLengthSubstring(char* s) {
 int max_len = 0;
        int i =0;
        int j =0;

        int freq[26] = {0};

        while(s[j] != '\0'){

            freq[s[j] - 'a']++;

            while(freq[s[j] - 'a'] > 2){
                freq[s[i] - 'a']--;
                i++;
            }

            int curr_len = j-i+1;

            if (curr_len > max_len){
                max_len = curr_len;
            }

            j++;
        }
        return max_len;   
}