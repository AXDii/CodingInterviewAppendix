#include <iostream>
using namespace std;

int func(int n) {

    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }

    int sum = 1;
    int tmp = 0;
    for(int i = n; i >= 2; i--) {
        //只要保留个位数乘以个位数就行了
        tmp = i;

        while(tmp % 10 == 0) {
            tmp /=10;
        }
        if(tmp > 100) {
            tmp %= 100;
        }
        sum *= tmp;
        while(sum % 10 == 0) {
            sum /= 10;
        } 
        if(sum > 100) {
            sum = sum%100;
        }
        // sum = sum % 10;
    }
    return sum;
}

int func2(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    int sum = 1;
    int tmp = 0;
    for(int i = n; i >= 2; i--) {
        tmp = i;
        while(tmp % 10 == 0) {
            tmp/=10;
        }
        if(tmp > 100) {
            tmp = tmp % 100;
        }

        sum *= tmp;
        while(sum % 10 == 0) {
            sum /= 10;
        } 
        if(sum > 100) {
            sum = sum % 100;
        }
    }
    return sum;
}
int main()
{
    int N;
    cin>>N;
    cout<<"func1="<<func(N)%10<<endl;
    cout<<"func2="<<func2(N)%10<<endl;
    cout<<endl;
    system("pause");
    return 0;
}