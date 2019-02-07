#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
/*162802016 MINE YAMAN
  162802046 SELENNUR DILSIZ
  162802047 BEYZA NUR OZKARA*/
typedef struct{
char harf;
int adet;
}struct_harf;

int main()
{
    setlocale(LC_ALL, "Turkish");
    FILE *pDosya;
    pDosya = fopen("dosya.txt", "r+");
    if(pDosya == NULL)
    {
        printf("dosya.txt acilamadi..");
        exit(1);
    }

    struct_harf dizi[29];
    char alfabe[29] = {'A', 'B', 'C', 'Ç', 'D', 'E', 'F', 'G', 'Ð', 'H', 'I', 'Ý','J', 'K', 'L',
    'M', 'N', 'O', 'Ö', 'P', 'R', 'S', 'Þ','T', 'U', 'Ü', 'V', 'Y', 'Z'};

    int i, sayac=0,toplam=0;
    for(i=0; i<29; i++)
    {
        dizi[i].harf = alfabe[i];
        dizi[i].adet = 0;
    }
    char temp_harf;
 for(i=0; i<29; i++)
{
        while(!feof(pDosya))
        {
            temp_harf = fgetc(pDosya); //dosyadan karakter karakter okuma yapýyor.

            if (ferror(pDosya)) {
                printf("Kaynak dosyadan okuma hatasý!\n");
                exit(1);
            }
            if(temp_harf == 'i') //bu i ve ý hatalý oldugu icin bu if kontrollerini yaptým.
            {
                temp_harf = 'Ý';
            }
            else if(temp_harf == 'ý')
            {
                temp_harf = 'I';
            }
            else
                temp_harf = toupper(temp_harf); //okudugumu buyuk harf yaptým.
            if(temp_harf == dizi[i].harf)
                sayac++;
        }
        dizi[i].adet=sayac;
        toplam+=sayac;
        sayac = 0;
        rewind(pDosya); //imleci dosya basina aliyor. aksi halde tekrardan dosyanin basina gitmiyor.
}
   printf("\nToplam Harf Sayisi: %d\n",toplam);

     printf("\nHarflerin adetlerine gore Bubble Sort (Kabarcik Siralamasi) ile siralanmis hali; \n");

//SIRALAMA KODU BASLANGICI
 int  j,w,f=29;
 float temp, temp2;

for(w=0 ; w<f ; w++)
    {
        for(j=0 ; j<f-w-1 ; j++)
        {
        if(dizi[j].adet>dizi[j+1].adet)
            {
            temp=dizi[j].adet;
            dizi[j].adet=dizi[j+1].adet;
            dizi[j+1].adet=temp;

            temp2=dizi[j].harf;
            dizi[j].harf=dizi[j+1].harf;
            dizi[j+1].harf=temp2;
            }

        }
    }
    for(w=0 ; w<29 ; w++)
        {
        printf("\n%c= %d",dizi[w].harf,dizi[w].adet);
        }


    fclose(pDosya);
    return 0;
}
