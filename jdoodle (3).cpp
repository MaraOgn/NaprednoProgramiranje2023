#include <stdio.h>     
#include <time.h>       // Vklucuvanje na bibliotekata za rabota so vreme za da presmeta kolku sekundi pominale od pocetokot na tekovnata godina odnosno od 1Januari do tekovnoto vreme `
int main ()
{
  time_t now;           // Promenliva za cuvanje na tekovnoto vreme vo format na time_t
  struct tm newyear;    // Struktura za cuvanje na detalite za pocetokot na godinata 
  double seconds;       // Promenliva za cuvanje na presmetanite sekundi 
  time(&now);           // ЗTekovnoto vreme se zacucuvuva vo promenlivata now 
  newyear = *localtime(&now);   // Tekovnoto vreme se pretvora vo lokalno i se zacuvuva vo newyear 

  // Setiranje na detalite za pocetokot na godinata vo newyear
  newyear.tm_hour = 0;
  newyear.tm_min = 0;
  newyear.tm_sec = 0;
  newyear.tm_mon = 0;   // Januari se postavuva kako nulti mesec
  newyear.tm_mday = 1;  // Se deklarira prviot den od mesecot

  // Se presmetuva kolku sekundi pominale od pocetokot na godinata do tekovnoto vreme 
  seconds = difftime(now, mktime(&newyear));

  // Se prikazuvaat presmetanite sekundi na standarden izlez 
  printf ("%.f sekundi od nova godina do sega\n", seconds);

  return 0;  
}
