class RandomizedSet {
public:
    unordered_set<int>r;
    RandomizedSet() {
        // set<int>r;
    }
    
    bool insert(int val) {
        if(r.find(val)==r.end()){
            r.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(r.find(val)==r.end()){
            return false;
        }
        r.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it=r.cbegin();
        int r1 = rand() % r.size();
        std::advance(it, r1);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */