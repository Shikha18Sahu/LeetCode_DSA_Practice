class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(); 
        priority_queue<int, vector<int>, less<int>>p;  // max heap
        for(int i = 0 ; i< n; i++){
            p.push(nums[i]); 
        }
        for(int i = 1; i<k; i++){
            p.pop(); 
        }
        return p.top(); 
    }
};


// using min heap

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size(); 
//         priority_queue<int, vector<int>, greater<int>>p; // min heap
//         for(int i = 0; i<k; i++){
//          p.push(nums[i]); 
//         }
//         for(int i = k; i<n; i++){
//            if(nums[i] > p.top()){
//             p.pop(); 
//             p.push(nums[i]); 
//            }

//         }
//         return p.top(); 
//     }
// };
