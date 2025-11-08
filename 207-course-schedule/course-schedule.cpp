class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build graph and indegree array
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        // Add all courses with no prerequisites
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                q.push(i);
        
        int count = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            count++;
            
            // Reduce indegree for connected courses
            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        
        // If we’ve processed all courses → no cycle
        return count == numCourses;
    }
};   
    