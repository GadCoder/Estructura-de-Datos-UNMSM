#include <iostream>
#include <time.h>
#include <stdlib.h>

struct Node{
    int id;
    float weight;
    Node * next_node;
    Node();
    void createNode();

};

typedef Node* Node_ptr;

void menu(Node_ptr & package_list_head);
void registerPackage(Node_ptr &package_list_head);
void showList(Node_ptr package_list_head);
void sort_selection(Node_ptr &package_list_head);
void sort_insercion(Node_ptr &package_list_head);

/*
 Metodos para ordenar:
 Seleccion
 Insercion
 intercambio
 */
int main() {
    srand(time(NULL));
    Node_ptr package_list_head = NULL;
    menu(package_list_head);
    return 0;
}

Node::Node() {
    id = 0;
    weight = 0.0;
    next_node = NULL;
}
void Node::createNode() {
    std::cout<<"\t-> Ingrese el codigo del paquete: ";
    std::cin>>id;
    std::cout<<"\t-> Ingrese el peso del paquete: ";
    std::cin>>weight;
}



void menu(Node_ptr & package_list_head){

    int opc;
    std::cout<<"\n\t\tMENU\n";
    std::cout<<"1. Registrar paquete\n";
    std::cout<<"2. Mostrar lista, cantidad de paquetes y promedio de pesos\n";
    std::cout<<"3. Ordenar lista\n";
    std::cout<<"0. Salir\n";
    std::cout<<"\t-> Opcion:";
    std::cin>>opc;
    switch (opc) {
        case 1: {
            registerPackage(package_list_head);
            break;
        }
        case 2: {
            showList(package_list_head);
            break;
        }
        case 3: {
            sort_selection(package_list_head);
            break;
        }
        default: break;

    }
    if (opc != 0){
        menu(package_list_head);
    }
}


void registerPackage(Node_ptr &package_list_head){
    Node_ptr new_package = new Node();
    new_package->createNode();
    Node_ptr copy_head = package_list_head;
    if(!copy_head){
        package_list_head = new_package;
        return;
    }
    while(copy_head->next_node){
        copy_head = copy_head->next_node;
    }

    copy_head->next_node = new_package;
}

void showList(Node_ptr package_list_head){
    if(!package_list_head){
        std::cout<<"\nLa lista se encuentra vacia\n";
        return;
    }
    int number_of_packages = 0;
    float weight_average = 0.0;
    while (package_list_head){
        int id = package_list_head->id;
        float weight = package_list_head->weight;
        std::cout<<"{id: "<<id<<", peso: "<<weight<<"} ->";
        package_list_head = package_list_head->next_node;
        number_of_packages++;
        weight_average += weight;
    }
    std::cout<<"NULL\n";
    weight_average = weight_average / float(number_of_packages);
    std::cout<<"Numero de paquetes: "<<number_of_packages<<std::endl;
    std::cout<<"Peso promedio de los paquetes: "<<weight_average<<std::endl;
}

void sort_selection(Node_ptr &package_list_head){
    // La lista se encuentra vacia
    if(!package_list_head || !package_list_head->next_node){
        std::cout<<"La lista se encuentra vacia o cuenta con un elemento.\n";
        return;
    }

    float min_weight = package_list_head->weight; // variable que va guardar el minimo peso en cada iteracion
    Node_ptr current_node = package_list_head; // nodo que va avanzando por cada iteracion

    while(current_node){
        Node_ptr travel_node = current_node;
        Node_ptr min_weight_node = travel_node;
        //Recorriendo la lista desde i + 1 hasta N
        while (travel_node){
            if(travel_node->weight < min_weight){
                min_weight = travel_node->weight; // Se actualiza el valor minimo
                min_weight_node = travel_node; // Se guarda el nodo con el minimo valor
            }
            travel_node = travel_node->next_node;
        }

        if(min_weight < current_node->weight){
            float temp_weight = current_node->weight;
            int temp_id = current_node->id;
            current_node->weight = min_weight;
            current_node->id = min_weight_node->id;
            min_weight_node->weight = temp_weight;
            min_weight_node->id = temp_id;
        }
        current_node = current_node->next_node;
        if(current_node){
            min_weight = current_node->weight;
        }
    }
}




