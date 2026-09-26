#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to hold key-value pairs for binary search
typedef struct {
    char* key;
    char* val;
} Pair;

// Comparator for qsort and bsearch
int cmp(const void* a, const void* b) {
    return strcmp(((Pair*)a)->key, ((Pair*)b)->key);
}

char * evaluate(char * s, char *** knowledge, int knowledgeSize, int* knowledgeColSize) {
    // 1. Create and sort an array of Pairs
    Pair* dict = (Pair*)malloc(knowledgeSize * sizeof(Pair));
    for (int i = 0; i < knowledgeSize; ++i) {
        dict[i].key = knowledge[i][0];
        dict[i].val = knowledge[i][1];
    }
    qsort(dict, knowledgeSize, sizeof(Pair), cmp);
    
    // 2. Prepare dynamic result string
    int cap = strlen(s) + 10000; 
    char* res = (char*)malloc(cap * sizeof(char));
    int res_idx = 0;
    
    char key_buf[100005]; // Buffer for the current key
    int key_idx = 0;
    bool inside = false;
    
    // 3. Parse the string
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(') {
            inside = true;
            key_idx = 0; // Reset key buffer
        } else if (s[i] == ')') {
            inside = false;
            key_buf[key_idx] = '\0';
            
            // Binary search for the key
            Pair target;
            target.key = key_buf;
            Pair* found = (Pair*)bsearch(&target, dict, knowledgeSize, sizeof(Pair), cmp);
            
            if (found) {
                int v_len = strlen(found->val);
                // Dynamically resize result buffer if needed
                if (res_idx + v_len >= cap) {
                    cap = (cap + v_len) * 2;
                    res = (char*)realloc(res, cap);
                }
                strcpy(res + res_idx, found->val);
                res_idx += v_len;
            } else {
                if (res_idx + 2 >= cap) {
                    cap *= 2;
                    res = (char*)realloc(res, cap);
                }
                res[res_idx++] = '?';
            }
        } else if (inside) {
            key_buf[key_idx++] = s[i];
        } else {
            if (res_idx + 2 >= cap) {
                cap *= 2;
                res = (char*)realloc(res, cap);
            }
            res[res_idx++] = s[i];
        }
    }
    
    res[res_idx] = '\0';
    free(dict);
    return res;
}