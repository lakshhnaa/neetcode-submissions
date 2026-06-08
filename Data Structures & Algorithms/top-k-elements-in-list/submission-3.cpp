class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        //count freq
        for(int num:nums){
            freq[num]++;
        }
        //create bucket
        vector<vector<int>>bucket(nums.size()+1);
        //put nos into the bucket
        for(auto &i : freq){
            bucket[i.second].push_back(i.first);
        }
        //create result vector
        vector<int> result;
        //put nos from highest freq into result
        for(int i =nums.size();i>=1;i--){
            for(int nums:bucket[i]){
                result.push_back(nums);
                if(result.size()==k){
                    return result;
                }
            }
        }

    }
};
