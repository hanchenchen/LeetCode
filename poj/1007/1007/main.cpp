//
//  main.cpp
//  1007
//
//  Created by 电脑 on 2019/1/24.
//  Copyright © 2019 电脑. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include<string>

using namespace std;
int sortness(char arr[],int n);
int main(int argc, const char * argv[]) {
    int n,m;
    int i;
    cin>>n>>m;
    multimap<int,string> dna;
    for(i=0;i<m;i++){
        char arr[50];
        cin>>arr;
        dna.insert(pair<int, string>(sortness(arr,n), arr));
    }
    multimap<int, string>::iterator iter;
    for(iter = dna.begin(); iter != dna.end(); iter++) {
        cout<<iter->second<<endl;
    }
    return 0;
}
int sortness(char arr[],int n){
    int x = 0;
    int i;
    int acgt[4] = {0,0,0,0};

    for(i=0;i<n;i++){
        if(arr[i]=='A')acgt[0]++;
        if(arr[i]=='C')acgt[1]++;
        if(arr[i]=='G')acgt[2]++;
        if(arr[i]=='T')acgt[3]++;
    }

    for(i=0;i<n;i++){
        if(arr[i]=='A'){
            acgt[0]--;
        }
        if(arr[i]=='C'){
            acgt[1]--;
            x = x + acgt[0];
        }
        if(arr[i]=='G'){
            acgt[2]--;
            x = x + acgt[0] + acgt[1];
        }
        if(arr[i]=='T'){
            acgt[3]--;
            x = x + acgt[0] + acgt[1] + acgt[2];
        }
    }
    return x;
}
