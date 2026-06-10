class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //init seen set
        unordered_set<char>seen;
        int longest=0;
        int left = 0;
        //iterate
        for(int right = 0;right<s.size();right++){
        //if count = 1 in seen set erase and add the new shrink left
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            //likely to forget
            seen.insert(s[right]);
        //find the longest
            longest = max(longest,right-left+1);
        }  
        return longest;   
    }
};
