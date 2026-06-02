class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2 = 0; 
     for(int i = 0; i<nums.size(); i++){
        if (nums[i] == 0) cnt0++;
        if(nums[i] == 1) cnt1++; 
        if(nums[i] == 2) cnt2++;
             }
             int ind = 0; 
    for(int i = 0; i<cnt0; i++){
        nums[ind] = 0; 
        ind++; 
    }
    for(int i = 0; i<cnt1; i++){
        nums[ind] = 1; 
        ind++; 
    }
    for(int i = 0; i<cnt2; i++){
        nums[ind] = 2; 
        ind++; 
    }
       
    }
};