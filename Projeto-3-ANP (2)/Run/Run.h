// Blibiotecas utilizadas
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
const char *UpperCaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *LowerCaseAlphabet = "abcdefghijklmnopqrstuvwxyz";
const char *Algarisms = "0123456789";
const char *SpecialChacteres = "!@#$^&*()+?:;|%-<>~[]{}.,_´` ºª§=¹²³£¢¬";
const char *SpecialChacteresEncryptedPassword = "_´` ºª§=¹²³£¢¬¨";

const char A[] = "0", B[] = "1", C[] = "2", D[] = "3", E[] = "4", F[] = "5",
           G[] = "6", H[] = "7", I[] = "8", J[] = "9", K[] = "!", L[] = "@",
           M[] = "#", N[] = "$", O[] = "^", P[] = "&", Q[] = "*", R[] = "(",
           S[] = ")", T[] = "_", U[] = "+", V[] = "?", W[] = ":", X[] = ";",
           Y[] = "|", Z[] = "%";

const char algarism0[] = "-", algarism1[] = "<", algarism2[] = ">",
           algarism3[] = "~", algarism4[] = "[", algarism5[] = "]",
           algarism6[] = "{", algarism7[] = "}", algarism8[] = ".",
           algarism9[] = ",";

// Tipo de dado para guardar dinamicamente as senhas
typedef struct Node {
  char password[64];
  struct Node *next;
} Node;

Node *head = NULL; // inicialização da cabeça do tipo de dado Node

// Arquivos contendo funções para encriptar dscriptar e a validação de cada
// procedimento
#include "../Decrypt/Decrypt.h";
#include "../Encrypt/Encrypt.h";