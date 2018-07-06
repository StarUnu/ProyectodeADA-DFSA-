#include <iostream>

using namespace std;

#include <iostream>

#include <vector>

using namespace std;

/*
Para renumerar los estados, los etiquetamos con un par (current_height, number).
Cuando el algoritmo de clasificación necesita un número de estado, es decir, se realiza una división en un nli.
Se usa un nuevo nombre en el lugar de nli calculado de la siguiente manera.
Supongamos que estamos clasificando estados de nivel current_height,
luego surgen dos casos cuando se necesita un número de estado en la clasificación de cubo: en el par (ch, num) en estado nli,
el valor ch es diferente de la altura actual, entonces el par (ch , num) es un par viejo,
debemos poner en su lugar el nuevo par (current-height, new_num).
En el caso en que ch es igual a la altura actual, la parte num del par se usa directamente
*/
int Renumerar(int s[], int h, int n)
{
    if(s[0]!=h)//s->ch!=h
    {
        s[0]=h; //s->sh=h
        s[1]=n; //s->num=n
        n=n+1;
    }
    return s[1];
}

/*
int main()
{

    int Renum;
    int s[2]={2,4};
    int h=3;
    int n=8;
    Renum=Renumerar(s,h,n);
    cout<<Renum;
    return 0;
}*/

/////////////////////////
void funcionlexicograma (vector <string> &lista)
{
    vector <vector<string> > quequ2;
    vector <vector<string> > queque1;
    vector <string > L;
    //string L;
    //vector <string> Q;
    vector< string > NONEMTY;
    vector <string> LEQUAL;
    int i=0;
    quequ2.push_back(lista);
    //char Q [27]={0};
    string Q[27]={""};
    cout<<"1"<<endl;
    int contador_queque2=0;
    do{

        for (int k=0;k<quequ2.size();k++)
        {
            //quequ2[k]=lista[k];
            queque1.push_back(quequ2[k]);
        }

        i=i+1;
        /*
        for (int j=0;j<quequ2.size();j++)
        {
            queque1[j]=quequ2[i];
            i++;
        }*/
        int contador=0;
        cout<<"tamano de queque1"<<queque1.size()<<endl;
        while (queque1.size()!= 0 && contador < queque1.size() )
        {
            cout<<"2"<<endl;
            //queque1.push_back(L);
            L=queque1[contador];
            int j=0;
            while (L.size()!=0 && j<L.size())
            {
                cout<<"3"<<endl;
                //L.push_back(lista);
                string S=L[j]; //string A
                string temp_cad="";
                ///palabra
                for(int p=0;p<S.size();p++)
                {
                    cout<<"4"<<endl;
                    if( Q[S[p]%97].size()==0 )
                    {
                        temp_cad=temp_cad+S[p];
                        Q[S[p]%97]=S;
                    }
                }
                NONEMTY.push_back(temp_cad);
                j++;
            }

            cout<<"tamano el noempty "<<NONEMTY.size()<<endl;

            for (int r=0;r<NONEMTY.size();r++)
            {
                if(NONEMTY[r].size()>1)
                {
                    vector<string> lista;
                    lista.push_back(NONEMTY[r]);
                    quequ2.push_back(lista) ;
                }
            }

            for (int y=0;y<NONEMTY.size();y++)
            {
                if(NONEMTY[y].size()==1)
                   NONEMTY.erase(NONEMTY.begin()+y+1,NONEMTY.begin()+y+2);
            }

            for(int t=0;t<27;t++)
            {
                //if(Q[t]!="")
                    LEQUAL.push_back(Q[t]);
            }
            contador++;
            //cout<<"contador"<<contador<<endl;
        }
        contador_queque2++;
        break;
    }while(contador_queque2 < quequ2.size());
    cout<<"imprimiendo de veras "<<endl;
    for(int i=0;i<LEQUAL.size();i++)
    {
        if(LEQUAL[i]!= "")
            cout<<LEQUAL[i]<<endl;
    }

}

/////////////////////////////////7
class lista_AB;

class estado{
public:
    estado(char caracter1,bool is_estado_final){
        this->caracter=caracter1;
        this->ptro=0;
        this->lista_e=0;
        this->haylista_e=is_estado_final;
        this->estado_final=is_estado_final;
    }

    bool get_haylista_e()
    {
        return haylista_e;
    }
    char get_caracter()
    {
        return caracter;
    }

    bool get_estado_final()
    {
        return estado_final;
    }

    void set_estado_final(bool estado2)
    {
        this->estado_final=estado2;
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
    char caracter;
    estado * ptro;
    lista_AB * lista_e;
    bool haylista_e;
    bool estado_final;
};

class lista_AB{
public:
    lista_AB()
    {
        this->lista[27]={0};
        this->indices[27];//={0};

        next_l=0;
    }

