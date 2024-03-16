#include <stdio.h>
#include "big_number.h"

int main()
{
   char str_1[] = "999";
   char str_2[] = "1";

   BigNumber* bn_1 = CreateBN(str_1);
   if (bn_1 == NULL)
      printf("bn == NULL!\n");
   BigNumber* bn_2 = CreateBN(str_2);
   if (bn_2 == NULL)
      printf("bn == NULL!\n");
   
   BigNumber* sum = SumBN(bn_1, bn_2);
   
   /// 111
   /// 008

   PrintBN(sum);

   //DeleteBN();

   //PrintBN();

   return 0;
}
