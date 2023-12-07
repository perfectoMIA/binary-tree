#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node//структура узла дерева 
{
  int data;
  struct Node *left;//указатель на левый узел
  struct Node *right;//указатель на правый узел
  struct Node *parent;//указатель на родителя
} Node; //название узла дерева

Node *createRoot(Node *root, int data) //функция создания корня бинарного дерева
{
  Node *tmp = (Node*)malloc(sizeof(Node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->parent = NULL;
  root = tmp;
  return root;
}

bool findNode(Node *root, int data) //функция поиска узла в дереве
{
  Node *tmp = root;
  while (true) 
  {
    if (tmp == NULL) 
    {
      return false;
    }
    else if (tmp->data == data) 
    {
      return true;  
    }
    else if (tmp->data < data) 
    {
      tmp = tmp->right;
    }
    else if (tmp->data > data) 
    {
      tmp = tmp->left;
    }
  }
}

void addNode (Node *root, int data) //функция добавления узла в дерево
{
  Node *tmp = root;
  while (true) 
  {
    if (tmp == NULL) 
    {
      Node* next = (Node*)malloc(sizeof(Node));
      next->data = data;
      next->left = NULL;
      next->right = NULL;
      next->parent = tmp; //чё то тут не то 
    }
    else if (tmp->data == data) 
    {
      return;
    }  
    else if (tmp->data < data) 
    {
      tmp = tmp->right;
    }
    else if (tmp->data > data) 
    {
      tmp = tmp->left;
    }
  }
}

int main(void) {
  printf("hello world");
  return 0;
}

//Зачем нужные бинарные деревья:
//хранение данных для алгоритмов сжатия. 
//основа для других структур данных (очередь с приоритетом, куча, словарь)
//
//Поиск O(logn) 
//вставка O(logn)
//Нужно балансировать дерево. 
//Каждый левый узел < правого, а каждый правый > левого.
//есть обход в ширину и обход в глубину. 
//не хранит элементы с одинаковым значением. 