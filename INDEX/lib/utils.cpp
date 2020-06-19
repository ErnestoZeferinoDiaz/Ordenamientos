// funcion de intercambio
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

// funcion comparador
int comparator(int x,int y){
    if(x==y){
        return 0;
    }else if(x<y){
        return -1;
    }else{
        return 1;
    }
}