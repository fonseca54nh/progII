#include "top.hpp"

void plant() 
{
    tam = 1;
}

void order(tree *t)
{
    if(t != NULL)
    {
        order(t -> left);
        printf("%5d",t -> data);
        order(t->right);
    }
}

void postOrder(tree *t)
{
    if(t != NULL)
    {
        postOrder(t -> left);
        postOrder(t -> right);
        printf("%5d",t -> data);
    }
}

void preOrder(tree *t)
{
    if(t != NULL)
    {
        printf("%5d",t -> data);
        preOrder(t -> left);
        preOrder(t -> right);
    }
}

void burn(tree *t)
{
    if (t == NULL)
        return;
    burn(t -> left);
    burn(t -> right);
    printf("\n Valor Deletado: %d", t->data);
    free(t);
}

tree *newtree(int x)
{
    tree *temp = (tree*)malloc(sizeof(tree));
    temp->data = x;
    printf("Valor Inserido: %d", temp -> data);
    temp->left = temp->right = NULL;
    return temp;
}

tree *crown(tree *t)
{
    tree *top = t;

    while (top && top->left != NULL)
        top = top->left;

    return top;
}

tree *newleaf(tree *t, int x)
{
    if (t == NULL)
        return newtree(x);

    if (x < t->data)
        t->left  = newleaf(t->left, x);

    else if (x > t->data)
        t->right = newleaf(t->right, x);

    tam++;
    return t;
}

tree *cut(tree *t, int x)
{
    if (t == NULL)
        return t;

    if (x < t->data)
        t->left = cut(t->left, x);

    else if (x > t->data)
        t->right = cut(t->right, x);

    else
    {
        if (t->left == NULL)
        {
            tree *temp = t->right;
            printf("Valor Removido: %d",t->data);
            free(t);
            return temp;
        }
        else if (t->right == NULL)
        {
            tree *temp = t->left;
            printf("Valor Removido: %d",t->data);
            free(t);
            return temp;
        }

        tree* temp = crown(t->right);
        t->data = temp->data;
        t->right = cut(t->right, temp->data);
    }
    tam--;
    return t;
}

tree *search(tree *t, int x)
{
    if(t->data < x && t->right != NULL)
        return search(t->right, x);

    if(t->data > x && t->left != NULL)
        return search(t->left, x);

    if(t->data == x)
    {
        printf("\nO valor %d existe nessa Arvore!\n",x);
	return 0;
    }
    printf("\nO valor %d nao existe nessa Arvore!\n",x);
    	return 0;
}
