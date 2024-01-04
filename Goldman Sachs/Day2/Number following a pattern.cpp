/*
1. find break point indices, (break point indices are indices where s[i]==I), and 1 cnt=1 se shuru krna hai, declare a n+1 vector or string of n+1 length
2. jab tak I nhi milta tab tak i index ko aage lekar jaao,.. jaha I mila , waha pr ans mein , ans[i]=cnt kro and as we are using this cnt, increment cnt here
3. ek jth charcter lo and wha se tab tak piche jao jab tak visited I or 0th index pr na pahuch jao, and while traversing back, ans[j] ko cnt store kro and cnt ko inc krna hai and then j ko piche le jana hai, 
4. afthe this , increment the i , now check weather apna index n toh nhi hua , i.e i==n (string khtm hui ) but it may possible ki D na milne ki wajah se hum aage aage hi badhe honge so lets find check by lopping back , is there any D left (and ye guarantee hai ki abhi tak ke saare I mark hue honge)
so just do ans[i]=cnt++, and keep j=i-1; and just loop(j>=0 and s[j]=='D') ans[j]=cnt++, j--
just return the ans


*/

string printMinNumberForPattern(string s) {
  int cnt = 1;
  int i = 0, j = 0;
  int n = s.length();
  //   string str(n+1);
  vector < int > ans(n + 1);
  while (i < n) {
    if (s[i] == 'I') {
      //   cout<<i<<" "<<s[i]<<endl;
      j = i - 1;
      ans[i] = cnt++;
      while (j >= 0 and s[j] == 'D') {
        ans[j] = cnt;
        cnt++;
        j--;
      }
    }

    i++;
    if (i == n) {
      j = i - 1;
      ans[i] = cnt++;
      while (j >= 0 and s[j] == 'D') {
        ans[j] = cnt;
        cnt++;
        j--;
      }
    }
  }
  string str;
  for (auto it: ans)
    str += (to_string(it));
  return str;

}
};
