class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;       // stores indices
        vector<int> ans;

        for(int right = 0; right < nums.size(); right++)
        {
            // Remove smaller elements from the back
            // because they can never become maximum
            while(!dq.empty() && nums[dq.back()] < nums[right])
            {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(right);

            // Remove indices that are outside the window
            if(dq.front() < right - k + 1)
            {
                dq.pop_front();
            }

            // Once the first complete window is formed
            if(right >= k - 1)
            {
                // Front of deque contains maximum element
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};