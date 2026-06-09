class Solution {
public:
    int maxArea(vector<int>& heights) {
        //intial left right pointers
        int left = 0;
        int right = heights.size()-1;
        int maxarea = 0;
        //iterate
        while(left<right){
            int area = min(heights[left],heights[right]) * (right-left);
        //take max
            maxarea = max(maxarea,area);
        //move the less tall element
            if(heights[left]>heights[right]){
                right--;
            }
//if(heights[left]<heights[right]) 
//gives Equal heights ⇒ no pointer moves ⇒ infinite loop.?
            else{
                left++;
            }
        
        }
        return maxarea;
    }
};
