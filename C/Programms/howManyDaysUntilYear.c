#include <stdio.h>
#include <stdlib.h>


 unsigned how_many_days ( unsigned year, unsigned month, unsigned day)
{
  const unsigned month12[12] = { 31,29,31,30,31,30,31,31,30,31,30,31};
  unsigned days = month12[month-1] - day;
  if ( year % 4 && month <= 2) days--;
  while ( month < 12 )
    days += month12[month++];
  return days;
}
 int main ( )
{
    unsigned year, month, day;
    printf ("Введите день, месяц, год : ");
    scanf ( "%d%d%d", &day, &month, &year);
    printf ( "Осталось до конца года полных дней : %d, осталось до конца года полных месяцев : %d \n", how_many_days( year, month, day), 12-month);
    system ( "pause");
 return 0;
}
