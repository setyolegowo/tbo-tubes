#ifndef MESINKAR1_H
#define MESINKAR1_H
#include <stdio.h>
#include "boolean.h"
#ifndef MARK
	#define MARK EOF
#endif

void START(void);
/*I.S. sembarang  */
/*F.S. CC adalah karakter pertama pita  */
/*      Jika CC==MARK, EOP menyala  (true)  */
/*      Jika CC  != MARK, EOP padam  (false)  */

void ADV(void); 
/*I.S. CC  != MARK  */
/*F.S. CC adalah karakter berikutnya dari CC pada I.S.  */
/*      Jika CC==MARK, EOP menyala  (true)  */

boolean EOP();
/* true jika CC  == MARK  */

void CLOSE(void);

boolean IsTandaBaca(char Karakter);
// true jika karakter termasuk tanda baca, false jika karakter bukan termasuk tanda baca.

boolean IsSkippedChar(char _CC);

boolean IsOperator(char _CC);

boolean IsBukaTutupKurung(char _CC);

boolean IsBukaKurung(char _CC);

boolean IsTutupKurung(char _CC);

boolean IsBukaTutupKurungKurawal(char _CC);

boolean IsBukaKurungKurawal(char _CC);

boolean IsTutupKurungKurawal(char _CC);

boolean IsLogicAssignChar(char _CC);

boolean IsAlphaNumeric(char _CC);

boolean IsNumber(char _CC);

boolean IsAlphaChar(char _CC);

boolean IsLowerCase(char _CC);

boolean IsUpperCase(char _CC);

char toLowerCase(char _CC);

#endif
