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




int solution(int n){
	if(n == 0)
		return 0;

  int maxTwoPower = 0;
  int pow = 2;

  while(pow <= n){
  	pow <<= 1LL;
  	maxTwoPower++;
  }

  // cout << maxTwoPower << endl;

  int ans = (1LL << (maxTwoPower-1)) * maxTwoPower + (n - (1LL << maxTwoPower) + 1) + solution(n - (1 << maxTwoPower));
  return ans;
}

int countSetBits(int n){
	++n; 
	int cnt = 0;
	int power = 1;

	while(power <= n){
		// d(power)

		int numOfPairs = n / power;
		int numOfPairOfOne = numOfPairs / 2;
		int temp = numOfPairOfOne * (power);

		if(numOfPairs & 1)
			temp += (n % power);
		cnt += temp;
		power <<= 1LL;

		 // d(numOfPairs) d(numOfPairOfOne) d(temp) dl(cnt) 
	}
	return cnt;
}

int ACsolution(int A){
	int i = 0;
	int MOD = 1e9 + 7;
	long long int ans(0);

	while((1 << i) <= A){
		int N = A - (1 << i) + 1;
		int set = N / (1 << (i + 1));
		ans += (set * (1 << i));
		int remain = N - set * (1 << (i + 1));
		ans += min(remain, 1 << i);
		ans %= MOD;
		i++;
	}
	return ans;
}

void solve(){
  int n; cin >> n;
  // cout << solution(n) << endl;

  // most optimized solution
  cout << countSetBits(n) % (1000000007)<< endl;
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}