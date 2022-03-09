#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 300+1

struct impiegato{
  int matricola;
  char cognome_nome[40];
  int anno_assunzione;
  int media_operazioni;
  int eta;
}typedef struttura;

int conta(FILE*);
void sort(int, struttura*);
void print (struttura*, int, int);
void carica (FILE* , struttura*);


int main(void){
  FILE* fp;
  struttura* impiegato;
  int min_operazioni;
  fp = fopen("impiegati.txt", "r");
  int dim;

  if(fp == NULL){
    printf("errore nella lettura del file\n");
    return 1;
  }

  printf("inserire il numero minimo di operazioni:\n");
  scanf("%d", &min_operazioni);
  dim = conta(fp);
  impiegato = malloc(dim * sizeof(struttura));
  carica(fp, impiegato);
  fclose(fp);
  sort(dim, impiegato);
  print(impiegato, min_operazioni, dim);


  return 0;
}




int conta (FILE* fp) {

    char temp[BUFFERSIZE];
    int i = 0;

    while (!feof(fp)) {

        fgets (temp , BUFFERSIZE , fp);
        i++;
    }


    rewind (fp);
    return (i);
}


void swap (struttura* impiegato , int j) {

    struttura temp = impiegato[j];
    impiegato[j] = impiegato[j+1];
    impiegato[j+1] = temp;

}



void sort(int dim , struttura* impiegato) {

    int flag=1 , i=0;

    while (flag==1) {

        flag=0;
        for (int j = 0; j < dim; j++) {
            if (impiegato[j].eta > impiegato[j+1].eta) {
                swap (impiegato , j);
                flag = 1;

        }
        i++;
    }
  }
}

void print (struttura* impiegato , int min_operazioni, int dim) {

      for (int i = 0; i <= dim; i++) {
        if (min_operazioni >= impiegato[i].media_operazioni) {

            printf("%d %s %d %d %d\n\n" , impiegato[i].matricola, impiegato[i].cognome_nome, impiegato[i].anno_assunzione, impiegato[i].media_operazioni, impiegato[i].eta);
        }


      }


}

void carica (FILE* fp , struttura* impiegato) {

    int i = 0;
    while (!feof (fp)) {

        fscanf (fp , "%d %s %d %d %d" , &impiegato[i].matricola, impiegato[i].cognome_nome,
        &impiegato[i].anno_assunzione, &impiegato[i].media_operazioni, &impiegato[i].eta);
        i++;
    }
}
