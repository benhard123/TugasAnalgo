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

int cari(masukan* in,int n){
    masukan* test=in;
    int i=1;
    while(test!=NULL){
        if(test->in==n){
            return i;
        }
        test=test->next;
        i++;
    }
    return 0;
}

int main(){
    cout<<"nama: Benhard David Hamonangan Tampubolon\n";
    cout<<"NPM: 140810170042\n\n";
    masukan* in;
    int cariin;
    int index;
    in=input();
    cout<<"Data yang mau dicari: ";cin>>cariin;
    index=cari(in,cariin);
    if(index>0){
        cout<<"Data ditemukan pada index: "<<index<<endl;
    }
    else{
        cout<<"Data tidak ditemukan \n";
    }
    getch();
    return 0;
}