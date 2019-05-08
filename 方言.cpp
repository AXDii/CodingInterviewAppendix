// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include<vector>
#include <cstdio>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    
    long long int N = 0, K = 0, tmp = 0;
    cin>>N>>K;
    vector<long long int> ans;
    for(int i = 0; i < K; i++) {
        cin>>tmp;
        ans.push_back(tmp);
    }

    

    int size = ans.size();
    while(size > 1) {
        long long int t = 0;
        for(int i = 0; i < size - 1; i++) {
            t = ans[i] + ans[i+1] - N;
            if(t < 0) {
                t = 0;
            }
            ans[i] = t;
        }
        ans.pop_back();
        size--;
    }
    cout<<ans[0];

    return 0;
}