/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; i++)
        {
            if(i == 0 || nums[i] > nums[i-1])
            {
                int start = i + 1;
                int end = n - 1;
                
                while(start < end)
                {
                    if(nums[i] + nums[start] + nums[end] == 0)
                    {
                        vector<int> v = {nums[i], nums[start], nums[end]};
                        ret.push_back(v);
                    }
                    
                    if(nums[i] + nums[start] + nums[end] < 0)
                    {
                        int currStart = start;
                        while(nums[currStart] == nums[start] && start < end)
                            start++;
                    }
                    
                    else
                    {
                        int currEnd = end;
                        while(nums[currEnd] == nums[end] && start < end)
                            end--;
                    }
                }
            }
        }
        return ret;
    }
};
