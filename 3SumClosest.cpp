/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int min_diff = INT_MAX;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                int start = i + 1;
                int end = n - 1;
                
                while(start < end)
                {
                    int sum = nums[i] + nums[start] + nums[end];
                    
                    if(sum > target)
                        end--;
                    
                    else if(sum < target)
                        start++;
                    
                    else
                        return target;
                    
                    if(abs(sum - target) < min_diff)
                    {
                        min_diff = abs(sum - target);   
                        ans = sum;
                    }  
                }
            }
        }
        return ans;
    }
};
