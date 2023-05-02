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

int convertStringToInt(string cur){
	int val = 0;
	for(int i = 0; i < cur.size(); ++i){
		if(cur[i] == '1')
			val |= (1 << i);
	}
	return val;
}
int getNthNumber(int n){
	if(n == 1)
		return 1;
	--n;

	queue<string>q;
	q.push("11");

	while(!q.empty()){
		string curr = q.front();
		q.pop();
		--n;

		if(!n){
			return convertStringToInt(curr);
		}

		int mid = curr.size() / 2;
		if(curr.size() & 1){
			string ch(1, curr[mid]);
			string temp = curr;
			temp.insert(mid, ch);
			q.push(temp);
		}
		else{
			string s = curr, s1 = curr;
			s.insert(mid, "0");
			s1.insert(mid,"1");
			q.push(s);
			q.push(s1);
		}
	}
	return 0;
}

void solve(){
	int n; cin >> n;
	cout << getNthNumber(n) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	solve();

	return 0;
}