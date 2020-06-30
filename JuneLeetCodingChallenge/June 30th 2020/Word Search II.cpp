class Trie{
    public:
    unordered_map<char, Trie*> children;
    bool isEnd=false;
    
    void insert(string word){
        Trie* node=this;
        for(char c : word){
            if(node->children.find(c)==node->children.end())
                node->children[c]=new Trie();
            node=node->children[c];
        }
        node->isEnd=true;
    }
    
    bool search(string word){
        Trie* node=this;
        for(char c : word){
            if(node->children.find(c)==node->children.end())
                return false;
            node=node->children[c];
        }
        return node->isEnd;
    }
    
};
class Solution {
public:
    vector<int> direction={0, -1, 0, 1, 0};
    void Backtracking(vector<vector<char>>& board, Trie* trie, int i, int j, string& partial, vector<string>& result){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='#') return; // Check if out of range or visited
        
        if(trie->children.find(board[i][j])==trie->children.end()) return; // Return no path
        trie=trie->children[board[i][j]]; // Move trie to child node
        
        partial.push_back(board[i][j]); // add this value to partial string
        if(trie->isEnd==true){ // If found, add to result
            result.push_back(partial);
            trie->isEnd=false; // Remove as a word for avoiding duplicates
        }
		
        char temp=board[i][j];
        board[i][j]='#'; // Mark visited
        
        for(int d=0; d<4; d++){ // DFS for all directions
            int row=i+direction[d];
            int col=j+direction[d+1];
            Backtracking(board, trie, row, col, partial, result); 
        }
        
        partial.pop_back(); // Backtrack
        board[i][j]=temp;
    }
    
    vector<string> exist(vector<vector<char>>& board, Trie* trie){
        int m=board.size(), n=board[0].size();
        
        vector<string> result;
        string partial;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                Backtracking(board, trie, i, j, partial, result);
        
        return result;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie=new Trie();
        for(string word : words)
            trie->insert(word);
        
        return exist(board, trie);
    }
};
