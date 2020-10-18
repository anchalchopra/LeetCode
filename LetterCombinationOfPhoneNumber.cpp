/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
    public:
    const vector<string> keyboard {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",        "wxyz"};
    
    vector<string> letterCombinations(string digits)
    {
        vector<string>ans;
        if(digits == "" || digits.length() == 0)
        {
            return ans;
        }
        
        string path;
        dfs(digits, 0, path, ans);
        return ans;
    }
    
    private:
    void dfs(string &digits, size_t curr, string &path, vector<string> &ans)
    {
        if(curr == digits.size())
        {
            ans.push_back(path);
            return;
        }
        
        for(auto c: keyboard[digits[curr] - '0'])
        {
            path.push_back(c);
            dfs(digits, curr+1, path, ans);
            path.pop_back();
        }
    }
};
