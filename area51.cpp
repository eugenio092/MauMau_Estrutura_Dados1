#include <bits/stdc++.h>

using namespace std;

template <typename dado> 

class NodeStack
{
    public:

        dado D;

        NodeStack <dado>* Next;

        static NodeStack <dado>* MontaNode(dado d)
        {
            NodeStack <dado>* p = new NodeStack <dado>;

            if(p)
            {
                p -> D = d;

                p -> Next = NULL;
            }

            return p;
        }
        
        static void DesmontaNode(NodeStack <dado>* p)
        {
            delete p;
        }
};

template <typename dado> 

class Stack
{
    NodeStack <dado>* top;

    int quantNodes;

    public:

        Stack()
        {
            top = NULL;

            quantNodes = 0;
        }

        ~Stack()
        {
            NodeStack <dado>* P;

            while(top)
            {
                P = top;

                top = top -> Next;

                delete P;
            }
        }

        bool Push(dado d)
        {
            NodeStack <dado>* P = NodeStack <dado> :: MontaNode(d);

            if(P)
            {
                P -> Next = top;

                top = P;

                quantNodes++;

                return true; 
            }

            return false;
        }

        void Pop()
        {
            if(top)
            {
                NodeStack <dado>* P = top;
                
                top = top -> Next;

                delete P;

                quantNodes--;
            }
        }

        dado Top()
        {
            dado d;

            if(top)
            {
                d = top -> D;
            }

            return d;
        }

        bool Empty()
        {
            return !top;
        }

        int size()
        {
            return quantNodes;
        }

        void clear()
        {
            if(!top)
            {
                quantNodes = 0;

                return;
            }

            NodeStack <dado>* P = top;

            top = top -> Next;

            delete P;

            return clear();
        }
};

template <typename dado>

class NodeLista
{
    public:

        dado Dado;

        NodeLista <dado>* Prev;

        NodeLista <dado>* Next;

        static NodeLista <dado>* MontaNode(dado d)
        {
            NodeLista <dado>* P = new NodeLista <dado>;

            if(P)
            {
                P -> Next = P -> Prev = NULL;

                P -> Dado = d;
            }

            return P;
        }

        static void DesmontaNode(NodeLista <dado>* P)
        {
            delete P;
        }
};

template <typename dado>

class Lista_Duplamente_Encadeada
{
    int quantidadeNodes;

    NodeLista <dado>* Head;

    NodeLista <dado>* It;

    public:

        Lista_Duplamente_Encadeada()
        {   
            Head = It = NULL;

            quantidadeNodes = 0;
        }

        ~Lista_Duplamente_Encadeada()
        {
            NodeLista <dado>* current = Head;

            NodeLista <dado>* next = NULL;

            if(!current)
            {
                return;
            }

            do
            {
                next = current -> Next;
            } 
            while(current != Head);
            
        }

        bool insert(dado x)
        {
            NodeLista <dado>* P = NodeLista <dado> :: MontaNode(x);

            if (!P)
            {
                return false;
            }

            if (!Head)
            {
                Head = It = P;
            }
            else
            {
                P -> Prev = It;

                P -> Next = It -> Next;

                It -> Next = P;

                if(P -> Next)
                {
                    (P -> Next) -> Prev = P;
                    
                }
            }

            quantidadeNodes++;

            return true;
        }

        bool search(dado x)
        {
            if (!Head)
            {
                return false;
            }

            It = It -> Next;

            while (!It and (It -> Dado) != x)
            {
                It = It -> Next;
            }
            
            if ((It -> Dado) == x)
            {
                return true;
            }

            return false; 
        }

        bool empty()
        {
            return !Head;
        }

        void begin()
        {
            It = Head;
        }

        void operator++()
        {
            It = It -> Next;
        }

        pair<bool,dado> get()
        {
            dado x;
            
            // cout << It -> Dado << endl;

            if(It)
            {
                return {true, It -> Dado};
            }

            return {false, x};
        }

        void erase()
        {
            if (!Head)
            {
                return;
            }

            NodeLista <dado>* Aux = It;

            if (It -> Next != It)
            {
                (It -> Next) -> Prev = It -> Prev;

                (It -> Prev) -> Next = It -> Next;
            }
            else
            {
                Head = NULL;
            }

            if (Head == It)
            {
                Head = It = It -> Next;
            }
            else
            {
                It = It -> Next;
            }

            delete Aux;

            quantidadeNodes--;
        }

        int size()
        {
            return quantidadeNodes;
        }
        
