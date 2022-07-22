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
    //ffunçao temporaria.
    void print(){
        cout<<"ID: "<<jobId<<" Profit:"<<profit<<" deadline: "<<deadline<<endl;
    };
}; 

// -------------------------- Definição da array de tarefas
struct jobArray
{
    job* array = new job[arraySize];
    int size = arraySize;
    void preencherArray();
    void printArray();
    void sortArray();
    job* maxProfitArray(int timeLimit);
    int findMaxDeadline();

};

// -------------------------- Preenchimento da array de tarefas 1
void jobArray::preencherArray(){
    for (int i = 0; i < size; i++)
    {
        //array[i] = new job;
        array[i].jobId = i + 1;
        array[i].deadline = rand() % 10 + 1;
        array[i].profit = rand() % 10 + 1;

    }
}

// -------------------------- Imprime a array de tarefas 1
void jobArray::printArray(){

    cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << (i+1) << "° Tarefa ID: " << array[i].jobId;
        cout << "\t Profit: " << array[i].profit;
        cout << "\t Prazo Máximo: " << array[i].deadline << endl;
    }
    cout << "\n \n"<<endl;
}

void jobArray::sortArray(){

	for (int i = 0; i < size; i++) //loop externo que percorre todo o vetor elemento a elemento
	{
		job aux; //variavel auxiliar
		for (int j = i; j > 0; j--) //loop interno que percorre todos os elementos anteriores ao elemento da interação do loop externo
		{	
			
			if (array[j].profit > array[j - 1].profit) { //compara o valor atual com cada valor anterior a ele e caso true substitui os valores
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

int jobArray::findMaxDeadline(){
    int maxDeadline = 0;
    for(int i =0; i< size; i++){
        if(array[i].deadline > maxDeadline){
            maxDeadline = array[i].deadline;
        }
    }
    return maxDeadline;
}

/*
job *jobArray::maxProfitArray(int timeLimit)
{
    int jobArrayPosition = 0;
    job * maxProfit= new job[timeLimit];
    for (int i = timeLimit; i > 0; i--)
    {
        for (int k = jobArrayPosition; k < size; k++)
        {
            if (array[k].deadline == i)
            {
                int positionInProfitArray = array[k].deadline;
                    
                    while(maxProfit[positionInProfitArray].jobId != NULL)
                        positionInProfitArray--;

                maxProfit[positionInProfitArray] = array[k];
                jobArrayPosition = k;
                break;
            }
        }
    //jobArrayPosition++;
    }

    return maxProfit;
}*/

job *jobArray::maxProfitArray(int maxDeadline)
{
    job * profitArr = new job[maxDeadline];
    for(int i = 0;i < size; i++){
        int pos = array[i].deadline;
        while(profitArr[array[i].deadline].jobId != NULL){
            pos = pos-1;
            cout<<"wrong!"<<endl;
            
        if(pos < 0){
            break;
        }
        }
        
        profitArr[pos] = array[i];
    }
    return profitArr;
}

int main(){
    jobArray jobs;
    jobs.preencherArray();
    jobs.printArray();
    jobs.sortArray();
    jobs.printArray();
    int deadline = jobs.findMaxDeadline();
    job* profitmax = jobs.maxProfitArray(deadline);
    cout<<"MAX PROFIT ARRAY "<<endl; 
    int i =0;
    while(i<deadline){
        profitmax[i].print();
        i++;
    }
    return 0; 
}
