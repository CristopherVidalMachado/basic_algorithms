#include <stdio.h>

#include <stdlib.h>

#include <ncurses.h>

#include "file.h"

#include "file.c"

#define SIZE_ELEMENTS 10000

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {


        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    FILE* bubbleArquivo = fopen("saida-bubble.txt", "w");
    for ( k = 0; k < SIZE_ELEMENTS; k++)
    {
        fprintf(bubbleArquivo, "%d\n", vetor[k]);
    }
    fclose(bubbleArquivo);
    getch();
    
}
void merge(int vetor[], int comeco, int meio, int fim) {

    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;

    int *vetAux;

    vetAux = (int*)malloc(tam * sizeof(int));


    while(com1 <= meio && com2 <= fim){

        if(vetor[com1] < vetor[com2]) {

            vetAux[comAux] = vetor[com1];

            com1++;

        } else {

            vetAux[comAux] = vetor[com2];

            com2++;

        }

        comAux++;

    }


    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade

        vetAux[comAux] = vetor[com1];

        comAux++;

        com1++;

    }


    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade

        vetAux[comAux] = vetor[com2];

        comAux++;

        com2++;

    }


    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original

        vetor[comAux] = vetAux[comAux-comeco];

    }

    

    free(vetAux);

}


void mergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim) {

        int meio = (fim+comeco)/2;


        mergeSort(vetor, comeco, meio);

        mergeSort(vetor, meio+1, fim);

        merge(vetor, comeco, meio, fim);

    }
    FILE* bubbleArquivo = fopen("saida-merge.txt", "w");
    int k;
    for ( k = 0; k < SIZE_ELEMENTS; k++)
    {
        fprintf(bubbleArquivo, "%d\n", vetor[k]);
    }
    fclose(bubbleArquivo);

}

int shellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    int k;
        FILE* bubbleArquivo = fopen("saida-shellsort.txt", "w");
    for ( k = 0; k < SIZE_ELEMENTS; k++)
    {
        fprintf(bubbleArquivo, "%d\n", arr[k]);
    }
    fclose(bubbleArquivo);
} 


 void quicksort_iterative(int array[], unsigned len) {
   unsigned left = 0, stack[SIZE_ELEMENTS], pos = 0, seed = rand();
   for ( ; ; ) {                                           /* outer loop */
      for (; left+1 < len; len++) {                /* sort left to len-1 */
         if (pos == SIZE_ELEMENTS) len = stack[pos = 0];  /* stack overflow, reset */
         int pivot = array[left+seed%(len-left)];  /* pick random pivot */
         seed = seed*69069+1;                /* next pseudorandom number */
         stack[pos++] = len;                    /* sort right part later */
         for (unsigned right = left-1; ; ) { /* inner loop: partitioning */
            while (array[++right] < pivot);  /* look for greater element */
            while (pivot < array[--len]);    /* look for smaller element */
            if (right >= len) break;           /* partition point found? */
            int temp = array[right];
            array[right] = array[len];                  /* the only swap */
            array[len] = temp;
         }                            /* partitioned, continue left part */
      }
      if (pos == 0) break;                               /* stack empty? */
      left = len;                             /* left to right is sorted */
      len = stack[--pos];                      /* get next range to sort */
   }

      int k;
        FILE* bubbleArquivo = fopen("saida-quick.txt", "w");
    for ( k = 0; k < SIZE_ELEMENTS; k++)
    {
        fprintf(bubbleArquivo, "%d\n", array[k]);
    }
    fclose(bubbleArquivo); 
}
 

