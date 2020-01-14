#include <bits/stdc++.h>
using namespace std;
#define int long long
//Fast modulo copied from https://discuss.codechef.com/t/a-tutorial-on-fast-modulo-multiplication-exponential-squaring/2899/3
typedef long long ll;
ll MOD=10e9+7;
ll fast_exp(int base, int exp)
{
    ll res=1;
    while(exp>0)
    {
        if(exp%2==1)
            res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}
int32_t main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int base,exp;
        cin>>base>>exp;
        cout<<fast_exp(base,exp)<<endl;
    }
}
