#include <iostream>
#include <vector>
using namespace std;
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
int main()
{
    /*
    vector<int> lista2;
    lista2.push_back(1);
    lista2.push_back(4);
    //for(int i=0;i<lista2.size();i++)
    //{}
    lista2.erase(lista2.begin()+1,lista2.begin()+2);

    for(int i=0;i<lista2.size();i++)
    {
        cout<<lista2[i]<<endl;
    }*/

    vector<string> lista2;
    /*
    lista2.push_back("marias");
    lista2.push_back("marcos");
    lista2.push_back("erikas");*/
    lista2.push_back("nicols");
    lista2.push_back("nicolas");

    funcionlexicograma(lista2);
//    NONEMTY.erase(NONEMTY.begin()+r-1,NONEMTY.begin()+r)
    cout << "Hello world!" << endl;
    return 0;
}
