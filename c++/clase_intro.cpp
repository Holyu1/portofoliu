#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int i,j,k,last,p;
        string rez="";
        for(i=0;i<=s.length()-1;i++)
        {
            j=i;
            k=s.length()-1;
            while(s[i]!=s[k] && i<=k)
                k--;
            last = k;
            while (j<=k-1) {
                while(s[j]!=s[k])
                    k--;
                if (j<=k-1)
                    j++;
            }
            if(j==k)
                if(last-i+1 > rez.size())
                {
                    rez="";
                    for(p=i;p<=last;p++)
                        rez.push_back(s[p]);
                }
        }
        return rez;
    }
};
int main() {
    Solution sol;
    string s;
    cin>>s;
    cout<<sol.longestPalindrome(s)<<endl;
    return 0;
}
