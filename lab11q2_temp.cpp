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

vector<vll> arr;
ll color[1000001];
ll flag=0;

void dfs(ll x, ll y){

    if(color[x]!=y && color [x]!=0){

        flag=1;
        return;

    } else if(color[x]==y)return;

    color[x]=y;

    if(y==1)y=2;
    else y=1;

    for (auto u:arr[x]){

        dfs(u, y);

    }


}



int main(){
 
    string n;
    ll m;
    cin>>n>>m;
    ll t=1;
    vll tempfull;
    arr.PB(tempfull);

    map<ll,ll> mp;    

    ll t2=1;

    REP(i,0,m){

        ll x,y,z;
        cin>>x>>y>>z;

        if(mp.find(x)==mp.end()){

            mp.insert(MP(x,t2));
            t2++;

            vll tempy;
            arr.PB(tempy);

        }
        if(mp.find(y)==mp.end()){

            mp.insert(MP(y,t2));
            t2++;

            vll tempy;
            arr.PB(tempy);

        }
        
        if(z%2){

            arr[mp[x]].PB(mp[y]);
            arr[mp[y]].PB(mp[x]);

        } else{

            vll tempy;
            arr.PB(tempy);
            arr[mp[x]].PB(t2);
            arr[t2].PB(mp[x]);
            arr[mp[y]].PB(t2);
            arr[t2].PB(mp[y]);
            t2++;
        }


        

    }

    REP(i,1,t2){

        if(color[i])continue;
        dfs(i,1);
        if(flag){

            cout<<"NO"<<endl;
            return 0;

        }

    }

    cout<<"YES"<<endl;


}