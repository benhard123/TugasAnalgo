#include <iostream>
#include <chrono>

using namespace std;

//Link Github: https://github.com/benhard123/TugasAnalgo

void satu(int* in, int p, int q,int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for (int i=1; i<=n1; i++){
        L[i-1] = in[(p-1)+i-1];
        // cout<<"L"<<L[i-1]<<endl;
    }
    for (int j=1; j<=n2; j++){
        R[j-1] = in[(q-1)+j];
        // cout<<"R"<<R[j-1]<<endl;
    }
    int i=0;
    int j=0;
    L[n1]=2147483647;
    R[n2]=2147483647;
    for (int k=(p-1); k<r; k++){
        if(L[i]<=R[j]){
            in[k]=L[i];
            i = i+1;
        }
        else{
            in[k]=R[j];
            j = j+1;
        }
    }
}

void msort(int* in, int p, int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        msort(in, p, q);
        msort(in, q+1, r);
        // cout<<"P"<<p<<endl;
        // cout<<"Q"<<q<<endl;
        // cout<<"r"<<r<<endl;
        // for(int i=0; i<5; i++){
        //     cout<<in[i]<<" ";
        // }
        satu(in, p, q, r);
    }
}

void input(int* a, int& n){
    cout<<"masukan banyak data: ";cin>>n;
    for (int i=0; i<n; i++){
        cout<<"masukan angka: ";cin>>a[i];
    }
}

int main(){
    cout<<"nama: Benhard David Hamonangan Tampubolon\n";
    cout<<"NPM: 140810170042\n\n";
    int in[100];
    int n;
    input(in,n);
    auto start = chrono::steady_clock::now();
    msort(in,1,n);
    auto end = chrono::steady_clock::now();
    cout<<"Hasil: ";
    for(int i=0; i<n; i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    cout << "Elapsed time in nanoseconds : " 
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

    return 0;
}