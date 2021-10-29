//https://leetcode.com/problems/monotone-increasing-digits/

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        string s=to_string(n);
        int mark=s.size();
        for(int i=s.size()-1;i>0;i--){
            if(s[i-1]>s[i]){
                mark=i;
                s[i-1]=s[i-1]-1;
            }
        }
        for(int i=mark;i<s.size();i++){
            s[i]='9';
        }
        return stoi(s);
    }
};
