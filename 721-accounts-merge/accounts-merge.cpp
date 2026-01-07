
class DSU {
    unordered_map<string, string> parent;

public:
    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string x, string y) {
        string px = find(x);
        string py = find(y);
        if (px != py)
            parent[py] = px;
    }

    void add(string x) {
        if (!parent.count(x))
            parent[x] = x;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;

        // Step 1: Union emails
        for (auto &acc : accounts) {
            string name = acc[0];
            string firstEmail = acc[1];
            dsu.add(firstEmail);
            emailToName[firstEmail] = name;

            for (int i = 2; i < acc.size(); i++) {
                dsu.add(acc[i]);
                emailToName[acc[i]] = name;
                dsu.unite(firstEmail, acc[i]);
            }
        }

        // Step 2: Group emails by root
        unordered_map<string, vector<string>> groups;
        for (auto &p : emailToName) {
            string root = dsu.find(p.first);
            groups[root].push_back(p.first);
        }

        // Step 3: Build result
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.push_back(emailToName[emails[0]]);
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }

        return result;
    }
};
