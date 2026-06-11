class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        vector<int> count1(26,0);
        vector<int> count2(26,0);

        for(char c: s1){
            count1[c-'a']++;
        }
          // Size of the sliding window must equal length of s1
        int windowsize = s1.size();
        //freq array
        for(int i=0;i<windowsize;i++){
            count2[s2[i]-'a']++;
        }
        if(count1==count2){
            return true;
        }
        

        for(int right =windowsize;right<s2.size();right++){
            //index leaving the window
            int left = right - windowsize;
            //remove left window
            count2[s2[left]-'a']--;
            //expand the right 
            count2[s2[right]-'a']++;
            if(count1==count2){
                return true;
            }
            

        }
        return false;


    }
};
