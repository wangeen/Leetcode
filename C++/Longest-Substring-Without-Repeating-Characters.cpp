// l. 用map存储之前出现过的char的位置
// 2. 用pre记录不重复周期的起始点，注意要与自己永远取max

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        int max_len = 0;
        map<char, int> pos;
        int pre = -1;
        for(int i=0; i<s.size(); ++i){
            if(pos.find(s[i])!=pos.end()){
                pre = max(pos[s[i]], pre); 
            }
            max_len = max(max_len, i-pre);
            pos[s[i]] = i;
        }
        return max_len;
    }
};
