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
    char txtdepo[100];          // satir başı 100 karakter   Nİ TE Fİ SE
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

void sekil(int hak){
    switch (hak)
    {
    case 6:printf("____\n|\n|\n|\n|\n");break;
    case 5:printf("____\n|  O\n|\n|\n|\n");break;
    case 4:printf("____\n|  O\n|  | \n|\n|\n");break;
    case 3:printf("____\n|  O\n| /| \n|\n|\n");break;
    case 2:printf("____\n|  O\n| /|\\\n|\n|\n");break;
    case 1:printf("____\n|  O\n| /|\\\n| /  \n|\n");break;
    case 0:printf("____\n|  O\n| /|\\\n| / \\\n|\n");break;
    }

   
}


void main() {
    SetConsoleOutputCP(65001);
    char rastgelekelime[100]; //max 100 karakter satir
    char *prastgelekelime = rastgelekelime;
    kelimedondur(prastgelekelime);
    int hak=6;
    char girilenharf;  //basically isteyeceğimiz harf
    int kontrol=0;   //string dizisinde istediğimiz harften varsa bunu arttıracagız ve bu deger 0 olmazsa demek ki
                    //dizide istediğimiz karakterden var bu sekilde hakkımız azalmaz tam tersi ise azaltmamız gerekir
    do {
        printf("%s",rastgelekelime); // kontrol için
        printf("harf giriniz\n");
        scanf("%c",&girilenharf);
       for(int i =0;i<strlen(rastgelekelime);i++){
        
            if(rastgelekelime[i]==girilenharf){ //karsılastırma
                kontrol++;
            }
       }
        if(kontrol==0){ //stringdeki hicbir karakter uyusmuyorsa hakkı bir azalt
            hak--;
        }
        sekil(hak);
        kontrol = 0; //dongu biterken kontrol degiskenini sıfırlamak önemli

    }while(hak!=0);
}