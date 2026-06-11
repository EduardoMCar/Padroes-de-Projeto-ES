#include <iostream>
using namespace std;
    
class Condominio{
    private:
        string cnpj;
        string nomeFantasia;
        string razaoSocial;
        string telefone;
        int numAptos;

        // O Construtor privado, com os capos ja todos pré-setados, 
        // evitando assim o novos instânciamentos.
        Condominio(){
            cnpj = "73.564.394/0001-84";
            nomeFantasia = "Parispozinho";
            razaoSocial = "Prediário LTDA";
            telefone = "(18) 2131-1132";
            numAptos = 35;

            cout << "\n--[Instancia unica criada]--\n" << endl;
        }

        //Bloqueia a construção por cópia ( Condominio c3 = c2; ) 
        // e passagem por valor.
        Condominio(const Condominio&) = delete;

    public:

        // metodo estatico, evidente que pertence a classe não a um objeto;
        // do tipo referência para o objeto, assim retornando o endereço de 
        // memória da instância; a instância estatica de Condominio é criada 
        // apenas na primeira chamada da função e morre junto do programa
        static Condominio& getInstance(){
            static Condominio instancia;
            return instancia;
        }
        
        //Apenas print dos dados do singleton
        void verDados(){
            cout << "\n--Dados do condominio--"
                << "\nCNPJ:" << cnpj
                << "\nNome Fantasia:" << nomeFantasia
                << "\nRasão Social:" << razaoSocial
                << "\nTelefone:" << telefone
                << "\nNumero de Aptos:" << numAptos
                << "\n------------------" << endl;
        }

        // metodo pra testar mudança do campo
        void setNome(const std::string& novoNome) { 
            nomeFantasia = novoNome; }
};

int main(){
    // pegando a instância
    Condominio& c1 = Condominio::getInstance();

    // Mostra os dados
    c1.verDados();

    // Tentando obter outra instância
    Condominio& c2 = Condominio::getInstance();

    //testando a mudança do campo
    c1.setNome("teste de mudanca");

    // Conferindo se soã os mesmo dados
    c1.verDados();
    c2.verDados();

    // Vendo se é o mesmo objeto
    if(&c1 == &c2){
        cout << "c1 e c2 apontam para a MESMA instancia" << endl;
    } else {
        cout << "sao diferentes" << endl;
    }
    
    //--Bloqueados por criarem nova instâncias-- {
    // Condominio c3 = c2;
    // GerenciadorCondominio g3;
    // Condominio c3;
    // Condominio* c3 = new Condominio; }
    
    return 0;
}