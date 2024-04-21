#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Make sure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int leftSize = (m + n + 1) / 2;
        int l = 0, r = m;
        
        while (l <= r) {
            int partitionX = (l + r) / 2;
            int partitionY = leftSize - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (double)(std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2;
                } else {
                    return (double)std::max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                r = partitionX - 1;
            } else {
                l = partitionX + 1;
            }
        }
        
        throw std::invalid_argument("Input arrays are not valid for finding median.");
    }
};
