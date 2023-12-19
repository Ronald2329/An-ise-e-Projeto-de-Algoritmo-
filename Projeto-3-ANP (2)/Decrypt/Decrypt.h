// Função para verificar se a senha já existe na lista
int isPasswordInList(char *password) {
  Node *current = head;
  while (current != NULL) {
    if (strcmp(current->password, password) == 0) {
      return 1; // A senha já está na lista
    }
    current = current->next;
  }
  return 0; // A senha não está na lista
}

// Função para adicionar uma senha à lista
void addPasswordToList(char *password) {
  if (!isPasswordInList(password)) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->password, password);
    newNode->next = head;
    head = newNode;
  }
}

// Função para imprimir todas as senhas na lista
void printPasswords() {
  Node *current = head;
  int count = 1;
  while (current != NULL) {
    printf("Senha[%i]: %s\n", count, current->password);
    current = current->next;
    count++;
  }
}

// Função para liberar a memória alocada pela lista
void freeList() {
  Node *current = head;
  Node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  head = NULL;
}

int countWords(char *password) {
  int count = 0;

  for (int i = 0; i < strlen(password); i++) {
    if (strchr(UpperCaseAlphabet, password[i]) != NULL ||
        strchr(LowerCaseAlphabet, password[i]) != NULL)
      count++;
  }

  return count;
}

// uppercase gerada pela decryptingPAssword , o index para indicar o inicio de
void generateCombinations(char *str, int index, char *result, int resultIndex,
                          int len) {
  if (index == len) {
    result[resultIndex] = '\0';
    if (isPasswordInList(result) == 0) {
      addPasswordToList(result);
    }
    return; // kkkkkkkkkkkkkk erro aqui
  }

  // Gera a combinação com o caractere atual em minúsculas
  result[resultIndex] = tolower(str[index]);
  generateCombinations(str, index + 1, result, resultIndex + 1, len);

  // Gera a combinação com o caractere atual em maiúsculas
  result[resultIndex] = toupper(str[index]);
  generateCombinations(str, index + 1, result, resultIndex + 1, len);
}

void decryptingPassword(char sh[64]) {
  char newPassword[64] = ""; // Inicializa newPassword

  for (int i = 0; i < strlen(sh); i++) {
    switch (sh[i]) {
    case '0':
      strcat(newPassword, "A");
      break;
    case '1':
      strcat(newPassword, "B");
      break;
    case '2':
      strcat(newPassword, "C");
      break;
    case '3':
      strcat(newPassword, "D");
      break;
    case '4':
      strcat(newPassword, "E");
      break;
    case '5':
      strcat(newPassword, "F");
      break;
    case '6':
      strcat(newPassword, "G");
      break;
    case '7':
      strcat(newPassword, "H");
      break;
    case '8':
      strcat(newPassword, "I");
      break;
    case '9':
      strcat(newPassword, "J");
      break;
    case '!':
      strcat(newPassword, "K");
      break;
    case '@':
      strcat(newPassword, "L");
      break;
    case '#':
      strcat(newPassword, "M");
      break;
    case '$':
      strcat(newPassword, "N");
      break;
    case '^':
      strcat(newPassword, "O");
      break;
    case '&':
      strcat(newPassword, "P");
      break;
    case '*':
      strcat(newPassword, "Q");
      break;
    case '(':
      strcat(newPassword, "R");
      break;
    case ')':
      strcat(newPassword, "S");
      break;
    case '_':
      strcat(newPassword, "T");
      break;
    case '+':
      strcat(newPassword, "U");
      break;
    case '?':
      strcat(newPassword, "V");
      break;
    case ':':
      strcat(newPassword, "W");
      break;
    case ';':
      strcat(newPassword, "X");
      break;
    case '|':
      strcat(newPassword, "Y");
      break;
    case '%':
      strcat(newPassword, "Z");
      break;
    case '-':
      strcat(newPassword, "0");
      break;
    case '<':
      strcat(newPassword, "1");
      break;
    case '>':
      strcat(newPassword, "2");
      break;
    case '~':
      strcat(newPassword, "3");
      break;
    case '[':
      strcat(newPassword, "4");
      break;
    case ']':
      strcat(newPassword, "5");
      break;
    case '{':
      strcat(newPassword, "6");
      break;
    case '}':
      strcat(newPassword, "7");
      break;
    case '.':
      strcat(newPassword, "8");
      break;
    case ',':
      strcat(newPassword, "9");
      break;
    }
  }

  if (countWords(newPassword) == 0)
    printf("A senha original é: %s\n", newPassword);
  else {

    char result[strlen(newPassword) + 1]; // vetor de char(string) vazia para
                                          // ser usado na geração de senha

    generateCombinations(newPassword, 0, result, 0, strlen(newPassword));
    printPasswords();
    freeList();
  }
}

int countCharaters(char *password) { return strlen(password) <= 64 ? 1 : 0; }

int verificateUpperCase(char password[64]) {
  for (int i = 0; i < strlen(password); i++) {
    if (strchr(UpperCaseAlphabet, password[i]) == NULL) {
      return 1;
    }
  }
  return 0;
}

int verificateLowerCase(char password[64]) {

  for (int i = 0; i < strlen(password); i++) {
    if (strchr(LowerCaseAlphabet, password[i]) == NULL) {
      return 1;
    }
  }
  return 0;
}

char *verificateDecrypt(char *password) {

  if (countCharaters(password) == 1) {

    if (verificateUpperCase(password) == 1) {
      return verificateLowerCase(password) == 1
                 ? "valida"
                 : "A senha criptografada eh invalida pois possui "
                   "caracter(es) "
                   "minusculo(s)";
    } else
      return "A senha criptografada eh invalida pois possui caracter(es) "
             "maisculo(s)";
  } else
    return "A senha  criptografada eh invalida pois excede o limite maximo "
           "da "
           "criptograda "
           "que eh 64 caracteres!";
}
