// Árvores em estruturas dinÂmicas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr; //ponteiro para subárvore esquerda
    int data; //valor do nó
    struct treeNode *rightPtr; //ponteiro para subárvode direita
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

//funções
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

//função principal
int main(void){
    int i;
    int item;
    TreeNodePtr rootPtr = NULL;
    
    srand(time(NULL));
    printf("Os números sendo colocados na árvore são:\n");
    
    //insere valores aleatórias entre 0 e 14 na Árvore
    for(i=1;i<=10;i++){
        item=rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }
    
    //atravessa a árvore preOrder
    printf("\n\nA travessia na pré-ordem é:\n");
    preOrder(rootPtr);
    
    //atravessa a árvore inOrder
    printf("\n\nA travessia na ordem é:\n");
    inOrder(rootPtr);
    
    //atravessa a árvore postOrder
    printf("\n\nA travessia na pós-ordem é:\n");
    postOrder(rootPtr);
    return 0; // indica conclusão bem sucedida
}

//insere nó na árvare
void insertNode(TreeNodePtr *treePtr, int value){
    //se árvore estiver vazia 
    if(*treePtr == NULL){
        *treePtr = malloc(sizeof(treePtr));
        
        //se a memória foi alocada, então atribui dados
        if(*treePtr != NULL){
          (*treePtr) -> data = value;
          (*treePtr) -> leftPtr = NULL;
          (*treePtr) -> rightPtr = NULL;
        }
        else {
            //dado a inserir é menor que dado no nó atual
            if(value<(*treePtr)->data){
                insertNode(&((*treePtr)->leftPtr),value);
            }
            else if(value > (*treePtr) -> data){
                insertNode(&((*treePtr)->rightPtr),value);
            }
            else {
                printf("duplificado");
            }
        }
    }
}

void inOrder(TreeNodePtr treePtr){
    //se a árvore não está vazia, então atravessa 
    if(treePtr != NULL){
        inOrder(treePtr -> leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr -> rightPtr);
    }
}

//inicia travessia da árvore na pré-ordem
void preOrder(TreeNodePtr treePtr){
    //se a árvore não está vazia, então atravessa
    if(treePtr != NULL){
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

//inicia travessia da árvore na pós-ordem
void postOrder(TreeNodePtr treePtr){
    //se a árvore não está vazia, então atravessa
    if(treePtr != NULL){
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}
