#include <iostream>
#include <vector>

using namespace std;

string shiftstring(string s,vector<int>&shift){
  int n=s.size();
  for(int i=n-1;i>=0;i--){
    shift[i]+=shift[i+1];
    shift[i]=shift[i]%26;
    int ind=s[i]-'a';
    ind=ind+shift[i];
    if(ind>25){
        ind=ind-26;
    }
    s[i]=char('a'+ind);
  }
  return s;

}


