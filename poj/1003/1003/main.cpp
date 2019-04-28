//
//  main.cpp
//  1003
//
//  Created by 电脑 on 2019/1/22.
//  Copyright © 2019 电脑. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    float c;
    while(cin>>c){
        if(c==0)break;
        float n = 2;
        float len = 0;
        for(;len<c;n++){
            len+=(1/n);
        }
        cout<<n-2<<" card(s)"<<endl;
    }
    return 0;
}
