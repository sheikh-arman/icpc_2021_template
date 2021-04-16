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
ll cnt_ar[5010];
ll prefix_function(string s,ll len)
{
    ll n=s.size();
    vector<ll>prefix(n+1);
    prefix[0]=0;
    ll j=0;
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
        //cnt_ar[j]++;
    }
    ll cnt=0;
    for(ll i=len; i<n; i++)
    {
        if(prefix[i]==len)cnt++;
    }
    return cnt;
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        ll n,ans=0;
        cin>>n;
        cin>>s;
        n=s.size();
        for(ll i=0; i<=n; i++)
        {
            cnt_ar[i]=0;
        }
        string tm_s;
        for(ll i=0; i<n; i++)
        {
            tm_s+=s[i];
            string tem=tm_s+"#"+s;
            ans+=prefix_function(tem,i+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

