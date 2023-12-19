#include "Run/Run.h";

int main() {
  char password[64];
  char encryptPassword[64];
  int resp;

  do {
    printf("Digite[0] para sair\n");
    printf("Digite[1] para cripografar senha\n");
    printf("Digite[2] para decripografar senha\n");
    scanf("%i", &resp);

    switch (resp) {
    case 1:
      printf("Informe a sua senha: \n");
      scanf("%s", password);

      if (countCharaters(password) == 1) {
        validateCreationPassword(password) == 0
            ? encryptingPassword(password)
            : printf("A senha digitada não é valida pois possui  %icaracteres"
                     "especiais!!\n",
                     validateCreationPassword(password));
      } else
        printf("Senha invalida pois possui mais de 64 caracteres!!\n");

      break;

    case 2:
      printf("Informe a sua senha  criptografada: \n");
      scanf("%s", encryptPassword);

      if (countCharaters(encryptPassword) == 1) {
        if (strcmp(verificateDecrypt(encryptPassword), "valida") == 0) {
          decryptingPassword(encryptPassword);
        } else {
          printf("\n%s", verificateDecrypt(encryptPassword));
        }
      } else {
        printf(
            "Senha encriptada invalida pois possui mais de 64 caracteres!!\n");
      }
      break;
    }

  } while (resp != 0);
}