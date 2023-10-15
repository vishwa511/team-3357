// Lexicographically Largest Kth Occurence :

// Author

// Ujjwal Srivastava

// Difficulty Level : Medium

// Submissions : 48

// Asked In : PhonePe

// Marks :30

//  : 0 |  : 0

// Bob gave Alex a string s
//  consisting of lowercase English letters of length n.
//  He then asked Alex to construct a new string s1
//  using the characters of s
//  such that no two characters appear more than k
//  times consecutively. It is not mandatory to use all characters from s.
// Help Alex find the lexicographically largest possible string s1.
// Input
// The first line contains two space-separated integers n
//  and k
// . The second line contains a string s
//  of length n
// .(1≤n≤105).
// (1≤k≤n.)
// Output
// Output the lexicographically largest string.

// Examples
// input
// 7 3
// xxxxzza
// output
// zzxxxax

#include <bits/stdc++.h>
  using namespace std;

  int main() {

    string s;
    int n, k;
    cin>>n>>k;
    cin>>s;
    map<int, int> mp;
    for(int i=0; i<n; i++){
      mp[s[i]]+=1;
    }
    string ans;
    for(auto it = mp.rbegin(); it!=mp.rend(); it++){
      if((*it).second<=k){
        char x = (*it).first;
        int y = (*it).second;
        while(y--){
          ans.push_back(x);
        }
      }
      else{
        auto it2 = next(it, 1);
        char x = (*it).first;
        int y = (*it).second;
        while(it2!=mp.rend() && y>k){
          int z = k;
          while(z--){
            ans.push_back(x);
          }
          y-=k;
          char nxt = (*it2).first;
          ans.push_back(nxt);
          mp[nxt]-=1;
          if(mp[nxt] == 0) it2 = next(it2, 1);
        }
        y = min(y, k);
          while(y--){
            ans.push_back(x);
          }
      }
    }
    cout<<ans<<endl;
  }