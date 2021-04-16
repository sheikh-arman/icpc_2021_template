#include<bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  base1 129
#define  base2 137
#define  MOD1  1479386893
#define  MOD2  1928476349
ll prefix_function(string s)
{
    ll ans=1;
    ll n=s.size();
    vector<ll>prefix(n+1);
    prefix[0]=0;
    ll start=n/2;
    for(ll i=start; i<n; i++)
    {
        ll j=prefix[i-1];
        while(j>0&&s[j]!=s[i])
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
//    for(ll i=0;i<n;i++){
//        cout<<prefix[i]<<" ";
//    }
//    cout<<"\n";
    return ans;
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
        string rev=s;
        reverse(rev.begin(),rev.end());
        s=s+'#'+rev;
        //cout<<s<<"\n";
        ll ans=prefix_function(s);
        string ss;
        for(ll i=0;i<ans;i++){
            ss+=s[i];
        }
        reverse(ss.begin(),ss.end());
        cout<<ss<<"\n";
    }
    return 0;
}

