// #include <owo>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

struct Node {
  int mid = 0;
  int top = 0;
  int bottom = 0;
  struct Node *next;
  struct Node *prev;
};

typedef struct Node *List;

int menu();
int generateNumber(int, int);
List createNode();
void push(List *);
List pop(List *);
void insertAtStart(List *, List);
void showList(List);
void setWeights(List);
void removeElement(List *);

int totalOfNodes = 1;

int main() {
  srand(time(NULL));
  int op2 = 0;
  List temp = NULL, originalStack = NULL, doubleList = NULL;

  do {
    int op = menu();

    switch (op) {
    case 1: {
      int op3 = 1;

      while (op3 == 1 && totalOfNodes <= 5) {
        push(originalStack);

        cout << "\nDesea ingresar un nuevo nodo? (1)Si (0)No: ";
        cin >> op3;
        totalOfNodes++;
      }

      if (totalOfNodes > 5)
        cout << "\nMaxima cantidad de nodos alcanzada." << endl;

      cout << "\nMostrando PILA de elementos ---" << endl;
      showList(originalStack);

      break;
    }
    case 2: {
      int op3 = 1;

      while (op3 == 1) {
        temp = pop(originalStack);
        insertAtStart(doubleList, temp);

        cout << "\nDesea descargar un nuevo nodo? (1)Si (0)No: ";
        cin >> op3;
      }

      cout << "\nMostrando LISTA de elementos descargados ---" << endl;

      showList(doubleList);

      break;
    }
    case 3: {
      setWeights(doubleList);

      cout << "\nMostrando LISTA de elementos ---" << endl;
      showList(doubleList);

      break;
    }
    case 4: {
      removeElement(doubleList);
      break;
    }
    case 5: {
      cout << "\nMostrando pila de elementos: " << endl;
      showList(originalStack);

      cout << "\nMostrando lista de Elementos: " << endl;
      showList(doubleList);
      break;
    }
    }
  } while (op2 == 0);
}

int menu() {
  int opcion;

  do {
    cout << "\n\t==== MENU ====\n" << endl;
    cout << "1. Ingresar elemento a la pila" << endl;
    cout << "2. Descargar elementos de la pila" << endl;
    cout << "3. Asignar pesos a la lista" << endl;
    cout << "4. Eliminar elemento" << endl;
    cout << "5. Mostrar lista" << endl;
    cout << "\n0 Salir ." << endl;
    cout << "\n\nIngresar opcion: ";
    cin >> opcion;
  } while (opcion < 1 || opcion > 5);

  return opcion;
}

int generateNumber(int start, int end) {
  int number = start + rand() % (1 + end - start);
  return number;
}

List createNode() {
  List newNode = NULL;
  newNode = new (struct Node);
  int element = generateNumber(10, 50);

  cout << "Nodo Generado: " << element;
  cout << endl;

  newNode->mid = element;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

void push(List &list) {
  List node = createNode();

  if (list != NULL)
    node->next = list;
  list = node;
}

List pop(List &list) {
  List temp = list;

  if (list == NULL) {
    cout << "La lista esta vacia." << endl;
    return temp;
  }

  list = list->next;
  temp->next = NULL;

  return temp;
}

void insertAtStart(List &list, List node) {
  List newNode = node;

  if (newNode == NULL)
    return;

  if (list != NULL) {
    newNode->next = list;
    list->prev = newNode;
  }

  list = newNode;
}

void showList(List list) {
  int i = 0;

  if (list == NULL) {
    cout << "Lista vacia.";
    return;
  }

  while (list != NULL) {
    cout << " " << i + 1 << ") " << list->top << " | " << list->mid << " | "
         << list->bottom << endl;
    list = list->next;
    i++;
  }
}

void setWeights(List list) {
  int op = 1;
  List returnList = NULL;

  cout << "\n-- Asignando peso de ida --" << endl;
  while (list != NULL && op == 1) {
    int toIncrement = generateNumber(10, 20);
    cout << "\nAsignando " << toIncrement << " al nodo " << list->mid;

    list->top = list->top + toIncrement;
    returnList = list;
    list = list->next;
    cout << "\nIncrementar otro nodo? (1)Si (0)No: ";
    cin >> op;
  }

  op = 1;
  list = returnList;
  cout << "\n-- Asignando peso de retorno --" << endl;
  while (list != NULL && op == 1) {
    int toIncrement = generateNumber(30, 50);
    cout << "\nAsignando " << toIncrement << " al nodo " << list->mid;

    list->bottom = list->bottom + toIncrement;
    list = list->prev;
    cout << "\nIncrementar otro nodo? (1)Si (0)No: ";
    cin >> op;
  }
}

void removeElement(List &list) {
  if (list == NULL) {
    cout << "Lista vacia.. no permite esta opcion" << endl;
    return;
  }

  int total = list->mid + list->bottom + list->top;

  if (list->next == NULL) {
    if (total >= 75) {
      cout << "Se elimina el nodo :" << list->top << " | " << list->mid << " | "
           << list->bottom << endl;
      delete (list);
      list = NULL;
      return;
    }

    cout << "El total es menor a 75.";
    return;
  }

  list = list->next;

  if (total >= 75) {
    cout << "Se elimina el nodo: " << list->prev->top << " | "
         << list->prev->mid << " | " << list->prev->bottom << endl;
    delete (list->prev);
    list->prev = NULL;
    return;
  }

  cout << "El total es menor a 75.";
  return;
}
