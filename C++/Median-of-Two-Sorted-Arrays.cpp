// 关键是理解算法的思路，在left，right的约束下不停的更新分割位置。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        if(x>y) return findMedianSortedArrays(nums2, nums1);
        x = nums1.size();
        y = nums2.size();
       //  cout << " " << x <<" " << y << endl;
        int s = 0;
        int e = x;
        while(s<=e){
            int px = (s+e)/2;
            int py = (x+y+1)/2-px;
            int lX = (px==0)?INT_MIN:nums1[px-1];
            int hX = (px==x)?INT_MAX:nums1[px];
            int lY = (py==0)?INT_MIN:nums2[py-1];
            int hY = (py==y)?INT_MAX:nums2[py];
            // cout << lX <<" " << hX <<" " << lY <<" " << hY << endl;
            if(lX<=hY && lY<=hX){
                if((x+y)%2==0){
                    return (max(lX, lY) + min(hX, hY)) / 2.0;
                }else{
                    return max(lX, lY);
                }
            }else if(hX<lY){
                s = px+1;
            }else{
                e = px-1;
            }
        }
        return 0;
    }
};
