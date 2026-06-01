class Solution {
public:
      void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1; 

        // step 1: breakpoint find kro 
        for(int i = n-2; i>=0; i--){
           if(nums[i] < nums[i+1]){
            ind = i; 
            break; 
           }
        }
        // agar descending hai (not possible)
           if(ind == -1){
           reverse(nums.begin(), nums.end()); 
           return ; 
        }
        // step2: just greater element find 
        for(int i = n-1; i>ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]); 
                break; 
            }
        }
        // step 3: remaining pare reverse; 
        reverse(nums.begin() + ind+1, nums.end()); 
    }
};