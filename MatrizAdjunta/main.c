#include <stdio.h>
#include <math.h>

int main () {
  int matriz[3][3] = {
    {1, 2, 3},
    {0, 3, 2},
    {0, 0, -2}
  }, matrizAdj[3][3], counter = 0, cache = 0;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {

      for(int l = 0; l < 3; l++) {
        for(int c = 0; c < 3; c++) {
          if(i != l && j != c) {
            switch(counter) {
              case 0:
                matrizAdj[j][i] = matriz[l][c]; //Dentro do case j e i estao invertidos para o resultado ser transposto.
                counter++;
                break;
              case 1:
                cache = matriz[l][c];
                counter++;
                break;
              case 2:
                cache *= matriz[l][c];
                counter++;
                break;
              case 3:
                matrizAdj[j][i] *= matriz[l][c];
                matrizAdj[j][i] -= cache;
                matrizAdj[j][i] = pow(-1, i + j) * matrizAdj[j][i];
                counter = 0;
                break;
            }
          }
        }
      }

    }
  }


  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrizAdj[i][j]);
    }
    printf("\n");
  }

  return 0;
}

