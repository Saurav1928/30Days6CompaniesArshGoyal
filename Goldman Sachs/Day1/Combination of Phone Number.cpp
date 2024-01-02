class Solution {
public:

void solve(int ind, string digits,vector<string>&ans, string output, map<int, string>&mp ){
    if(ind>=digits.length())
    {
        ans.push_back(output);
        return ;
    }
    int digit= digits[ind]-48;
    string currStr=mp[digit];
    for(int i=0;i<currStr.length();i++)
    solve(ind+1, digits, ans, output+currStr[i], mp );
    return ;
}
    vector<string> letterCombinations(string digits) {
        map<int, string>mp;
        if(digits.length()==0)
        return {};
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string>ans;
        string tmp;
        solve(0, digits, ans, tmp, mp);
        return ans;
    }
};
