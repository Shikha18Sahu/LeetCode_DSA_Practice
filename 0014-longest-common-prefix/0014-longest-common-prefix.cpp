class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       string ans = ""; 
       string ref = strs[0]; 
       for(int i = 0; i<ref.length(); i++ ){
             for(int j = 1; j<strs.size() ; j++){
                if(i > strs[j].length()-1) return ans; 
                if(ref[i] != strs[j][i])  return ans; 
                
             }
              ans += ref[i]; 
       }
       return ans; 
      
    }
};