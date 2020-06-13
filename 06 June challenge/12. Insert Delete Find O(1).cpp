// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/

class RandomizedSet {
    set<int> s;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
        srand((unsigned)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val)==s.end())
            s.insert(val);
        else
            return false;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val)!=s.end())
            s.erase(val);
        else
            return false;
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int p = rand()%(size);
        auto i = s.begin();
        advance(i,p);
        return *i;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */