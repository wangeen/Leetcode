// 注意边界情况处理，以及重复的处理。
// 注意不能直接删除重复数字，因为会存在【-1 -1 2】这样的符合结果的情况，会存在重复的数字。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        int current_min = INT_MAX;
        for (int i=0; i<nums.size()-2; ++i){
            int left = i+1; 
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if(sum == 0){
                    vector<int> vect{ nums[i], nums[left], nums[right] }; 
                    res.push_back(vect);
                }
                if(sum>0){
                    while(left<right && nums[right]==nums[right-1]) { --right; } 
                    right--;
                }else{
                    while(left<right && nums[left]==nums[left+1]) { ++left; }
                    left++;
                }
            }
            
            while((i+1)<(nums.size()-2) && nums[i]==nums[i+1]) { ++i; }
        }
        return res;
    }
};
