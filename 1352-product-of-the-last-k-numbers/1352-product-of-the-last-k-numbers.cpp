class ProductOfNumbers {
public:
    vector<int> prefix{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num) prefix.push_back(prefix.back() * num);
        else prefix = {1};
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        return k >= n ? 0 : prefix[n - 1] / prefix[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
 
