// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 01-05-23
#include <bits/stdc++.h>
            
#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define pi acos(-1.0)
#define fr(i,a,b)                         for(int i=a;i<=b;++i)
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

const int N   = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
  int n; cin >> n;
  int arr[n+10], zero[32] = {0}, one[32] = {0};

  for(int i = 0; i < n; ++i){
  	cin >> arr[i];
  }

  int mod = 1000000007;
  for(int i = 0; i < n; ++i){
  	for(int j = 0; j < 32; ++j){
  		if(arr[i] & (1 << j))
  			one[j]++;
  		else
  			zero[j]++;
  	}
  }

  int ans = 0;
  for(int i = 0; i < 32; ++i){
  	ans += ((zero[i] % mod) * (one[i] % mod)) % mod;
  } 

  ans = (ans * 2) % mod;
  cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}