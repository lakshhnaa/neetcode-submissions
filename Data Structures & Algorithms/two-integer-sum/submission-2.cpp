class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(pos.find(diff)!= pos.end()){
                return { pos[diff],i};
            }
            pos.insert({nums[i], i});
            
        }
        return {};
    };
};
