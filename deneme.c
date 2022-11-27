#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>

void main() {
   char deneme[100];
   strcpy(deneme,"sa");
   char *pdeneme = deneme;
   int sayi =5;
   int *psayi = &sayi;
   printf("%s\n",pdeneme);
   printf("%d",*psayi);
}