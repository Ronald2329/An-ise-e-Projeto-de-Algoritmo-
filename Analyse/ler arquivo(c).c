#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Estrutura para contagem de entidades
typedef struct {
    int functions;
    int loops_for;
    int loops_while;
    int loops_do_while;
    int ifs;
    int elses;
    int chars;
    int cases;
    int printf_calls;
    int scanf_calls;
    int return_statements;
} CountResult;

// Função para verificar se uma linha contém uma palavra-chave específica
int contains_keyword(const char *line, const char *keyword) {
    char *pos = strstr(line, keyword);
    if (pos != NULL) {
        // Verifica se a palavra-chave está no início da linha ou é precedida por um espaço
        if (pos == line || *(pos - 1) == ' ') {
            return 1;
        }
    }
    return 0;
}

// Função para contar as entidades no código
CountResult count_entities(FILE *file) {
    CountResult result = {0};
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Contagem de funções
        if (contains_keyword(line, "void ") || contains_keyword(line, "int ") || contains_keyword(line, "float ") || contains_keyword(line, "double ")) {
            result.functions++;
        }

        // Contagem de loops
        if (contains_keyword(line, "for ")) {
            result.loops_for++;
        } else if (contains_keyword(line, "while ")) {
            result.loops_while++;
        } else if (contains_keyword(line, "do ")) {
            result.loops_do_while++;
        }

        // Contagem de outras estruturas
        if (contains_keyword(line, "if ")) {
            result.ifs++;
        } else if (contains_keyword(line, "else ")) {
            result.elses++;
        } else if (contains_keyword(line, "char ")) {
            result.chars++;
        } else if (contains_keyword(line, "case ")) {
            result.cases++;
        } else if (contains_keyword(line, "printf(")) {
            result.printf_calls++;
        } else if (contains_keyword(line, "scanf(")) {
            result.scanf_calls++;
        } else if (contains_keyword(line, "return ")) {
            result.return_statements++;
        }
    }

    return result;
}

int main() {
	
    FILE *file = fopen("main.c", "r");
    if (file == NULL) {
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }

    CountResult result = count_entities(file);
    int allEnties = result.functions + result.loops_for + result.loops_while + result.loops_do_while
    			  + result.ifs + result.elses + result.chars + result.cases + result.printf_calls
    			  + result.scanf_calls + result.return_statements;

    printf("Numero de funcoes: %d\n", result.functions);
    printf("Numero de loops for: %d\n", result.loops_for);
    printf("Numero de loops while: %d\n", result.loops_while);
    printf("Numero de loops do-while: %d\n", result.loops_do_while);
    printf("Numero de ifs: %d\n", result.ifs);
    printf("Numero de elses: %d\n", result.elses);
    printf("Numero de variaveis char: %d\n", result.chars);
    printf("Numero de cases: %d\n", result.cases);
    printf("Numero de chamadas de printf(saida de dados): %d\n", result.printf_calls);
    printf("Numero de chamadas de scanf(entrada de dados): %d\n", result.scanf_calls);
    printf("Numero de declaracoes de retorno: %d\n", result.return_statements);
	printf("Numero total de passos: %d",allEnties);
	
    fclose(file);

    return 0;
}
