#include <iostream>
using namespace std;

// ----- [ Implementação Observer pt1] ----- {
    class Observer{
        public:
            //metodo virtual obrigatório ser sobrescrito pras classes q herdarem
            virtual void notificar(string chamada) = 0;
    };

    //Calsse Aparteamento que herda o Observer
    class Apartamento : public Observer{
        private:
            int numero;
            string nomeMorador;
        public:
            //metodos comuns pra utilização da classe
            Apartamento(int apto, string nome) : numero(apto), nomeMorador(nome) {}
            int getApto(){return this->numero;}

            //implementação do metodo herdado, e verificado pelo override
            void notificar(string encomenda) override{
                cout << "\n -[NOTIFICACAO] Nova encomenda -"
                    << "\n  Morador: " << this->nomeMorador
                    << "\n  Apartamento: " << this->numero
                    << "\n  Encomenda: " << encomenda
                    << endl;
            }
    };
//}

// ----- [ Implementação Singleton ] ----- {

    class Condominio{
        private:
            string cnpj;
            string nomeFantasia;
            string razaoSocial;
            string telefone;
            int numAptos;
            Apartamento* aptos[10];


            // O Construtor privado, com os capos ja todos pré-setados, 
            // evitando assim o novos instânciamentos.
            Condominio(){
                cnpj = "73.564.394/0001-84";
                nomeFantasia = "Parispozinho";
                razaoSocial = "Prediário LTDA";
                telefone = "(18) 2131-1132";
                numAptos = 0;
                
                cout << "\n--[Instancia unica criada]--\n" << endl;
            }

            // Destrutor pra deletar os aptos dinamicos
            ~Condominio(){
                for(int i = 0; i < numAptos; i++){
                    delete this->aptos[i];
                }
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
                nomeFantasia = novoNome;
            }

            //adiciona um novo apto
            void addApto(int num, string nome){
                this->aptos[numAptos] = new Apartamento(num, nome);
                numAptos++;
                cout << "-[ Apartamento Adicionado ]-\n";
            }

            // ----- [ Implementação Observer pt2] ----- {
                //metodo acha o apto no array, aciona o metodo implementado pela
                //classe Apartamento que foi herdado do Observer
                void novaEncomenda(int apto, string encomenda){
                    cout << "\n -[Portaria]: nova encomenda-\n";
                    for(int i = 0; i < numAptos; i++){
                        if(this->aptos[i]->getApto() == apto)
                            this->aptos[i]->notificar(encomenda);
                    }
                }
            //}
    };
//}

// ----- [ Implementação Facade ] ----- {
    
    //---Subsistemas
    class Portaria{
        public:
            void acessarCamera(){
                cout << "[ Camera portao ]\n";
            }
            void abrirPortão(){
                cout << "[ Abrindo portao ]\n";
            }
            void FecharPortão(){
                cout << "[ fechando portao ]\n";
            }
    };
    
    class Garagem{
        public:
            void abrirGaragem(){
                cout << "[ Abrindo garagem ]\n";
            }
            void FecharGaragem(){
                cout << "[ fechando garagem ]\n";
            }
    };

    class Seguranca{
        public:
            void ligarCameras(){
                cout << "[ Cameras ligadas ]\n";
            }
            void desligarCameras(){
                cout << "[ Cameras desligadas ]\n";
            }
            void ligarAlarme(){
                cout << "[ Alarmes ligados ]\n";
            }
            void desligarAlarme(){
                cout << "[ Alarmes desligados ]\n";
            }
            void travarSaidas(){
                cout << "[ Predio trancados ]\n";
            }

    };
    
    //---Facade em si
    class condominioFacade{
        private:
            Portaria portaria;
            Garagem garagem;
            Seguranca seguranca;

        public:
            void moradorEntrada(){
                portaria.acessarCamera();

                cout << "-[ Morador identificado ]-\n";

                portaria.abrirPortão();
                portaria.FecharPortão();
            }
            void moradorCarro(){
                portaria.acessarCamera();

                cout << "-[ Carro de morador identificado ]-\n";

                garagem.abrirGaragem();
                garagem.FecharGaragem();
            }
            void modoNoite(){
                cout << "-[ Modo noite ]-\n";

                seguranca.ligarCameras();
                seguranca.ligarAlarme();

            }

            void modoLockdown(){
                cout << "- Predio invadido [Botao Panico]-\n";

                seguranca.travarSaidas();
                seguranca.ligarCameras();
                garagem.FecharGaragem();
                portaria.acessarCamera();

                cout << "-[ Policia a caminho ]-\n";
            }
    };

//}

int main(){

// ----- [ Singleton ] ----- {
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
//}

// ----- [ Facade ] ----- {
    condominioFacade sist;
    cout << endl;
    sist.moradorEntrada();
    cout << endl;
    sist.moradorCarro();
    cout << endl;
    sist.modoNoite();
    cout << endl;
    sist.modoLockdown();

//}

// ----- [ Observer ] ----- {
    //Ciando o aptos para testar o Observer
    c2.addApto(101, "Eduardo");
    cout << endl;
    c2.addApto(202, "Wiese");
    cout << endl;

    //Testando notificação
    c2.novaEncomenda(101,"Teclado mecanico");
    cout << endl;;
    c2.novaEncomenda(202,"Notebook");
    cout << endl;
//}

    return 0;
}