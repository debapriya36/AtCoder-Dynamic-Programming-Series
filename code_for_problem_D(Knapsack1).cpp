/*

ATCODER DP :     PROBLEM D (Knapsack 1)
PROBLEM LINK :   https://atcoder.jp/contests/dp/tasks/dp_d

*/


#include<algorithm>
#include<bits/stdc++.h>
#define ll  long long int
#define dbl long double
#define loop(i,ed) for(ll i=0;i<ed;i++)
#define rloop(i,ed) for(ll i=ed-1;i>=0;i--)
#define aloop(it,a) for(auto it:a)
#define test(tc) ll tc;cin>>tc;while(tc--)
#define debo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<ll>
#define sz size()
#define bs binary_search
#define setBits  __builtin_popcountll
#define  mod 1000000007
#define yos cout<<"YES"<<endl
#define nos cout<<"NO"<<endl
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define vep vector<pair<ll,ll>>
#define all(v) v.begin(),v.end()
#define tos to_string
#define iss(v) is_sorted(all(v))
#define sp " "
#define mem(a,i) memset(a,i,sizeof(a))

using namespace std;

/*
" " =>32
A=>65
a=>97
*/


bool isPrime(ll  n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool IsPalindrome( string  str)
{
    if (str.empty())
        return false;
 
    ll i = 0;                // first characters
    ll j = str.length() - 1; // last character
 
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
 
// Binary Exponentiation fun to calculate pow in 0(logN)
ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return (res * res * a);
    
        return (res * res);
}


 





signed main(){
    debo;
 // test(tc){

     

     ll N,W;
     cin >> N >> W;
    vector<long long> weight(N),value(N);
    vector<vector<long long>> dp(N + 1,vector<long long>(W + 1,0));
     for (ll i = 0; i < N; i++) cin >> weight[i] >> value[i];
 
      for (ll i = 0; i < N; i++) {
      for (ll j = 0; j <= W; j++) {
      if (j - weight[i] >= 0) {
        dp[i + 1][j] = max(dp[i][j],dp[i][j - weight[i]] + value[i]);
       } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }
 
  cout << dp[N][W] ;

   
        


        

  //  }
   return 0;
}

