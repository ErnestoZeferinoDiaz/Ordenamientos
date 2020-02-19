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
int * seleccion(int *array,int size){
    int *index,min;
    index=new int[size];
    for(int x=0; x<size; x++){
        index[x]=x;
    }
    for(int x=0; x<size-1; x++){
        min=x;
        for(int y=x+1; y<size; y++){
            if(comparator(array[index[min]],array[index[y]])==1){
                min=y;
            }
        }
        swap(&index[min],&index[x]);
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

    index=seleccion(array,15);
    
    cout<<"\n";
    for(int x=0; x<15; x++){    
        cout<<array[index[x]]<<"\t";
    }
    return 0;
}