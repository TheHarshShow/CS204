#include<bits/stdc++.h>

using namespace std;

string reverse(string c){

	string d;
	for(int i=c.length()-1; i>=0; i--){

		d.push_back(c[i]);

	}

	return d;

}

string Sum(string a, string b){

	long long t1=0,t2=0;
	for(long long i=0; i<a.length(); i++){

		if(a[i]!='0' || i==a.length()-1){
			t1=i;
			break;
		}

	}
	for(long long i=0; i<b.length(); i++){

		if(b[i]!='0'||i==b.length()-1){
			t2=i;
			break;
		}

	}

	a=a.substr(t1,a.length()-t1);
	b=b.substr(t2,b.length()-t2);

	string c;
	if(a.length()< b.length())swap(a,b);
	int carry=0;
	for(long long i = 0; i<b.length(); i++){
		int sum=(a[a.length()-i-1]+b[b.length()-i-1]+carry-'0'-'0');
		carry=sum/10;
		c.push_back(sum%10+'0');

	}

	for(int i=b.length(); i <a.length(); i++){

		int sum=a[a.length()-i-1]+carry-'0';
		carry=sum/10;
		c.push_back(sum%10+'0');

	}
	if(carry)c.push_back(carry+'0');

	c=reverse(c);

	return c;


}

int main(){

	string a,b,c;
	cin>>a>>b;

	c=Sum(a,b);
	cout<<endl<<c<<endl;


}