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

int divide(int dividend, int divisor){
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

	divisor = abs(divisor);
	dividend = abs(dividend);

	int temp = 0, quotient = 0, total = 0;

	for(int i = 31; i >= 0; --i){
		if(temp + (divisor << i) <= dividend){
			temp += (divisor << i);
			quotient |= (1LL << i);
			d(i) d(temp) dl(quotient)
		}
	}

	return quotient * sign;
}

int divideWithLog(int dividend, int divisor){
	int sign;

	if((divisor < 0 && dividend < 0) || (dividend >= 0 && divisor >= 0))
		sign = 1;
	else
		sign = -1;

	if(divisor == 1LL)
		return dividend;

	dividend = (dividend == INT_MIN) ? INT_MAX : abs(dividend);
	divisor = (divisor == INT_MIN) ? INT_MAX : abs(divisor);

	int ans = exp(log(dividend) - log(divisor)) + 0.0000000001;
	if(ans > INT_MAX) 
		ans = INT_MAX;

	return ans * sign;
}

void solve(){
	int a, b; cin >> a >> b;
	cout << divideWithLog(a, b) << endl;
	// cout << divide(a, b) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(nullptr));

	solve();

	return 0;
}