    bool buscar_c(char caracter)
    {
        if(indices[caracter%97]== 1)
        {
            return true;
        }

        return false;
    }
    estado * add_lista(char caracter,bool is_estado_fn)
    {
        if(!buscar_c(caracter))
        {
            estado * nuevo=new estado(caracter,is_estado_fn);
            lista[caracter%97]=nuevo;
            indices[caracter%97]=1;
            return nuevo;
        }
        if(lista[caracter%97]->get_estado_final() != true)
            lista[caracter%97]->set_estado_final(is_estado_fn);
        return lista[caracter%97];

    }

    estado * add_lista_final(char caracter)
    {
        if(!buscar_c(caracter))
        {
            estado * nuevo=new estado(caracter,true);
            lista[caracter%97]=nuevo;
            indices[caracter%97]=1;
            return nuevo;
        }
         lista[caracter%97]->set_estado_final(true);
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

    int get_height()
    {
        return height;
    }

    void set_height(int height1)
    {
        this->height=height1;
    }

    estado * lista[27]={0};
    int  indices[27]={0};
private:
    int tpagina=27;
    lista_AB * next_l;
     int height ;

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
    void imprime(lista_AB * cp_head_l,vector<vector< estado> > palabras_arbol,vector<estado> lista_estado);
    lista_AB * get_lista()
    {
        return head_l;
    }

    void height_arbol( lista_AB * cp_head_l ,int & count_height,vector< vector<estado> > grupopi);


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
    bool is_estado_final=false;

    if(head_l == 0)
    {
        cphead=nuevo_lista->add_lista(palabra[i],is_estado_final);
        this->head_l=nuevo_lista;
        cpheal_lista=nuevo_lista;
    }
    else
    {
         cphead=head_l->add_lista(palabra[i],is_estado_final);
    }

    i++;

    for(;i<palabra.size();i++)
    {
        //cout<<"cphead"<<cphead<<endl;
        nuevo_lista=new lista_AB;
        if(i+1== palabra.size())
            {is_estado_final=true;
            }
        if( cphead->get_lista_e() == 0  )
        {
            estado * cpestado=nuevo_lista->add_lista(palabra[i],is_estado_final);
            cphead->set_lista_e(nuevo_lista);
            cphead=cpestado;
            cpheal_lista=nuevo_lista;
            //cout<<cphead<<endl;
            //cout<<" "<<palabra[i]<<endl;
        }
        else{
            cphead=cphead->get_lista_e()->add_lista(palabra[i],is_estado_final);

        }
    }

}

void arbolB :: imprime(lista_AB * cp_head_l,vector<vector< estado> > palabras_arbol,vector< estado> lista_estado)
{

    if(cp_head_l==0)
        return;
    //cout<<cp_head_l->lista[4]->get_caracter()<<endl;
    //cout<<"esto es dvd"<<endl;
    for(int i=0;i<27;i++)
    {
        if(cp_head_l->lista[i]!=0 )
        {
            cout<<cp_head_l->lista[i]->get_caracter()<<"  es estado "<<cp_head_l->lista[i]->get_estado_final()<<"altura"<<cp_head_l->get_height()<<endl;
            //cout<<"i"<<i;

            lista_AB * cp_head_l2=cp_head_l->lista[i]->get_lista_e();
            imprime(cp_head_l2,palabras_arbol,lista_estado );
            estado  estado_actual=*(cp_head_l->lista[i]);
            lista_estado.push_back(estado_actual);
        }
        if(cp_head_l->lista[i]->get_lista_e() )
        {
            palabras_arbol.push_back(lista_estado);
        }
        if(cp_head_l== cp_head_l)
        {
            //aca hay problemas
            ///lista_estado.resize(0);
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
            cout<<cp_head_l->lista[i]->get_caracter()<<"  es estado "<<cp_head_l->lista[i]->get_estado_final()<<"altura"<<cp_head_l->get_height()<<endl;
            //cout<<"i"<<i;

            lista_AB * cp_head_l2=cp_head_l->lista[i]->get_lista_e();
            imprime( cp_head_l2);

        }
    }
}




void arbolB :: height_arbol( lista_AB * cp_head_l,int & count_height ,vector<vector<estado>>grupopi )
{
    if(cp_head_l==0)
        return;

    for(int i=0;i<27;i++)
    {
        if(cp_head_l->lista[i]!=0 )
        {
            //cout<<cp_head_l->lista[i]->get_caracter()<<"es estado "<<cp_head_l->lista[i]->get_estado_final()<<endl;
            //cout<<"i"<<i;
            if(cp_head_l==head_l)
            {
             head_l->set_height(count_height);
             count_height++;
            }

            lista_AB * cp_head_l2=cp_head_l->lista[i]->get_lista_e();
            height_arbol( cp_head_l2,count_height, grupopi);
            if(cp_head_l2 !=0 )
            {
             cp_head_l2->set_height(count_height);
             count_height++;
            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;

    arbolB prueba;
    prueba.add_arbol("erika");
    prueba.add_arbol("eriko");
    prueba.add_arbol("erikoto");
    prueba.add_arbol("hp");

    int altura=0;
    vector<vector<estado>>grupopi ;
    prueba.height_arbol(prueba.get_lista(),altura,grupopi);

    prueba.imprime(prueba.get_lista());
    return 0;
}

