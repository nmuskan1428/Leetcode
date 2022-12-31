//Question - https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
int lengthOfLongestSubstring(string n) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i=0; i<n.size(); i++){
        if (m[n[i]]!=-1 && lastRepeatPos < m[n[i]]) {
            lastRepeatPos = m[n[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[n[i]] = i;
    }
    return maxLen;
}
};