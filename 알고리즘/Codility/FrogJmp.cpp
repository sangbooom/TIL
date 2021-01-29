#include <bits/stdc++.h>

int solution(int X, int Y, int D) {
   int quot = (Y-X)/D;
   if(quot*D == Y-X){
       return quot;
   } else {
       return quot+1;
   }
}
