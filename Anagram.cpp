#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  int n;
  cin>>n;
  vector< map< char, int> > v;
  vector<string> str;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    str.push_back(s);
    map<char, int> m;
    for(int i=0;i<s.length();i++){
      m[s[i]]++;
    }
    v.push_back(m);
  }
  int arr[n];
  for(int i=0;i<n;i++){
    arr[i] = 0;
  }
  for(int i=0;i<v.size();i++){
    if(arr[i] == 1){
      continue;
    }
    std::vector<string> v2;
    v2.push_back(str[i]);
    for(int j=i+1;j<v.size();j++){
      if(arr[j] == 0 && v[i] == v[j]){
        arr[i] = 1;
        arr[j] = 1;
        v2.push_back(str[j]);
      }
    }
    for(int k=0;k<v2.size();k++){
      cout << v2[k] << " ";
    }
    cout << endl;
  }
	return 0;
}