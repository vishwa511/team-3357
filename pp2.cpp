// QNO-1 STORY TELLER

#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int c){
	int ts = a/b;
	int cs = ts;
	while(cs >= c){
		int ns = cs/c;
		cs = cs%c;
		cs+=ns;
		ts+=ns;
	}
	return ts;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		cout<<f(a, b, c)<<endl;
	}
}
