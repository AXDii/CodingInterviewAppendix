/**请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串
 * 为We%20Are%20Happy。
 * 
 * 解题思路：函数能通过，不过复杂度较高，正解是从后往前扫描
 */

#include<iostream>>
#include<vector>
#include<cstring>

using namespace std;

void stop();
void replaceSpace(char *str,int length) {
    int count = 0;//统计空格数量
    for(int i = 0; i < length; i++) {
        if(str[i] == ' ') {
            count++;
        }
    }
    int N = length + 2 * count;
    char tmp[N] = {'\0'};
    for(int i = 0, j = 0; i < N; i++) {
        if(str[i] == ' ') {
            tmp[j++] = '%';
            tmp[j++] = '2';
            tmp[j++] = '0';
        } else {
            tmp[j++] = str[i];
        }
    }
    for(int i = 0; i < length; i++) {
        str[i] = tmp[i];
    }
}

int main(){

    // char *str = "We Are Happy";
    // replaceSpace(str, strlen(str) + 2*2);
    // cout<<str;
    stop();
    return 0;
}

void stop(){
    cout<<endl;
    system("pause");
}