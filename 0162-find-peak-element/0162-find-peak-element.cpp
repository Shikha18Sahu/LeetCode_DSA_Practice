class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       // case 1 
       if(nums.size() == 1) return 0; 
       //case 2 0th element
       if(nums[0] > nums[1]) return 0; 
       // case 3
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i; 
        }
        // case 4 last element
      
         return nums.size()-1; 
    }
   
};