#include <stdio.h>
#include <windows.h>

int s[10][3]; int pr;

void display(int al){
    if (al==1)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    else if (al==2)
        system("cls");
    for (int i=9; i>=0; --i) {
        for (int j=0; j<3; ++j) {
            int k;
            for (k=0; k<11-s[i][j]; ++k)
                printf(" ");
            for (k=0; k<s[i][j]; ++k)
                printf("*");
            printf("|");
            for (k=0; k<s[i][j]; ++k)
                printf("*");
            for (k=0; k<11-s[i][j]+3; ++k)
                printf(" ");
        }
        printf("\n");
    }
    printf("00000000000000000000000   00000000000000000000000   00000000000000000000000");
}

void moove (int x, int a, int b) {
    int i,j;
    for (i=0; i<10; ++i)
        if (s[i][a]==0)
            break;
    if (i>10)
        printf("error!"), exit(1);
    --i;
    if (i<0)
        printf("error!!"), exit(2);
    for (j=0;j<10;++j)
        if (s[j][b]==0)
            break;
    if (j>10)
        printf("error!!!"), exit(3);
    s[j][b]=s[i][a];
    s[i][a]=0;
    display(pr);
    printf("\n from %d to %d\n", a+1, b+1);
    Sleep(1000);
}

void transfer (int n, int a,int b) {
    if (n==1)
        moove(1,a,b);
    else {
        transfer(n-1,a,3-(a+b));
        moove(n,a,b);
        transfer(n-1,3-(a+b),b);
    }
}

int main() {
    int n, a=0, b=2, i;
    printf("How much coins?\nanswer - ");
    scanf("%d", &n);
    printf("Save history?\n 1 - yes\n 2 - no\nanswer - ");
    scanf("%d", &pr);
    memset(&s[0][0],0,sizeof(s));
    for (i=0; i<n; ++i)
        s[i][0]=n-i;
    system("cls");
    printf("Initial:\n\n");
    display(0);
    Sleep(1000);
    transfer(n,a,b);
    printf("\n      Well done.\n");
    return 0;
}
