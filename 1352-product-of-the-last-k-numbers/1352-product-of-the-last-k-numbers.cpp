class ProductOfNumbers {
    vector<long long> pref;

public:
    ProductOfNumbers() {
        pref.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            pref.clear();
            pref.push_back(1);
        } else {
            pref.push_back(pref.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = static_cast<int>(pref.size());
        if (k >= n) {
            return 0;
        }
        return static_cast<int>(pref.back() / pref[n - 1 - k]);
    }
};