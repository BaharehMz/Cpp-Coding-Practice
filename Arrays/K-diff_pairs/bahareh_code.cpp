class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        unordered_map<int, int> elements;
        int result = 0;
        for(auto x: nums){
            if(!k && elements.count(x)){
                elements[x]++;
                if(elements[x] == 1)
                    result++;
            }
            if(!elements.count(x)){
                elements.insert(make_pair(x, 0));
                if(k){
                    if(elements.count(x - k)) 
                        result++;
                    if(elements.count(x + k))
                        result++;
                }
                
            }
        }
        return result;
    }
};
