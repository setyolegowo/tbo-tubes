#include "boolean.h"
#include "mesinkata.h"
#include "cnf.h"

extern unsigned int line_num;
extern boolean error_found;
extern Kata CKata;
extern Kata listTerminal[MaxTerminal];
extern boolean EndKata;
static int N = 0;
static int TerminalLine[MaxTerminal];

void ReadFile() {
    int i;
    
    STARTKATA();
    
    i = 0;
    while(!EndKata) {
        //CetakKata(CKata);
        CopyKata(CKata,&listTerminal[i]);
        //CetakKata(listTerminal[i]);
        TerminalLine[i] = line_num;
        ADVKATA();
        //printf("\n");
        i++;
        N += 1;
    }
    
    CLOSE();
}

boolean S(Kata _CKata)
{
	boolean _A = A(_CKata);
	boolean _B = B(_CKata);
	boolean _C = C(_CKata);
	boolean _Z = Z(_CKata);
	if((_A && _B) || (_A && _C) || (_A && _Z))
		return true;
	else
		return false;
}
boolean A(Kata _CKata)
{
	Kata KataT = KataMaker("begin");
	if(IsKataSama(_CKata,KataT) == true)
		return true;
	else
		return false;
}
boolean B(Kata _CKata)
{
	return true;
}
boolean C(Kata _CKata)
{
	// Kata KataT = KataMaker("end");
	// if(IsKataSama(_CKata,KataT) == true)
		// return true;
	// else
		// return false;
	return true;
}

/*
* Begin editan
* @author : Fawwwaz
*
*/
// mencoba menambahkan set sori kalau gak ngerti
boolean E(Kata _CKata){
	Kata KataT = KataMaker("input");
	if(IsKataSama(_CKata,KataT) == true)
		return true;
	else
		return false;	
}

boolean F(Kata _CKata){
	Kata KataT = KataMaker("output");
	if(IsKataSama(_CKata,KataT) == true)
		return true;
	else
		return false;		
}
boolean G(Kata _CKata){
	Kata KataT = KataMaker("if");
	if(IsKataSama(_CKata,KataT) == true)
		return true;
	else
		return false;		
}
boolean H(Kata _CKata){
	Kata KataT = KataMaker("repeat");
	if(IsKataSama(_CKata,KataT) == true)
		return true;
	else
		return false;		
}
boolean I(Kata _CKata){
	Kata KataT = KataMaker("whie");
	if(IsKataSama(_CKata,KataT) == true)
		return true;
	else
		return false;		
}

boolean O1(Kata _CKata){
	Kata KataT1 = KataMaker("+");
	Kata KataT2 = KataMaker("-");
	Kata KataT3 = KataMaker("=");
	return IsKataSama(_CKata,KataT1)||IsKataSama(_CKata,KataT2)||IsKataSama(_CKata,KataT3);
}
boolean O2(Kata _CKata){
	Kata KataT = KataMaker("{");
	return IsKataSama(_CKata,KataT);
}
boolean O3(Kata _CKata){
	Kata KataT = KataMaker("}");
	return IsKataSama(_CKata,KataT);
}
boolean O4(Kata _CKata){
	Kata KataT = KataMaker("(");
	return IsKataSama(_CKata,KataT);
}
boolean O5(Kata _CKata){
	Kata KataT = KataMaker("(");
	return IsKataSama(_CKata,KataT);
}
boolean O6(Kata _CKata){
	Kata KataT = KataMaker("=");
	return IsKataSama(_CKata,KataT);
}
boolean O7(Kata _CKata){
	Kata KataT1 = KataMaker("=");
	Kata KataT2 = KataMaker("<");
	Kata KataT3 = KataMaker(">");
	Kata KataT4 = KataMaker("<=");
	Kata KataT5 = KataMaker(">=");
	Kata KataT6 = KataMaker("<>");
	return IsKataSama(_CKata,KataT1)||IsKataSama(_CKata,KataT2)||IsKataSama(_CKata,KataT3)||IsKataSama(_CKata,KataT4)||IsKataSama(_CKata,KataT5)||IsKataSama(_CKata,KataT6);
}
boolean O8(Kata _CKata){
	Kata KataT = KataMaker("then");
	return IsKataSama(_CKata,KataT);
}
boolean O9(Kata _CKata){
	Kata KataT = KataMaker("else");
	return IsKataSama(_CKata,KataT);
}
boolean OA(Kata _CKata){
	Kata KataT = KataMaker("untill");
	return IsKataSama(_CKata,KataT);
}
boolean OB(Kata _CKata){
	Kata KataT = KataMaker("do");
	return IsKataSama(_CKata,KataT);
}


/*//*/


// End Editan */ Delete 2 garis miring di depan to deactivate my line

boolean Z(Kata _CKata)
{
	return true;
}