/**************************************************
* Filename:       multiplicativeInverse.cpp
* Author:         Austin Anderson
* Class:          CSI 3336
* Date Modified:  2016-02-01
*   -File Created
* Description:    dynamic programming approach to extended euclidean algorithm
* 
***************************************************/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
#include "vectorio.h"

using namespace std;

enum ndxs{q,a,r,b,x,xt,y,yt};
int main(int argc, char** argv){



    if(argc!=3){
        cerr<<"usage: "<<argv[0]<<" <number> <mod set> "<<endl;
        exit(1);
    }
    vector<vector<int> > end;
    vector<int> current(8);
    vector<int> next(8);
    current[q]=0;
    current[a]=0;
    current[r]=atoi(argv[1]);
    int base=atoi(argv[2]);
    current[b]=base;
    current[x]=1;
    current[xt]=0;
    current[y]=0;
    current[yt]=1;
    cerr<<"\
    current[q]=0;\n\
    current[a]=0;\n\
    current[r]="<<atoi(argv[1])<<";//find inverse of\n\
    current[b]="<<base<<";//base\n\
    current[x]=1;\n\
    current[xt]=0;\n\
    current[y]=0;\n\
    current[yt]=1;\n\
    int count=0;\n\
    while(current[r]!=0&&count<base){\n\
        next[a]=current[b];\n\
        next[b]=current[r];\n\
        next[q]=int(next[a]/next[b]);\n\
        next[r]=next[a]%next[b];\n\
        next[x]=current[xt];\n\
        next[y]=current[yt];\n\
        next[xt]=current[x]-next[q]*current[xt];\n\
        next[yt]=current[y]-next[q]*current[yt];\n\
        end.push_back(current);\n\
        current=next;\n\
    }\n\
    | q[i]=floor(a[i]/b[i])| a[i]=b[i-1]| r[i]=a[i]%b[i]| b[i]=r[i-1]| x | xt | y[i]=yt[i-1] | y[i-1]-q[i]*yt[i-1]"<<endl;
    int count=0;
    while(current[r]!=0&&count<base){
        next[a]=current[b];//a
        next[b]=current[r];//b
        next[q]=int(next[a]/next[b]);//q
        next[r]=next[a]%next[b];//r
        next[x]=current[xt];//x
        next[y]=current[yt];//y
        next[xt]=current[x]-next[q]*current[xt];//xt
        next[yt]=current[y]-next[q]*current[yt];//yt
        end.push_back(current);
        current=next;
    }
    end.push_back(current);
    cerr<<end<<endl;
    cerr<<endl;
    cerr<<"| q| a| r| b| x| xt| y| yt"<<endl;
    cerr<<"        ^  ^         ^inverse"<<endl;
    cerr<<"        |  |         "<<endl;
    cerr<<"        0  1  < has an inverse if matches"<<endl;

    if(current[y]<0){
        current[y]+=base;
    }
    cout<<current[y];
    return 0;
}
