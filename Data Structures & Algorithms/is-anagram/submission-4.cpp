class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;

        string scopy = s;
        string tcopy = t;

        sort(scopy.begin(),scopy.end());
        sort(tcopy.begin(),tcopy.end());
        
        return scopy == tcopy;
    }
};
