struct Trie{

    char ch;
    unordered_map<char,Trie*> mp;
    bool isTerminal;

    Trie(char ch){
        this->ch = ch;
        this->isTerminal = false;
    }

};

class PrefixTree {
    Trie* root;
public:
    PrefixTree() {
        root = new Trie('*');
    }
    
    void insert(string word) {
        Trie* temp = root;

        for(int i=0;i<word.length();++i){
            char ch = word[i];
            if(temp->mp.count(ch)){
                temp = temp->mp[ch];
            }
            else{
                temp->mp[ch] = new Trie(ch);
                temp = temp->mp[ch];
            }

            if(i == word.length()-1) temp->isTerminal = true;
        }
    }
    
    bool search(string word) {
        Trie *temp = root;
        
        for(int i=0;i<word.length();++i){
            char ch = word[i];
            if(temp->mp.count(ch)) temp = temp->mp[ch];
            else return false;
        }
        

        return temp->isTerminal == true;
    }


    
    bool startsWith(string prefix) {
        Trie *temp = root;
        
        for(int i=0;i<prefix.length();++i){
            char ch = prefix[i];
            if(temp->mp.count(ch)) temp = temp->mp[ch];
            else return false;
        }
        

        return true;
    }
};
