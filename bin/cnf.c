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
    int line = 0;
    
    STARTKATA();
    //system("pause");
    i = 0;
    while(!EndKata) {
        //CetakKata(CKata);
        CopyKata(CKata,&listTerminal[i]);
        //CetakKata(listTerminal[i]);
        TerminalLine[i] = line_num;
        ADVKATA();
        //printf("\n");
        //system("pause");
        i++;
        N += 1;
    }
    CLOSE();

    /*
    *
    *@author : Fawwaz Muhammad
    *
    */

    // Read terminals
    /*
    * Format file TERMINAL
    * harus dimulai dengan sebuah angka yang menyatakan jumlah TERMINAL yang ada dalam file tersebut
    * lalu setiap variabel harus berupa angka integer
    * bentuk konversi dari penulisan umum ke format file ini adalah sbb:
    * format penulisan umum :  
    *   A->a B->c
    * format penulisan file
    *   A : a 
    *   B : c 
    * sehingga contoh lengkapnya isi filenya adalah sbb
    * CONTOH:
    *   2
    *   A : a
    *   B : c 
    * artinya file diatas hanya memiliki 2 jenis terminal, yaitu A->a dan B->c
    *
    **/
    FILE *terminalfile;
    int jumlahterminal;
    terminalfile= fopen("terminal.txt","r");
    fscanf(terminalfile,"%d\n", &jumlahterminal); 

    int Terminal[jumlahterminal];
    // char *Terminal[jumlahterminal];
    char arti[jumlahterminal][15];
    
    
    int z;
    for(z=0; z<jumlahterminal; z++){
        fscanf(terminalfile, "%d : %s\n", &Terminal[z], &arti[z]);
        //printf("%d : %s\n", Terminal[z], &arti[z]);
        //system("pause");
    }
    fclose(terminalfile);

    //printf("%d : %s\n", Terminal[1], &arti[1]);
    FILE *nonterminalfile;
    
    /* Format file productions ( rule / grammar)
    * harus dimulai dengan sebuah angka yang menyatakan jumlah Rule yang ada dalam file tersebut
    * lalu setiap variabel harus berupa angka integer
    * bentuk konversi dari penulisan umum ke format file ini adalah sbb:
    * format penulisan umum :  
    *   A->BC | CC
    * format penulisan file
    *   A : B , C
    *   A : C , C
    * sehingga contoh lengkapnya isi filenya adalah sbb
    * CONTOH:
    *   2
    *   A : B , C
    *   A : C , C
    * artinya file diatas hanya memiliki 2 rule, yaitu A->BC dan A->CC
    *
    */
    nonterminalfile = fopen("nonterminal.txt", "r");
    int JumlahNonTerminal;
    fscanf(nonterminalfile,"%d\n", &JumlahNonTerminal);
    
    //Readrules
    int From[JumlahNonTerminal];
    int To1[JumlahNonTerminal];
    int To2[JumlahNonTerminal];

    for(z=0; z<JumlahNonTerminal; z++){
        fscanf(nonterminalfile, "%d : %d , %d\n", &From[z], &To1[z], &To2[z]);
        //printf("%d : %d , %d \n", From[z], To1[z], To2[z]);
    }
    

    fclose(nonterminalfile);












    
    //  CCC Y   Y K  K
    // C     Y Y  K K 
    // C      Y   KK  
    // C      Y   K K 
    //  CCC   Y   K  K
    /*
    *
    * get from wikipedia translated from pesudocode by Fawwaz
    *
    */
    
    // setting up
    Kata ArrayOfArti[jumlahterminal];
    for (i = 0; i < jumlahterminal; ++i)
    {
        Kata temp=KataMaker(arti[i]);
        CopyKata(temp,&ArrayOfArti[i]);
    }

    // configuration
    int Inputcounter=N;
    int NonTerminalcounter=JumlahNonTerminal;
    int Terminalcounter=jumlahterminal;
    int StartVariable=0;
    int p,q,r,s,t; // dummy vairable for looping
    boolean MatriksCYK[Inputcounter][Inputcounter][NonTerminalcounter];

    for (p = 0; p < Inputcounter; ++p)
    {
        for (q = 0; q < Inputcounter; ++q)
        {
            for (r = 0; r < NonTerminalcounter; ++r)
            {
                MatriksCYK[p][q][r]=false;
            }
            
        }
    }
    boolean wasSelected;
    for (p = 0; p < Inputcounter; ++p){
        wasSelected = false;
        for (q = 0; q < Terminalcounter; ++q){
            if (IsKataSama(listTerminal[p],ArrayOfArti[q]))
            {
                MatriksCYK[0][p][Terminal[q]]=true;
                // printf("koordinat di %d - %d - %d adalah ", 0,p,Terminal[q]);
                // CetakKata(listTerminal[p]);
                // printf(" dibandingkan dengan ");
                // CetakKata(ArrayOfArti[q]);
                // printf("\n");
                // system("pause");
                wasSelected = true;
            } else if((IsKataSama(KataMaker("IsAlphaNumeric"),ArrayOfArti[q])) && (!wasSelected)) {
                if(IsVariabel(p)) {
                    MatriksCYK[0][p][33]=true;
                    // printf("koordinat di %d - %d - %d adalah ", 0,p,33);
                    // CetakKata(listTerminal[p]);
                    // printf(" (terbaca sebagai variabel) dibandingkan dengan ");
                    // CetakKata(ArrayOfArti[q]);
                    // printf("\n");
                    // system("pause");
                } else if(IsBilangan(p)) {
                    MatriksCYK[0][p][54]=true;
                    // printf("koordinat di %d - %d - %d adalah ", 0,p,54);
                    // CetakKata(listTerminal[p]);
                    // printf(" (terbaca sebagai bilangan) dibandingkan dengan ");
                    // CetakKata(ArrayOfArti[q]);
                    // printf("\n");
                    // system("pause");
                }
            }
        }
    }


    for (p = 2; p <= Inputcounter; p++) // i
    {
        // printf("Ketinggian sekarang %d\n", p);
        for (q = 1; q <= Inputcounter-p + 1; q++) // j
        {
            // printf("koordinat kanan ke %d\n", q);
            for (r = 1; r <= p - 1; r++) // 
            {
                // printf("A: (%d,%d) ? B: (%d,%d)\n", r - 1,q - 1,p-r-1,q+r - 1);
                for (s = 1; s <= NonTerminalcounter; s++) // RULE ke berapa
                {
                    if ((MatriksCYK[r-1][q-1][To1[s-1]]==true) && (MatriksCYK[p-r- 1][q+r - 1][To2[s - 1]]==true))
                    {
                        MatriksCYK[p-1][q-1][From[s-1]]=true;
                        // printf(" TRUE at (%d,%d) ",p-1,q-1);
                        // system("pause");
                        line = p - 1;
                    }
                }
            }
        }
    }
    if (MatriksCYK[Inputcounter-1][0][0]==true)
    {
        printf("MASUKAN VALID UNTUK DI COMPILE (LULUS UJI) \n");
    }else{
        printf("MASUKAN TIDAK LULUS COMPILE ADA KESALAHAN DI LINE : %d\n",TerminalLine[line] + 1);
    }
}

/* ---------------------------------------------------------------------------- */
/* --------------------------------- TERMINAL --------------------------------- */
/* ---------------------------------------------------------------------------- */

boolean IsBilangan(int no) {
    int i = 0;
    while(listTerminal[no].Length > i) {
        if(IsNumber(listTerminal[no].TabKata[i]))
            i++;
        else
            break;
    }
    return ((listTerminal[no].Length == i) && (i != 0));
}
boolean IsVariabel(int no) {
    if(listTerminal[no].Length == 0)
        return false;
    else {
        int i = 0;
        if(IsAlphaChar(listTerminal[no].TabKata[i])) {
            i++;
            while(listTerminal[no].Length > i) {
                if(IsAlphaNumeric(listTerminal[no].TabKata[i]))
                    i++;
                else
                    break;
            }
            return (listTerminal[no].Length == i);
        } else return false;
    }
}


//============ADDED BY FAWWAZ===================


