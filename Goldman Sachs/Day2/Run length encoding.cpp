string encode(string src)
{     
  int cnt=1;
  int i=1, n=src.length();
  string ans;
  while(i<n)
  {
      if(src[i]==src[i-1])
      cnt++;
      else{
          ans+=src[i-1];
          ans+=to_string(cnt);
          cnt=1;
      }
      i++;
  }
  ans+=src[i-1];
  ans+=to_string(cnt);
  return ans;
}     
 
