// Time Complexity: O(nlgn) because of insertion into the set
// Space Complexity: O(n)
class AllOne {
public:
  std::unordered_map<std::string, int> storage_map;
  std::set<std::pair<int, string>> storage_set;
  AllOne() {}

  void inc(string key) {
    int n = storage_map[key];
    storage_map[key]++;
    // remove the old pair & insert the new pair
    storage_set.erase(std::make_pair(n, key));
    storage_set.insert(std::make_pair(storage_map[key], key));
  }

  void dec(string key) {
    int n = storage_map[key];
    storage_map[key]--;
    storage_set.erase(std::make_pair(n, key));
    if (storage_map[key])
      storage_set.insert(std::make_pair(storage_map[key], key));
    else
      storage_map.erase(key);
  }

  string getMaxKey() {
    if (!storage_set.empty())
      return storage_set.rbegin()->second;
    else
      return "";
  }

  string getMinKey() {
    if (!storage_set.empty())
      return storage_set.begin()->second;
    else
      return "";
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
