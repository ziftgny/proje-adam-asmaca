#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void kelimedondur(char *pKelime){       //rastgele kelime seçme fonksiyonu
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
    fclose(pF);
}

void sekil(int hak){                     //kalan hak sayısına göre şekili yazdıracak fonksiyon
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
    char rastgelekelime[20];                          //rastgele kelime seçimi için
    kelimedondur(rastgelekelime);

    int uzunluk=strlen(rastgelekelime)-1;
    int hak=6;
    char girilenharf='0';                             
    int kontrol=0;                                    //kelimede girilen harf varsa 1 değerini alır
    int bulunanSayisi=0;
    int yenidenGir=0;                                 //harf daha önce girildiyse bu değişken 1 değerini alacak
    int sirano=0;                                     //girilen harfin kaçıncı olduğu

    char kelimedurum[uzunluk+1];                      //bulacağımız kelimenin son hali için yeni bir dizi
    memset(kelimedurum, '_', sizeof(kelimedurum));    //kelimedurum'un tüm karakterlerini alt-tirele
    kelimedurum[uzunluk]='\0';
    char girilenharfler[20];
    memset(girilenharfler, '\0', sizeof(girilenharfler));

    do{
        printf("Harf giriniz\n");
        do{
            yenidenGir=0;
            fflush(stdin);                            //buffer temizleme
            scanf("%c",&girilenharf);
            system("cls");
            for(int i=0; i<20; i++){                 //harfin daha önce girilip girilmediğinin kontrolü
                if(girilenharfler[i]==girilenharf){
                yenidenGir=1;
                }
            }
            if(yenidenGir==1){                      //girildiyse tekrar harf istenir
                printf("%c daha önce girildi.\nYeni bir harf giriniz:", girilenharf);
                sirano--;
            }
            else{
            girilenharfler[sirano]=girilenharf;     //girilen harf diziye atanır
            }  
            sirano++;
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
        printf("Daha once girilen harfler: ");
        for(int i=0; i<20; i++){                       //girilen harfleri görüntüler
            printf("%c ", girilenharfler[i]);
        }
        printf("\n");                    
        sekil(hak); 
        printf("Kelimenin son durumu:");            
        puts(kelimedurum);                          //bulunan ve bulunamayan harfleri kelime içinde gösterir
        kontrol = 0;                                
    }while(hak!=0 && bulunanSayisi!=uzunluk);       //hak sıfırlanınca ya da tüm harfler bulununca döngüden çıkılır
    
    printf("Oyun bitti!\n");
    if(hak==0){                                     //kaybetme durumu
        printf("Kaybettiniz!\n");
        printf("Aranan kelime: %s", rastgelekelime);
    }
    else{
        printf("Kazandınız!");                      //kazanma durumu
    }
}