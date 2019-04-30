#include <stdio.h>
#include <iostream>

using namespace std;

int input(int x[100][100]){
    int node;
    printf("masukan banyaknya node: ");
    scanf("%i",&node);
    for(int i=0; i<node; i++){
        printf("masukan adjacency dari node %i (Hentikan dengan memasukan 0): ", i+1);
        for(int j=0; j<node; j++){
            scanf("%i", &x[i][j]);
            if(x[i][j]<=0 || x[i][j]>node){
                break;
            }
        }
    }
    return node;
}

void output(int input[100][100],int node,int matrix[100][100]){
    for(int i=0; i<node; i++){
        for(int j=0; j<node; j++){
            bool ok=true;
            for(int k=0; k<node; k++){
                if(input[i][k]==(j+1)){
                    printf("%i ",1);
                    ok=false;
                    break;
                }
            }
            if(ok){
                printf("%i ",0);
            }
        }
        printf("\n");
    }
}

int main(){
    int matrix[100][100];
    int in[100][100];
    int node = input(in);
    printf("\n");
    output(in,node,matrix);
    return 0;
}