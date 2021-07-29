
/*

ATCODER DP :     PROBLEM C (Vacation)
PROBLEM LINK :   https://atcoder.jp/contests/dp/tasks/dp_c

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

ll n;
ll a[100000+5][4];
ll dp[100000+5][4];
ll w=0,x=1,y=2,z=3;

ll func(ll ind, ll flag) {
 
	if (ind == n) return 0;
 
	if (dp[ind][flag] != -1) return dp[ind][flag];
 
	ll maxi = 0;
	if (flag == w) {
		maxi = max(maxi, a[ind][1] + func(ind + 1, x));
		maxi = max(maxi, a[ind][2] + func(ind + 1, y));
		maxi = max(maxi, a[ind][3] + func(ind + 1, z));
	}
	else if (flag == x) {
		maxi = max(maxi, a[ind][2] + func(ind + 1, y));
		maxi = max(maxi, a[ind][3] + func(ind + 1, z));
	}
	else if (flag == y) {
		maxi = max(maxi, a[ind][1] + func(ind + 1, x));
		maxi = max(maxi, a[ind][3] + func(ind + 1, z));
	}
	else {
		maxi = max(maxi, a[ind][1] + func(ind + 1, x));
		maxi = max(maxi, a[ind][2] + func(ind + 1, y));
	}
 
	return dp[ind][flag] = maxi;
}






 


signed main(){
    debo;
  // test(tc){


   cin>>n;
   loop(i,n)
   {
       for(ll j=1;j<=3;j++)
       {
           cin>>a[i][j];
       }
   }

mem(dp,-1);

cout<<func(w,w);







  //   }
   return 0;
}

