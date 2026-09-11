class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        vector<int> frq(10);
        for (auto& i : nums) frq[i]++;

        unordered_set<int> st;
        for (int i = 0; i <= 8; i += 2) { // last digits
            if (!frq[i]) continue;
            frq[i]--; // use last digit

            for (int j = 1; j < 10; j++) { // first digit
                if (!frq[j]) continue;
                frq[j]--; // use first digit

                for (int k = 0; k < 10; k++) { // mid digit
                    if (!frq[k]) continue;
                    frq[k]--; // use mid digit

                    int num = j * 100 + k * 10 + i; // even num
                    st.insert(num);

                    frq[k]++; // for another num
                }
                frq[j]++; // for another num
            }
            frq[i]++; // for another num
        }
        return st.size();
    }
};
