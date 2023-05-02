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

int getIthBit(int a, int i){
  int mask = (1 << i);
  if(a & mask) return 1;
  return 0;
}

void setIthBit(int a, int i){
  int mask = (1 << i);
  a |= mask;
}

void clearIthBit(int *a, int i){
  int mask = (1LL << i);
  *a &= ~(1LL << i);
}

void updateIthBit(int *a, int i, int value){
  int mask = (1LL << i);
  clearIthBit(a, i);
  *a |= (value << i);
}

void solve(){
  int a, i; cin >> a >> i;
  cout << getIthBit(a, i) << endl;

  // setIthBit(a, i);
  // dl(a)

  clearIthBit(&a,i);
  dl(a)

  updateIthBit(&a, i, 0);
  dl(a)
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}