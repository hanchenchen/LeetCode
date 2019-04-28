//
//  main.cpp
//  1004
//
//  Created by 电脑 on 2019/1/23.
//  Copyright © 2019 电脑. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int num,i;
    cin>>num;
    float *x = new float[num];
    float *y = new float[num];
    float *s = new float[num];
    for(i=0;i<num;i++){
        cin>>x[i]>>y[i];
    }
    for(i=0;i<num;i++){
        s[i] = 3.14 * (x[i]*x[i]+y[i]*y[i])/2;
    }
    for(i=0;i<num;i++){
        float a = s[i]/50;
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<(a>(int)a?(int)a+1:(int)a)<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
