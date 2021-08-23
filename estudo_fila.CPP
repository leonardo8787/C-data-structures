// fila em estruturas dinÂmicas

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    char data;
    struct queueNode *nextPtr;
} ;

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

//funções 
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
void instructions(void);

//função principal (main)
int main(void){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    int choice;
    char item;
    
    instructions();
    printf("?");
    scanf("%d", &choice);
    
    //enquanto o usuário não digita 3 
    while(choice != 3){
        switch(choice){
            case 1:
                printf("Digite um caractere: ");
                scanf("\n%c", &item);
                enqueue(&headPtr, &tailPtr, item);
                printQueue(headPtr);
                break;
            case 2:
                if(!isEmpty(headPtr)){
                    item = dequeue(&headPtr, &tailPtr);
                    printf("%c saiu da fila.\n", item);
                }
            default:
                printf("Escolha inválida.\n\n");
                instructions();
                break;
        }
        printf("?");
        scanf("%d", &choice);
    }
    printf("Fim da execução!\n\n");
    return 0;
}


//menu
void instructions(void){
    printf("Digite sua Escolha:\n"
    "1 para incluir um item na fila\n"
    "2 para remover um item da fila\n"
    "3 para encerrar\n"
    );
}


//insere um nó na cauda da fila
void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value ){
    
    QueueNodePtr newPtr;
    
    newPtr = malloc(sizeof(QueueNode));
    
    if(newPtr != NULL){// se houver espaço disponível
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        
        //se vazia, ensire nó na cabeça 
        if(isEmpty(*headPtr)){
            *headPtr = newPtr;
        }
        else{
            (*tailPtr)->nextPtr = newPtr;
        }
        
        *tailPtr = newPtr;
    }
    else {
        printf("%c não inserido. Não há memória disponível.\n", value);
    }
}

//remove nó da cabeça da fila 
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    char value;
    QueueNodePtr tempPtr;
    
    value = ( *headPtr ) -> data;
    tempPtr = *headPtr;
    *headPtr = ( *headPtr ) -> nextPtr;
    
    //se a fila estiver vazia
    if(*headPtr == NULL){
        *tailPtr = NULL;
    }
    
    free(tempPtr);
    return value;
}


//retorna 1 se a lista estiver vazia; caso contrário, retorna 0
int isEmpty(QueueNodePtr headPtr){
    return headPtr == NULL;
}

//imprime fila 
void printQueue(QueueNodePtr currentPtr){
    //se a fila estiver vazia 
    if(currentPtr == NULL){
        printf("A fila está vazia.\n\n");
    }
    else {
        printf("A fila é:\n");
        
        //enquanto não for fim da fila
        while(currentPtr != NULL){
            printf("%c ---> ", currentPtr->nextPtr);
            currentPtr = currentPtr->nextPtr;
        }
        
        printf("NULL\n\n");
    }
}