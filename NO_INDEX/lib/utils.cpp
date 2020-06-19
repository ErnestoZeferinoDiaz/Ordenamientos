void printArray(double* array,int s){
    cout<<"\n\t";
    for(int x=0; x<s; x++){
        cout<<array[x];
        if(x<s-1){
            cout<<", ";
        }
    }
}

void swap(double* x,double* y){
    double tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int compare(double x,double y){
    if(x<y){
        return -1;
    }else if(x>y){
        return 1;
    }else{
        return 0;
    }
}