class Solution {
public:

    vector<int> zFunction(string s)
    {
        int n = s.size();
        vector<int> z(n);
        int L = 0, R = 0;
        for(int i = 1; i < n; i++)
        {
            if(i <= R)
                z[i] = min(R - i + 1, z[i - L]);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if(i + z[i] - 1 > R)
            {
                L = i;
                R = i + z[i] - 1;
            }
        }
        return z;
    }

    bool contains(string text, string pattern)
    {
        string temp = pattern + "$" + text;
        vector<int> z = zFunction(temp);
        int m = pattern.size();
        for(int val : z)
        {
            if(val == m)
                return true;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b)
    {
        string text = a;
        int cnt = 1;
        while(text.size() < b.size())
        {
            text += a;
            cnt++;
        }
        if(contains(text, b))
            return cnt;
        text += a;
        if(contains(text, b))
            return cnt + 1;
        return -1;
    }
};