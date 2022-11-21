#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>//systm("cls") icin gerekli kütüphane
int main()
{

    char deneme[][10] ={"selam","merhaba"};
        
       int dene;
         for(int i =0;i<sizeof(deneme)/sizeof(deneme[0]);i++){//sizeofdeneme = 20 ,sizeofdeneme[0]=10

                for(int j =0;deneme[i][j];j++){ //deneme[i][j] nin degersel olarak karsılıgı oldugu surece devam et
                                                //deneme[0][5] in bir degeri olmadıgı için döngü burda kırılır
                
                    printf("%c\n",deneme[i][j]);// %s yerine %c kullanımına dikkat
                    deneme[i][j]=='h'?system("cls"):1;//system("cls") terminal ekranini temizler

        }
        
    }
    
}