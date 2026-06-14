
// set (brute) 
// time complexity: O(nlogn + n)
// space complexity: O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st; 
        for(int i = 0; i<nums.size(); i++){
            st.insert(nums[i]); 
        }
        int index = 0; 
        for(auto it: st){
            nums[index] = it; 
            index++; 
        }
        return index; 
    }
};


// Optimal:  two pointer: O(n)

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//            int k = 1; 
//         for(int i= 1; i<nums.size(); i++){
//            if (nums[i] == nums[i-1]) continue;  
//            else {
//             nums[k] = nums[i]; 
//             k++; 
//            } 
//         }
//         return k; 
//     }
// };