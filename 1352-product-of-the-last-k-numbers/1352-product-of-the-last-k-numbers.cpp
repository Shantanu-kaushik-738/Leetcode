class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if (num) nums.push_back(nums.back() * num);
        else nums = {1};
    }
    
    int getProduct(int k) {
        int n = nums.size();
        return k >= n ? 0 : nums[n - 1] / nums[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
 
