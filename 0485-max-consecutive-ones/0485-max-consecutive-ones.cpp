class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0; 
        int maxi = 0;
        if(nums.size() == 1 && nums[0] == 1) return 1; 
        for(int i = 0; i<nums.size(); i++){
           if(nums[i] ==1){
            count++; 
            maxi = max(count, maxi);
           }
           else {
            count =0;
           }
        }
        return maxi; 
    }
};