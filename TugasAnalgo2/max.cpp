#include <iostream>
#include <conio.h>

using namespace std;

struct masukan{
    int in;
    masukan* next;
};

masukan* input(){
    int x;
    masukan* in=NULL;
    masukan* test=NULL;
    cout<<"masukan banyaknya data: ";cin>>x;
    for (int i=0; i<x; i++){
        if(in==NULL){
            in = new masukan;
            cout<<"masukan angka: ";cin>>in->in;
            in->next=NULL;
            test=in;
            continue;
        }
        else if(test->next==NULL){
            test->next=new masukan;
            cout<<"masukan angka: ";cin>>test->next->in;
            test->next->next=NULL;
        }
        test=test->next;
    }
    return in;
}

int makss(masukan* in){
    masukan* test=in;
    int maks=test->in;
    test=test->next;
    while(test!=NULL){
        if(test->in>maks){
            maks=test->in;
        }
        test=test->next;
    }
    return maks;
}

int main(){
    cout<<"nama: Benhard David Hamonangan Tampubolon\n";
    cout<<"NPM: 140810170042\n\n";
    masukan* in;
    int maks;
    in=input();
    maks=makss(in);
    cout<<"nilai maksimum: "<<maks<<endl;
    getch();
    return 0;
}