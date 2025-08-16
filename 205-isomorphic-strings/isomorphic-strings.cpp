class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

    unordered_map<char, char> map_s_t; 
    unordered_map<char, char> map_t_s; 

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

       
        if (map_s_t.count(c1)) {
            if (map_s_t[c1] != c2) return false;
        } else {
            map_s_t[c1] = c2;
        }

      
        if (map_t_s.count(c2)) {
            if (map_t_s[c2] != c1) return false;
        } else {
            map_t_s[c2] = c1;
        }
    }

    return true;
    }
};