/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.
*/

class Solution {
private:
    vector<vector<int>> twoSum(vector<int> nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        vector<vector<int>> ret{};
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum > target || (j < nums.size() - 1 && nums[j] == nums[j+1])) {
                j--;
            } else if (sum < target || (i > 0 && nums[i] == nums[i-1])) {
                i++;
            } else {
                ret.push_back({nums[i], nums[j]});
                i++;
                j--;
            }
        }
        return ret;
    }
    
    vector<vector<int>> kSum(vector<int> nums, int k, int target) {
        vector<vector<int>> ret{};
        if (nums.size() == 0 || nums[0] * k > target || nums[nums.size()-1] * k < target) {
            return ret;
        }
        if (k == 2) {
            return twoSum(nums, target);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (auto ele : kSum({nums.begin()+i+1, nums.end()}, k-1, target-nums.at(i))) {
                ret.push_back({nums[i]});
                ret.back().insert(end(ret.back()), begin(ele), end(ele));
            }
        }
        return ret;
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, 4, target);
    }
};

/*
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [], target = 0
Output: []

Time: O(n^k-1)
*/
