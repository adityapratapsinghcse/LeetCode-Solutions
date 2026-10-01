class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();

        for (char c : s.toCharArray()) {

            // Opening bracket
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // Closing bracket
            else {
                if (st.isEmpty())
                    return false;

                char top = st.peek();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.isEmpty();
    }
}