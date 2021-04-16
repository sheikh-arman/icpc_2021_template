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
#define MAX 1100010
deque<char>ans;
ll prefix[2000000];
void prefix_function(string s)
{
    s+="#";
    ll siz_s=s.size();
    ll siz_ans=ans.size();
    ll j=0;
    prefix[0]=0;
    for(ll i=1; i<siz_s; i++)
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
    }
    j=0;
    ll mi=min(siz_s-1,siz_ans);
    ll start=siz_ans-mi;
    ll last=0;
    for(ll i=start; i<mi+start; i++)
    {
        while(j>0&&ans[i]!=s[j])
        {
            j=prefix[j-1];
        }
        if(ans[i]==s[j])
        {
            j++;
        }
        prefix[i+siz_s]=j;
        last=i+siz_s;
    }
    ll len=prefix[last];
    for(ll i=len; i<siz_s-1; i++)
    {
        ans.PB(s[i]);
    }
}
int main()
{
    //freopen("1input.txt","r",stdin);
    fast;
    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        cin>>n;
        string s;
        vector<string>V;
        for(ll i=0; i<n; i++)
        {
            cin>>s;
            V.PB(s);
        }
        if(n==1)
        {
            cout<<V[0]<<"\n";
            return 0;
        }
        for(ll i=0; i<(ll)V[0].size(); i++)
        {
            ans.PB(V[0][i]);
        }
        for(ll i=1; i<n; i++)
        {
            prefix_function(V[i]);
        }
        ll siz=ans.size();
        for(ll i=0; i<siz; i++)
        {
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
