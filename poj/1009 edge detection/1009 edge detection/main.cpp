//
//  main.cpp
//  1009 edge detection
//
//  Created by 电脑 on 2019/1/25.
//  Copyright © 2019 电脑. All rights reserved.
//

#include <iostream>
using namespace std;
static int input[2000][2];
static int output[2000][2];
static int s_index,s_i;
int max(int arr[],int num){
    int result = 0;
    for(int i = 0;i< num;i++){
        if(result<arr[i])result = arr[i];
    }
    return result;
}
int value(int x,int width,int length){
    int va = 0,sub=0;
    int num =0;int arr[8]={0};
    int index=s_index;int i=s_i;
    for(;index<=x;i++){
        index += input[i][0];
    }
    i--;index -=input[i][0];
    if(i<0||index<0){index=0;i=0;}
    va = input[i][1];
    int a1,a2,b1,b2;
    if(x%width==0){
        a1=x-width+1;a2=x;
        b1=x+1;b2=x+width;
    }else if((x+1)%width==0){
        a1=x-width;a2=x-1;
        b1=x;b2=x+width-1;
    }else{
        a1=x-width+1;a2=x-1;
        b1=x+1;b2=x+width-1;
    }
    for(;index>a2-width&&i!=0;i--,index -= input[i][0]){}
    if(i<0||index<0){index=0;i=0;}
    s_index = index;s_i=i;
    for(;index<b1+width+1&&index<length;i++){
        int x1 = index;
        if(input[i][0]==0)break;
        index += input[i][0];
        int x2 = index;
        if((x1>a1&&x2<=a2)||(x1>b1&&x2<=b2)||(x1==x&&x2==x+1))continue;
        sub = (input[i][1]-va)>0?(input[i][1]-va):(-input[i][1]+va);
        arr[num]=sub;
        num++;
    }
    return max(arr,num);
}


int main(){
    int width=0;
    int pixel=0,length=0;
    while(cin>>width){
        if(width == 0)break;
        s_index = 0;s_i=0;
        int n = 0;
        for(n=0;n<2000;n++){
            input[n][0]=0;
            input[n][1]=0;
            output[n][0]=0;
            output[n][1]=0;
        }
        int all = 0;int index = 0;
        while(cin>>pixel>>length){
            if(pixel==0&&length==0)break;
            input[all][0]=length;
            input[all][1]=pixel;
            all++;
            index+=length;
        }
        int l = index;
        if(index==width&&all==1){
            if(index==1){
                cout<<width<<endl;
                cout<<input[all--][1]<<" "<<width<<endl<<"0 0"<<endl;
            }
            else {
                cout<<width<<endl;
                cout<<"0 "<<width<<endl<<"0 0"<<endl;
            }
            continue;
        }
        index=0;
        int start=0,end=0;
        int i=0,j=0,mid=0;
        output[0][1]=value(0, width, l);
        for(n=0;n<all;n++){
            start = index;
            index+=input[n][0];
            end = index - 1;
            if(input[n][0]>(width*2+2)){
                for(i=start;i<start+width+1;i++){
                    mid=value(i, width, l);
                    if(output[j][1]!=mid){
                        output[++j][1]=mid;
                    }
                    output[j][0]++;
                }
                if(output[j][1]!=0){
                    output[++j][1]=0;
                }
                output[j][0]+=end-width-i;
                for(i=end-width;i<=end;i++){
                    mid=value(i, width, l);
                    if(output[j][1]!=mid){
                        output[++j][1]=mid;
                    }
                    output[j][0]++;
                }
            }else{
                for(i=start;i<=end;i++){
                    mid=value(i, width, l);
                    if(output[j][1]!=mid){
                        output[++j][1]=mid;
                    }
                    output[j][0]++;
                }
            }
        }
        cout<<width<<endl;
        for(n=0;n<=j;n++){
            if(output[n][0]==0)break;
            cout<<output[n][1]<<" "<<output[n][0]<<endl;
        }
        cout<<"0 0"<<endl;
    }
    cout<<"0"<<endl;
    return 0;
}
