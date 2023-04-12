#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int CalculaDeterminante (int **mat, int ordem) { 

  if(ordem > 1) {
    int result = 0;
    int ** matm = malloc(sizeof (int*) * (ordem - 1));
    int  * bufm = malloc(sizeof (int*) * pow(ordem - 1, 2));
    for(int i = 0; i < ordem - 1; i++){
      matm[i] = &bufm[(ordem - 1)*i];
    }

    int cm[2] = {0, 0};

    for(int e = 0; e < ordem; e++) {

      for(int i = 0; i < ordem; i++) {
        for(int j = 0; j < ordem; j++) {

          if(i != 0 && j != e) {
            matm[cm[0]][cm[1]] = mat[i][j];
            if(cm[1] > ordem - 3) {
              cm[0]++;
              cm[1] = 0;
            } else {
              cm[1]++;
            }
          }

        }
      }

      result += mat[0][e] * pow(-1, e + 2) * CalculaDeterminante(matm, ordem - 1);
      cm[0] = 0;
      cm[1] = 0;
    }

    return result;
  } else if (ordem == 1) {
    return **mat;
  } else {
    return -1;
  }

}

int main () {
  int matrizInput[5][5] = {
    {2, 3, 4, 2, 1},
    {3, 2, 5, 4, 2},
    {4, 5, 6, 3, 4},
    {4, 3, 5, 6, 8},
    {8, 8, 6, 5, 5}
  };
  int ordem = 5;


  int ** mat = malloc(sizeof (int*) * ordem);
  int  * buf = malloc(sizeof (int*) * pow(ordem, 2));
  for(int i = 0; i < ordem; i++){
      mat[i] = &buf[ordem*i];
  }

  for(int i = 0; i < ordem; i++){
    for(int j = 0; j < ordem; j++){
      mat[i][j] = matrizInput[i][j];
    }
  }

  printf("Result:%d\n", CalculaDeterminante(mat, ordem));
  free(mat);
  free(buf);

  return 0;
}
