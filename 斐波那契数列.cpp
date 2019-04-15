/**斐波那契数组，用非递归方式
 */ 
#include<iostream>
using namespace std;

int Fibonacci(int n) {
    //1，1，2，3，5，8
    int f1 = 0;
    int f2 = 1;
    if(n == 0) {
        return f1;
    }
    if(n == 1) {
        return f2;
    }
    int i = 2;
    int sum = 0;
    while(i++ <= n) {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum;
}

int main(){
    cout<<Fibonacci(39)<<endl;
    system("pause");
    return 0;
}