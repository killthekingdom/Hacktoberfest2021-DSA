//https://leetcode.com/problems/word-break/

class TrieNode
{
    public:
     unordered_map<char,TrieNode*> m;
     bool isEnd;
    TrieNode()
    {
        isEnd=false;
    }
};
class Trie
{
    public:
    TrieNode* root;
    Trie()
    {
        root=new TrieNode();
    }
    public:
    void insert(string s)
    {
        TrieNode *p=root;
        for(char c:s)
        {
            if(!p->m.count(c))
            {
                p->m[c]=new TrieNode();
                
            }
            p=p->m[c];
        }
        p->isEnd=true;
        
    }
    public:
    bool search(string key)
    {
        TrieNode *p=root;
        for(char c:key)
        {
            if(!p->m.count(c))
            {
                return false;
            }
           p=p->m[c];
        }
         return p->isEnd;
    }
 
    
};
class Solution {
  public:
    bool word(string str,Trie* p)
    {
        
         	int size = str.size();
	if (size == 0) return true;

	 
	bool wb[size+1];
	memset(wb, 0, sizeof(wb));  

	for (int i=1; i<=size; i++)
	{
		
		if (wb[i] == false && p->search( str.substr(0, i) ))
			wb[i] = true;

		
		if (wb[i] == true)
		{
			// If we reached the last prefix
			if (i == size)
				return true;

			for (int j = i+1; j <= size; j++)
			{
				 
				if (wb[j] == false && p->search( str.substr(i, j-i) ))
					wb[j] = true;

				// If we reached the last character
				if (j == size && wb[j] == true)
					return true;
			}
		}
	}

	 
	return false;
    }
    public:
    void print(TrieNode* root)
    {
         
        for(auto c : root->m)
        {
            cout<<c.first;
            
            print( root->m[c.first]);
        }
    }
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *p=new Trie();
        for(string s : wordDict)
        {
            
                p->insert(s);
             
        }
         
          
        
        return  word(s,p);
    }
};
