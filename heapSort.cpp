#include <iostream>
#include <vector>

using namespace std;

void menu(){
    cout<<"+++++++++++++++++++++++++++++"<<endl;
    cout<<"+ 1.Mostra Vetor            +"<<endl;
    cout<<"+ 2.Verificar Pai/Filhos    +"<<endl;
    cout<<"+ 3.Ordenar Vetor Crescente +"<<endl;
    cout<<"+++++++++++++++++++++++++++++"<<endl;
}
void MostraVetor(vector<int> &v1){
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
}

void CorrigirVetor(vector<int> &v1, int pai, int *ordena){
    if(v1[pai*2+1]>v1[pai*2+2] && v1[pai*2+1]>v1[pai]){
        swap(v1[pai*2+1], v1[pai]);
        *ordena=0;
    }else{
        if(v1[pai*2+2]>v1[pai]){
            swap(v1[pai*2+2], v1[pai]);
            *ordena=0;
        }
    }
    
    if(pai!=0) CorrigirVetor(v1, (pai-=1), &*ordena);

}

void OrdenarMostra(vector<int> &v1, vector<int> &v2, int trocador){
    
    cout<<v1.size()<<"  ";
    vector<int>::iterator it = v1.begin();
    swap(*it, v1[v1.size()-1]);
    if(v1.size()==1){
        cout<<"aqui  "<<endl;
        v2.push_back(v1[trocador]);
        v1.pop_back();
        return;
    }
    
    v2.push_back(v1[trocador]);
    cout<<v1[v1.size()-1]<<"  ";
    v1.pop_back();
    cout<<v1[v1.size()-1]<<endl;
}

int main(){
    int i, inicio, ordena, caso, correto=0, aux, trocador;

    vector<int> v1={40, 90, 20, 10, 50, 70, 80}; 
    vector<int> v2;

    MostraVetor(v1);
    system("pause\n");
    

    for(;;){
        menu();
        cin>>caso;
        switch(caso){
            case 1:
                MostraVetor(v1);
            break;
            case 2:
                if(correto==1){
                    cout<<"Vetor ja esta corrigido!"<<endl;
                    break;
                }
                for(;;){
                    ordena=1;
                    CorrigirVetor(v1, inicio=v1.size()/2-1, &ordena);
                    if(ordena==1) break;
                }
                cout<<"Vetor Corrigido!"<<endl;
                correto=1;
            break;
            case 3:
                trocador=v1.size()-1;
                for(;;){
                    for(;;){
                        ordena=1;
                        CorrigirVetor(v1, inicio=v1.size()/2-1, &ordena);
                        if(ordena==1) break;
                    }
                    OrdenarMostra(v1, v2, trocador);
                    if(v1.size()==1) break;
                }
                cout<<"chegou"<<endl;
                // MostraVetor(v1);
                MostraVetor(v2);
                system("pause");
            break;
            case 6:
                exit(0);
            
        }

        
        


        // cout<<"Final!"<<endl;
        // system("pause");
    }

    return 0;
}
