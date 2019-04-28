#include <iostream>
#include <map>
using namespace std;
map<int,float> a;
map<int,float> b;
map<int,float> c;
int main() {
    int k = 0;
    cin>>k;
    int index = 0;//指数
    float coef = 0;//系数
    while(k--){
        cin>>index>>coef;
        a.insert(pair<int,float>(index,coef));
    }
    cin>>k;
    while(k--){
        cin>>index>>coef;
        b.insert(pair<int,float>(index,coef));
    }
    map<int,float>::iterator i,j;
    map<int,float>::iterator p;
    for(i=a.begin();i!=a.end();i++){
        for(j=b.begin();j!=b.end();j++){
            index = i->first+j->first;
            coef = (i->second)*(j->second);
            p=c.find(index);
            if(p==c.end()){
                c.insert(pair<int,float>(index,coef));
            }else{
                p->second = p->second + coef;
                
            }
        }
    }
    i=c.end();
    while(i!=c.begin()){
        i--;
        //printf(" %d %0.1f",i->first,i->second);
        if(i->second==0){
            c.erase(i);
        }
    }
    i=c.end();
    cout<<c.size();
    while(i!=c.begin()){
        i--;
        printf(" %d %0.1f",i->first,i->second);

    }
    return 0;
}
