int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}

int trap(int* height, int heightSize) {
        int n = heightSize;
        int count = 0;
        int* prefix = (int*)malloc(heightSize * sizeof(int));
        int* suffix = (int*)malloc(heightSize * sizeof(int));


        prefix[0] = height[0];
        for(int i=1 ; i< n ; i++){
            prefix[i] = max(prefix[i-1] , height[i]);
        }
        
        suffix[n-1] = height[n-1];
        for(int i=n-2 ; i >= 0 ; i--){
            suffix[i] = max(suffix[i+1] , height[i]);
        }

        for(int i = 0 ; i< n ; i++){
            count += (min(prefix[i] , suffix[i]) - height[i]);
        }
        return count;
}