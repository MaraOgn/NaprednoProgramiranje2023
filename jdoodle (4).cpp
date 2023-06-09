#include <stdio.h>    
#include <time.h>     // библиотека за мерење на времето потребно за извршување на програмата
#include <math.h>     // библиотека за математички операции

// Функција за пресметување на фреквенцијата на прости броеви помали од n
int frequency_of_primes (int n) {
  int i, j;
  int freq = n - 1;  // Почетна вредност на фреквенцијата е n-1, бидејќи едницата не е прост број
  for (i = 2; i <= n; ++i) {
    for (j = sqrt(i); j > 1; --j) {  // Проверување дали i е прост број
      if (i % j == 0) {  // Доколку i не е прост, намали ја фреквенцијата и прекини ја проверката
        --freq;
        break;
      }
    }
  }
  return freq;  // Врати го бројот на прости броеви
}

int main () {
  clock_t t;  // Декларација на clock_t променлива за чување на времето
  int f;      // Декларација на променлива за чување на резултатот
  t = clock();  // Започни со мерење на времето
  printf ("Calculating...\n");  
  f = frequency_of_primes (99999);  // Пресметај ја фреквенцијата на прости броеви
  printf ("The number of primes lower than 100,000 is: %d\n",f);  
  t = clock() - t;  // Заврши со мерење на времето и извлечи го временското трошење
  printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);  // Испис на времето
  return 0;  // Заврши со програмата
}
