#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void kelimedondur(char *pKelime){
     srand(time(0)); 
    FILE *pF;
    pF = fopen("kelimeler.txt","r");  
    char txtdepo[100];          // satir başı 100 karakter
    int satir = 1;  
    int rastgelesayi = rand()%100+1;  //sececegimiz rastgele satırın belirlenmesi    
    while(fgets(txtdepo,100,pF)){   //fgets dökümanın sonuna ulaştığında null dönderir
        if(satir==rastgelesayi){
            strcpy(pKelime,txtdepo); //satir 1 den baslayacağı için rastgele satırla eşlenene kadar çevirip o satırdaki
                                    //kelimeyi kopyalar
        }
        
        satir++;
    }   
   
    fclose(pF); // it is always a good habit

}

void sekil(int *hak){
    for(int i =0;i<17;i++){
         printf("-");
    }
    printf("\n");
    for(int j =0;j<8;j++){
       
        printf("|");
        j==0?printf("               |"):1;
        printf("\n");
    }
   
}


void main() {
    SetConsoleOutputCP(65001);
    char rastgelekelime[100]; //max 100 karakter satir
    char *prastgelekelime = rastgelekelime;
    kelimedondur(prastgelekelime);
    int hak=6;
    int *phak=&hak;
    //do {
        sekil(phak);

    //}while(hak!=0)
}