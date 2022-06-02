#include <iostream>
#include <string.h>

using namespace std;

namespace ListNode {
  struct Node {
    char type;
    int code;
    struct Node *next;
  };

  typedef struct Node *List;

  List newOrder() {
    List newOrder = NULL;
    newOrder = new(struct Node);

    cout << "Ingrese el tipo de pedido [A: Abarrotes, E: Electro]: "; cin >> newOrder->type;
    cout << "\nIngrese el codigo del pedido: "; cin >> newOrder->code;
    cout << endl;
    newOrder->next = NULL;
    return newOrder;
  }

  void showList(List list) {
    if (list == NULL) {
      cout << "La lista esta vacia.";
      return;
    }

    string typeOfOrder = strcmp(&(list->type), "A") == 0 ? "Abarrote" : "Electro";

    while (list != NULL) {
      cout << "\nPedido: " << list->code << " - " << typeOfOrder;
      cout << endl;
      list = list->next;
    }
  }
}

using namespace ListNode;

namespace Stack {
  void push(List &list) {
    List node = newOrder();

    if (list != NULL) node->next = list;
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
}

namespace Queue {
  void add(List &list, List node) {
    List currentList = list, orderToTranslate = node;

    if (list == NULL) {
      list = orderToTranslate;
      return;
    }

    while(currentList->next != NULL) {
      currentList = currentList->next;
    }

    currentList->next = orderToTranslate;
  }

  void remove(List &list) {
    List currentList = list;

    if (list == NULL) {
      cout << "La cola está vacia." << endl;
      return;
    }

    list = list->next;

    cout << "Removiendo el pedido: " << list->code << endl;

    delete(currentList);
  }
}