int main()
{
    initscr();
    cbreak();
    clear();
    char option;
    do
    {

        printw("1: Gerar entrada.\n");
        printw("2: Bubblesort.\n");
        printw("3: MergeSort.\n");
        printw("4: ShellSort.\n");
        printw("5. RadixSort.\n");
        printw("6. QuickSort.\n");
        printw("7. Análise Assintótica.\n");
        printw("0: Sair.\n");
        refresh();
        option = getch();
 

        if (option == '1')
        {
            
            clear();            
            FILE *fp = createFile();
            insertRandomNumbersInFile(fp,-(SIZE_ELEMENTS), SIZE_ELEMENTS, SIZE_ELEMENTS);
            closeFile(fp);
            clear();
            printw("Arquivo criado com sucesso!");
            getch();
            clear(); 
        }
        else if (option == '2')
        {
            clear();   

            int *buffer = malloc(sizeof(int));
            FILE* arquivo = fopen("entrada.txt", "rb");
            fseek(arquivo, 0, SEEK_SET);
            register int k = 0; 
            int vetor[SIZE_ELEMENTS];
            for ( k = 0; k < SIZE_ELEMENTS; k++)
            {
                fread( buffer, sizeof(int), 1, arquivo);
                vetor[k] = *buffer;
                printw("%d\n", *buffer);
                 
            }

            bubble_sort(vetor, SIZE_ELEMENTS);


            clear(); 
        }
        else if (option == '3')
        {
          
            clear();   

            int *buffer = malloc(sizeof(int));
            FILE* arquivo = fopen("entrada.txt", "rb");
            fseek(arquivo, 0, SEEK_SET);
            register int k = 0; 
            int vetor[SIZE_ELEMENTS];
            for ( k = 0; k < SIZE_ELEMENTS; k++)
            {
                fread( buffer, sizeof(int), 1, arquivo);
                vetor[k] = *buffer;
                printw("%d\n", *buffer);
                 
            }
            int arr_size = sizeof(vetor[SIZE_ELEMENTS])/sizeof(vetor[0]);
            mergeSort(vetor, 0, SIZE_ELEMENTS - 1); 
    
            clear(); 
        }
        else if (option == '4')
        {
           
            clear();   
            int *buffer = malloc(sizeof(int));
            FILE* arquivo = fopen("entrada.txt", "rb");
            fseek(arquivo, 0, SEEK_SET);
            register int k = 0; 
            int vetor[SIZE_ELEMENTS];
            for ( k = 0; k < SIZE_ELEMENTS; k++)
            {
                fread( buffer, sizeof(int), 1, arquivo);
                vetor[k] = *buffer;
                printw("%d\n", *buffer);
                 
            }
            int arr_size = sizeof(vetor[SIZE_ELEMENTS])/sizeof(vetor[0]);
            shellSort(vetor,SIZE_ELEMENTS); 
    
            clear(); 

        }
        else if (option == '5')
        {
           
                       clear();   
            int *buffer = malloc(sizeof(int));
            FILE* arquivo = fopen("entrada.txt", "rb");
            fseek(arquivo, 0, SEEK_SET);
            register int k = 0; 
            int vetor[SIZE_ELEMENTS];
            for ( k = 0; k < SIZE_ELEMENTS; k++)
            {
                fread( buffer, sizeof(int), 1, arquivo);
                vetor[k] = *buffer;
                printw("%d\n", *buffer);
                 
            }
            
            int arr_size = sizeof(vetor[SIZE_ELEMENTS])/sizeof(vetor[0]);
            // radixsort(vetor,arr_size); 
    
            clear(); 


        }
        else if (option == '6')
        {
           
            clear();   
            int *buffer = malloc(sizeof(int));
            FILE* arquivo = fopen("entrada.txt", "rb");
            fseek(arquivo, 0, SEEK_SET);
            register int k = 0; 
            int vetor[SIZE_ELEMENTS];
            for ( k = 0; k < SIZE_ELEMENTS; k++)
            {
                fread( buffer, sizeof(int), 1, arquivo);
                vetor[k] = *buffer;
                printw("%d\n", *buffer);
                 
            }
            
          
            quicksort_iterative(vetor,SIZE_ELEMENTS); 
    
            clear(); 

        }
        else if (option == '7')
        {
           
            clear();

        }
        else if (option == '8')
        {
            
             clear();
        }
        else if (option == '9')
        {
           
             clear();
        }
        else if (option == '0')
        {
           
            clear();

        }

    } while (option != '0');
	endwin();
    remove("entrada.txt");
    return 0;

    // int i;
    
    // FILE *fp = createFile();
    // insertRandomNumbersInFile(fp,-(SIZE_ELEMENTS), SIZE_ELEMENTS, SIZE_ELEMENTS);
    // fclose(fp);
    
    
    // FILE* arquivo = fopen("entrada.txt", "rb");
    // if(arquivo == NULL) {
    //     fprintf(stderr, "Erro ao tentar abrir entrada.txt.\n");
    //     return 1;
    // }

    // /* Lê o tamanho total do arquivo */
    // // fseek(arquivo, 0, SEEK_SET );
    // // long tamanho = ftell(arquivo);
    // // rewind(arquivo);

    // /* Armazena a posição inicial */
    // int *buffer = malloc(sizeof(int));

    // /* Lê o fp inteiro em uma só chamada */
    // // int  elementos_lidos = fread(buffer, 1, sizeof(int), arquivo);
//    fseek(arquivo, 0, SEEK_SET);
//     register int k = 0; 

//    for ( k = 0; k < SIZE_ELEMENTS; k++)
//    {
//       fread( buffer, sizeof(int), 1, arquivo);
//       printf("O BUFFER : %d\n",*buffer);
//    }
   
    

    // if(elementos_lidos != tamanho) {
    //     fprintf(stderr, "Erro ao tentar ler o fp inteiro.\n");
    //     return 3;
    // }
    
    
    // /* Desaloca os recursos */
    // // free(buffer);
    // fclose(arquivo);



//   if(fwrite(floatValue, sizeof(float), 5, fp) != 5)
//     printf("File read error.");
//   fclose(fp);

//   /* read the values */
//   if((fp=fopen("test", "rb"))==NULL) {
//     printf("Cannot open file.\n");
//   }

//   if(fread(floatValue, sizeof(float), 5, fp) != 5) {
//     if(feof(fp))
//        printf("Premature end of file.");
//     else
//        printf("File read error.");
//   }
//   fclose(fp);

//   for(i=0; i<5; i++)
//     printf("%f ", floatValue[i]);

//   return 0;


}

