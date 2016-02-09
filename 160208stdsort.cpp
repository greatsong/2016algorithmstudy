#include <stdio.h>
#include <stdlib.h>
#include <time.h> //ctime -> time.h로 수정
#include <algorithm> //xcode에서 실행할 경우 확장자를 cpp로 할 것

int n, S[1000000];
using namespace std;

//S배열의 내용 출력, 0~n-1까지
//정렬 전과 정렬 후에 2번 사용되기 때문에 재사용성을 높이기 위해 함수로 구현
void print_array(){
    for(int i=0;i<n;i++)
        printf("%3d\t",S[i]);
    printf("\n");
}

bool compare(int a, int b){
    //오름차순
    return a < b;
    /* 내림차순
     return a > b;
     */
}

int main(){
    srand(time(NULL));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        S[i]=rand();
    //print_array();
    int start = clock();
    //STandard Library 사용, 퀵정렬(nlgn)
    //std::sort(정렬할 자료 시작주소, 마지막주소, [비교함수 주소])
    //std::sort(S,S+n);
    sort(S,S+n,compare);
    printf("result=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    print_array();
    return 0;
}