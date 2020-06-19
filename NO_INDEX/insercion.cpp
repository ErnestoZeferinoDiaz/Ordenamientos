#include <iostream>
using namespace std;
#include "lib/utils.cpp"

int main(){
    int size=10;
    int i,j;
    double items[size] = {9,7,5,6,1,2,0,8,3,4};
    double tmp;

    printArray(items,size);    
    for(i = 1; i < size; i++) {
		tmp = items[i];
		j = i;
		while(j > 0 && compare(tmp,items[j - 1])==-1) {
			items[j] = items[j - 1];
			j--;
		}
		items[j] = tmp;
	}
    printArray(items,size);

    return 0;
}