/*
""
"B"
"66"
"A"
"BA"
"66A"
"65"
"B65"
"6665"
*/

#include<bits/stdc++.h>
using namespace std;

void subseq(string s, string ans)
{
    if(s.length()==0)//Base case
    {
        cout<<ans<<"\n";
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros,ans+to_string(int(ch)));//acsii code
} 

int main()
{
    subseq("AB ","");
    return 0;
}