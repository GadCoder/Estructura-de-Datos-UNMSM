#include <iostream>
using namespace std;
struct nodo{
	int codigo;
    int peso;
	struct nodo *sgte;
	};
	
typedef struct nodo *TpLista;

TpLista crearNodo(){
	TpLista nuevo=NULL;
	nuevo = new(struct nodo);
	cout<<"Ingresar codigo --> "; cin>>nuevo->codigo;
    cout<<"Ingresar peso --> "; cin>>nuevo->peso;
	cout<<endl;
	nuevo->sgte=NULL;
	return nuevo;
}

void insertaFinal(TpLista &lista){
	TpLista p=lista;
	TpLista q=crearNodo();
	
	if(lista==NULL){
		lista=q;
		return;
	}
	
	while(p->sgte != NULL){
			p=p->sgte;
	}
	
	p->sgte=q;	
}
float funcPromedio(TpLista lista, int cantidad){
	
	float peso = 0.00;
	while(lista != NULL){
		peso += lista->peso;
		lista=lista->sgte;
	}
    return peso/cantidad;
	
}
void verLista(TpLista lista){
	
	while(lista != NULL){
		cout<<" codigo: "<<lista->codigo<<" peso: "<<lista->peso<<" ----->";
        lista=lista->sgte;
	}
	
}
int menu(){
    cout<<"MENU"<<endl;
    cout<<"=================="<<endl;
    cout<<"[1] Registrar Paquetes y mostrar peso promedio y total paquetes"<<endl;
    cout<<"[2] Mostrar Paquetes, con promedio y cantidad"<<endl;
    cout<<"[3] Ordenamiento segun peso"<<endl;
    cout<<"[0] SALIR"<<endl;
    int op;
    cout<<"OPCION [ ]\b\b";cin>>op;
    return op;
}
//En este algoritmo se adapta el algoritmo de inserción, pasandolo del ppt el cual está para arreglos. En este caso, traté de simular
//en la mayor medida a un arreglo
void insertSort(TpLista lista){
	TpLista p=lista;
    TpLista q;
	int n=0, auxcodigo, auxpeso;
    int m;
	// contar la cantidad de nodos
	while(p!=NULL){
		n++;
		p=p->sgte;
	}
	
	for(int i=2; i<=n;i++){
        p = lista;
        q = lista;
		m = 1;//usamos m como variable auxiliar
        while(m < i){
            p = p->sgte;//nos ubicamos en el elemento "i"
            m++;
        }
        auxcodigo = p->codigo;
        cout<<auxcodigo<<endl;
        auxpeso = p->peso;
        cout<<auxpeso<<endl;
        int j = i-1;
        m = 1;
        while( m < j){
            q = q->sgte; //Nos ubicamos en el elemento i-1
            m++;
        }
        cout<<"PARA Q"<<endl;
        
        cout<<q->codigo<<endl;
        
        cout<<q->peso<<endl;
        cout<<"====="<<endl;
        while(j >=1  &&   q->peso > auxpeso){ //Aqui vamos a simular el arreglo
            q->sgte->peso = q->peso;
            q->sgte->codigo = q->codigo;
            j--;
            q = lista;
            m=1;
            while( m < j){
                q = q->sgte;
                m++;
            }
        }
        q = lista;
        m=1;
        while(m < j+1){
                q = q->sgte;
                m++;
        }
        q->codigo=auxcodigo;
        q->peso=auxpeso;

		cout<<"Para i : "<<i<<endl;
		verLista(lista);
		cout<<endl;
	}//for
}
int main(){
    TpLista lista=NULL;
    float promedio = 0.00;
    int cantidad = 0, opcion;

    do{
        opcion = menu();
        switch (opcion)
        {
        case 1:
            insertaFinal(lista);
            cantidad++;
            promedio = funcPromedio(lista,cantidad);
            cout<<"Nueva cantidad: "<<cantidad<<" Nuevo promedio de peso: "<<promedio<<endl;
            break;
        
        case 2:
            verLista(lista);
            cout<<"Cantidad: "<<cantidad<<" Promedio de pesos: "<<promedio<<endl;
            break;
        case 3:
            insertSort(lista);
            cout<<"Cantidad: "<<cantidad<<" Promedio de pesos: "<<promedio<<endl;
            break;
        }
        system("pause");
        system("cls");
    } while(opcion != 0);
}
