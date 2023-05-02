// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 29-04-23
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
  vector<int>v(n);
  for(int i = 0; i < n; ++i){
  	cin >> v[i];
  }

  int xorVal = v[0];
  for(int i = 1; i < n; ++i){
  	xorVal^=v[i];
  }

  int firstSetBit = 0;
  for(int i = 0; i < 64; ++i){
  	if(xorVal & (1 << i)){
  		firstSetBit = i;
  		break;
  	}
  }

  int firstVal = 0;
  for(int i = 0; i < n; ++i){
  	if(v[i] & (1 << firstSetBit)){
  		firstVal ^= v[i];
  	}
  }

  int secondVal = xorVal ^ firstVal;

  cout << firstVal << " " << secondVal << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}