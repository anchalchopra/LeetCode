/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []
 

Constraints:

0 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector <int>> result;
        int n = nums.size();
        int a, b, c, d;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3;) {
            a = nums[i];
            for (int j = i + 1; j < n - 2;) {
                b = nums[j];
                for (long k = j + 1, m = n - 1; k < m;) {
                    c = nums[k];
                    d = nums[m];
                    sum = a + b + c + d;
                    if (sum == target) {
                        result.push_back({a, b, c, d});
                        while (k < m && c == nums[++k]);
                        while (k < m && d == nums[--m]);
                    }                  
                    else if (sum > target) m--;
                    else k++;
                }
                while (j < n-2 && b == nums[++j]);
            }
            while (i < n-3 && a == nums[++i]);
        }
        return result;
    }
};
