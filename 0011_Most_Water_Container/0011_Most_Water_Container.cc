/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int cur_area = min(height.at(left), height.at(right)) * (right - left);
            if (cur_area > max_area) {
                max_area = cur_area;
            }
            if (height.at(left) > height.at(right)) {
                right--;
            } else {
                left++;
            }
        }
        return max_area;
    }
};

/*
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16

Example 4:
Input: height = [1,2,1]
Output: 2

Time: O(n)
*/
