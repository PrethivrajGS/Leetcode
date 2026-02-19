#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, 
                                     vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) {
        
        vector<vector<bool>> prereq(numCourses, vector<bool>(numCourses, false));
        
        for (auto &p : prerequisites) {
            prereq[p[0]][p[1]] = true;
        }
        
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (prereq[i][k] && prereq[k][j]) {
                        prereq[i][j] = true;
                    }
                }
            }
        }
        
        vector<bool> answer;
        for (auto &q : queries) {
            answer.push_back(prereq[q[0]][q[1]]);
        }
        
        return answer;
    }
};
