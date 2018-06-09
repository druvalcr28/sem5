#include <stdio.h>

int chess[20][20] = {0};

int is_safe(int r,int c,int n){

    int i;
    for(i = 1;i < c;i++){
        if(chess[r][i] == 1){ 
            return 0;
        }
    }
    for(i = 1;i < r;i++){
        if(chess[i][c] == 1){ return 0;}
    }
    i = 1;
    while((r-i >= 1) && (c-i >= 1)){
        if(chess[r-i][c-i] == 1){ return 0;}
        i++;
    }
    i = 1;
    while((r-i >= 1) && (c+i <= n)){
        if(chess[r-i][c+i] == 1){ return 0;}
        i++;
    }
    return 1;
}
void place(int r,int pos,int *success,int n,int index[]){
    int i;
    if(pos <= n){
        for(i = pos;i <= n;i++){
            if(is_safe(r,i,n)){
                chess[r][i] = 1;
                *success = 1;
                index[r] = i;
                return;
            }
        }
    }
    return;
}
int main(){
    
    int r = 1,success,i,n,j;
    int index[20];

    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        index[i] = 1;
    }
    while(r < n+1){
        success = 0;
        place(r,index[r],&success,n,index);
        if(success == 1){
            printf("r=%d index[%d]=%d\n",r,r,index[r]);
        }
        if(success == 0){
            index[r-1] = index[r-1] + 1;
            index[r] = 1;
            chess[r-1][index[r-1]-1] = 0;
            printf("r=%d index[%d]=%d\n",r,r,index[r]);
            printf("r-1=%d index[%d]=%d\n",r-1,r-1,index[r-1]);
            r = r - 2;
        }
        r++;
    }
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            printf("%d  ",chess[i][j]);
        }
        printf("\n");
    }
    return 0;
}
