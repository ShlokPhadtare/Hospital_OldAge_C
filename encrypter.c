#include <stdio.h>

int main(void)
{
    printf("\n\n");
char pw[100];

printf("Enter Passowrd: ");
scanf("%99s", pw);
printf("Encrypted Password: ");


for (int i = 0; pw[i] != '\0'; i++) 
{
    printf("%c", pw[i] + 10);
}
printf("\n\n");

}