        void all()
        {
            It = Head;
            
            while(It)
            {
                cout << It -> Dado << '\n';
                
                It = It -> Next;
            }
        }
};

template <typename dado>

class NodeListaCircular
{
    public:

        Lista_Duplamente_Encadeada <dado> mao;

        int idJogador;

        int pontuacao;

        NodeListaCircular <dado>* Prev;

        NodeListaCircular <dado>* Next;

        static NodeListaCircular <dado>* MontaNode(int id)
        {
            NodeListaCircular <dado>* P = new NodeListaCircular <dado>;

            if(P)
            {
                P -> Next = P -> Prev = NULL;

                P -> idJogador = id;

                P -> pontuacao = 0;
            }

            return P;
        }

        static void DesmontaNode(NodeListaCircular <dado>* P)
        {
            delete P;
        }
};


template <typename dado>

class Lista_DE_Circular
{
    public:

        NodeListaCircular <dado>* Head;

        NodeListaCircular <dado>* it;

        int quantidadeNode;

        Lista_DE_Circular()
        {
            Head = it = NULL;

            quantidadeNode = 0;
        }

        ~Lista_DE_Circular()
        {
            while(Head -> Prev != Head -> Next)
            {
                it = Head;

                (it -> Next) -> Prev = it -> Prev;

                (it -> Prev) -> Next = it -> Next;

                Head = Head -> Next;

                delete it;
            }

            delete it;
        }

        bool push(int id)
        {
            //adicionar na frente da lista
            it = NodeListaCircular <dado> :: MontaNode(id);

            if(!it)
            {
                //nao foi alocado dinamicamente
                return false;
            }

            if(!Head)
            {
                //nao ha elementos na lista
                it -> Prev = it -> Next = Head = it;
            }
            else
            {
                it -> Next = Head;

                it -> Prev = Head -> Prev;

                Head -> Prev = it;

                (it -> Prev) -> Next = it;

                Head = it;
            }

            quantidadeNode++;

            return true;
        }

        void pop()
        {
            if(Head)
            {
                //tem elementos na lista
                if(Head == Head -> Next)
                {
                    //tem somente um elemento na lista

                    delete it;

                    Head = it = NULL;

                    quantidadeNode = 0;
                }
                else
                {
                    (it -> Prev) -> Next = it -> Next;

                    (it -> Next) -> Prev = it -> Prev;

                    if(Head == it)
                    {
                        Head = it -> Next;
                    }

                    delete it;

                    it = Head;

                    quantidadeNode--;
                }
            }
        }

        // dado get()
        // {
        //     return it -> Dado;
        // }

        void operator++()
        {
            it = it -> Next;
        }

        void operator--()
        {
            it = it -> Prev;
        }

        void begin()
        {
            it = Head;
        }

        int size()
        {
            return quantidadeNode;
        }
        
        bool empty()
        {
            //verdadeiro se estiver vazia
            return !Head;
        }
};

template <typename dado>

class Jogo
{
    int numeroJogadores;

    Stack <dado> monte,
                 lixo;
                 
    bool sentido = true;
        // true -> horario
        // false -> anti-horario

    Lista_DE_Circular <dado> Jogadores;

    public:

        Jogo()
        {
            cin >> numeroJogadores;

            for(int i = 1; i <= numeroJogadores; i++)
            {
                Jogadores.push(i);
            }
        }

        void LeituraCartas()
        {
            string cartaAuxiliar;

            for(int i = 0; i < 104; i++)
            {
                cin >> cartaAuxiliar;

                monte.Push(cartaAuxiliar);
            }
        }

        void DistribuicaoCartas()
        {
            // no incio do jogo, cada jogador recebera 5 cartas

            Jogadores.begin();

            for(int i = 0; i < numeroJogadores; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    Jogadores.it->mao.insert(monte.Top());

                    monte.Pop();
                }

                ++Jogadores;
            }
        }

        void run()
        {
            LeituraCartas();
            
            Jogadores.begin();
            
            DistribuicaoCartas();
            
            while(Jogadores.size() > 1)
            {
               if(Jogadores.it->mao.empty())
                {
                    //final de uma partida, ou seja, um jogador não possuei cartas
                    int idJogadorSemCartas = Jogadores.it->idJogador;

                    do
                    {
                        cout << idJogadorSemCartas << '\n';

                        ++Jogadores;

                    } 
                    while (idJogadorSemCartas != Jogadores.it->idJogador);
                    
                    
                }
            }
        }
};

int main()
{
    Jogo <string> j;

    j.run();
}