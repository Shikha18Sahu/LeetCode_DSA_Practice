class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int m = nums2.size();
        int t = n+m;
        int left = 0; 
        int right = 0;  
        vector<int>nums3; 
        while(left < n && right < m){
            if(nums1[left] <= nums2[right]){
            nums3.push_back(nums1[left]); 
            left++; 
            }
            else{
                nums3.push_back(nums2[right]); 
                right++; 
            }

        }
        while(left<n){
            nums3.push_back(nums1[left]);
            left++; 
        }
        while(right<m){
            nums3.push_back(nums2[right]); 
            right++; 
        }
        if( t%2==1)  return nums3[t/2]; 
        return (nums3[t/2]+ nums3[t/2 - 1])/2.0; 
    }
};