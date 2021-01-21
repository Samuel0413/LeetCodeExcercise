/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
*/

class Solution {
public:
    int find(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                return find(nums, target, mid+1, right);
            } else {
                return find(nums, target, left, mid-1);
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int target_indx = find(nums, target, 0, nums.size()-1);
        if (target_indx == -1) return {-1,-1};
        int left = target_indx;
        int right = target_indx;
        while (left-1 >= 0 && nums[left-1] == target) left--;
        while (right+1 < nums.size() && nums[right+1] == target) right++;
        return {left, right};
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
