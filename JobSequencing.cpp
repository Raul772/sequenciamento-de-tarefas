#include <iostream>

using namespace std;

// ------------------------ Verificação de SO para aplicação da função correta
#ifdef __unix__              
	#define clearT  "clear" 
#elif _WIN32 
	#define clearT  "" 
#endif
// --------------------------------------------------------------------------

// Declaração de variável global para a quantidade de tarefas a serem geradas
const int arraySize = 5;


// -------------------------- Definição de uma tarefa
struct job{
    int profit;
    int deadline;
    int jobId;
}; 

// -------------------------- Definição da array de tarefas
struct jobArray{
    job* array[arraySize];

    void preencherArray();
    void printArray();
    void sortArray();
    jobArray finalArray();
    int findMaxDeadline();
};

// -------------------------- Preenchimento da array de tarefas 1
void jobArray::preencherArray(){
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = new job;

        array[i]->jobId = i + 1;
        array[i]->deadline = rand() % 10 + 1;
        array[i]->profit = rand() % 10 + 1;

    }
}

// -------------------------- Imprime a array de tarefas 1
void jobArray::printArray(){

    system(clearT);
    cout << "\n\n";
    for (int i = 0; i < arraySize; i++)
    {
        cout << (i + 1) << "° Tarefa ID: " << array[i]->jobId;
        cout << "\t Profit: " << array[i]->profit;
        cout << "\t Prazo Máximo: " << array[i]->deadline << endl;
    }
    cout << "\n\n";
}

void jobArray::sortArray(){

    job* aux;

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
           if (array[i]->profit > array[j]->profit)
           {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
           }
        }
    }

	// for (int i = 0; i < arraySize; i++) //loop externo que percorre todo o vetor elemento a elemento
	// {
	// 	job* aux; //variavel auxiliar
	// 	for (int j = i; j > 0; j--) //loop interno que percorre todos os elementos anteriores ao elemento da interação do loop externo
	// 	{	
			
	// 		if (array[j]->profit < array[j - 1]->profit) { //compara o valor atual com cada valor anterior a ele e caso true substitui os valores
	// 			aux = array[j - 1];
	// 			array[j - 1] = array[j];
	// 			array[j] = aux;
	// 		}
	// 		else {
	// 			break; //no caso falso não é necessário continuar nesta estrutura de repetição
	// 		}
	// 	}
		
	// }
}

int jobArray::findMaxDeadline(){
    int maxDeadline = 0;
    for(int i =0; i < arraySize; i++){
        if(array[i]->deadline > maxDeadline){
            maxDeadline = array[i]->deadline;
        }
    }
    return maxDeadline;
}

jobArray jobArray::finalArray(){

    jobArray aux;
    int maxDeadLine = findMaxDeadline();

    job* auxJobArray[maxDeadLine];

    for (int i = 0; i < maxDeadLine; i++){
        auxJobArray[i] = NULL;
    }
    for (int i = 0; i < arraySize; i++)
    {
        if (auxJobArray[array[i]->profit] == NULL){
            auxJobArray[array[i]->profit] = array[i];
            array[i] = NULL;
        }
    }
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] != NULL)
        {
            for (int j = (array[i]->profit - 1); j > 0; j--)
            {
                if (auxJobArray[j] != NULL){
                    auxJobArray[array[i]->profit] = array[i];
                    break;
                }
            }
            
        }
        
    }
    
    for (int i = 0; i < arraySize; i++){
        for (int j = 0; j < maxDeadLine; j++)
        {
            if (auxJobArray[j] != NULL){
                aux.array[i] = auxJobArray[j];
            }
        }
    }

    return aux;
}

int main(){

    jobArray firstArray;
    firstArray.preencherArray();
    firstArray.printArray();
    firstArray.sortArray();
    firstArray.printArray();

    jobArray finalArray = firstArray;
    finalArray.finalArray().printArray();
    
}