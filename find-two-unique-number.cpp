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
  int numberOfInputs; cin >> numberOfInputs;
  vector<int>arr(numberOfInputs);

  for(int i = 0;i < numberOfInputs; ++i){
  	cin >> arr[i];
  }

  print(arr)

  int xorOfArr = arr[0];
  for(int i = 1; i < numberOfInputs; ++i){
  	xorOfArr ^= arr[i];
  }

  dl(xorOfArr)

  int firstSetBitOfXorValue = 0;
  for(int i = 0; i < 64; ++i){
  	if(xorOfArr & (1 << i)){
  		firstSetBitOfXorValue = i;
  		break;
  	}
  }

  dl(firstSetBitOfXorValue)

  int firstVal = 0;

  // Checking which numbers first set value match with our XorSum
  // all matching repeating value will cancel out except one 
  
  for(int i = 0; i < numberOfInputs; ++i){
  	if(arr[i] & (1 << firstSetBitOfXorValue)){
  		firstVal ^= arr[i];
  	}
  }

  int secondVal = xorOfArr ^ firstVal;  // firstVal ^ secondVal = xorOfArr
  cout << firstVal << " " << secondVal << endl;    // xorOfArr ^ firstVal = secondVal
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}