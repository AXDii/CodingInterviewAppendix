
#include<iostream>
#include<stdio.h>
using namespace std;
static int minCount = 0;

int abs(int num) {
    if(num < 0) {
        return -num;
    }
    return num;
}


int min(int &a, int &b, int &c) {
    if(a <= b && a <= c) {
        return a;
    }
    if(b <= a && b <= c) {
        return b;
    }
    if(c <= a && c <= b) {
        return c;
    }
    return b;
}
int fun(int num1, int num2, int type) {
    //先处理两者皆为正，num1 < num2
    if(type == 1) {
        int count1 = num2 - num1;
        int count2 = abs(num2/2 - num1) + 1;
        int count3 = 0;
        if(num2 % 2 == 1) {
            count2++;
        }
        while(num1 < num2) {
            num1 = num1*2;
            count3++;
        }
        count3 = count3 + num1 - num2;
        return min(count1, count2, count3);
    }
    return -1;

}




//将小的转为num1， 大的转为num2
void B1S2(int &a, int &b) {
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}


int main(){

    int num1, num2;
    scanf("%d,%d", &num1, &num2);
    int count = 0;
    if(num1 * num2 > 0) {
        B1S2(num1, num2);
        count = fun(abs(num1), abs(num2), 1);
    } else {
        B1S2(num1, num2);
        count = fun(num1, num2, 2);
    }
    cout<<count;


    return 0;
}
