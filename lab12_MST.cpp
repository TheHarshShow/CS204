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

ll find(ll x, ll parent[]){

    if(x==parent[x])return x;
    return parent[x]=find(parent[x], parent);

}

void tuplesort(ll edgeweight[], ll edgestart[], ll edgeend[], ll m){

    vector< tuple<ll, ll, ll> > arr;
    REP(i,0,m){

        arr.PB(make_tuple(-1*edgeweight[i], edgestart[i], edgeend[i]));

    }

    sort(arr.begin(), arr.end());

    REP(i,0,m){

        edgeweight[i] = -1*get<0>(arr[i]);
        edgestart[i] = get<1>(arr[i]);
        edgeend[i] = get<2>(arr[i]);


    }


}

void unio(ll x, ll y, ll size[], ll parent[]){

    x=find(x, parent);
    y=find(y, parent);
    if(x!=y){

        if(size[x]>size[y])swap(x,y);
        parent[x]=y;
        size[y]+=size[x];

    }

}   

ll arr[2001][2001];

ll maximumSpanningTree(ll edgestart[], ll edgeend[], ll edgeweight[], ll parent[], ll size[], ll m){

    ll cost=1;
    REP(i,0,m){



        if(find(edgestart[i], parent) != find(edgeend[i], parent)){

            cost=((cost%1000000007)*(edgeweight[i]%1000000007))%1000000007;

            unio(edgestart[i], edgeend[i], size, parent);

            //cout<<cost<<endl;
        }
    }

    return cost;

}

int main(){
 
    io

    ll n,m;
    cin>>n>>m;

    ll edgestart[m];
    ll edgeend[m];
    ll edgeweight[m];

    ll size[n+1];
    ll parent[n+1];

    REP(i,0,m){


        parent[i]=i;
        ll x,y;
        ll z;
        cin>>x>>y>>z;
        edgestart[i]=x;
        edgeend[i]=y;
        edgeweight[i]=z;

    }


    REP(i,1,n+1){

        parent[i]=i;
        size[i]=1;

    }


    tuplesort(edgeweight, edgestart, edgeend, m);


    cout<<maximumSpanningTree(edgestart, edgeend, edgeweight, parent, size, m)<<endl;


}