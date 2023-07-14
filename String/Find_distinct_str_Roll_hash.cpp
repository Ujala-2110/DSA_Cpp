#include<bits/stdc++.h>
using namespace std;

// Applications of Hashing
// Here are some typical applications of Hashing:

// Rabin-Karp algorithm for pattern matching in a string in  time
// Calculating the number of different substrings of a string in  (see below)
// Calculating the number of palindromic substrings in a string.

int p = 31;
const int N = 10, mod = 1e9+7;
vector<long long>powers(N);
//Bruteforce 
// int main()
// {
//     vector<string>str = {"aa", "ab", "aa", "b", "cc", "aa"};

//     sort(str.begin(),str.end());

//     int dist = 0;
//     for(int i=0;i<str.size();i++) 
//     {
//         if(i == 0 || str[i] != str[i-1]){
//             dist++;
//             cout<<str[i]<<" ";
//         }
        
//     }

//     cout<<dist<<"\n";
//     return 0;
// }
// TC -> O(nmlog(n)) m->sizeof(every string)

//Rolling hashing

long long calculate_hash(string &s)
{
    long long hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
       hash = (hash + (s[i]-'a' +1)*powers[i]) % mod;
    }
    return hash;
}

int main()
{
    powers[0] = 1;
    for(int i=1;i<N;i++) powers[i] = (powers[i-1] * p) % mod;

    vector<string>str = {"aa", "ab", "aa", "b", "cc", "aa"};

    vector<long long>hashes;

    for(auto w : str)
    {
        hashes.push_back(calculate_hash(w));
    } //TC-> O(nm)

    sort(hashes.begin(),hashes.end()); //TC -> O(nlon(n))

    int dist = 0;
    for(int i=0;i<hashes.size();i++){
        if(i == 0 || hashes[i] != hashes[i-1]) dist++;
    }

    cout<<dist<<"\n";
    return 0;
}
