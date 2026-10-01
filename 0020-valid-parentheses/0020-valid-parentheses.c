bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Opening bracket
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }

        // Closing bracket
        else {
            if (top == -1)
                return false;

            char t = stack[top];

            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '[')) {
                return false;
            }

            top--;
        }
    }

    return top == -1;
}