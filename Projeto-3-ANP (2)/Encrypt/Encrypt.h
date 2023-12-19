
void encryptingPassword(char sh[64]) {
  char newPassowrd[64] = "";

  for (int i = 0; i < strlen(sh); i++) {
    if (strchr(UpperCaseAlphabet, toupper(sh[i])) == NULL) {
      switch (sh[i]) {
      case '0':
        strcat(newPassowrd, algarism0);
        break;
      case '1':
        strcat(newPassowrd, algarism1);
        break;
      case '2':
        strcat(newPassowrd, algarism2);
        break;
      case '3':
        strcat(newPassowrd, algarism3);
        break;
      case '4':
        strcat(newPassowrd, algarism4);
        break;
      case '5':
        strcat(newPassowrd, algarism5);
        break;
      case '6':
        strcat(newPassowrd, algarism6);
        break;
      case '7':
        strcat(newPassowrd, algarism7);
        break;
      case '8':
        strcat(newPassowrd, algarism8);
        break;
      case '9':
        strcat(newPassowrd, algarism9);
        break;
      }
    } else {
      switch (toupper(sh[i])) {
      case 'A':
        strcat(newPassowrd, A);
        break;
      case 'B':
        strcat(newPassowrd, B);
        break;
      case 'C':
        strcat(newPassowrd, C);
        break;
      case 'D':
        strcat(newPassowrd, D);
        break;
      case 'E':
        strcat(newPassowrd, E);
        break;
      case 'F':
        strcat(newPassowrd, F);
        break;
      case 'G':
        strcat(newPassowrd, G);
        break;
      case 'H':
        strcat(newPassowrd, H);
        break;
      case 'I':
        strcat(newPassowrd, I);
        break;
      case 'J':
        strcat(newPassowrd, J);
        break;
      case 'K':
        strcat(newPassowrd, K);
        break;
      case 'L':
        strcat(newPassowrd, L);
        break;
      case 'M':
        strcat(newPassowrd, M);
        break;
      case 'N':
        strcat(newPassowrd, N);
        break;
      case 'O':
        strcat(newPassowrd, O);
        break;
      case 'P':
        strcat(newPassowrd, P);
        break;
      case 'Q':
        strcat(newPassowrd, Q);
        break;
      case 'R':
        strcat(newPassowrd, R);
        break;
      case 'S':
        strcat(newPassowrd, S);
        break;
      case 'T':
        strcat(newPassowrd, T);
        break;
      case 'U':
        strcat(newPassowrd, U);
        break;
      case 'V':
        strcat(newPassowrd, V);
        break;
      case 'W':
        strcat(newPassowrd, W);
        break;
      case 'X':
        strcat(newPassowrd, X);
        break;
      case 'Y':
        strcat(newPassowrd, Y);
        break;
      case 'Z':
        strcat(newPassowrd, Z);
        break;
      }
    }
  }

  printf("A senha criptografada é %s\n", newPassowrd);
}

int validateCreationPassword(char senha[64]) {

  int countSpecialCharacteres = 0;

  for (int i = 0; i < strlen(senha); senha++) {
    if (strchr(SpecialChacteres, senha[i]) != NULL) {
      countSpecialCharacteres++;
    }
  }
  return countSpecialCharacteres;
}