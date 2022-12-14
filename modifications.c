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
    SetConsoleOutputCP(65001);                        //türkçe karakterler için
    char rastgelekelime[20];                          //dosyadan seçilen kelime
    char *prastgelekelime = rastgelekelime;
    kelimedondur(prastgelekelime);
    int uzunluk=strlen(rastgelekelime)-1;
    int hak=6;
    char girilenharf='0';                             //isteyeceğimiz harf
    int kontrol=0;                                    //kelimede girilen harf varsa 1 değerini alır
    int bulunanSayisi=0;
    char kelimedurum[uzunluk];                        //bulacağımız kelimenin son hali için yeni bir dizi
    memset(kelimedurum, '_', sizeof(kelimedurum));    //kelimedurum'un tüm karakterlerini alt-tirele
    int yenidenGir=0;                                 //harf daha önce girildiyse bu değişken 1 değerini alacak
    
    do{
        printf("%s",rastgelekelime);                  // kontrol için
        printf("Harf giriniz\n");
        do{
            yenidenGir=0;
            fflush(stdin);                            //buffer temizleme
            scanf("%c",&girilenharf);
            system("cls");
            getchar();
            for(int i=0; i<uzunluk; i++){             //harfin daha önce girilip girilmediğinin kontrolü
                if(kelimedurum[i]==girilenharf){
                yenidenGir=1;
                }
            }
            if(yenidenGir==1)
                printf("%c daha önce girildi.\nYeni bir harf giriniz:", girilenharf);
        }while(yenidenGir==1);

        for(int i=0; i<uzunluk ;i++){                //girilen harf kelimede var mı
            if(rastgelekelime[i]==girilenharf){
                kontrol++;
                kelimedurum[i]=girilenharf;
                bulunanSayisi++;
            }
        }
        if(kontrol==0){                              //yanlış harf girildiyse hak düşer
            hak--;
        }
        sekil(hak); 
        printf("Kelimenin son durumu:");
        puts(kelimedurum);
        printf("\n");                               //null karakterine kadar string'i yazdırır
        kontrol = 0;                                //dongu biterken kontrol degiskenini sıfırlamak önemli
    }while(hak!=0 && bulunanSayisi!=uzunluk);       //hak sıfırlanınca ya da tüm harfler bulununca döngüden çıkılır
    
    printf("Oyun bitti!\n");
    if(hak==0){
        printf("Kaybettiniz!\n");
        printf("Aranan kelime: %s", rastgelekelime);
    }
    else{
        printf("Kazandınız!");
    }
}