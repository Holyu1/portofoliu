#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector <int>& nums)
    {
        int i,aux,sum,j,t,l,k=0;
        vector <int> u,q;
        for (i = 0; i <= nums.size()-1; i++) {
            sum=0;
            aux=nums[i];
            while (aux!=0) {
                sum=sum+aux%10;
                aux=aux/10;
            }
            u.push_back(sum);
        }
        for (i=0;i<=nums.size()-1;i++)
            q.push_back(i);
        for (i=0;i<=nums.size()-2;i++)
            for (j=i+1;j<=nums.size()-1;j++)
                if (u[i]>u[j]) {
                    swap(u[i],u[j]);
                    swap(nums[i],nums[j]);
                    swap(q[i],q[j]);
                }
        i=0;
        while (i<=nums.size()-2) {
            j=i+1;
            int ok = 0;
            while (u[i]==u[j]) {
                j++;
                ok=1;
            }
            if (ok==1)
                for (t=i;t<=j-2; t++)
                    for (l=t+1; l<=j-1; l++)
                        if (nums[t]>nums[l])
                            swap(nums[t],nums[l]);
            i=j;
        }
        for (i=0;i<=nums.size()-1;i++)
           cout << nums[i] << " ";
        cout << endl;
        for (i=0;i<=q.size()-1;i++)
            cout << q[i] << " ";
        cout << endl;
        return k;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    int i,x,n;
    cin >> n;
    for (i = 0;i <=n-1;i++) {
        cin >> x;
        v.push_back(x);
    }
    cout << s.minSwaps(v);
}