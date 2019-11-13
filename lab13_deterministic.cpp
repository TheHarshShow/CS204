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
ll modpowerrr(ll x, ll y, ll p);
ll power(ll x, ll y);
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
 
 
 
ll binarySearch(vll arr, ll l, ll r, ll x) 
{ 
    if (r >= l) { 
        ll mid = l + (r - l) / 2; 
  

        if (arr[mid] == x) 
            return mid; 
  

        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 

        return binarySearch(arr, mid + 1, r, x); 
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
 
ll modpowerrr(ll x, ll y, ll p) 
{ 
    ll res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = (res*x) % p; 
  
       
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
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

ll power(ll x, ll y) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
}
 
ll countSetBits(ll n) 
{ 

    if (n == 0) 
        return 0; 
  
    else
  
        return (n & 1) + countSetBits(n >> 1); 
} 
  


ll modulo( ll value, ll m) {
    ll mod = value % m;
    if (value < 0) {
        mod += m;
    }
    return mod;
}

vll pf;

void primeFactors(ll n)  
{  

    while (n % 2 == 0)  
    {  
        if(pf.size()==0 || pf[pf.size()-1]!=2)pf.PB(2);
        n = n/2;  
    }  
  


    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  

        while (n % i == 0)  
        {  
            if(pf.size()==0 || pf[pf.size()-1]!=i){



                pf.PB(i);

                continue;
            }
            n = n/i;  
        }  
    }  
  


    if (n > 2)  {

        if(pf.size()==0 || pf[pf.size()-1] !=n){pf.PB(n);return;}

        
    }
}  



ll approximate(ldb a){

    if(ceil(a)-a<0.00001)return (ll)ceil(a);
    return floor(a);

}


ll close(ll a, ll b, ll k){

    if(abs(a-k)>abs(b-k))return b;
    return a;

}


int main(){
 
    io

    ll n;
    cin>>n;
    string arr[n];
    ll flag=0;

    REP(i,0,n)cin>>arr[i];

    sort(arr, arr+n);

    REP(i,0,n){

        string temp=arr[i];
        reverse(temp.begin(), temp.end());

        if(temp==arr[i])continue;

        if(binary_search(arr, arr+n, temp)){

            cout<<"YES"<<endl;
            return 0;

        }
    }

    cout<<"NO"<<endl;










}