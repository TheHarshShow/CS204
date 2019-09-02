#include <bits/stdc++.h>
#include <math.h>
#include<unordered_map>

#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define enl "\n"
#define INF std::numeric_limits<ll>::max()
#define F first
#define S second
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
 
ll greatestSubarraySum(ll array[], ll n);
ll powerrr(ll a, ll b);
void swapp(ll *a, ll*b);
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll min(ll a, ll b);
ll max(ll a, ll b);
ll search(ll arr[], ll n, ll k);
string findSum(string str1, string str2);
 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) {
        string s = str1;
        str1=str2;
        str2=s;
    }
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
 
 
 
ll search(ll arr[], ll n, ll k){
    
    ll u = k;
    ll l = 0;
 
    
    while(u>=l){
        
        if(arr[(u+l)/2] == n){
            
            return (u+l)/2;
            
        } else if(arr[(u+l)/2] > n){
            
            u = (u+l)/2 - 1;
            
        } else {
            
            l = (u+l)/2 + 1;
            
        }
        
        
    }
    
    return -1;
    
    
}
 
ll greatestSubarraySum(ll array[], ll n){
 
    ll best = 0, sum = 0;
    for (ll k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
 
    return best;
}
 
ll powerrr(ll a, ll b){
 
    if(b<0)return 0;

    ll ans = 1;
 
    for(ll i = 0; i < b; i++)ans*=a;
 
    return ans;
 
 
}
 
void swapp(ll *a, ll*b){
 
    ll temp = *a;
    *a = *b;
    *b = temp;
 
 
}
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    
    return gcd(b%a, a);
}
 
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
} 
 
ll min(ll a, ll b){
    if(a < b)return a;  
    return b;
}
 
ll max(ll a, ll b){
    if(a > b)return a;
    return b;
}



int main(){


    io

    int n,q;
    cin>>n>>q;
    ll x[q];
    ll y[q];
    ll z[q];
    ll w[q];
    ll k=0;
    REP(i,0,q){
        cin>>x[i];
        if(x[i]==1){
            cin>>y[i]>>z[i];
            w[k]=y[i];
            k++;
        }else{
            y[i]=-1;
            z[i]=-1;
        }
    }
    sort(w,w+k);
    ll users[k];

    users[0]=w[0];
    ll k2=1;
    REP(i,1,k){
        if(w[i]==w[i-1])continue;
        else{
            users[k2]=w[i];
            k2++;
        }
    }

    ll val[k2]={0};

    //REP(i,0,k2)cout<<users[i]<<endl;
    //sort(users, users+k2);
    ll max1=-1,maxindex=-1;
    REP(i,0,q){
        if(x[i]==1){
            ll temp=search(users,y[i],k2);
            //cout<<temp<<endl;
            val[temp]+=z[i];
            if(val[temp]>max1){
                max1=val[temp];
                maxindex=temp;
            }
        } else{
            if(maxindex==-1)cout<<"No data available."<<endl;
            else cout<<users[maxindex]<<endl;
        }
    }

}