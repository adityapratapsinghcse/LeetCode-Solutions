class Solution {
    public int[] replaceElements(int[] arr) {
        int[] suffix_max = new int[arr.length];

        int n = arr.length;

        suffix_max[n-1] = -1;
        for(int i=n-2 ; i >= 0 ; i--){
            if(suffix_max[i+1] > arr[i+1]){
                suffix_max[i] = suffix_max[i+1];
            }
            else{
                suffix_max[i] = arr[i+1];
            }
        }
        return suffix_max;
    }
}