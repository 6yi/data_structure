#include <iostream>
 
using namespace std;
 
const int BASE = 10;
 
int palindrom(int n)
{
    if(n == 1 || n == 2)
        return BASE - 1;
    else {
        if(n % 2 == 1)
            return palindrom(n-1) * BASE;
        else
            return palindrom(n-2) * BASE;
    }
}
 
// 递推的计算回文数函数，参数为10进制位数
int palindrom2(int n)
{
    if(n == 1 || n == 2)
        return BASE - 1;
 
    int p1= BASE - 1, p2 = BASE - 1, i, temp;
 
    i = 2;
    while(i < n) {
        i++;
        if(i % 2 == 1) {
            p1 = p2;
            p2 = p1 * BASE;
        } else {
            temp = p1;
            p1 = p2;
            p2 = temp * BASE;
        }
    }
 
    return p2;
}
 
int main()
{
    int n, sum;
 
    cin >> n;
 
    sum = 0;
    for(int i=1; i<=n; i++)
        sum += palindrom2(i);
 
    cout << sum << endl;
 
    return 0;
}
