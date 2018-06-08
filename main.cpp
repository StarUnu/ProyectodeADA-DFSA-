#include <iostream>

using namespace std;
class lista_AB;

class estado{
public:
    estado(char caracter1){
        this->caracter=caracter1;
        this->ptro=0;
        this->lista_e=0;
        this->haylista_e=false;
    }

    bool get_haylista_e()
    {
        return haylista_e;
    }
    char get_caracter()
    {
        return caracter;
    }

    lista_AB * get_lista_e()
    {
        return lista_e;
    }
    void  set_lista_e(lista_AB * nuevo)
    {
        this->lista_e=nuevo;
        this->haylista_e=true;
    }
private:
    int height;
    char caracter;
    estado * ptro;
    lista_AB * lista_e;
    bool haylista_e;
};

class lista_AB{
public:
    lista_AB()
    {
        this->lista[27]={0};
        this->indices[27];//={0};
        /*cout<<"lista"<<indices[10]<<endl;
        cout<<"lista"<<lista[10]<<endl;*/
        next_l=0;
    }

    bool buscar_c(char caracter)
    {
        if(indices[caracter%97]== 1)
        {
            return true;
        }

        return false;
        //cout<<"termino acas";
    }
    estado * add_lista(char caracter)
    {
        if(!buscar_c(caracter))
        {
            estado * nuevo=new estado(caracter);
            lista[caracter%97]=nuevo;
            indices[caracter%97]=1;
            return nuevo;
        }
        //cout<<"entro acas"<<lista[caracter%97]<<endl;
        return lista[caracter%97];

    }


    void set_lista(lista_AB * nuevo)
   {
     this->next_l=nuevo;
   }

    int get_tpagina()
    {
        return tpagina;
    }

    lista_AB * get_next_l()
    {
        return next_l;
    }

    estado * lista[27]={0};
    int  indices[27]={0};
private:
    int tpagina=27;

    lista_AB * next_l;
};

///funcion hash

class arbolB{
public:
    arbolB()
    {
        this->head_l=0;
    }
    void add_arbol(string palabra );
    void imprime(lista_AB * cp_head_l);

    lista_AB * get_lista()
    {
        return head_l;
    }

private:
    int tpagina=27;
    lista_AB * head_l;
};

void arbolB::add_arbol( string palabra )
{
    estado * cphead=0;

    bool entra=false;
    lista_AB * cpheal_lista=head_l;
    int i=0;
    lista_AB * nuevo_lista=new lista_AB;

     /// inciando los valores iniciales !
    if(head_l == 0)
    {
        cphead=nuevo_lista->add_lista(palabra[i]);
        this->head_l=nuevo_lista;
        cpheal_lista=nuevo_lista;
    }
    else
    {
        cphead=head_l->add_lista(palabra[i]);
    }

    i++;

    for(;i<palabra.size();i++)
    {
        //cout<<"cphead"<<cphead<<endl;
        nuevo_lista=new lista_AB;
        if( cphead->get_lista_e() == 0  )
        {
            estado * cpestado=nuevo_lista->add_lista(palabra[i]);
            cphead->set_lista_e(nuevo_lista);
            cphead=cpestado;
            cpheal_lista=nuevo_lista;
            //cout<<cphead<<endl;
            //cout<<" "<<palabra[i]<<endl;
        }
        else{
            cphead=cphead->get_lista_e()->add_lista(palabra[i]);

        }
    }

}

void arbolB :: imprime(lista_AB * cp_head_l)
{

    if(cp_head_l==0)
        return;
    //cout<<cp_head_l->lista[4]->get_caracter()<<endl;
    //cout<<"esto es dvd"<<endl;
    for(int i=0;i<27;i++)
    {
        if(cp_head_l->lista[i]!=0 )
        {
            cout<<cp_head_l->lista[i]->get_caracter()<<endl;
            //cout<<"i"<<i;

            lista_AB * cp_head_l2=cp_head_l->lista[i]->get_lista_e();
            imprime( cp_head_l2);

        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    //char ZEROARRAY[1024];
    /*int ZEROARRAY[10] = {0};
    for(int i=0;i<10;i++)
    {
        cout<<ZEROARRAY[i]<<" "<<endl;
    }*/

    arbolB prueba;
    prueba.add_arbol("erika");
    prueba.add_arbol("eriko");
    prueba.add_arbol("erikoto");
    prueba.add_arbol("hp");
    prueba.imprime(prueba.get_lista());

    return 0;
}
