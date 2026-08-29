class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int group = 0;
        unordered_map<int, int> ng;
        ng[vec[0]] = group;

        unordered_map<int, list<int>> gl;
        gl[group].push_back(vec[0]); //O(1)

        for(int i = 1; i < n; i++) {
            if(abs(vec[i] - vec[i-1]) > limit) group  += 1;

            ng[vec[i]] = group ;
            gl[group].push_back(vec[i]);
        }
        
        vector<int> res(n); 
        for(int i = 0; i < n; i++) { // merge the groups
            int num = nums[i];
            int group = ng[num];

            res[i] = *gl[group].begin(); 
            gl[group].pop_front();
        }
        return res;
    }
};
