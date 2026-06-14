class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size(); 
        if(n == 0) return 0; 

        vector<int>prefix(n); 
        vector<int>suffix(n); 
 
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1]; 
        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1], arr[i]); 
        }
        for(int i = n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], arr[i]); 
        }
        int total = 0; 
        for(int i = 0; i<n; i++){
            total+= min(prefix[i], suffix[i]) -arr[i]; 
        }
return total; 
    }
};