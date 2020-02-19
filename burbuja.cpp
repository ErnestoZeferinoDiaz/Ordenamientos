#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int comparator(int x,int y){
    if(x==y){
        return 0;
    }else if(x<y){
        return -1;
    }else{
        return 1;
    }
}
int * burbuja(int *array,int size){
    int *index;

    index=new int[size];
    for(int x=0; x<size; x++){
        index[x]=x;
    }
    for(int x=1; x<size; x++){
        for(int y=0; y<size-1; y++){
            if(comparator(array[index[y]],array[index[y+1]])==1){
                swap(&index[y],&index[y+1]);
            }
        }
    }
    return index;
}

int main(){
    srand(time(NULL));
    int a=0,b=50;
    int array[15],*index;

    cout<<"\n";
    for(int x=0; x<15; x++){
        array[x]=a+rand()%(b-a+1);
        cout<<array[x]<<"\t";
    }

    index=burbuja(array,15);
    
    cout<<"\n";
    for(int x=0; x<15; x++){    
        cout<<array[index[x]]<<"\t";
    }
    return 0;
}