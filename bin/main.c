#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "boolean.h"
#include "cnf.h"
#include "mesinkar.h"
#include "mesinkata.h"

// Definisi prosedur fungsi
boolean IsFileExist(char * namaFile);
void ArrayCharCopy(char * st1, char * st2);

// Definisi Variabel Global
unsigned int line_num;
extern char CC;
extern Kata CKata;
extern boolean EndKata;
extern char Nama_File[100];

int main(int argc, char **argv)
{    
    if(argc > 1)
    {
        if(IsFileExist(argv[1]))
        {
            ArrayCharCopy(argv[1],Nama_File);
            line_num = 1;
            
            ReadFile();
        } else {
            printf("\nPERHATIAN: Tidak ditemukan nama file \"%s\"\n",argv[1]);
        }
    } else {
        printf("\nPERHATIAN: Nama file tidak terdefinisi.\n");
    }
    
    return 0;
}

void ArrayCharCopy(char * st1, char * st2)
{
    int i;
    for(i=0; st1[i] > ' '; i++)
    {
        st2[i] = st1[i];
    }
}

boolean IsFileExist(char * namaFile)
{
    struct stat st;
    FILE *fp;
    
    if(stat(namaFile,&st) != 0)
        return 0;
    else
        return 1;
}

