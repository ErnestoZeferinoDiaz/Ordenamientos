#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int comparator(int x,int y){
    if(x==y){
        return 0;
    }else if(x<y){
        return -1;
    }else{
        return 1;
    }
}

void mezclar(int *array,int *index,int min,int mitad,int max){
    int *tmp;
    int i=min,j=mitad,x=0;
    tmp = new int[max-min];
    while(i<mitad && j<max){
        if(comparator(array[index[i]],array[index[j]])==-1){
            tmp[x]=index[i];
            i++;
        }else{
            tmp[x]=index[j];
            j++;
        }
        x++;
    }
    while(i<mitad){
        tmp[x]=index[i];
        i++;
        x++;
    }
    while(j<max){
        tmp[x]=index[j];
        j++;
        x++;
    }
    for(x=0; x<max-min; x++){
        index[x+min]=tmp[x];
    }
    

}
void merge(int *array,int *index,int min,int max){
    int mitad=(max+min)/2;
    int length = max-min;
    if(min<max-1){
        merge(array,index,min,mitad);
        merge(array,index,mitad,max);
        mezclar(array,index,min,mitad,max);
    }
}
int *mergeSort(int *array,int size){
    int *index;
    index=new int[size];
    for(int x=0; x<size; x++){
        index[x]=x;
    }
    merge(array,index,0,size);
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

    index=mergeSort(array,15);
    
    cout<<"\n";
    for(int x=0; x<15; x++){    
        cout<<array[index[x]]<<"\t";
    }

    return 0;
}