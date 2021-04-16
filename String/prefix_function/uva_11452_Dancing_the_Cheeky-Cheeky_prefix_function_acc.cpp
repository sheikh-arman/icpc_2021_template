#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
#define VST(V) sort(V.begin(),V.end())
#define VSTrev(V) sort(V.begin(),V.end(),greater<long long int>())
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
#define MAX 2000010
string prefix_function(string s)
{
    ll n=s.size();
    vector<ll>prefix(n+2);
    prefix[0]=0;
    ll j=0;
    ll ans=0;
    for(ll i=1; i<n; i++)
    {
        while(j>0&&s[i]!=s[j])
        {
            j=prefix[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        prefix[i]=j;
        ans=max(ans,j);
    }
    ans=n-ans;
    s=s.substr(0,ans);
    reverse(s.begin(),s.end());
    while(1)
    {
        ll siz=s.size();
        if(siz>=8)break;
        s+=s;
    }
    s=s.substr(0,8);
    return s;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        s=prefix_function(s);
        cout<<s<<"...\n";
    }
    return 0;
}
