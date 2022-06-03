#include <iostream>
#include <cstring>
#include <cstdio>

#ifdef _WIN32
  #include<windows.h>
#endif 

#include "ListNode.h"

using namespace std;
using namespace ListNode;
using namespace Stack;
using namespace Queue;

int totalOfOrders = 1;

int menu();
void cleanScreen();

int main() {
  int op2 = 0;
  List temp = NULL, pedidos = NULL, abarrotes = NULL, electros = NULL;

  do {
    int op = menu();

    switch (op) {
      case 1: {
        int op3;
        do {
          push(pedidos);

          if (totalOfOrders <= 8) {
            cout << "\nDesea registrar un nuevo pedido? (1)Si (0)No: "; cin >> op3;
          } else {
            cout << "Maxima cantidad de pedidos alcanzada." << endl;
          }
        } while (op3 == 1 && totalOfOrders <= 8);
                
        break;
      }
      case 2: {
        temp = pop(pedidos);

        if (strcmp(&(temp->type), "A") == 0) {
          cout << "Moviendo el pedido " << temp->code << " a la cola de Abarrotes." << endl;
          add(abarrotes, temp);
        } else {
          cout << "Moviendo el pedido " << temp->code << " a la cola de Electros." << endl;
          add(electros, temp);
        }

        break;
      }
      case 3: {
        char tipo;
        cout << "Ingrese el tipo de producto que desee eliminar: "; cin >> tipo;

        if (strcmp(&tipo, "A") == 0) remove(abarrotes);
        else remove(electros);

        break;
      }
      case 4: {
        cout << "\nMostrando la lista de todos los pedidos: " << endl;
        showList(pedidos);

        getchar();

        break;
      }
      case 5: {
        cout << "\nMostrando lista de Abarrotes: " << endl;
        showList(abarrotes);

        cout << "\nMostrando lista de Electros: " << endl;
        showList(electros);

        getchar();

        break;
      }
    }
  } while (op2 == 0);
}

int menu() {
  int opcion;

  do {
    cout << "\n\t==== PEDIDOS ====\n" << endl;
    cout << "1. Recibir pedido" << endl;
    cout << "2. Reasignar pedido" << endl;
    cout << "3. Despachar pedido" << endl;
    cout << "4. Mostrar todos los pedidos" << endl;
    cout << "5. Mostrar pedidos por tipo" << endl;
    cout << "\n0 Salir ." << endl;
    cout << "\n\nIngresar opcion: " ;
    cin >> opcion;
  } while (opcion < 1 || opcion > 5);

  return opcion;
}

void cleanScreen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}