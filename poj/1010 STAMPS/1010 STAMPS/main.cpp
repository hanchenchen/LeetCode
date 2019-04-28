//
//  main.cpp
//  1010 STAMPS
//
//  Created by 电脑 on 2019/2/6.
//  Copyright © 2019 电脑. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include <map>
using namespace std;

int main() {
    
    //while(1)???有病吧
    for(int a = 0;a<100;a++){
        int types[100]={0};
        int i=0;
        int hhh;
        while(cin>>hhh){
            types[i]=hhh;
            i++;
            if(hhh==0)break;
        }
        sort(types,types+i-1);
        int need=0;
        while(cin>>need){
            if(need==0)break;
            int a,b,c,d;
            int sum=0;
            int best[4]={-1,-1,-1,-1},tie=0;
            int typenum=0;
            for(a=0;a<i;a++)
                for(b=a;b<i;b++)
                    for(c=b;c<i;c++)
                        for(d=c;d<i;d++){
                            sum=types[a]+types[b]+types[c]+types[d];
                            if(sum==need){
                                if(best[0]==-1){
                                    best[0]=a;best[1]=b;best[2]=c;best[3]=d;
                                    typenum=0;
                                    if(a!=i-1)typenum++;
                                    if(b!=i-1&&b!=a)typenum++;
                                    if(c!=i-1&&c!=b&&c!=a)typenum++;
                                    if(d!=i-1&&d!=c&&d!=b&&d!=a)typenum++;
                                }else{
                                    int tm = 0;
                                    if(a!=i-1)tm++;
                                    if(b!=i-1&&b!=a)tm++;
                                    if(c!=i-1&&c!=b&&c!=a)tm++;
                                    if(d!=i-1&&d!=c&&d!=b&&d!=a)tm++;
                                    if(tm==typenum){
                                        int numb_1=0,numb_2=0;
                                        if(best[0]!=i-1)numb_1++;
                                        if(best[1]!=i-1)numb_1++;
                                        if(best[2]!=i-1)numb_1++;
                                        if(best[3]!=i-1)numb_1++;
                                        if(a!=i-1)numb_2++;
                                        if(b!=i-1)numb_2++;
                                        if(c!=i-1)numb_2++;
                                        if(d!=i-1)numb_2++;
                                        if(numb_1>numb_2){
                                            best[0]=a;best[1]=b;best[2]=c;best[3]=d;
                                            tie=0;
                                        }
                                        if(numb_1==numb_2){
                                            int x = best[numb_1-1];
                                            int y =0 ;
                                            if(numb_2==1)y =a;
                                            if(numb_2==2)y =b;
                                            if(numb_2==3)y =c;
                                            if(numb_2==4)y =d;
                                            if(types[x]<types[y]){
                                                best[0]=a;best[1]=b;best[2]=c;best[3]=d;
                                                tie=0;
                                            }else if(types[x]>types[y]){
                                            }else{
                                                tie=1;
                                            }
                                            
                                        }
                                    }
                                    if(tm>typenum){
                                        best[0]=a;best[1]=b;best[2]=c;best[3]=d;
                                        typenum=tm;
                                        tie=0;
                                    }
                                }
                            }
            }
            if(tie){
                cout<<need<<" ("<<typenum<<"): tie "<<endl;
            }else if(best[0]==-1){
                cout<<need<<" ---- none "<<endl;
            }
            else{
                cout<<need<<" ("<<typenum<<"): ";
                a=best[0];b=best[1];c=best[2];d=best[3];
                if(a!=i-1)cout<<types[a]<<" ";
                if(b!=i-1)cout<<types[b]<<" ";
                if(c!=i-1)cout<<types[c]<<" ";
                if(d!=i-1)cout<<types[d]<<" ";
                cout<<endl;
            }
            
            
        }
    }
    return 0;
}
