#include<iostream>
#include<cstring>
using namespace std;
bool isPalindrome(string str);
int main()
{
    cout<<isPalindrome("hhdhh")<<endl;
    cout<<isPalindrome("haah")<<endl;
    cout<<isPalindrome("hafasg")<<endl;
    cout<<isPalindrome("hahaahahe")<<endl;
    return 0;
}

bool isPalindrome(string str)
{
    for(int i=0;i<(str.size()+1)/2;i++)
    {
        if(str[i]==str[str.size()-i-1])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
