/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                // use continue instead of simply adding one to i
                // so that the logic is ensured and no duplicates will occur
                continue;
            }
            // when the first number is greater than 0, no chance for the rest two
            // numbers to be less than 0 since the array is sorted, thus it is 
            // impossible to have result of zero when the first number is greater than 0
            if (nums[i] > 0) break;
            
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int total_sum = nums[i] + nums[j] + nums[k];
                if (total_sum > 0) {
                    k--;
                } else if (total_sum < 0) {
                    j++;
                } else {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return ret;
    }
};
/*
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Time: O(N^2)
*/
