#include <iostream>
#include <string>
using namespace std;
int * multiply(int * a,int * b,int len_a,int len_b);
int main() {
    string R;
    int n;
    while(cin>>R>>n){
        int i = 0;
        int point = 0;
        while(i<6){
            i++;
            if(R[i]=='.'){
                point = 5-i;
                R.erase(i,1);
            }
        }
        int x=atoi(&R[0]);
        if(n==0){
            cout<<'1'<<endl;
            continue;
        }
        int * result = new int[6*n];
        int * h = new int[6];
        for(i = 0;i<6;i++){
            h[i]=x%10;
            result[i]=h[i];
            x = x/10;
        }
        for(i = 1;i<n;i++){
            result = multiply(result,h,6*i,6);
        }
        i = 6*n-1;
        while(i>=point*n&&result[i]==0)i--;
        int end = 0;
        while(end<point*n&&(result[end]==0||result[end]=='.'))end++;
        for(; i >= end;i--){
            if(point!=(-1)&&i==point*n-1)cout<<'.';
            cout<<result[i];
        }
        cout<<endl;
    }
    return 0;
}

int * multiply(int * a,int * b,int len_a,int len_b){
    int len = len_a + len_b;
    int * num = new int [len];
    for(int i = 0; i < len;i++){
        num[i] =0;
    }
    for(int i = 0; i < len_a;i++){
        for(int j = 0; j < len_b;j++){
            num[i+j]+=a[i]*b[j];
        }
    }
    for(int i = 0; i < len-1;i++){
        num[i+1]+=num[i]/10;
        num[i] = num[i]%10;
    }
    return num;
}

