class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int h1 = stoi(st.substr(0, 2));
        int h2 = stoi(et.substr(0, 2));
        int m1 = stoi(st.substr(3, 2));
        int m2 = stoi(et.substr(3, 2));
        int s1 = stoi(st.substr(6, 2));
        int s2 = stoi(et.substr(6, 2));

        return (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
    }
};