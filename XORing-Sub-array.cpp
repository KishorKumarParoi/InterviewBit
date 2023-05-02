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
	vector<int>v(n);

	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	vector<int>cnt(n, 0);
	for(int i = 0; i < n; ++i){
		cnt[i] = (i + 1) * (n - i);
		cnt[i] &= 1;
	}

	// print(cnt)
	int val = 0;

	for(int i = 0; i < n; ++i){
		if(cnt[i] == 1){
			val ^= v[i];
		}
	}
	val ^= 0;
	
	cout << val << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	solve();

	return 0;
}