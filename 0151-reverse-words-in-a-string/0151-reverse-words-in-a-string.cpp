class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() -1; 
        string ans; 
        while(n >= 0){
            while(n >= 0 && s[n] == ' ')
            n--; 
            if(n<0) break; 
            int j = n; 
            while(j >= 0 && s[j] != ' ')
            j--; 
            ans += s.substr(j+1, n-j);
            ans+= ' '; 
            n = j-1; 
        }
        if(!ans.empty()) ans.pop_back(); 
        return ans; 
    }
};