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

struct Point{
    ll x;
    ll y;
};
 
Point P0;

ll distance(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

ll orientation(Point a, Point b, Point c){

    ll temp=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
    if(!temp)return 0;
    if(temp>0)return 1;
    else return 2;

}
 
Point next(stack<Point> s){
    Point p=s.top();
    s.pop();
    Point t=s.top();
    s.push(p);
    return t;
}

bool compare(Point a, Point b){

    ll ori = orientation(P0,a,b);
    if(!ori){
        if(distance(a,P0)>=distance(b,P0))return false;
        else return true;
    }
    if(ori==1)return true;
    return false;
}

void hull(vector<Point> points, ll n){

    ll min=0;
    REP(i,1,n){
        if(points[i].x<points[min].x || (points[i].x==points[min].x && points[i].y<points[min].y))min=i;
    }
    swap(points[0], points[min]);
    P0=points[0];
    sort(points.begin()+1, points.end(), compare);
    //cout<<endl;
    // REP(i,0,n)cout<<points[i].x<<" "<<points[i].y<<endl;
    // cout<<endl;

    vector<Point> blunt;

    blunt.PB(P0);
    REP(i,0,n-1){

        if(orientation(P0,points[i], points[i+1])!=0)blunt.PB(points[i]); 

    }
    blunt.PB(points[n-1]);

    if(blunt.size()<3){
        cout<<"NO CONVEX HULL\n";
        return;
    }
    // REP(i,0,blunt.size())cout<<blunt[i].x<<" "<<blunt[i].y<<endl;

    stack<Point> s;
    s.push(blunt[0]);
    s.push(blunt[1]);
    s.push(blunt[2]);

    REP(i,3,blunt.size()){

        while(orientation(next(s), s.top(), blunt[i])!=1)s.pop();
        s.push(blunt[i]);

    }
    stack<Point> s2;
    ll count = 0;
    while(!s.empty()){
        count++;
        Point a=s.top();
        s.pop();
        s2.push(a);
    }
    cout<<count<<endl;
    while(!s2.empty()){
        cout<<(s2.top()).x<<" "<<(s2.top()).y<<endl;
        s2.pop();
    }

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
    ll n;
    cin>>n;
    vector<Point> points(n);
    REP(i,0,n)cin>>points[i].x>>points[i].y;

    hull(points, n);
    // cout<<ans.size()<<endl;
    // REP(i,0,ans.size()){
    //     cout<<ans[i].x<<" "<<ans[i].y<<endl;
    // }

}