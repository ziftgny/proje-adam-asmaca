#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


void kelimedondur(char *pKelime){       //rastgele kelime seçme fonksiyonu
     srand(time(0)); 
    FILE *pF;
    pF = fopen("kelimeler.txt","r");  

    char txtdepo[20];          // satir başı 20 karakter
    int satir = 1;  
    int rastgelesayi = rand()%100+1;  //sececegimiz rastgele satırın belirlenmesi    
    while(fgets(txtdepo,20,pF)){   //fgets dökümanın sonuna ulaştığında null dönderir
        if(satir==rastgelesayi){
            strcpy(pKelime,txtdepo); //satir 1 den baslayacağı için rastgele satırla eşlenene kadar çevirip o satırdaki
                                    //kelimeyi kopyalar
        }
        satir++;
    }   
    fclose(pF);
}

void sekil(int hak){                     //kalan hak sayısına göre şekili yazdıracak fonksiyon
    printf("\n");
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
    char yenidenoyna='1';                             //oyundan çıkmak için 0 olmalı

do{ 
    system("cls");
    printf("\n--------------------------------");
    printf("\nAdam asmaca oyununa hoşgeldiniz!");
    printf("\n--------------------------------");
    
    char rastgelekelime[20];                          //rastgele kelime seçimi için
    kelimedondur(rastgelekelime);
    int uzunluk=strlen(rastgelekelime)-1;
    int hak=6;
    char girilenharf='0';                             
    int kontrol=0;                                    //kelimede girilen harf varsa = 1
    int bulunanSayisi=0;
    int yenidenGir=0;                                 //harf daha önce girildiyse = 1
    int sirano=0;                                     //girilen harfin kaçıncı olduğu
    int dogruGiris=0;                                 //giriş değerinin istenen bir değer ise = 1

    char kelimedurum[uzunluk+1];                      //bulacağımız kelimenin son hali için yeni bir dizi
    memset(kelimedurum, '_', sizeof(kelimedurum));    //kelimedurum'un tüm karakterlerini alt-tirele
    kelimedurum[uzunluk]='\0';
    char girilenharfler[20];
    memset(girilenharfler, '\0', sizeof(girilenharfler));

    do{                                                //oyun döngüsü
        printf("\n-----Harf giriniz-----\n");  
        do{                                            //input alma döngüsü
            yenidenGir=0;
            
            do{                                        //doğru input alınması için döngü
                dogruGiris=0;                   
                girilenharf=getch();
            
                if(girilenharf<=122 && girilenharf>=97){ //ascii 122 = 'z', 97 = 'a'
                    dogruGiris=1;
                }else{
                    system("cls");
                    printf("Hatalı giriş yaptınız!\nTekrar giriş yapınız.\n");
                }

            }while(dogruGiris==0);
            
            system("cls");                              //ekranı temizler
            
            for(int i=0; i<20; i++){                 //harfin daha önce girilip girilmediğinin kontrolü
                if(girilenharfler[i]==girilenharf){
                yenidenGir=1;
                }
            }
            
            if(yenidenGir==1){                      //girildiyse tekrar harf istenir
                printf("%c daha önce girildi.\nYeni bir harf giriniz:", girilenharf);
            }
            else{
            girilenharfler[sirano]=girilenharf;     //girilen harf diziye atanır
            sirano++;
            }

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
        sekil(hak);                                    //şekili yazdırır
        printf("Kelimenin son durumu: %s\n", kelimedurum); //bulunan ve bulunamayan harfleri kelime içinde gösterir
        
        kontrol = 0;

    }while(hak!=0 && bulunanSayisi!=uzunluk);       //hak sıfırlanınca ya da tüm harfler bulununca döngüden çıkılır
    
    printf("\n-----Oyun bitti!-----\n");
    if(hak==0){                                     //kaybetme durumu
        printf("     Kaybettiniz!     \n");
        printf("Aranan kelime: %s", rastgelekelime);
    }
    else{
        printf("     Kazandınız!     ");                      //kazanma durumu
    }

    printf("\n-----------------------------------------------------------------");
    printf("\nYeniden oynamak için herhangi bir tuşa, çıkmak için q'ya basınız.");
    printf("\n-----------------------------------------------------------------");

    yenidenoyna=getch();

}while(yenidenoyna!='q');
printf("\n-----------------------------");
printf("\nOynadığınız için teşekkürler!");
printf("\n-----------------------------");

}