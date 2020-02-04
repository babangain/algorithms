#include <bits/stdc++.h>

using namespace std;

int subsetsum(vector<int> lst, int target)
{
    int l = lst.size();
    vector<vector<bool>> arr(l,vector<bool>(target+1, false));
    for(int i=0; i<l; i++)
        arr[i][0] = true;
    for(int i=1; i<l;i++)
    {
        for(int j=1; j<= target; j++)
        {
            if((( j>= lst[i]) && arr[i-1][j-lst[i]]) || (arr[i-1][j]))
            {
                arr[i][j] = true;
            }

            //cout<<arr[i][j]<<"\t";
        }
        //cout<<endl;
    }
    int possible = arr[l-1][target];
    return possible;
}

int32_t main()
{
    int T,N,target;
    cin>>T;
    while (T--)
    {
        cin>>N>>target;
        vector<int> lst(N+1,0);
        for(int i=1; i<=N; i++)
            cin>>lst[i];
        if(subsetsum(lst, target))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }


}
