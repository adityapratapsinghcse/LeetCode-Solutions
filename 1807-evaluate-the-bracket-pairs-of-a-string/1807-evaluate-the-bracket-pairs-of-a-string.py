from typing import List

class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        # Convert knowledge list to a dictionary for O(1) lookups
        know_dict = {k: v for k, v in knowledge}
        
        res = []
        curr_key = []
        inside = False
        
        for char in s:
            if char == '(':
                inside = True
            elif char == ')':
                inside = False
                # Reconstruct the key string and look it up
                key_str = "".join(curr_key)
                res.append(know_dict.get(key_str, "?"))
                # Reset the temporary key container
                curr_key = []
            elif inside:
                curr_key.append(char)
            else:
                res.append(char)
                
        # Join the list into the final string
        return "".join(res)