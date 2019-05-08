#include <stdio.h>   
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;


int func(int n)

{

    if (n < 2)

        return n;
    // fork();

    return func(n - 1) + func(n - 2);

}



int main ()   

{

    printf("%d\n",func(7)); 


    system("pause");
    return 0;  

}  