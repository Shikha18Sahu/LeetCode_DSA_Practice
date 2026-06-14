class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        int maxLeft = 0, maxRight = 0, water=0; 
        int maxHeight = height[0]; 
        int index = 0; 
        //find maxHeight index 
        for(int i = 1; i<n; i++){
            if(height[i] > maxHeight){
                maxHeight = height[i]; 
                index = i; 
            }
        }
        for(int i = 0; i<index; i++){
            if(maxLeft > height[i]){
                water+= maxLeft - height[i]; 
            }
            else 
            maxLeft = height[i]; 
        }
        for(int i = n-1; i>index; i--){
            if(maxRight > height[i]){
                water+= maxRight - height[i]; 
            }
            else
            maxRight = height[i]; 
        }
        return water; 
    }
};