class Solution {
    public boolean isVowel(char c){
        return c == 'a' || c== 'e' || c== 'i' || c=='o' || c=='u';
    }

    public int maxVowels(String s, int k) {
        int i=0;
        int vowel = 0;
        int maxi =0;

        for(int idx = 0; idx < k ; idx++){
            if(isVowel(s.charAt(idx))){
                vowel++;
            }
        }
        maxi = vowel;

        for(int j=k ; j<s.length() ; j++){

            if(isVowel(s.charAt(i))){
                vowel--;
            }
            i++;
            if(isVowel(s.charAt(j))){
                vowel++;
            }
            maxi= Math.max(maxi,vowel);
        }
        return maxi;
    }   
}