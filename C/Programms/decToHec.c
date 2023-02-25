#include <stdio.h>

void Dec_hex(int n)
{
    int x;
    if(n != 0)
    {
        x = n%16;
        Dec_hex(n /=16);
        printf("%c", x <10 ? x+'0' : x-10 + 'A');
    }
}

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("n_16 = ");
    Dec_hex(n);
    return 0;
}
