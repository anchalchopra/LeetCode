/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        int m = A.size();
        int n = B.size();
        
        int low = 0;
        int high = m;
        
        while(low <= high)
        {
           int partitionX = (low+high)/2;
           int partitionY = (m+n+1)/2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : A[partitionX];
            int maxLeftY = (partitionY == 0) ? INT_MIN : B[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : B[partitionY];
               
            if(maxLeftX <= minRightY && minRightX >= maxLeftY)
            {
                if((m+n)%2 == 0)
                    return (double) (max(maxLeftX, maxLeftY)+min(minRightX, minRightY))/2;
            
                else
                    return (double) max(maxLeftX, maxLeftY);
            }
            
            else if(maxLeftX > minRightY)
                high = partitionX + 1;
            
            else
                low = partitionX - 1;
        }
        return 0;
    }
};
