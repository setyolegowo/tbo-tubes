/* File  : mesinkar1.c */ 
/* Body mesinkar1.h  */ 

#include <assert.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> 
#include "boolean.h" 
#include "mesinkar.h" 

/* definisi states  */ 
char CC;

/* definisi pita  */ 

char Nama_File[100];
extern unsigned int line_num;
static FILE * FILEBACA;
static FILE * FILETULIS;

void START(void)  {
 /*I.S. sembarang  */ 
/*F.S. CC adalah karakter pertama pita  */ 
/*      Jika CC==MARK, EOP menyala  (true)  */
/*      Jika CC  != MARK, EOP padam  (false)  */
	printf("\nMembaca file: %s\n\n",Nama_File);
	FILEBACA  = fopen(Nama_File,"r");
	CC = fgetc (FILEBACA);
    if(CC == '\n') line_num += 1;
}

void ADV(void)  {
/*I.S. CC  != MARK  */ 
/*F.S. CC adalah karakter berikutnya dari CC pada I.S.  */ 
/*Jika CC==MARK, EOP menyala  (true)  */ 
    CC = fgetc (FILEBACA);
    if(CC == '\n') line_num += 1;
}

void CLOSE(void)
{
	fclose(FILEBACA);
}

boolean EOP()  { 
/* true jika CC  == MARK  */ 
	return (CC == -1);
}

boolean IsSkippedChar(char _CC)
{
	return (((_CC <= ' ') && (_CC >= 0)) || (_CC >= 127));
    // return false;
}
boolean IsOperator(char _CC)
{
	if((_CC == '+') || (_CC == '-') || (_CC == '*'))
		return true;
	else
		return false;
}
boolean IsBukaTutupKurung(char _CC)
{
	if((_CC == '(') || (_CC == ')'))
		return true;
	else
		return false;
}
boolean IsBukaKurung(char _CC)
{
    if (_CC == '(') return true;
    else return false;
}
boolean IsTutupKurung(char _CC)
{
    if (_CC == ')') return true;
    else return false;
}
boolean IsBukaTutupKurungKurawal(char _CC)
{
	if((_CC == '{') || (_CC == '}'))
		return true;
	else
		return false;
}
boolean IsBukaKurungKurawal(char _CC) {
    if(_CC == '{')
		return true;
	else
		return false;
}
boolean IsTutupKurungKurawal(char _CC) {
    if(_CC == '}')
		return true;
	else
		return false;
}
boolean IsLogicAssignChar(char _CC)
{
	if((_CC == '=') || (_CC == '>') || (_CC == '<'))
		return true;
	else
		return false;
}
boolean IsAlphaNumeric(char _CC)
{
	if((IsAlphaChar(_CC) == true) || (IsNumber(_CC) == true))
		return true;
	else
		return false;
}
boolean IsNumber(char _CC)
{
	if((_CC >= '0') && (_CC <= '9'))
		return true;
	else
		return false;
}
boolean IsAlphaChar(char _CC)
{
	if((IsLowerCase(_CC) == true) || (IsUpperCase(_CC) == true))
		return true;
	else
		return false;
}
boolean IsLowerCase(char _CC)
{
	if((_CC >= 'a') && (_CC <= 'z'))
		return true;
	else
		return false;
}
boolean IsUpperCase(char _CC)
{
	if((_CC >= 'A') && (_CC <= 'Z'))
		return true;
	else
		return false;
}
char toLowerCase(char _CC)
{
    if(IsUpperCase(_CC) == true)
        return _CC + 32;
    else
        return _CC;
}