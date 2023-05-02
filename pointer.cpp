// Let's Begin Mara Khawa ^+^
// author : @I_Love_My_Sherniii

// 13-04-23
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

struct str {

};

void func(int a, int b){

};

void f(int *p, int *q){
  p = q;
  *p = 2;
}

void solve(){
  cout << "Hello Pointers" << endl;
  int var = 10;
  int *ptr = &var;
  d(var) d(ptr) dl(*ptr)

  *ptr = 20;
  d(var) d(ptr) dl(*ptr)

  // int *(*ptr) = &ptr;
  // *(*ptr) = 30;
  
  d(var) d(ptr) dl(*ptr)

  int a = 100;
  char c = 'a';
  double d = 10.12334;
  struct str x;

  int *ptr_int = &a;
  char *ptr_char = &c;
  struct str* ptr_str = &x;

  void (*ptr_func)(int,int) = &func;
  void *ptr_null = NULL;

  d(a) d(*ptr_int) dl(sizeof(*ptr_int))
  d(c) d(*ptr_char) dl(sizeof(*ptr_char))
  // d(x) d(*ptr_str) dl(sizeof(*ptr_str))

  // 0
  // 0
  // 5
  // 5
  // 6
  // 6

  // Size of pointer is fixed for all data types

  float arr[] = {12.5, 10,0, 13.5,90.5, 0.5};
  float *ptr1 = &arr[0];
  float *ptr2 = ptr1 + 3;

  d(*ptr1) d(ptr1) d(ptr2) d(*ptr2) dl(ptr2-ptr1)
  
  char *p = "GeekforGeeks";
  dl(*&*&p)
  dl(&*&*&p)
  dl(*&*&*&*p)
  dl(*&*&*&p)

  int i = 0, j = 1;
  f(&i, &j);
  d(i) dl(j)
}

int32_t main(){
  ios_base::sync_with_stdio(!cin.tie(nullptr));
  
  solve();

  return 0;
}