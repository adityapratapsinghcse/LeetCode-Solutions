class Solution {
    bool isVowel(char c){
        return c == 'a' || c== 'e' || c== 'i' || c=='o' || c=='u';
    }

public:
    int maxVowels(string s, int k) {
        int i=0;
        int vowel = 0;
        int maxi =0;

        for(int idx = 0; idx < k ; idx++){
            if(isVowel(s[idx])){
                vowel++;
            }
        }
        maxi = vowel;

        for(int j=k ; j<s.size() ; j++){

            if(isVowel(s[i])){
                vowel--;
            }
            i++;
            if(isVowel(s[j])){
                vowel++;
            }
            maxi= max(maxi,vowel);
        }
        return maxi;
    }

};