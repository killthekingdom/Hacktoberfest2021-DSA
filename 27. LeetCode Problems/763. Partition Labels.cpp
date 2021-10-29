//https://leetcode.com/problems/partition-labels/

class Solution {
public:
  vector<int> partitionLabels(string s) {
    map<char,int> m;
    vector<int> out;
    for(int i=0;i<s.length();i++) m[s[i]] = i;
    string curr = "";
    int left = 0, right = s.length()-1, depth = -1;
    while(left < s.length()) {
      curr += s[left];
      depth = max(depth,m[s[left]]);
      if(left == depth) {
        out.push_back(curr.length());
        curr = "";
      }
      left++;
    }
    return out;
  }
};
