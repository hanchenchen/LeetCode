#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MAX 30
float a[MAX][2];
float b[MAX][2];

int main(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int k = 0;
    cin>>k;
    int i = 0;
    for(;i<k;i++){
        cin>>a[i][0]>>a[i][1];
    }
    
    int k_2 = 0;
    cin>>k_2;
    for(i = 0;i<k_2;i++){
        cin>>b[i][0]>>b[i][1];
    }
    
    int kk = k+k_2;
    int j;
    i=j=0;

    while(i!=k&&j!=k_2){
        //if(i==0&&j==0)sprintf(s," ");
        if(a[i][0]==b[j][0]){
            if(a[i][1]+b[j][1]==0)kk--;
            //sprintf(s,"%.0f %.1f",a[i][0],a[i][1]+b[j][1]);
            i++;j++;kk--;
            
        }
        else if(a[i][0]>b[j][0]){
            //sprintf(s,"%.0f %.1f",a[i][0],a[i][1]);
            i++;
        }else{
            //sprintf(s,"%.0f %.1f",b[j][0],b[j][1]);
            j++;
        }
    }
    cout<<kk<<" ";
    i=j=0;
    int sta = 0;
    while(i!=k&&j!=k_2){
        if(sta)
            printf(" ");
        else
            sta=1;
        if(a[i][0]==b[j][0]){
            if(a[i][1]+b[j][1]!=0){
                printf("%.0f %.1f",a[i][0],a[i][1]+b[j][1]);
            }else sta=0;
            i++;j++;
        }
        else if(a[i][0]>b[j][0]){
            printf("%.0f %.1f",a[i][0],a[i][1]);
            i++;
        }else{
            printf("%.0f %.1f",b[j][0],b[j][1]);
            j++;
        }
    }
    while(i!=k){
        printf(" %.0f %.1f",a[i][0],a[i][1]);
        i++;
    }
    while(j!=k_2){
        printf(" %.0f %.1f",b[j][0],b[j][1]);
        j++;
    }
    cout<<endl;
    return 0;
}
