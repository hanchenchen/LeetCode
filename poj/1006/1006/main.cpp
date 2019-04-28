//
//  main.cpp
//  1006
//
//  Created by 电脑 on 2019/1/24.
//  Copyright © 2019 电脑. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int p,e,i,d;
    int num;
    int x=1;
    while(cin>>p>>e>>i>>d){
        if(p==-1&&e==-1&&i==-1&&d==-1)break;
        for(num = d+1;num < 50000;num++){
            if(num%23==p%23&&num%28==e%28&&num%33==i%33)break;
        }
        cout<<"Case "<<x;
        cout<<": the next triple peak occurs in "<<num-d;
        cout<<" days."<<endl;
        x++;
    }
    return 0;
}
