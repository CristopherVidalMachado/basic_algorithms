#ifndef FILE_H

#define FILE_H

/**
 * 
 * Cria um FILE em um determinado local.
 * 
 * @return *FILE
 */
void* createBinaryFile(char *path);
void* createReadbleFile();
/**
 * Cria valores randomicos dentro de um range definido por min e max.
 * 
 * @return int
 */
int randomNumbers(int min, int max);
/**
 * Coloca um total de números aleatórios em um arquivo aberto.
 * 
 */
void insertRandomNumbersInFile(char *textualFile, char *binaryFile, int totalNumbers);

/**
 * Fecha o arquivo aberto
 */
void closeFile(FILE *fp);
#endif