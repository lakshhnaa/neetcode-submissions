class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int maxFreq = 0;
        int longest = 0;

        vector<int> count(26, 0);

        for(int right = 0; right < s.size(); right++)
        {
            // add current character
            count[s[right] - 'A']++;

            // update maximum frequency
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // shrink window if too many replacements are needed
            while((right - left + 1) - maxFreq > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            // update answer
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};