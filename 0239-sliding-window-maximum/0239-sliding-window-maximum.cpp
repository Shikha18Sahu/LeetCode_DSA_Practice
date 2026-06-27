class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int>arr;
       
        // int result;
        // for(int i= 0; i<nums.size()-k+1; i++){
        //      int ans= nums[i];
        //     for(int j=i ; j<i+k; j++){
        //        result = nums[j];
        //         ans= max(ans, result);
        //     }
        //     arr.push_back(ans);
        // }
        // return arr;


  
        deque<int> dq; // stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Store result when first window is completed
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
   

    }
};