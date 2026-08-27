class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        vector<vector<int>> x(nums.size()+1) ;
        for(int num : nums){
            freq[num]++;
        }
        for(const auto& i : freq){
            x[i.second].push_back(i.first);
        }

        vector<int> result;

        for(int j =x.size()-1;j >=0;j--){
            for(int n : x[j]){
                result.push_back(n);
            }
            if(result.size() == k){
                break;
            }
        }
        return result;
    }
};
