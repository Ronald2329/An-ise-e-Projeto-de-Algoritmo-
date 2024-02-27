#include <iostream>
#include <fstream>
#include <string>
#include <regex>


using namespace std; //retirando o std para usar os métodos estaticos diretamente sem o std::

typedef struct Information{
	string name;
	string type;	
}Information;

// Estrutura para contagem de entidades
struct CountResult {
    int functions;
    int loops_for;
    int loops_while;
    int loops_do_while;
    int ifs;
    int elses;
    int chars;
    int ints;
    int floats;
    int doubles;
    int chars_initialized;
    int ints_intialized;
    int floats_initialized;
    int doubles_initialized;
    int cases;
    int printf_calls;
    int scanf_calls;
    int return_statements;
    vector<Information> var;
};

// Função para contar as entidades no código
CountResult count_entities(ifstream &file) {
    CountResult result = {0};
    string line;

    // Expressões regulares para identificar entidades no código
    regex function_regex("\\b(void|int|float|double)\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*\\(");
    
    regex loop_for_regex("\\bfor\\s*\\(");
    regex loop_while_regex("\\bwhile\\s*\\(");
    regex loop_do_while_regex("\\bdo\\s*\\{");
    //Condicionais
    regex if_regex("\\bif\\s*\\(");
    regex else_regex("\\belse\\s*\\{");
    regex case_regex("\\bcase\\b");
    
    // Variáveis inicializadas
	regex char_initialized_regex("\\bchar\\s+([a-zA-Z_][a-zA-Z0-9_]*(\\s*,\\s*[a-zA-Z_][a-zA-Z0-9_]*)*\\s*=)");
	regex int_initialized_regex("\\bint\\s+([a-zA-Z_][a-zA-Z0-9_]*(\\s*,\\s*[a-zA-Z_][a-zA-Z0-9_]*)*\\s*=)");
	regex float_initialized_regex("\\bfloat\\s+([a-zA-Z_][a-zA-Z0-9_]*(\\s*,\\s*[a-zA-Z_][a-zA-Z0-9_]*)*\\s*=)");
	regex double_initialized_regex("\\bdouble\\s+([a-zA-Z_][a-zA-Z0-9_]*(\\s*,\\s*[a-zA-Z_][a-zA-Z0-9_]*)*\\s*=)");
	
	// Variáveis não inicializadas
	regex char_regex("\\bchar\\s+[a-zA-Z_][a-zA-Z0-9_]*(\\s*\\[\\d+\\])?\\s*;");
	regex int_regex("\\bint\\s+[a-zA-Z_][a-zA-Z0-9_]*(\\s*\\[\\d+\\])?\\s*;");
	regex float_regex("\\bfloat\\s+[a-zA-Z_][a-zA-Z0-9_]*(\\s*\\[\\d+\\])?\\s*;");
	regex double_regex("\\bdouble\\s+[a-zA-Z_][a-zA-Z0-9_]*(\\s*\\[\\d+\\])?\\s*;");

    //Funções de entrada e saída de dados
	regex printf_regex("\\bprintf\\s*\\(");
    regex scanf_regex("\\bscanf\\s*\\(");

    while (getline(file, line)) {
        // Contagem de funções
        if (regex_search(line, function_regex)) {
            result.functions++;
        }

        // Contagem de loops
        if (regex_search(line, loop_for_regex)) {
            result.loops_for++;
        } else if (regex_search(line, loop_while_regex)) {
            result.loops_while++;
        } else if (regex_search(line, loop_do_while_regex)) {
            result.loops_do_while++;
        }

        // Contagem de outras estruturas
        if (regex_search(line, if_regex)) {
            result.ifs++;
        }
        
        if (regex_search(line, else_regex)) {
            result.elses++;
        } 

        if (regex_search(line, case_regex)) {
            result.cases++;
        } 
        
        if (regex_search(line, printf_regex)) {
            result.printf_calls++;
        } 
        
        if (regex_search(line, scanf_regex)) {
            result.scanf_calls++;
        } 
        
         if (regex_search(line, char_regex)) {
            result.chars++;
        } 
            
        if(regex_search(line,int_regex)){
        	result.ints++;
        	
		}
		
		if(regex_search(line,float_regex)){
        	result.floats++;
		}
		
		if(regex_search(line,double_regex)){
        	result.doubles++;
		}
		
		//Variaveis declardas e já inicializadas
		if (regex_search(line, char_regex)) {
            result.chars_initialized++;
        }  
        
        if(regex_search(line,int_initialized_regex)){
        	result.ints_intialized++;
		}
		
		if(regex_search(line,float_initialized_regex)){
        	result.floats_initialized++;
		}
		
		if(regex_search(line,double_regex)){
        	result.doubles_initialized++;
		}
    }

    return result;
}

int main() {
    ifstream file("main.c");
    if (!file.is_open()) {
        cout << "Erro ao tentar abrir o arquivo!" << endl;
        exit(1);
    }
    
    CountResult result = count_entities(file);
    
	int allEnties = result.functions + result.cases + result.loops_for + result.loops_while + result.loops_do_while
				  + result.ifs + result.elses + result.chars + result.ints + result.floats + result.doubles
				  + result.chars_initialized + result.ints_intialized + result.floats_initialized + result.doubles_initialized
				  + result.cases + result.printf_calls + result.scanf_calls;

    cout << "Numero de funçoes: " << result.functions << endl;
    cout << "Numero de loops for: " << result.loops_for << endl;
    cout << "Numero de loops while: " << result.loops_while << endl;
    cout << "Numero de loops do-while: " << result.loops_do_while << endl;
    
    cout << "Numero de ifs: " << result.ifs << endl;
    cout << "Numero de elses: " << result.elses << endl;
    cout << "Numero de cases: " << result.cases << endl;

    cout << "Numero de declaracao de variaveis do tipo char nao inicilizadas: " << result.chars << endl;
    cout << "Numero de declaracao de variaveis do tipo int nao inicializadas: " << result.ints << endl;
    cout << "Numero de declaracao de variaveis do tipo float nao inicializadas: " << result.floats << endl;
    cout << "Numero de declaracao de variaveis do tipo double nao inicializadas: " << result.doubles << endl;
    
    cout << "Numero de declaracao de variaveis do tipo char inicilizadas: " << result.chars_initialized << endl;
    cout << "Numero de declaracao de variaveis do tipo int  inicializadas: " << result.ints_intialized << endl;
    cout << "Numero de declaracao de variaveis do tipo float inicializadas: " << result.floats_initialized << endl;
    cout << "Numero de declaracao de variaveis do tipo double inicializadas: " << result.doubles_initialized << endl;
    
    cout << "Numero de chamadas de printf(saida de dados): " << result.printf_calls << endl;
    cout << "Numero de chamadas de scanf(entrada de dados): " << result.scanf_calls << endl;
    
    cout << "Numero totais de passos:" <<allEnties << endl;

    file.close();
return 0;
}
