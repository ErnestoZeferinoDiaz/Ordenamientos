#include <iostream>
using namespace std;
#include "lib/utils.cpp"

int main(){
    int size=10;
    double items[size] = {9,7,5,6,1,2,0,8,3,4};

    printArray(items,size);    
    for(int x=0; x<size-1; x++){
        for(int y=x+1; y<size; y++){
            if( compare(items[x],items[y]) == 1 ){
                swap(&items[x],&items[y]);
            }
        }
    }
    printArray(items,size);

    return 0;
}