#include <iostream>
using namespace std;

string latest(string s1, string s2)
{

  if (s1 == s2)
    return s1;

  int n = s1.size();
  int m = s2.size();
  int i = 0;
  while (i < n && i < m)
  {
    if (s1[i] == s2[i])
      i++;
    else if (s1[i] > s2[i])
      return s1;
    else
      return s2;
  }
  if (i == n)
    return s2;
  else
    return s1;
}

int main()
{
  // string s1 = "10.1.1.3";
  // string s2 = "10.1.1.9";
  string s1 = "10";
  string s2 = "10.1";
  cout << latest(s1, s2) << endl;
  return 0;
}