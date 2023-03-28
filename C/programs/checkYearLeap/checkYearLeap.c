#include <stdio.h>


int yearLeap (int year) {
  if ((year % 4 == 0) && !(year % 100 == 0)) {
      return 1;
      }
      else if ((year % 4 == 0) && (year % 100) == 0) {
        if ((year % 4 == 0) && (year % 400) == 0) {
          return 1;
        }
        return 0;
    }
  return 0;
  }


int main(void) {
  printf("Hello user\nPlease give the year ");
  int year;
  scanf("%d", &year);

  int result = yearLeap(year);
  printf("%i ==> ", result);
  if (result) {
    printf("It is a leap year.");
    }
  else {
    printf("It is not a leap year");
    }

  return 0;
}
