#include <bits/stdc++.h>

using namespace std;

int main(){

	set<char> a={'(', '{', '[', '<'};
	map<char, char> b;
	b[')']='(';
	b[']']='[';
	b['>']='<';
	b['}']='{';

	long long n;
	cin>>n;

	while(n--){

		string s;
		cin>>s;
		stack<char> c;
		int flag=0;
		for(long long i=0; i<s.length(); i++){

			if(s[i]=='|'){

				if(c.empty())c.push(s[i]);
				else if(c.top()=='|')c.pop();
				else c.push(s[i]);

			} else{

				if(a.find(s[i]) != a.end())c.push(s[i]);
				else if(c.empty()){flag=1; break;}
				else if(c.top() == b[s[i]])c.pop();
				else {flag=1; break;}

			}

		}

		if(flag==1)cout<<"NO"<<endl;
		else {
			if(c.empty())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}

	}

}
