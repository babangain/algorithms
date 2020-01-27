#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int W,items;
    cin>>W>>items;
    int  weight[items+1], value[items+1];
    for(int i=1; i<=items; i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }
    vector<vector<int>> arr(items+1, vector<int>(W+1,0));

    for(int i=1; i<=items;i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(weight[i] > j)
                arr[i][j] = arr[i-1][j];
            else
            {
                arr[i][j] = max(arr[i-1][j],value[i]+arr[i-1][j-weight[i]]);
            }
        }
    }
    cout<<arr[items][W];

}
