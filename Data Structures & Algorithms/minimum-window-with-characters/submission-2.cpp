class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> target;
        unordered_map<char,int> window;

        for(char c : t)
            target[c]++;

        int have = 0;
        int need = target.size();

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;

            // Character requirement satisfied
            if(target.count(c) && window[c] == target[c])
                have++;

            // Window is valid
            while(have == need)
            {
                // Update answer
                if(right-left+1 < minLen)
                {
                    minLen = right-left+1;
                    start = left;
                }

                // Remove leftmost character
                char removeChar = s[left];
                window[removeChar]--;

                // Window became invalid
                if(target.count(removeChar) &&
                   window[removeChar] < target[removeChar])
                {
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};