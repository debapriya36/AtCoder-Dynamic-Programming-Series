
/*

ATCODER DP :     PROBLEM A (Frog 1)
PROBLEM LINK :   https://atcoder.jp/contests/dp/tasks/dp_a

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





ll ar[100000+5];
ll n; 
ll dp[100000+5]; 






ll minCost(ll ind)
{
	if(ind==(n-1))
		return 0;
	else if(dp[ind]!=-1) return dp[ind];
	else
	{
		ll ans = INT_MAX; 
		for(ll i = 1;i<=2;i++)
		{
			if(ind+i<=n-1)
				ans = min(ans,abs(ar[ind+i]-ar[ind]) + minCost(ind+i));
 
		}
		return dp[ind] = ans; 
	}
 
}
 
 


signed main(){
    debo;
  // test(tc){




     cin >> n ;
     for(ll i=0;i<n;i++){     
     cin >> ar[i];
     dp[i]=-1;
}
  
  cout << minCost(0); 
 





  //   }
   return 0;
}

