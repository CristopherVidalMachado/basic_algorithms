void* createFile(char *path){
    fclose(fopen(path, "w"));
}

int randomNumbers(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void insertRandomNumbersInFile(char *textualFile, char *binaryFile, int totalElements){
   
    FILE* txtFile = fopen(textualFile, "w");

    FILE* binFile = fopen(binaryFile, "w");
   
    for ( register int i = 0; i < totalElements; i++)
    {
        int element = 0;

        element = randomNumbers(-SIZE_ELEMENTS, SIZE_ELEMENTS);

        fwrite(&element, sizeof(int), 1, binFile);
        
        fprintf(txtFile, "%d\n", element);

    }

    fclose(txtFile);
    
    fclose(binFile);
}
