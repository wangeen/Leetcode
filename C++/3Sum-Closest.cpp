// 大致思路， 先选定3个数字中的第一个，遍历第一个，其余的从剩下的找

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ClosestVal = INT_MAX, sum = 0;
        for (int i = 0; i + 2 < nums.size(); i ++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int temp = nums[left] + nums[right] + nums[i];
                if (ClosestVal > abs(temp - target)) {
                    ClosestVal = abs(temp - target);
                    sum = temp;
                }
                if (temp == target) return target;
                else if (temp < target) {
                    left ++;
                } else {
                    right --;
                }
            }
        }
        return sum;
    }
};
