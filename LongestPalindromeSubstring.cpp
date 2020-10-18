/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case)
*/

class Solution {
public:
    int expandaroundcenter(string s, int l, int r)
    {
        while(l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
    
    string longestPalindrome(string s) {
    if(s.empty() || s.length() < 1)
        return "";
        
    int start = 0, end = 0;
    int max_len = 0;
    int n = s.length();    
        
    for(int i = 0; i < n; i++)
    {
        int len1 = expandaroundcenter(s, i, i);
        int len2 = expandaroundcenter(s, i, i+1);
        int len = max(len1, len2);
        
        if(len > end - start)
        {
            start = i - (len - 1)/2;
            end = i + len/2;
            max_len = len;
        }
    }
        return s.substr(start, max_len);        
    }
};
