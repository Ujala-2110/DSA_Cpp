#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "GeeksforGeeks is good to learn";
    // breaking input into word using string stream
    stringstream ss(str);   // Used for breaking words
    string word; // word variable to store word

    while (ss >> word)
    {
        reverse(word.begin(), word.end());
        cout << word << " ";
    }

    return 0;
}