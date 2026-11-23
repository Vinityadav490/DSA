class ProductOfNumbers {
public:
    vector<long long>nums{1};
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num==0) nums={1};
        else nums.push_back(nums.back()*num);
    }
    
    long long getProduct(int k) {
        int n=nums.size();
        if(k>=n) return 0;
        return nums[n-1]/nums[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */