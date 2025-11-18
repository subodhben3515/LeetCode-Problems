class Solution {
public:
/*
Create adj matrix
create in degree matrix

fill adj matrix
increment indegree

Create process queue to process courses whose indegree is 0. No prerequisite


while q not empty
front pop
--courses

next find out the dependent courses
for()
get dependent course from adj matrix
reduce in order degree
if it's 0 --> all prerequisite met
add to completed courses list

ret numcoures ==0
*/
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 1)
            return true;
        vector<vector<int>> adjMat(numCourses);
        vector<int> indegree(numCourses);

        for(auto pr : prerequisites)
        {
            adjMat[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }

        queue<int> pq;
        for(int deg = 0; deg < numCourses; deg++)
        {
            if(indegree[deg] == 0)
                pq.push(deg);
        }

        while(!pq.empty())
        {
            auto currentCourse = pq.front();
            pq.pop();

            --numCourses;

            for(auto dependent: adjMat[currentCourse])
            {
                if(--indegree[dependent] == 0)
                {
                    pq.push(dependent);
                }
            }

        }
        return numCourses==0;
    }
};
