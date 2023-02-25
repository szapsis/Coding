#include <stdio.h>
#include <string.h>

int main(void) {

  char str[100];


  printf("Please give me a string (only characters) ");

  scanf("%s",str);

  char allLetters[] = {"abcdefghijklmnopkqrstuvwxyzABCDEFGHIJKLMNOPKQRSTUVWXYZ"};

  int len1 = strlen(str), len2 = strlen(allLetters), i, g;

  int allok;
  for (i = 0; i < len1; i++) {
    allok = 0;
    for (g = 0; g < len2; g++) {
      //printf("\n allLetters %c", allLetters[g]);
      if (str[i] == allLetters[g]) {
        printf("Found %c\n", str[i]);
        allok = 1;
        break;
      }
    }
    if (allok == 0){
      printf("This character %c is not allowed", str[i]);
      break;
    }
  }

  return 0;
}
