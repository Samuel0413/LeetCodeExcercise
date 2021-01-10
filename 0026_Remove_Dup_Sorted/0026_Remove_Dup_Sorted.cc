/*
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-plce with O(1) extra memory.
*/

class Solution {
public:
    // two pointer method, increment cur_count when two elements are different
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        if (nums[0] == nums[nums.size() - 1]) {
            return 1; // when number are all the same
        }
        int cur_dup = nums[0];
        int cur_count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != cur_dup) {
                nums[cur_count] = nums[i];
                cur_dup = nums[i];
                cur_count++;
            }
        }
        return cur_count;
        /*nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        return nums.size();*/
    }
};

/*
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.

Time: O(n)
Space: O(1)
*/
