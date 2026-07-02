class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; 
        unordered_map<char, int>freq; 
        for(int i = 0; i<s.length(); i++){
            freq[s[i]]++; 
        }
        for(int i =  0; i<t.length(); i++){
          freq[t[i]]--; 
          if(freq[t[i]]< 0) return false; 
        }
        return true; 
    }
};