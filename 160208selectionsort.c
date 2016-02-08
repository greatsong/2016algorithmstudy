#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ctime -> time.h로 수정

int n, S[1000000];

//S배열의 내용 출력, 0~n-1까지
//정렬 전과 정렬 후에 2번 사용되기 때문에 재사용성을 높이기 위해 함수로 구현
void print_array(){
    for(int i=0;i<n;i++)
        printf("%3d\t",S[i]);
    printf("\n");
}

//swap함수 구현, S가 전역 변수이기 때문에 call by value로도 가능
void swap(int a, int b){
    int t = S[a];
    S[a] = S[b];
    S[b] = t;
}

//선택정렬, 왼쪽부터 정렬하기 시작. 좌가 우보다 크면 스왑
//(n이 10일 경우) 0-1, 0-2, 0-3, ..., 8-9까지 비교
void selection_sort(void){
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n; j++)
            if(S[i]>S[j])
                swap(i,j);
    }
}

int main(){
    srand(time(NULL));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        S[i]=rand();
    print_array();
    int start = clock();
    selection_sort();
    printf("result=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    print_array();
    return 0;
}