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

int getNthBinaryPalindrom(int n){
	if(n == 1)
		return 1;

	--n;

	queue<string>q;
	q.push("11");
	
	while(!q.empty()){
		string cur = q.front();
		q.pop();
		--n;

		if(!n){
			int val = 0;
			for(int i = 0; i < cur.size(); ++i){
				if(cur[i] == '1')
				   val |= (1 << i);
			}
			return val;
		}

		int mid = cur.size() / 2;

		if(cur.size() & 1){
			string ch(1, cur[mid]);
			string tmp = cur;
			tmp.insert(mid, ch);
			q.push(tmp);
		}
		else{
			string s = cur, s1 = cur;
			s.insert(mid, "0");
			s1.insert(mid, "1");
			q.push(s);
			q.push(s1);
		}
	}

	return 0;
}

void solve(){
  int n; cin >> n;
  cout << getNthBinaryPalindrom(n) << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}