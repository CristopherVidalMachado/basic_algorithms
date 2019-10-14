FILE* createFile(){
    FILE *fp = fp=fopen("entrada.txt", "w");
    return fp;
}

int randomNumbers(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void insertRandomNumbersInFile(FILE *fp, int min, int max, int totalNumbers){
    int element = 0;
    FILE* arquivo = fopen("saida.txt", "w");
    



    
    for ( size_t i = 0; i < totalNumbers; i++)
    {
        
        element = randomNumbers(min,max);
        fwrite( &element, sizeof(int), 1, fp );
        fprintf(arquivo, "%d\n", element);
    }
    fclose(arquivo);
}

void closeFile(FILE *fp){
    fclose(fp);
}