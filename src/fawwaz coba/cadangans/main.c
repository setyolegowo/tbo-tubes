#include "mesinkar.h"
#include "mesinkata.h"

int main()
{
	int i;
	STARTKATA();
	while(!EndKata){
		// for (i = 0; i < CKata.Length; ++i)
		// {
		// 	printf("%c \n",CKata.TabKata[i]);
		// }
		printf("%d \n", CKata.Length);
		ADVKATA();
	}
	return 0;
}