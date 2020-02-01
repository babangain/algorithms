#include <bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    s1 = " "+s1;
    s2 = " "+s2;
    vector<vector<int>> arr(l1+1,vector<int>(l2+1,0)); // arr[l1+1][l2+1]
    for(int i=1; i<=l1;i++)
    {
        for(int j=1; j<= l2; j++)
        {
            if(s1[i] == s2[j])
            {
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
            //cout<<arr[i][j]<<"\t";
        }
        //cout<<endl;
    }
    return arr[l1][l2];
}
int32_t main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<lcs(s1,s2);


}
