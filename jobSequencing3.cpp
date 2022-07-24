#include <iostream>
using namespace std;

// Declaração de variável global para a quantidade de tarefas a serem geradas
const int arraySize = 5;

int comp(int a, int b){
    return (a < b) ? a : b;
}

// -------------------------- Definição de uma tarefa
struct job{
    int profit;
    int deadline;
    int jobId;
}; 

// -------------------------- Definição da array de tarefas
struct jobArray{

    job array[arraySize];

    void preencherArray(){ // Preenche a Array de tarefas com tarefas de valores aleatórios
        for (int i = 0; i < arraySize; i++)
        {

            array[i].jobId = i + 1;
            array[i].deadline = rand() % 10 + 1;
            array[i].profit = rand() % 10 + 1;

        }
    };

    void sortArray(){ // Ordena a Array de tarefas em ordem crescente de Profits

        job aux;

        for (int i = 0; i < arraySize; i++)
        {
            for (int j = 0; j < arraySize; j++)
            {
            if (array[i].profit > array[j].profit)
            {
                    aux = array[j];
                    array[j] = array[i];
                    array[i] = aux;
            }
            }
        }
    };

    void printArray(){ // Imprime a Array de tarefas e todos os seus valores

        cout << "\n\n";
        for (int i = 0; i < arraySize; i++) // Iteração sobre cada tarefa da Array
        {  
            // Impressão dos valores relacionados à tarefa
            cout << (i+1) << "° Tarefa ID: " << array[i].jobId;
            cout << "\t Profit: " << array[i].profit;
            cout << "\t Prazo Máximo: " << array[i].deadline << endl;
        }
        cout << "\n \n"<<endl;
    };

    jobArray finalArray(){ // Gera um novo objeto JobArray ordenada para maximizar o profit total

        sortArray(); // Ordena-se a Array de tarefas em ordem crescente de Profits

        jobArray resultArray; // objeto JobArray a ser retornado como resultado ao final da função
        bool pos[arraySize]; // Array contendo informações sobre ocupação das posições pelas tarefas

        for (int i = 0; i < arraySize; i++) // Inicialmente todas as posições estão livres (desocupadas)
        pos[i] = false;

        for (int i = 0; i < arraySize; i++) // Iteração sobre cada elemento da Array de tarefas original
        {
            // Encontrar uma posição para a tarefa em questão, começando pela última posição possível
            for (int j = comp(arraySize, array[i].deadline) - 1; j >= 0; j--) 
            {
                if (pos[j] == false) // Caso a posição esteja desocupada, insere-se a tarefa aqui
                {                    // Caso contrário, itera-se novamente até encontrar uma posição desocupada
                    resultArray.array[j] = array[i];
                    pos[j] = true;
                    break;
                }
                
            }
            
        }
        return resultArray; // retorna-se o objeto JobArray com as tarefas já ordenadas para maximizar o profit total.
    };

};

int main(){

    jobArray jobs;
    jobs.preencherArray();
    jobs.printArray();
    jobs.finalArray().printArray();

    return 0;
}
