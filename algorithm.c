void bubbleSort (int vetor[], int n) {
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

    FILE* bubbleArquivo = fopen("bubble/bubble.txt", "w");

    for ( register int counter = 0; counter < SIZE_ELEMENTS; counter++)
    {
        fprintf(bubbleArquivo, "%d\n", vetor[counter]);
    }
    fclose(bubbleArquivo);   
}