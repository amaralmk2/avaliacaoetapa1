#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
    string cpf;
    string nome;
    string dt_nascimento;

public:
    Paciente(string _nome, string _cpf, string _dt_nascimento) : nome(_nome), cpf(_cpf), dt_nascimento(_dt_nascimento) {}

    string getNome() {
        return nome;
    }

    string getCpf() {
        return cpf;
    }

    string getDt_nascimento() {
        return dt_nascimento;
    }

    void setDt_nascimento(string _Dt_nascimento) {
        dt_nascimento = _Dt_nascimento;
    }

    void setCpf(string _cpf) {
        cpf = _cpf;
    }

    void setNome(string _nome) {
        nome = _nome;
    }

    static void ListarPacientes(vector<Paciente> &pacientes) {
    cout << "Listando pacientes..." << endl;

    for (int i = 0; i < pacientes.size(); i++) {
        cout << "Paciente " << i + 1 << endl;
        cout << pacientes[i].getNome() << endl;
        cout << pacientes[i].getCpf() << endl;
        cout << pacientes[i].getDt_nascimento() << endl;
        cout << " - - - - - - - - - - - - -" << endl;
    }
}

    static void editarPaciente(vector<Paciente> &pacientes){
         
         string aux_cpf,aux_nome,aux_dt_nascimento;
         int op2;

            cout << "Informe o paciente que deseja alterar pelo cpf";
            std::cin.ignore();
            getline(std::cin, aux_cpf);

            for (int i = 0; i < pacientes.size(); i++) {
                if (aux_cpf == pacientes[i].getCpf()) {
                    cout << pacientes[i].getNome()<< endl;
                    cout << pacientes[i].getCpf() << endl;
                    cout << pacientes[i].getDt_nascimento() << endl;

                    cout << "Deseja alterar o nome? (1-Sim/2-Nao)" << endl;
                    std::cin >> op2;
                
                    if(op2 == 1){
                        cout << "Digite o novo nome: " << endl;
                        std::cin.ignore();
                        getline(std::cin, aux_nome);
                        pacientes[i].setNome(aux_nome);
                    }

                    cout << "Deseja alterar a data de nascimento? (1-Sim/2-Nao)" << endl;
                    std::cin >> op2;

                    if(op2 == 1){
                        cout << "Digite a nova data de nascimento: " << endl;
                        std::cin.ignore();
                        getline(std::cin, aux_dt_nascimento);
                        pacientes[i].setDt_nascimento(aux_dt_nascimento);
                    }

                    cout << "Dados alterados com sucesso...";
                }
            }
    }


    


    static void incluirPaciente(vector<Paciente>&pacientes){
         string aux_nome, aux_cpf, aux_dt_nascimento;
         cout << "Informe o nome: " << endl;
            std::cin.ignore();
            getline(std::cin, aux_nome);

            cout << "Informe o cpf: " << endl;
            getline(std::cin, aux_cpf);

            cout << "Informe a data de Nascimento: ";
            getline(std::cin, aux_dt_nascimento);

            Paciente novoPaciente(aux_nome, aux_cpf, aux_dt_nascimento);
            pacientes.push_back(novoPaciente);
    }

    static void buscarApartirPacientes(vector<Paciente>&pacientes){
        string aux_cpf;
        bool aux_flag = false;

        cout << "Insira o cpf para buscar a pessoa" << endl;
        std::cin.ignore();
        getline(std::cin, aux_cpf);

        for(int i = 0;i < pacientes.size(); i++){
            if(pacientes[i].getCpf() == aux_cpf){
               cout << "Os dados do Paciente " << endl;
                cout << "Paciente: " << pacientes[i].getNome()<< endl;
                cout << "Cpf: " << pacientes[i].getCpf() << endl;
                cout << "Data Nascimento: " << pacientes[i].getDt_nascimento() << endl;
                aux_flag = true;
            }
        }if(aux_flag == false){
        cout << "cpf nao corresponde!" << endl;
        }
    }

  
};


int main() {
    vector<Paciente> pacientes;
    int op;
  
    
        
    do{
        cout << "---------Menu--------" << endl;
        cout << "1. Incluir paciente" << endl;
        cout << "2. Excluir Paciente" << endl;
        cout << "3. Alterar dados paciente" << endl;
        cout << "4. Listar pacientes" << endl;
        cout << "5. Buscar paciente especifico" << endl;
        cout << "0. Sair" << endl;
        std::cin >> op;

        if (op == 1) {
           Paciente::incluirPaciente(pacientes);
        }

        if (op == 2) {
           
        }
    
        
        if (op == 3) {
          Paciente::editarPaciente(pacientes);
        }

        if(op == 4){
            Paciente::ListarPacientes(pacientes);
        }

        if(op == 5){
           Paciente::buscarApartirPacientes(pacientes);
        }
 


    }while(op != 0);
}