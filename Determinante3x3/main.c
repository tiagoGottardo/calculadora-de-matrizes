#include <stdio.h>
#include <math.h>

int main () {
  int matriz[3][3] = {
    {1, 2, 3},
    {4, 3, 2},
    {4, 4, -2}
  }, det = 0, cache[4], k = 0;

  for(int e = 0; e < 3; e++) {

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(i != 0 && j != e) {
          cache[k] = matriz[i][j];
          k++;
        }
      }
    }

    det += matriz[0][e] * pow(-1, e + 2) * ((cache[0] * cache[3]) - (cache[1] * cache[2]));
    k = 0;
  }

  printf("\nResult:%d\n", det);

  return 0;
}

