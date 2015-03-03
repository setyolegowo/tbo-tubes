#include "mesinkata.h"
#include <stdio.h>
boolean EndKata;
Kata CKata;
void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC BLANK atau CC = MARK */
{ /* Kamus Lokal */
/* Algoritma */
// printf("%d ", CC==32);
while ((CC ==32) && (CC != MARK3)) {
ADV();
} /* CC != BLANK or CC = MARK */
}

void IgnoreNewline(){
	while(CC=='\n'){
		ADV();
	}
}

void STARTKATA()
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
{ /* Kamus Lokal */
/* Algoritma*/
START();
IgnoreBlank();
IgnoreNewline();
if (CC == MARK3) {
EndKata = true;
} else /* CC != MARK */ {
EndKata = false;
SalinKata();
}
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{ /* Kamus Lokal */
/* Algoritma*/
IgnoreBlank();
IgnoreNewline();
if (CC == MARK3) {
EndKata = true;
} else /* CC != MARK */ {
SalinKata();
}
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{ /* Kamus Lokal */
int i = 0; /* inisialisasi */
/* Algoritma*/
for (;;) {
CKata.TabKata[i] = CC;
ADV();
if ((CC == MARK3) || (CC == BLANK || CC=='\n')) {
break;
} else {
i++;
}
} /* CC = MARK or CC = BLANK */
CKata.Length = i+1;
}