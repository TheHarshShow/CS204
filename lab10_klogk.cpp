#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

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
 
    ll ans = 1;
 
    for(ll i = 0; i < b; i++){
 
 
        ans*= a;
 
 
    }
 
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

ll find(ll rank[], ll i){

    if(rank[i]==i)return i;
    else return rank[i] = find(rank, rank[i]);

}

void unio(ll rank[], ll size[], ll x, ll y){

    x=find(rank, x);
    y=find(rank, y);

    if(x==y)return;
    if(size[x]>size[y])swap(x,y);

    rank[x]=y;
    size[y]+=size[x];


}


int main(){
 
    io

    ll n,m;
    cin>>m>>n;

    ll k;
    cin>>k;

    ll rank[k];
    ll size[k];
    ll x[k];
    ll y[k];

    map<pll, ll> val;

    REP(i,0,k){

        ll a,b;
        cin>>a>>b;
        rank[i]=i;
        size[i]=1;
        x[i]=a;
        y[i]=b;

        val[MP(a,b)]=i;


    }

    REP(i,0,k){

        if(val.find(MP(x[i]-1,y[i])) != val.end()) unio(rank, size, i, val[MP(x[i]-1,y[i])]);
        if(val.find(MP(x[i]+1,y[i])) != val.end()) unio(rank, size, i, val[MP(x[i]+1,y[i])]);
        if(val.find(MP(x[i],y[i]-1)) != val.end()) unio(rank, size, i, val[MP(x[i],y[i]-1)]);
        if(val.find(MP(x[i],y[i]+1)) != val.end()) unio(rank, size, i, val[MP(x[i],y[i]+1)]);


    }

    ll ans=0;
    REP(i,0,k)ans=max(ans,size[i]);

    cout<<ans<<endl;

}