#include <iostream>
#include <string>

using namespace std;

string removeduplicates(string s)
{
    int i = 0,j = 0;
    int hash[26] = {0};
    while(i < s.length() && j < s.length())
    {
        if( ++hash[s[i] - 'a'] <= 1)
        {
            i++;
            j++;
        }
        else
        {
        while(hash[s[j] - 'a'] > 1)
            j++;
        s[i] = s[j];
        }
    }
    for(int k = i;k < s.length();k++)
        s[k] = '\0';
    return s;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        string ans = removeduplicates(s);
        cout << ans << endl;
    }
    return 0;
}
