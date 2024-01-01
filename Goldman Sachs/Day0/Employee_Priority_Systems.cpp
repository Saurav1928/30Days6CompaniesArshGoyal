//leetcode 2933: https://leetcode.com/problems/high-access-employees/description/

class Solution {
public:
    vector<string>
    findHighAccessEmployees(vector<vector<string>>& access_times) {
        /*
       1.  1st of all lets find , access time assosiated with each employee, for
       that lets use map ( empName, [access times])
       2.  then now lets check for each employee , we have list of access times
       3.  sort the list ,
       4. travese the list, using brute force, for each accesstime[i] , lets
       find accesstime[j] for which (at=accesstime) at[j]-at[i]<100, othewisee
       if we found >100 at any index j, then is is obvious ki j ke aage vale
       saaare element j se bade ya equal honge.. so travesing for those index
       will be waste of time , so lets break...
        */
        map<string, vector<string>> mp;
        for (auto at : access_times) {
            mp[at[0]].push_back(at[1]);
        }
        vector<string> ans;
        for (auto emp : mp) {
            sort(emp.second.begin(), emp.second.end());
            int n = emp.second.size();
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt = 0;
                // here its not good to start from itself i becaus if we start
                // from index i (or from diff=0) its obvoious that this will be
                // one of time, so make sure to include i th time as well if j=i
                // then start cnt=0 or else if j=i+1 then make sure to use cnt=1;
                for (int j = i; j < n; j++) {
                    if (stoi(emp.second[j]) - stoi(emp.second[i]) < 100)
                        cnt++;
                    else
                        break;
                }
                if (cnt > 2) {
                    ans.push_back(emp.first);
                    // if we found more than 2 count (i.e 3, 4, 5...)
                    // this means that for this employee we dont need c=to check
                    // for any other pairs, as we alredy found that these emp
                    // has alredy access more than 3 so he is high access, so
                    // lete break the loop and go for next employee
                    break;
                }
            }
        }
        return ans;
    }
};
