#include <iostream>
#include <vector>

using namespace std;

void menu(){
    cout<<"+++++++++++++++++++++++++++++++"<<endl;
    cout<<"+ 1.Mostra Vetor              +"<<endl;
    cout<<"+ 2.Verificar Pai/Filhos      +"<<endl;
    cout<<"+ 3.Ordenar Vetor Crescente   +"<<endl;
    cout<<"+ 4.Ordenar Vetor Decrescente +"<<endl;
    cout<<"+ 5.Sair                      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++"<<endl;
}
void MostraVetor(vector<int> &v1){
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}

void CorrigirVetor(vector<int> &v1, int pai, int *ordena, int tam){
    int aux;
    if(v1.size()==1) return;
    if((pai*2+2)<=tam){
        if(v1[pai*2+1]>v1[pai*2+2] && v1[pai*2+1]>v1[pai]){
            aux=v1[pai];
            v1[pai]=v1[pai*2+1];
            v1[pai*2+1]=aux;
            *ordena=0;
        }else{
            if(v1[pai*2+2]>v1[pai]){
                aux=v1[pai];
                v1[pai]=v1[pai*2+2];
                v1[pai*2+2]=aux;
                *ordena=0;
            }
        }
    }else{
        if((pai*2+1)<=tam){
            if(v1[pai*2+1]>v1[pai]){
                aux=v1[pai];
                v1[pai]=v1[pai*2+1];
                v1[pai*2+1]=aux;
                *ordena=0;
            }
        }
    }
    
    if(pai!=0) CorrigirVetor(v1, (pai-=1), &*ordena, tam);
}

void Mudar(vector<int> &v1, vector<int> &v2, int aux){
    if(aux==0){
        for(int i=0; i<v2.size(); i++){
            v1.push_back(v2[i]);
        }
    }else{
        for(int i=(v2.size()-1); i>-1; i--){
            v1.push_back(v2[i]);
        }
    }
}

int main(){
    int inicio, ordena, caso, correto=0,tam, ordem=0;

    vector<int> v1={40, 90, 20, 10, 50, 70, 80}; 
    vector<int> v2;


    for(;;){
        menu();
        cin>>caso;
        inicio:
        switch(caso){
            case 1:
                cout<<"Vetor ";
                MostraVetor(v1);
                system("pause");
                system("cls");
            break;
            case 2:
                if(correto==1){
                    cout<<"Vetor ja esta corrigido!"<<endl;
                    break;
                }
                tam=v1.size();
                cout<<"vetor de tamanho "<<tam<<endl;
                cout<<"Vetor a ser corrigido: ";
                MostraVetor(v1);
                for(;;){
                    ordena=1;
                    CorrigirVetor(v1, inicio=v1.size()/2-1, &ordena,tam);
                    if(ordena==1) break;
                }
                cout<<"Vetor apos ser corrigido: ";
                MostraVetor(v1);
                cout<<"Vetor Corrigido com sucesso!"<<endl;
                correto=1;
                system("pause");
                system("cls");
            break;
            case 3:
                cout<<"Vetor a ser ordenado: ";
                MostraVetor(v1);
                for(;;){
                    if(v1.size()==0) break;
                    tam=v1.size();
                    for(;;){
                        ordena=1;
                        CorrigirVetor(v1, inicio=v1.size()/2-1, &ordena, tam);
                        if(ordena==1) break;
                    }
                    if(v1.size()==1){
                        v2.push_back(v1[0]);
                        v1.erase(v1.end() - 1);
                        break;
                    }
                    v2.push_back(v1[0]);
                    v1[0]=v1[v1.size()];
                    v1.erase(v1.end() - 1);

                }
                Mudar(v1, v2, ordem);
                cout<<"Vetor ordenado:      ";
                MostraVetor(v1);
                system("pause");
                system("cls");
            break;
            case 4:
                ordem=1;
                caso=3;
                goto inicio;
            break;
            case 5:
                exit(0);
            break;

            default:
                system("cls");
            break;
        }

    }

    return 0;
}