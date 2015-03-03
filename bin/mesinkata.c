/* NIM/Nama 	: 13511071 / Setyo Legowo 										  
   Nama file 	: mesinKata_v1.h
   Topik 		: Abstract Data Type Mesin Kata Akuisisi Versi 1
   Tanggal 		: 
   Deskripsi 	: */
   
/* ################################## HEADER #################################### */
#include <stdio.h>
#include "assert.h"
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"

/* ******************************** KONSTANTA *********************************** */
// #define MARK '.'
// #define BLANK ' '
// #define NMax 50

/* **************************** Definisi Tipe Kata ****************************** */
// typedef struct {
	// char TabKata[NMax + 1];
	// unsigned int Length;
// } Kata;
// { TabKata adalah tempat menampung/container kata,
//   Length menyatakan panjangnya kata }

/* ************************ Definisi State Mesin Kata *************************** */
extern char CC;
boolean EndKata;
Kata CKata;

/* ********************** Primitif-Primitif Mesin Kata ************************** */
void Ignore_Blank(void)
// { Mengabaikan satu atau beberapa BLANK } 
// { I.S. : CC sembarang } 
// { F.S. : CC != BLANK atau CC == MARK }
{
	while(IsSkippedChar(CC)) {
        //printf("Skipped char: %d\n",CC);
        ADV();
	}
}
void STARTKATA(void)
// { I.S. : CC sembarang } 
// { F.S. : EndKata = true, dan CC = Mark; } 
// { atau EndKata = false, CKata adalah kata yang sudah diakuisisi, 
//   CC karakter pertama sesudah karakter terakhir kata }
{
	START();
	Ignore_Blank();
	if(EOP() == true)
		EndKata = true;
	else {
		EndKata = false;
		SalinKata();
	}
}
void ADVKATA(void)
// { I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir dari kata
//          yg sudah diakuisisi }
// { F.S. : Jika CC = MARK, maka EndKata = true atau EndKata = false, CKAta adalah
//          kata terakhir yang sudah diakuisisi;
//          CC karakter pertama sesudah karakter terakhir kata }
{
	Ignore_Blank();
	if(EOP() == true)
		EndKata = true;
	else
		SalinKata();
}
void SalinKata(void)
// { Mengakuisisi kata, menyimpan dalam CKata } 
// { I.S. : CC adalah karakter pertama dari kata } 
// { F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi NMAX,
//          sisa "kata" dibuang; CC = BLANK atauCC = MARK; CC adalah karakter
//          sesudah karakter terakhir yang diakuisisi }
{
	// KAMUS
	int i;
	boolean IsExecuted;
	
	// ALGORITMA
	i = 1;
    // for(;;) {
        // CKata.TabKata[i - 1] = CC;
        // //printf("\nSaling Kata: %i",CC);
        // ADV();
        // if(IsSkippedChar(CC) || (i >= NMax))
            // break;
        // else
            // i++;
    // }
    //printf("\nSaling Kata: --------------------------\n");
	IsExecuted = false;
    
	if((IsBukaKurungKurawal(CC) == true) && (IsExecuted == false)) {
		for(;;)
		{
			ADV();
			if((IsTutupKurungKurawal(CC) == true) || (i >= NMax)) {
                //printf("\n'}' is found\n");
                ADV();
                Ignore_Blank();
				break;
            } else if(EOP() == true) {
                IsExecuted = true;
                i = 0;
                break;
			}
		}
	}
    if((IsOperator(CC) == true) && (IsExecuted == false)) {
		IsExecuted = true;
		for(;;)
		{
			CKata.TabKata[i - 1] = CC;
			ADV();
			if((IsOperator(CC) == false) || (i >= NMax))
				break;
			else
				i++;
		}
	}
	if((IsBukaTutupKurung(CC) == true) && (IsExecuted == false)) {
		IsExecuted = true;
		for(;;)
		{
			CKata.TabKata[i - 1] = CC;
			ADV();
			if((IsBukaTutupKurung(CC) == false) || (i >= NMax))
				break;
			else
				i++;
		}
	}
    if((IsBukaKurung(CC) == true) && (IsExecuted == false)) {
        IsExecuted = true;
        CKata.TabKata[0] = CC;
        ADV();
    }
    if((IsTutupKurung(CC) == true) && (IsExecuted == false)) {
        IsExecuted = true;
        CKata.TabKata[0] == CC;
        ADV();
    }
	if((IsLogicAssignChar(CC) == true) && (IsExecuted == false)) {
		IsExecuted = true;
		for(;;)
		{
			CKata.TabKata[i - 1] = CC;
			ADV();
			if((IsLogicAssignChar(CC) == false) || (i >= NMax))
				break;
			else
				i++;
		}
	}
	if((IsAlphaNumeric(CC) == true) && (IsExecuted == false)) {
		IsExecuted = true;
		for(;;)
		{
			CKata.TabKata[i - 1] = CC;
			ADV();
			if((IsAlphaNumeric(CC) == false) || (i >= NMax))
				break;
			else
				i++;
		}
	}
    // if(IsExecuted == false) {
        // IsExecuted = true;
		// for(;;)
		// {
			// CKata.TabKata[i - 1] = CC;
			// ADV();
			// if((IsSkippedChar(CC) == true) || (i >= NMax) || (EOF() == true))
				// break;
			// else
				// i++;
		// }
    // }
    assert(IsExecuted == true);
    
	CKata.TabKata[i] = '\0';
	CKata.Length = i;
}

/* ******************************* Operasi Lain ********************************* */
boolean IsKataSama (Kata K1, Kata K2)
// { Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama
//   dan urutan karakter yang menyusun kata juga sama }
{
	// KAMUS
	int i;
	
	// ALGORITMA
	if(K1.Length != K2.Length)
		return false;
	else {
		i = 1;
		while((i < K1.Length) && (toLowerCase(K1.TabKata[i-1]) == toLowerCase(K2.TabKata[i-1])))
		{
			i++;
		}
		if(K1.TabKata[i - 1] == K2.TabKata[i - 1])
			return true;
		else
			return false;
	}
}
Kata KataMaker(char * string)
{
	// KAMUS
	int i;
	Kata TKata;
	
	// ALGORITMA
	i = 1;
	for(;;)
	{
		if((string[i-1] < ' ') || (string[i-1] >= 127))
			break;
		else {
			TKata.TabKata[i-1] = string[i-1];
			i++;
		}
	}
	TKata.Length = i-1;
	return TKata;
}
void CopyKata(Kata src, Kata * dst) {
    int i;
    
    i = 1;
    while(src.TabKata[i - 1] != '\0') {
        (*dst).TabKata[i - 1] = src.TabKata[i - 1];
        i++;
    }
    (*dst).Length = src.Length;
}
void CetakKata(Kata src) {
    int i;
    
    for(i = 0; i < src.Length; i++) {
        printf("%c",src.TabKata[i]);
    }
}