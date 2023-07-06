# insert-delete-getrandom-o1-duplicates-allowed

```
class RandomizedCollection {
    vector<pair<int,int>> nums;
    unordered_map<int, vector<int>> map;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool isPresent = map.count(val);
        map[val].push_back(nums.size());
        nums.push_back({val, map[val].size()-1});

        return !isPresent;
    }
    
    bool remove(int val) {
        bool isPresent = map.count(val);
        if(isPresent){
            auto last = nums.back();
            map[last.first][last.second] = map[val].back();
            nums[map[val].back()] = last;
            map[val].pop_back();
            if(map[val].empty()) map.erase(val);
            nums.pop_back();
        }
        return isPresent;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
