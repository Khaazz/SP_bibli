#include "tree.c"

node_t * createNode(char value)
{
    node_t * node = malloc(sizeof(*node));
    if(node != NULL)
    {
        stack->value   = value;
        stack->son     = NULL;
        stack->brother = NULL;
    }
    else
    {
        printf("ERROR: Allocation Node\n")
    }
    return node;
}

void insertBrother(node_t * node, node_t * element)
{
    node->brother = element;
}

void insertSon(node_t * node, node_t * element)
{
    node->son = element;
}

void getPostfix(node_t * node, int * taille, char * liste)
{
    node_t *  cour  = node;
    stack_t * stack = createStack(10);
    while(cour != NULL)
    {
        while(cour->son)
        {
            push(stack, cour);
            cour = cour->son;
        }
        liste[*taille] = cour->value;
        *taille++;
        cour = cour->brother;
        while(cour = NULL && isEmptyStack(stack) == 0)
        {
            cour = peek(stack);
            pop(stack);
            liste[*taille] = cour->value;
            *taille++;
            cour = cour->brother;
        }
    }
    freeStack(stack);
}

void displayPostFix(char * liste, int taille)
{
    int i;
    printf("Ordre prefixe : \n");

    for(i = 0; i <= taille; i++)
    {
        print("%c ", liste[i];)
    }
}

node_t * search(node_t * node, char valeur)
{
    node_t *  cour  = node;
    queue_t * queue = createQueue(10);
    while(cour != NULL || cour->value != valeur)
    {

        if(cour->son != NULL)
        {
            pushBack(queue, cour);
        }
        if(cour->brother != NULL)
        {
            cour = cour->brother;
        }
        else
        {
            cour = front(queue);
            popFront(queue);
        }
    }
    return cour;
}