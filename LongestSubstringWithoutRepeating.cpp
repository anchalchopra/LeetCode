/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> m;
		size_t n = s.length();
		size_t i = 0, ans = 0;

		for (int j = 0; j < n; j++)
		{
			auto it = m.find(s[j]);
			if (it == m.end())
			{
				m.emplace_hint(it, s[j], j);
			}
			else
			{
				if (it->second >= i)
				{
					ans = max(ans, j - i);
					i = it->second + 1;
				}
				it->second = j;
			}
		}
		ans = max(ans, n - i);
		return ans;
	}
};

int main()
{
	Solution a;
	string s = "pwwkew";
	cout << "\n\nLength of longest substring : " << a.lengthOfLongestSubstring(s);
	return 0;
}
