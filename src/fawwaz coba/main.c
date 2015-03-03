#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

typedef struct{
	char *From;
	// char From[3];
	char *Var1;
	// char Var1[3];
	char *Var2;
	// char Var2[3];
}Production;

typedef struct
{
	Production P[127];
	char jumlah;
}TabProduction;

TabProduction T;
// TabProduction *T2;

// void Contruct(TabProduction T,TabProduction *T2){
// 	int z=0;
// 	T2->jumlah=T.jumlah;
// 	while(T.P[z].From != '\0'){
// 		// CopyChar(T2->P[z].From,T.P[z].From);
// 		// CopyChar(T2->P[z].Var1,T.P[z].Var1);
// 		// CopyChar(T2->P[z].Var2,T.P[z].Var2);
// 		z++;
// 	}
// }

void CopyChar(char *t,char *s){
	int z=0;
	while((s[z]=t[z])!='\0') z++;
	char d;
	printf("%s\n", &s);
	scanf("%c",&d);
}

boolean StringCompare(char*t, char *s){
	int z=0;
	boolean ret=true;
	while((s[z]!='\0') && (t[z]!='\0')){ 
		if (s[z]!=t[z]){
			ret=false;
			break;
		}
		z++;
	}
	return ret;
}



int main(){
	FILE *fp;
	FILE *fp2;
	FILE *input;
	

	/*
	* Format file productions ( rule / grammar)
	* harus dimulai dengan sebuah angka yang menyatakan jumlah Rule yang ada dalam file tersebut
	* lalu setiap variabel harus berupa angka integer
	* bentuk konversi dari penulisan umum ke format file ini adalah sbb:
	* format penulisan umum :  
	*	A->BC | CC
	* format penulisan file
	* 	A : B , C
	*	A : C , C
	* sehingga contoh lengkapnya isi filenya adalah sbb
	* CONTOH:
	*	2
	* 	A : B , C
	*	A : C , C
	* artinya file diatas hanya memiliki 2 rule, yaitu A->BC dan A->CC
	*
	**/
	fp2 = fopen("testing3.txt", "r");
	int z,jumlahproduction;
	fscanf(fp2,"%d\n", &jumlahproduction);
	
	//Readrules
	char *From[jumlahproduction];
	char *To1[jumlahproduction];
	char *To2[jumlahproduction];

	for(z=1; z<jumlahproduction; z++){
		fscanf(fp2, "%s : %s , %s\n", &From[z], &To1[z], &To2[z]);
		printf("%s : %s , %s \n", &From[z], &To1[z], &To2[z]);
	}
	fclose(fp2);



	// Read terminals
	/*
	* Format file TERMINAL
	* harus dimulai dengan sebuah angka yang menyatakan jumlah TERMINAL yang ada dalam file tersebut
	* lalu setiap variabel harus berupa angka integer
	* bentuk konversi dari penulisan umum ke format file ini adalah sbb:
	* format penulisan umum :  
	*	A->a B->c
	* format penulisan file
	* 	A : a 
	*	B : c 
	* sehingga contoh lengkapnya isi filenya adalah sbb
	* CONTOH:
	*	2
	* 	A : a
	*	B : c 
	* artinya file diatas hanya memiliki 2 jenis terminal, yaitu A->a dan B->c
	*
	**/
	int jumlahterminal;
	fp= fopen("terminal3.txt","r");
	fscanf(fp,"%d\n", &jumlahterminal);	
	char *Terminal[jumlahterminal];
	char *arti[jumlahterminal];
	
	for(z=1; z<jumlahterminal; z++){
		fscanf(fp, "%s : %s\n", &Terminal[z], &arti[z]);
		printf("%s : %s\n", &Terminal[z], &arti[z]);
	}
	fclose(fp);
	



	// Read the input stream
	char *temp[100];
	char *total;
	char temporary2[1000000];
	char cc;
	char dummy;
	input = fopen("input.txt","r");
	// int pjgtotal,pjgcurrentkata,jumlahline,j;
	int pjgtotal=0;
	// do{
		int a=0;
		while(!feof(fp)){
			// cc= fgetc(fp);
			fscanf(fp,"%c",&cc);
			// printf("ini true or false %d\n", cc !='\n');
			// if(cc!='\n' ){
			// 	if(cc!='\t'){
			// 		temporary2[a] =cc;
			// 	}
			// }
			printf("%c ", cc);
			scanf("%c",&dummy);	
			if((cc!='\n' )&&(cc!='\t')){
				temporary2[a] =cc;
			}else{
				temporary2[a] =' ';
			}
			a++;
		}
		temporary2[a-1]='\0'; // dont know should i do this

		pjgtotal=a;
		int q=0;
		
		printf("%s", temporary2);
		
		// for (j = 0; j < 9; j++)
		// {
			// printf("%c", temp[i]);
			/* code */
		// }
		
		// while(temp[j]!='\0'){
		// 	pjgcurrentkata++;
		// }
		// pjgtotal=pjgtotal+pjgcurrentkata;
		// jumlahline++;
		// printf("%s\n", &temp);
		// printf("%d\n", pjgtotal);
	// }while(!feof(input));



	//asumsikan sudah di read filenya
	//Configure here

	// int JumlahKataTerminalDariFileInput=6; 
	// int ArrayTerminalInputFile;
	// /* counter jumlah kata yang ada di terminal aja, misal kalau diasumsikan setiap syntax harus ditulis dalam baris yang terpisah
	// * Contoh :
	// * 	begin
	// * 		input(x)
	// * 	end
	// * Contoh diatas berarti membuat variabel JumlahKataTerminalDariFileInput=6.
	// *
	// * BUKAN SEPERTI INI
	// * 	begin input(x) end
	// * Contoh SALAH diatas berarti membuat variabel JumlahKataTerminalDariFileInput=1.
	// * Dalam contoh diatas, array of input string akan menghasilkan array berupa:
	// * ArrayTerminalInputFile[0]=begin
	// * ArrayTerminalInputFile[1]=input
	// * ArrayTerminalInputFile[2]=(
	// * ArrayTerminalInputFile[3]=x
	// * ArrayTerminalInputFile[4]=)
	// * ArrayTerminalInputFile[5]=end
	// *
	// *
	// */

	// int JumlahGrammarNonTerminal=jumlahproduction;
	// int jumlahGrammarTerminal=jumlahterminal;

	// int i,l,m,n,o,p;
	// int a,b,c;
	// MatriksCYK[JumlahKataTerminalDariFileInput][JumlahKataTerminalDariFileInput][JumlahGrammarNonTerminal];

	// for (i ; i < JumlahKataTerminalDariFileInput; i++)
	// {
	// 	for (l = 0; l < jumlahterminal; l++)
	// 	{
	// 		if (&arti[l]==ArrayTerminalInputFile[i])
	// 		{
	// 			MatriksCYK[i][1][l]=true;
	// 		}
	// 	}
	// }

	// for (i = 2; i < JumlahKataTerminalDariFileInput; ++i)
	// {
	// 	for (l = 0; l < (JumlahKataTerminalDariFileInput-i+1); ++l)
	// 	{
	// 		for (m = 0; m < (i-1); ++m)
	// 		{
	// 			for (n = 0; n < JumlahGrammarNonTerminal; ++n)
	// 			{
	// 				// if ((MatriksCYK[l][i][&To1[n]]==true) && (MatriksCYK[l+m][j-m][&To2[n]]==true))
	// 				// {
	// 				// 	// MatriksCYK[l][j][&From[n]]=true;
	// 				// }
					
	// 			}
	// 		}
	// 	}
	// }
	return 0;
}	