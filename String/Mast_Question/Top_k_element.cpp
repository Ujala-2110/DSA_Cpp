// You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.

// Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.

// You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.

// Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.

 

// Example 1:

// Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
// Output: [1,2]
// Explanation: 
// Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.

// Constraints:

// 1 <= positive_feedback.length, negative_feedback.length <= 104
// 1 <= positive_feedback[i].length, negative_feedback[j].length <= 100
// Both positive_feedback[i] and negative_feedback[j] consists of lowercase English letters.
// No word is present in both positive_feedback and negative_feedback.
// n == report.length == student_id.length
// 1 <= n <= 104
// report[i] consists of lowercase English letters and spaces ' '.
// There is a single space between consecutive words of report[i].
// 1 <= report[i].length <= 100
// 1 <= student_id[i] <= 109
// All the values of student_id[i] are unique.
// 1 <= k <= n

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool static sortbysecdesc(const pair<int,int> &a,
           const pair<int,int> &b)
    {
           if(a.second == b.second) return a.first < b.first;
           return a.second>b.second;
        
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& reports, vector<int>& student_id, int k) {
        
        int n = reports.size();
        set<string>pos, neg;
        
        for(auto it : positive_feedback) pos.insert(it);
        for(auto it : negative_feedback) neg.insert(it);
        
        int sz = student_id.size();
        vector<int> points(sz,0);
        
        // for(int i=0;i<n;i++)
        // {
        //     stringstream ss(reports[i]);
        //     string s;
        //     while (ss >> s) {
        //         if (pos.find(s) != pos.end()) points[i] += 3;
        //         else if (neg.find(s) != neg.end()) points[i]--;
        //     }
        // }

        //M->2
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<reports[i].size();j++)
            {
                string s = "";
                while(reports[i][j] != ' ' && j < reports[i].size()) {
                    s += reports[i][j];
                    j++;
                }
                
                if(pos.find(s) != pos.end())points[i] += 3;
                else if(neg.find(s) != neg.end())points[i] -= 1;
            }
        }
        
        vector<pair<int,int>>vect;
        for(int i=0;i<sz;i++)
        {
            vect.push_back({student_id[i],points[i]});
        }
        
        sort(vect.begin(), vect.end(), sortbysecdesc);
        
        vector<int>ans;
        for(auto it : vect) {
            if(k == 0) break;
            ans.push_back(it.first);
            k--;
        }
        return ans;
    }
};