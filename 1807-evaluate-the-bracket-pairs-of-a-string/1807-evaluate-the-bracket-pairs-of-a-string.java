import java.util.List;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        // Build the hash map for O(1) lookups
        Map<String, String> map = new HashMap<>();
        for (List<String> pair : knowledge) {
            map.put(pair.get(0), pair.get(1));
        }
        
        StringBuilder res = new StringBuilder();
        StringBuilder currKey = new StringBuilder();
        boolean inside = false;
        
        for (char c : s.toCharArray()) {
            if (c == '(') {
                inside = true;
            } else if (c == ')') {
                inside = false;
                String key = currKey.toString();
                // Append the mapped value or "?" if it doesn't exist
                res.append(map.getOrDefault(key, "?"));
                currKey.setLength(0); // Efficiently clear the current key
            } else if (inside) {
                currKey.append(c);
            } else {
                res.append(c);
            }
        }
        
        return res.toString();
    }
}