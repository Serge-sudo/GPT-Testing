#include <vector>

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> arr1, arr2;
        
        // Append the first element to arr1 and the second to arr2 as per the rules.
        arr1.push_back(nums[0]);
        if (n > 1) arr2.push_back(nums[1]);
        
        // Function to count elements greater than a given value in a sorted array
        auto countGreater = [](const std::vector<int>& arr, int val) {
            return arr.end() - std::upper_bound(arr.begin(), arr.end(), val);
        };
        
        // Sort each array to use binary search (upper_bound)
        std::sort(arr1.begin(), arr1.end());
        std::sort(arr2.begin(), arr2.end());
        
        for (int i = 2; i < n; ++i) {
            int count1 = countGreater(arr1, nums[i]);
            int count2 = countGreater(arr2, nums[i]);
            
            if (count1 > count2) {
                arr1.push_back(nums[i]);
                std::sort(arr1.begin(), arr1.end());
            } else if (count1 < count2) {
                arr2.push_back(nums[i]);
                std::sort(arr2.begin(), arr2.end());
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    std::sort(arr1.begin(), arr1.end());
                } else {
                    arr2.push_back(nums[i]);
                    std::sort(arr2.begin(), arr2.end());
                }
            }
        }
        
        // Concatenate arr1 and arr2 to form the result array
        std::vector<int> result = arr1;
        result.insert(result.end(), arr2.begin(), arr2.end());
        
        return result;
    }
};
