int min(int a , int b){
    if(a<b){
        return a;
    }
    return b;
}

int max(int a , int b){
    if(a>b){
        return a;
    }
    return b;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    int width = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
    int height = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);

    return width > 0 && height > 0;
}