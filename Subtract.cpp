#include<bits/stdc++.h>

using namespace std;

string reverse(string c){

	string d;
	for(int i=c.length()-1; i>=0; i--){

		d.push_back(c[i]);

	}

	return d;

}

int stringCompare(string a, string b){

	if(a.length()>b.length())return 1;
	else if(a.length()<b.length())return 0;
	else{

		for(int i=0; i < a.length(); i++){

			if(a[i]>b[i])return 1;
			else if(a[i]<b[i])return 0;

		}


	}

	return 1;

}

string Subtract(string a, string b){


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
	if(stringCompare(a,b)){

		for(int i=0; i < b.length(); i++){

			if(a[a.length()-i-1]>=b[b.length()-i-1]){

				c.push_back(a[a.length()-i-1]-b[b.length()-i-1]+'0');

			} else {

				c.push_back(a[a.length()-i-1]-b[b.length()-i-1]+'0'+10);
				int j=a.length()-i-2;

				while(true){
					if(a[j]-'0'){a[j]--;break;}
					else a[j]='9';

					j--;

				}

			}

		}

		for(int i=b.length(); i<a.length(); i++){

			c.push_back(a[a.length()-i-1]);

		}

		c=reverse(c);

		long long t=0;

		for(long long i=0; i<c.length(); i++){


			if(c[i]!='0' || i==c.length()-1){t=i;break;}

		}

		c=c.substr(t, c.length()-t);

		return c;


	} else{

		c='-';

		c+=Subtract(b,a);

		return c;

	}



}

int main(){

	string a,b,c;
	cin>>a>>b;

	c=Subtract(a,b);

	cout<<endl<<c<<endl;

}