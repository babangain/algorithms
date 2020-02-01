#include <bits/stdc++.h>
#include <stack>

using namespace std;

void printLcs(vector<vector<int>> arr, string s1, string s2,int lcs_len)
{
    int l1 = s1.length(); // Orginal length + 1
    int l2 = s2.length(); // Orginal length + 1
    char res[lcs_len+1];
    res[lcs_len] ='\0';
    int i=l1-1, j=l2-1;
    while (i>0 && j>0)
    {
        if(s1[i] == s2[j])
        {
            res[--lcs_len] = s1[i];
            i--;
            j--;
        }
        else
        {
            if(arr[i-1][j] > arr[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    cout<<res;
    cout<<endl;


}
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
    int lcs_len = arr[l1][l2];
    printLcs(arr,s1,s2,lcs_len);
    return lcs_len;
}

int32_t main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<lcs(s1,s2);



}
