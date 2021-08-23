//Listas encadeadas

#include<stdio.h>
#include<stdlib.h>

/* estrutura autorreferenciada */
struct listNode{
    char data; //cada listNode contém um caractere
    struct listNode *nextPtr; //ponteiro para próximo nó
}; // fim da estrutura listNode

typedef struct listNode ListNode; //sinônimo de struct listNode
typedef ListNode *ListNodePtr; // sinônimo de ListNode*

//protótipos
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList(ListNodePtr currentPtr);
void instructions(void);

int main (void) {
    
    ListNodePtr startPtr = NULL; //inicialmente não existem nós
    int choice; //escolha do usuário
    char item; //char inserido pelo usuário

    instructions(); //exibe o menu
    printf("?");
    scanf("%d", &choice);

    while(choice != 3){
        switch(choice){
            case 1:
                getchar();
                printf("Digite um caractere: ");
                scanf("%c", &item);
                insert(&startPtr, item);//insere item na lista
                printList(startPtr);
                break;
            case 2://exclui um elemento
                //se lista não está vazia
                if(!isEmpty(startPtr)){
                    printf("Digite caractere a ser excluído: ");
                    scanf("\n%c", &item);
                    if(delete(&startPtr, item)){ //remove item
                        printf("%c Delete.", item);
                        printList(startPtr);
                    } else {
                        printf("%c não encontrado\n\n", item);
                    }
                } else {
                    printf("Lista esta vazia\n\n");
                }
                break;
            default:
                printf("Escolha inválida.\n\n");
                instructions();
                break;
        }
        printf("?");
    scanf("%d", &choice);
    }
    printf("Fim de execução\n");
    return 0;
}


void instructions( void ){
    printf("Digite sua escolha: \n"
    " 1 para inserir um elemento na lista.\n"
    " 2 para excluir um elemento da lista.\n"
    " 3 para terminar.\n"
    );
}

void insert(ListNodePtr *sPtr, char value){

    ListNodePtr newPtr; /* ponteiro para novo nó */ 
    ListNodePtr previousPtr; /* ponteiro para nó anterior na lista */ 
    ListNodePtr currentPtr; /* ponteiro para nó atual na lista */ 

    newPtr = malloc(sizeof(ListNode));/* cria nó */

    if ( newPtr != NULL ) { /* espaço está disponível */ 
        newPtr->data = value; /* coloca valor no nó */ 
        newPtr->nextPtr = NULL; /* nó não se une a outro nó */
        
        previousPtr = NULL;
        currentPtr = *sPtr;
        
        /* loop para achar o local correto na lista */ 
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr; /* caminha para ...*/
            currentPtr = currentPtr->nextPtr; /* ... próximo nó */
        } /* fim do while */

        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr; 
            *sPtr = newPtr; 
        } /* fim do if */ 
        else { /* insere novo nó entre previousPtr e currentPtr */ 
            previousPtr->nextPtr = newPtr; 
            newPtr->nextPtr = currentPtr; 
        } /* fim do else */ 
    }else{
        printf("%c não inserido. Sem memória disponível.\n\n", value );
    }
}

char delete(ListNodePtr *sPtr, char value){

    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if ( value == ( *sPtr )->data ) {
        tempPtr = *sPtr; /* aponta para o nó que está sendo removido */ 
        *sPtr = ( *sPtr )->nextPtr; /* retira thread do nó */ 
        free( tempPtr ); /* libera o nó com thread retirado */ 
        return value;
    } /* fim do if */ 
    else {
        previousPtr = *sPtr; 
        currentPtr = ( *sPtr )->nextPtr; 
    /* loop para achar local correto na lista */ 
    }while ( currentPtr != NULL && currentPtr->data != value ) {
        previousPtr = currentPtr; /* caminha até ... */
        currentPtr = currentPtr->nextPtr; /* ... próximo nó */ 
    } /* fim do while */ 
    /* exclui nó em currentPtr */ 
    if ( currentPtr != NULL ) {
        tempPtr = currentPtr; 
        previousPtr->nextPtr = currentPtr->nextPtr; 
        free( tempPtr ); 
        return value;
    }
    return '\0';
}

int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}

void printList(ListNodePtr currentPtr){
    if( currentPtr == NULL ){
        printf("Lista está vazia.\n\n");
    }
    else {
        printf("\nA lista é: \n");

        while(currentPtr != NULL){
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}
