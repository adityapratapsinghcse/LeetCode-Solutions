class Solution {
    public int maximumLengthSubstring(String s) {
             int max_len = 0;
        int i =0;
        int j =0;

        HashMap<Character, Integer> count = new HashMap<>();

        while(j < s.length()){
            count.put(s.charAt(j), count.getOrDefault(s.charAt(j), 0) + 1);

            while(count.get(s.charAt(j)) > 2){
                count.put(s.charAt(i), count.getOrDefault(s.charAt(i), 1) - 1);
                i++;
            }

            max_len = Math.max(max_len,(j-i+1));

            j++;
        }
        return max_len;   
    }
}