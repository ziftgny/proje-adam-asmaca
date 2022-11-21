#include <stdio.h>
#include <string.h>
#include<conio.h>
#include<stdlib.h>
int main()
{

    char deneme[][10] ={"selam","merhaba"};
        
       int dene;
         for(int i =0;i<sizeof(deneme)/sizeof(deneme[0]);i++){

                for(int j =0;deneme[i][j];j++){
                
                    printf("%c\n",deneme[i][j]);
                    deneme[i][j]=='h'?system("cls"):1;

        }
        
    }
    
}