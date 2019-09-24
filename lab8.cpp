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

ll partition(ll arr[], ll l, ll r, ll x){

    //if(l==r)return l;

    ll i=l-1,j=l;
    for(;j<=r;j++){
        if(arr[j]<=x){
            swap(arr[j],arr[i+1]);
            i++;

        }
    }

    //REP(y,l,r+1)cout<<arr[y]<<" ";
    //cout<<endl;
    //cout<<'i'<<i<<endl;
    return i;

}

ll ismall(ll arr[], ll l, ll r, ll i){

    ll k=r-l+1;

    //cout<<k<<endl;

    ll med[(ll)ceil((long double)k/5)];
    ll t2=0;
    for(ll t=l; t<=r; t+=5){

        if(r-t+1>=5){
         
            sort(arr+t, arr+t+5);

            med[t2]=*(arr+t+2);

        }
        else {sort(arr+t, arr+r+1);
            med[t2]=*(arr+t+(r-t+1)/2);
        }
        //cout<<t<<" "<<med[t2]<<endl;
        t2++;
    }
    //cout<<(ll)ceil((long double)k/5)<<endl;
    //cout<<'t'<<" "<<t2<<endl;  
    ll mom;
    //cout<<'h'<<(ll)ceil((ldb)ceil((long double)k/5)/2)<<endl;
    if(t2==1){

        mom=med[0];

    }
    else mom=ismall(med, 0, (ll)ceil((long double)k/5)-1, (ll)ceil((ldb)ceil((ldb)k/5)/2));

    //cout<<mom<<" "<<k<<" "<<l<<" "<<r<<endl;

    ll lol=partition(arr, l, r, mom);

    //cout<<"lol"<<lol<<endl;



    //cout<<"yeet"<<endl;

    if(lol+1==i)return mom;
    if(lol+1>i){
        //cout<<"yeet"<<endl;
        return ismall(arr, l, lol-1, i);
    } else {

        return ismall(arr, lol+1, r, i);

    }

    //REP(t3,0,ceil((long double)k/5))cout<<t3<<" "<<med[t3]<<endl;


}

int main(){
 
    io

    ll n;
    cin>>n;
    while(n--){
        ll k;
        cin>>k;
        ll a[k];
        REP(i,0,k){
            ll x,y;
            cin>>x>>y;
            a[i]=x*x+y*y;
            //cout<<a[i]<<" ";
        }
        //cout<<(ll)ceil((long double)k/2)<<endl;
        cout<<sqrt(ismall(a,0,k-1,(ll)ceil((long double)k/2)))<<endl;

    }
}