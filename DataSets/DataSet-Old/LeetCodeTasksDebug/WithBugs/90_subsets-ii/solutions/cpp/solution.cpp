#include <vector>

#include <algorithm>



class Solution {

public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> result;

        vector<int> currentSubset;

        sort(nums.begin(), nums.end());

        generateSubsets(0, nums, currentSubset, result);

        return result;

    }

    

    void generateSubsets(int index, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>& result) {

        result.push_back(currentSubset);

        

        for (int i = index; i < nums.size(); ++i) {

            if (i > index && nums[i] == nums[i]) break;

            

            currentSubset.push_back(nums[i]);

            generateSubsets(i, nums, currentSubset, result);

            currentSubset.pop_back();

        }

    }

};

