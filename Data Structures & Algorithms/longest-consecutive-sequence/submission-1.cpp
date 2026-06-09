class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //since we need to check consecutive num exist we use set
        unordered_set<int>numSet(nums.begin(),nums.end());
        int longest = 0;
        // find the first number
        for(int num:numSet){
            //after finding first check consecutive
            if(!numSet.count(num-1)){
                int current = num;
                int length =1;
                //update longest sequence
                while(numSet.count(current+1)){
                    current++;
                    length++;
                }

                longest = max(longest,length);
            }
        }
        return longest;
        
    }
};
