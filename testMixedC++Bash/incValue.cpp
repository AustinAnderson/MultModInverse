/**************************************************
* Filename:       incValue.cpp
* Author:         Austin Anderson
* Class:          CSI 3336
* Date Modified:  2016-03-17
*   -File Created
* Description:   
* 
***************************************************/


#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){

    if(argc!=2){
        return 1;
    }
    if(strlen(argv[1])!=1){
        return 1;
    }
    cerr<<"before "<<argv[1]<<" (inside program)"<<endl;
    argv[1][0]=argv[1][0]+1;
    cerr<<"after  "<<argv[1]<<" (inside program)"<<endl;

    cout<<300;
    
    return 0;
}
