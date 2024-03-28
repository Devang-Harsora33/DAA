#include<stdio.h>
#include<stdio.h>
int max, min;
int a[100];
void maxmin(int low, int high)
{
 int max1, min1, mid;
 if(low==high)
 {
  max = min = a[low];
 }
 else
 {
  if(low == high-1)
  {
   if(a[low] <a[high])
   {
    min = a[low];
    max = a[high];
   }
   else
   {
    min = a[high];
    max = a[low];
   }
  }
  else
  {
   mid = (low+high)/2;
   maxmin(low, mid);
   max1 = max; min1 = min;
   maxmin(mid+1, high);
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 }
}
int main ()
{
 int i, num=100;
 for (i=1;i<=num;i++)
  a[i] = rand()%100;

 max = a[0];
 min = a[0];
 maxmin(1, num);
 printf ("Minimum element in an array : %d\n", min);
 printf ("Maximum element in an array : %d\n", max);
 return 0;
}