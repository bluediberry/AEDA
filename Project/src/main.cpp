

#include <iostream>
using namespace std;

int main() {
    
    int menu = 0;
    int cliente;
    
    while(menu != 4){
        while(true){
            cout << endl << "MENU INICIAL" << endl << endl;
            cout << "[1] Informações" << endl;
            cout << "[2] Registar" << endl;
            cout << "[3] Reservar campo" << endl;
            cout << "[4] Sair" << endl;
            
            cin >> menu;
            
            if(cin.fail()){
                cin.clear();
                cin.ignore('\n', 100);
            }
            
            switch(menu){
                case 1:
                    //menuInformacao();
                    break;
                case 2:
                    //Registar();
                    break;
                case 3:
                    //Reservar();
                    break;
                case 4:
                    exit(0);
                default:
                    return 0;
            }
            
        }
        
        
    }
    
    return 0;
}
