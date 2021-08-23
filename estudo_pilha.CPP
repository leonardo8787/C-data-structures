// pilha dinâmica 

#include <stdio.h>
#include <stdlib.h>

//struct
struct stackNode {
    int data;
    struct stackNode *nextPtr;
};

typedef struct stackNode stackNode;
typedef stackNode *StackNodePtr;

//funções
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

//função principal (main)
int main(void){
    
    StackNodePtr stackPtr = NULL; //aponta pro topo da pilha
    int choice; //escolha do menu
    int value;
    
    instructions(); //chama a função de instrução
    printf("?");
    scanf("%d", &choice);
    
    //enquanto o usuário não digita 3, o loop continua
    while(choice != 3){
        switch(choice){
            //coloca um valor na pilha
            case 1:
                printf("Digite um inteiro: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            //remove valor da pilha 
            case 2:
                if(!isEmpty(stackPtr)){
                    printf("O valor retirado é %d.\n", pop(&stackPtr));
                }
                printf(stackPtr);
                break;
            default:
                printf("Escolha inválida.\n\n");
                instructions();
                break;
        }
        printf("?");
        scanf("%d", &choice);
    }//fim do while
    printf("Fim da execução!\n");
    return 0;
}

//instruções do menu
void instructions(void){
    printf("Digite escolha:\n"
    "1 para colocar um valor na pilha\n"
    "2 para retirar um valor da pilha\n"
    "3 para terminar programa\n"
    );
}

//insere novo nó(informação) na pilha
void push(StackNodePtr *topPtr, int info){
    StackNodePtr newPtr;//ponteiro para novo nó
    
    //insere o nó no topo da pilha 
    if(newPtr != NULL){
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else { // se não tiver espaço disponível
        printf("%d não inserido. Nenhuma memória disponível.\n", info);
    }
}

//remove nó(informação) da pilha 
int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr; // ponteiro de nó temporário
    int popValue; //node value 
    
    tempPtr = *topPtr;
    popValue = ( *topPtr ) -> data;
    *topPtr = ( *topPtr ) -> nextPtr;
    free(tempPtr);
    
    return popValue;
}

//imprime a pilha
void printStack(StackNodePtr currentPtr){
    
    //se a pilha estiver vazia
    if(currentPtr == NULL){
        printf("A pilha está vazia.\n\n");
    }
    else{
        printf("A pilha é: \n");
        
        //enquanto não chega ao final da pilha
        while(currentPtr != NULL){
            printf("%d ---> ", currentPtr->data);
            currentPtr=currentPtr->nextPtr;
        }
        
        printf("NULL\n\n");
    }
}

//retorna 1 se a pilha está vazia, caso contrário, retorna 1 
int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}