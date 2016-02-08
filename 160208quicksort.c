#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ctime -> time.h로 수정
#include <algorithm>
//이 부분은 어떻게 처리해야 하나?

int n, S[1000000];

//S배열의 내용 출력, 0~n-1까지
//정렬 전과 정렬 후에 2번 사용되기 때문에 재사용성을 높이기 위해 함수로 구현
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
    print_array();
    int start = clock();
    std::sort(S,S+n);
    printf("result=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    print_array();
    return 0;
}