// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 30-04-23
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

void updateArray(vector<int>&sumArray, int n){
	for(int i = 0; i < 32; ++i){
		if(n & (1 << i)){
			sumArray[i]++;
		}
	}
}

void solve(){
	int n; cin >> n;
	vector<int>v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	vector<int>sumArray(32, 0);
	for(int x : v){
		updateArray(sumArray, x);
	}

	print(sumArray)

	for(int i = 0; i < 32; ++i){
		sumArray[i] %= 3;
	}

	print(sumArray)

	int val = 0;
	for(int i = 0; i < 32; ++i){
		if(sumArray[i])
		   val |= (1LL << i);
	}
	cout << val << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	solve();

	return 0;
}


// // Let's Begin Mara Khawa ^+^
// // author : @I_Love_My_Sherniii

// // 29-04-23
// #include <bits/stdc++.h>

// #define endl "\n"
// #define int long long
// #define sz(s) (int)s.size()
// #define pi acos(-1.0)
// #define fr(i,a,b)                         for(int i=a;i<=b;++i)
// #define all(v)                            v.begin(),v.end()
// #define TEST                              int tc;cin>>tc; while(tc--)
// // Debug
// #define d(a)                              cout << #a << " : " << a << " ";
// #define dl(a)                             cout << #a <<" : " << a << endl;
// #define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
// #define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
// #define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

// using namespace std;

// const int N   = 1e6 + 5;
// const int MOD = 1e9 + 7;

// void solve(){
// 	int n; cin >> n;
// 	vector<int>v(n);
// 	for(int i = 0; i < n; ++i){
// 		cin >> v[i];
// 	}

// 	int cnt[n+10][34] = {0};

// 	for(int i = 0; i < n; ++i){
// 		for(int bit = 0; bit < 32; ++bit){
// 			if(v[i] & (1LL << bit)){
// 				cnt[v[i]][bit] = 1;
// 			}
// 			else{
// 				cnt[v[i]][bit] = 0;
// 			}
// 		}
// 	}

// 	for(int i = 0; i < n; ++i){
// 		cout << v[i] << " : ";
// 		for(int bit = 0; bit < 32; ++bit){
// 			cout << cnt[v[i]][bit] << " ";
// 		}
// 		cout << endl;
// 	}

// 	int sum[65] = {0};
// 	for(int bit = 0; bit < 32; ++bit){
// 		for(int i = 0; i < n; ++i){
// 			sum[bit] += cnt[v[i]][bit];
// 		}
// 	}

// 	for(int i = 0; i < 32; ++i){
// 		cout << sum[i] << " ";
// 	}
// 	cout << endl;

// 	for(int i = 0; i < 32; ++i){
// 		sum[i] = (sum[i] % 3);
// 	}

// 	int val = 0;
// 	for(int i = 0; i < 32; ++i){
// 		if(sum[i])
// 		   val |= (1LL << i);
// 	}

// 	cout << val << endl;
// }

// int32_t main(){
// 	ios_base::sync_with_stdio(!cin.tie(nullptr));

// 	solve();

// 	return 0;
// }