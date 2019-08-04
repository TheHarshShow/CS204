#include<bits/stdc++.h>

using namespace std;

string Subtract(string a, string b);
string reverse(string c);
string Sum(string a, string b);
int stringCompare(string a, string b);

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


	long long t=0;



	return c;


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

	return 0;

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

string Multiply(string a, string b){

	long long sign=0;

	if(a[0]=='-'){a=a.substr(1,a.length()-1);sign++;}
	if(b[0]=='-'){b=b.substr(1,b.length()-1);sign++;}

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

	if(!stringCompare(a,b))swap(a,b);

	string c;


	for(long long i=b.length()-1; i>=0; i--){

		long long carry=0;


		string d;

		for(long long j=a.length()-1; j>=0; j--){

			long long first=(b[i]-'0')*(a[j]-'0')+carry;
			d.push_back(first%10+'0');
			carry=first/10;


		}


		if(carry)d.push_back(carry+'0');
		d=reverse(d);

		long long k=b.length()-1-i;
		while(k!=0){
			d.push_back('0');
			k--;


		}


		c=Sum(c,d);

	}

	if(sign%2==0)return c;
	else return '-'+c;



}


int main(){

	long long t;
	cin>>t;

	while(t--){

		string a,b;
		cin>>a>>b;
		string d=Multiply(a,b);

		cout<<d<<endl;

	}

}

