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
struct job
{
    int profit;
    int deadline;
    int jobId;
}; 

// -------------------------- Definição da array de tarefas
struct jobArray
{
    job* array[arraySize];

    void preencherArray(int size);
    void printArray(int size);
    void sortArray(int size);
    jobArray maxProfitArray(int size);
    int findMaxDeadline(int size);
};

// -------------------------- Preenchimento da array de tarefas 1
void jobArray::preencherArray(int size){
    for (int i = 0; i < size; i++)
    {
        array[i] = new job;

        array[i]->jobId = i + 1;
        array[i]->deadline = rand() % 10 + 1;
        array[i]->profit = rand() % 10 + 1;

    }
}

// -------------------------- Imprime a array de tarefas 1
void jobArray::printArray(int size){

    system(clearT);
    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << (i + 1) << "° Tarefa ID: " << array[i]->jobId;
        cout << "\t Profit: " << array[i]->profit;
        cout << "\t Prazo Máximo: " << array[i]->deadline << endl;
    }
    cout << "\n\n";
}

void jobArray::sortArray(int size){

	for (int i = 0; i < size; i++) //loop externo que percorre todo o vetor elemento a elemento
	{
		job* aux; //variavel auxiliar
		for (int j = i; j > 0; j--) //loop interno que percorre todos os elementos anteriores ao elemento da interação do loop externo
		{	
			
			if (array[j]->profit < array[j - 1]->profit) { //compara o valor atual com cada valor anterior a ele e caso true substitui os valores
				aux = array[j - 1];
				array[j - 1] = array[j];
				array[j] = aux;
			}
			else {
				break; //no caso falso não é necessário continuar nesta estrutura de repetição
			}
		}
		
	}
	

}

jobArray jobArray::maxProfitArray(int size){

    job* aux[size];

    for (int i = 0; i < size; i++)
    {
        
    }
    
    
    

}

int jobArray::findMaxDeadline(int size){
    int maxDeadline = 0;
    for(int i =0; i<size; i++){
        if(array[i]->deadline > maxDeadline){
            maxDeadline = array[i]->deadline;
        }
    }
    return maxDeadline;
}

int main(){

    jobArray jobArray;

    jobArray.preencherArray(arraySize);
    jobArray.printArray(arraySize);
    jobArray.sortArray(arraySize);
    jobArray.printArray(arraySize);
    jobArray.findMaxDeadline(arraySize);
    
}