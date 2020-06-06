class Trie {
public:
    
    vector<Trie*> list;
    bool eow;
    
    Trie() {
        list = vector<Trie*>(26);
        eow = false;
    }

    void insert(string word) {
        Trie* cur = this;
        for(char c: word){
            if(cur->list[c-'a']==NULL) 
                cur->list[c-'a']=new Trie();
            cur=cur->list[c-'a'];
        }
        cur->eow = true;
    }

    bool search(string word) {
        Trie* cur = this;
        for(char c: word){
            if(cur->list[c-'a']==NULL)
                return false;
            cur = cur->list[c-'a'];
        }
        if(cur->eow) 
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        Trie* cur = this;
        for(char c: prefix){
            if(cur->list[c-'a']==NULL)
                return false;
            cur=cur->list[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 // https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/
