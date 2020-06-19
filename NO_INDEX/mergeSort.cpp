#include <iostream>
using namespace std;
#include "lib/utils.cpp"

void mezclar(double *array,int min,int mitad,int max){
    double *tmp;
    int i=min,j=mitad,x=0;
    tmp = new double[max-min];
    while(i<mitad && j<max){
        if(compare(array[i],array[j])==0){
            tmp[x]=array[i];
            i++;
            j++;
        }else if(compare(array[i],array[j])==-1){
            tmp[x]=array[i];
            i++;
        }else{
            tmp[x]=array[j];
            j++;
        }
        x++;
    }
    while(i<mitad){
        tmp[x]=array[i];
        i++;
        x++;
    }
    while(j<max){
        tmp[x]=array[j];
        j++;
        x++;
    }
    for(x=0; x<max-min; x++){
        array[x+min]=tmp[x];
    }
}

void mergeSort(double *array,int min,int max){
    int mitad=(max+min)/2;
    int length = max-min;
    if(min<max-1){
        mergeSort(array,min,mitad);
        mergeSort(array,mitad,max);
        mezclar(array,min,mitad,max);
    }
}

int main(){
    int size=10;
    int i;
    double items[size] = {9,7,5,6,1,2,0,8,3,4};

    printArray(items,size);
    mergeSort(items,0,size);
    printArray(items,size);
    
    

    return 0;
}