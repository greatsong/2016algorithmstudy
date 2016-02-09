#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ctime -> time.h로 수정
#include <algorithm> //xcode에서 실행할 경우 확장자를 cpp로 할 것

int n, S[1000000];
using namespace std;

void swap(int a, int b){
    int t = S[a];
    S[a] = S[b];
    S[b] = t;
}

//s : start, e : end
void quick_sort(int s, int e){
    //start와 end가 뒤바뀌거나 같아지면 함수 종료
    if(s<e){
        //p : pivot, l : left, r : right
        int p = s, l = s+1, r = e;
        while(l<=r){
            while(l<=e && S[l]<=S[p])
                l++;
            while(r>=s+1 && S[r]>=S[p])
                r--;
            if(l<r)
                swap(l,r);
        }
        swap(p, r);
        quick_sort(s, r-1);
        quick_sort(r+1, e);
    }
}

void print_array(){
    for(int i=0;i<n;i++)
        printf("%3d\t",S[i]);
    printf("\n");
}

int main(){
    srand(time(NULL));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        S[i]=rand();
    //print_array();
    int start = clock();

    quick_sort(0, n-1);
    printf("result=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    print_array();
    return 0;
}