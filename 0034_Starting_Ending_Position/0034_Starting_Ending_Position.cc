/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == target) {
                if (ans.size() == 2) {
                    ans[1] = i;
                } else {
                    ans.push_back(i);
                }
            }
        }
        if (ans.size() == 0) {
            ans = {-1, -1};
        } else if (ans.size() == 1) {
            ans.push_back(ans[0]);
        }
        return ans;
    }
};

/*
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
