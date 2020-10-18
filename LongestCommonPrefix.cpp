/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if(strs.empty() || strs.size() < 1)
            return s;
        
        int index = 0;
        for(char c : strs[0])
        {
            for(int i = 1; i < strs.size(); i++)
            {
                if(index >= strs[i].length() || c != strs[i][index])
                {
                    return s;
                }
            }
            s += c;
            index++;
        }
        return s;
    }
};
