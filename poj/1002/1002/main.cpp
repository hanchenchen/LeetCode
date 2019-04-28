//
//  main.cpp
//  1002
//
//  Created by 电脑 on 2019/1/22.
//  Copyright © 2019 电脑. All rights reserved.
//
#include<stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int tel(char x[]){
    int y=0;
    int n=0;
    for(int i = 0;i<100;i++){
        if(n==7)break;
        if(x[i]>=48&&x[i]<=57){
            y=y*10+x[i]-48;
            n++;continue;
        }
        if(x[i]>=65&&x[i]<=80){
            y=y*10+(x[i]+1)/3-20;
            n++;continue;
        }
        if(x[i]>=81&&x[i]<=89){
            y=y*10+x[i]/3-20;
            n++;continue;
        }
    }
    return y;
}

int main() {
    multimap<int,int> directory;
    char input[100];
    int num;
    int midst;int i=0;
    multimap<int,int>::iterator iter;
    scanf("%d",&num);
    for(i = 0;i<num;i++){
        cin>>input;
        midst=tel(input);
        directory.insert(pair<int,int>(midst,1));
    }
    int ifdup = 0;
    
    for(iter=directory.begin();iter!=directory.end();){
        i=0;int past=iter->first;
        while(past==iter->first){iter++;i++;}
        if(i>1){
            printf("%03d-%04d",past/10000,past%10000);
            cout<<" "<<i<<endl;
            ifdup=1;
        }
    }
    if(ifdup==0)cout<<"No duplicates. "<<endl;
    return 0;
}


