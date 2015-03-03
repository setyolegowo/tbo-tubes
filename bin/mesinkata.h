/* NIM/Nama 	: 13511071 / Setyo Legowo 										  
   Nama file 	: mesinKata_v1.h
   Topik 		: Abstract Data Type Mesin Kata Akuisisi Versi 1
   Tanggal 		: 
   Deskripsi 	: 
*/
   
#ifndef MESINKATA_V1_H
#define MESINKATA_V1_H

/* ################################## HEADER #################################### */
#include "boolean.h"
#include "mesinkar.h"

/* ******************************** KONSTANTA *********************************** */
#define NMax 70

/* **************************** Definisi Tipe Kata ****************************** */
typedef struct {
	char TabKata[NMax + 1];
	unsigned int Length;
} Kata;
// { Tabkata adalah tempat menampung/container kata,
//   Length menyatakan panjangnya kata }

/* ********************** Primitif-Primitif Mesin Kata ************************** */
void Ignore_Blank(void);
// { Mengabaikan satu atau beberapa BLANK } 
// { I.S. : CC sembarang } 
// { F.S. : CC != BLANK atau CC = MARK } 
void STARTKATA(void);
// { I.S. : CC sembarang } 
// { F.S. : EndKata = true, dan CC = Mark; } 
// { atau EndKata = false, CKata adalah kata yang sudah diakuisisi, 
//   CC karakter pertama sesudah karakter terakhir kata } 
void ADVKATA(void);
// { I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir dari kata
//          yg sudah diakuisisi }
// { F.S. : Jika CC = MARK, maka EndKata = true atau EndKata = false, CKAta adalah
//          kata terakhir yang sudah diakuisisi;
//          CC karakter pertama sesudah karakter terakhir kata } 
void SalinKata(void);
// { Mengakuisisi kata, menyimpan dalam CKata } 
// { I.S. : CC adalah karakter pertama dari kata } 
// { F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi NMAX,
//          sisa "kata" dibuang; CC = BLANK atauCC = MARK; CC adalah karakter
//          sesudah karakter terakhir yang diakuisisi }

/* ******************************* Operasi Lain ********************************* */
boolean IsKataSama (Kata K1, Kata K2);
// { Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama
//   dan urutan karakter yang menyusun kata juga sama }

Kata KataMaker(char * string);

void CopyKata(Kata src, Kata * dst);

void CetakKata(Kata src);

#endif // MESINKATA_V1
