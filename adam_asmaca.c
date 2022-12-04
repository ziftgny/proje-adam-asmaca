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

void altTirele(char *dizi, int boyut){
	int i;
	
	for( i=0; i<boyut-1; i++ ){
		dizi[i] = '_';
	}
	
	// En sonuna terminator karakterini koy
	dizi[i] = '\0';
}

void main() {
    SetConsoleOutputCP(65001); //türkçe karakterler için
    char rastgelekelime[100]; //max 100 karakter satir
    char *prastgelekelime = rastgelekelime;
    kelimedondur(prastgelekelime);
    int uzunluk=strlen(rastgelekelime);
    int hak=6;
    int bulunansayisi=0;
    char girilenharf;  //isteyeceğimiz harf
    int kontrol=0;   //string dizisinde istediğimiz harften varsa bunu arttıracagız ve bu deger 0 olmazsa demek ki
                    //dizide istediğimiz karakterden var bu sekilde hakkımız azalmaz tam tersi ise azaltmamız gerekir 
    char *kelimedurum; //kelimenin son hali için yeni bir dizi
    kelimedurum = (char *)malloc(uzunluk + 1 * sizeof(char));// Bulunan harflerin saklanaacagi dizi icin bellek ayır
    altTirele(kelimedurum, uzunluk);// Bulunan harflerin saklanacagi diziyi alt-tirele

    do{
        printf("%s",rastgelekelime); // kontrol için
        printf("harf giriniz\n");
        scanf("%c",&girilenharf);
        for(int i=0; i<uzunluk ;i++){
            if(rastgelekelime[i]==girilenharf){ //karsılastırma
                kontrol++;
                kelimedurum[i]=girilenharf;
                bulunansayisi++;
            }
        }
        if(kontrol==0){
            hak--;
        }
        else{
            printf("Bildiniz!\n");
        }
        sekil(hak);
        kontrol = 0; //dongu biterken kontrol degiskenini sıfırlamak önemli
        printf("Kelimenin son durumu:");
        puts(kelimedurum);
        getchar(); //buffer'dan enter karakterini okur
        printf("\n");
    }while(hak!=0 && bulunansayisi!=uzunluk-1);
    
    printf("Oyun bitti!\n");
    if(hak==0){
        printf("Kaybettiniz!\n");
        printf("Aranana kelime: %s", rastgelekelime);
    }
    else{
        printf("Kazandınız!");
    }
    //Ayırdıgın bellek alanını serbest bırak
	free(kelimedurum);
}