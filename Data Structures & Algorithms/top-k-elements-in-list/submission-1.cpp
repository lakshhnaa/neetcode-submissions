class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> count;// map creation key is number , value is freq
       vector<vector<int>> freq(nums.size()+1);
// stores the freq of the indices meaning at index 1 , the count array stores the freq of 1 in the input array
       for(int n : nums){
            count[n]++;
       }
// in each element's freq = index of freq , meaning
       for(const auto& no: count){
            freq[no.second].push_back(no.first);
       }
       vector<int> result;
       for(int i = freq.size() -1 ; i>0;i--){
            for(int each : freq[i]){
                result.push_back(each);
            }
            if(result.size()==k){
                return result;
            }
       }
       return result;
    }
};
