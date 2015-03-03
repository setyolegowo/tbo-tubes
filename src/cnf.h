#ifndef __MYCNF
#define __MYCNF

#define MaxTerminal 256

#include "mesinkata.h"

Kata Begin;
Kata End;
Kata Input;
Kata Output;
Kata If;
Kata Repeat;
Kata While;
Kata Plus;
Kata Minus;
Kata Star;
Kata Open;
Kata Close;
Kata Equal;
Kata LowerThan;
Kata GreaterThan;
Kata LowerOrEqualThan;
Kata GreaterOrEqualThan;
Kata NotEqual;
Kata Then;
Kata Else;
Kata Until;
Kata Do;
Kata listTerminal[MaxTerminal];

boolean S(int no);
boolean A(int no);
boolean B(int no);

boolean IsBilangan(int no);
boolean IsVariabel(int no);

#endif // __MYCNF