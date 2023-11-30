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

class Node
{
    public:
    dado Dado;

    Node <dado>* Next;

    Node <dado>* Prev;

    static Node<dado> *MontaNo(dado d)
    {
        Node <dado>* p = new Node <dado>;

        if (p)
        {
            p -> Dado = d;

            p -> Next = p -> Prev = NULL;
        }
        return p;
    }
    static void DesmontaNo(Node <dado>* p)
    {
        delete p;
    }
};

template <typename dado>

class Lista_Duplamente_Encadeada
{
    Node <dado>* Head;

    Node <dado>* It;

    int quantidadeNodes;

    public:

        Lista_Duplamente_Encadeada()
        {
            Head = It = NULL;
            
            quantidadeNodes = 0;
        }

        ~Lista_Duplamente_Encadeada()
        {
            Node <dado>* P = Head;

            while(Head)
            {
                P = Head -> Next;

                delete Head;

                Head = P;

                quantidadeNodes--;
            }
        }

        bool push(dado d)
        {
            Node <dado>* P = Node <dado> :: MontaNo(d);

            if(!P)
            {
                return false;
            }

            if(!Head)
            {
                P -> Prev = P -> Next = Head = It = P;
            }
            else
            {
                P -> Prev = Head -> Prev;

                P -> Next = Head;

                (Head -> Prev) -> Next = P;
                
                Head -> Prev = P;
            }

            quantidadeNodes++;

            return true;
        }

        void erase()
        {
            if (Head)
            {
                if (Head == Head -> Next)
                {
                    delete It;

                    Head = It = NULL;

                    quantidadeNodes = 0;
                }
                else
                {
                    (It -> Prev) -> Next = It -> Next;

                    (It -> Next) -> Prev = It -> Prev;

                    if (Head == It)
                    {
                        Head = It -> Next;
                    }

                    delete It;

                    It = Head;

                    quantidadeNodes--;
                }
            }
        }

        int size()
        {
            return quantidadeNodes;
        }

        void begin()
        {
            It = Head;
        }

        dado get()
        {
            dado d;

            if(It)
            {
                d = It -> Dado;
            }

            return d;
        }

        void operator++()
        {
            if(It and It -> Next)
            {
                It = It -> Next;
            }
        }

        void operator--()
        {
            if(It and It -> Prev)
            {
                It = It -> Prev;
            }
            
        }

        void clear()
        {
            It = Head;

            while(It)
            {
                erase();

                if(It and It -> Next)
                {
                    It = It -> Next;
                }
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

        void all()
        {
            NodeListaCircular <dado>* P = it;
            
            it = it -> Next;

            while(P != it)
            {
                it->mao.clear();
            }
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

        int pontuacao(string c)
        {
            return c[0] - 64;
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
                    string aux = monte.Top();

                    Jogadores.it->pontuacao += pontuacao(aux);

                    Jogadores.it->mao.push(aux);

                    monte.Pop();
                }
                
                cout << "Id: " << Jogadores.it->idJogador << endl
                     << "Cartas: " << Jogadores.it->mao.size() << endl << endl;

                ++Jogadores;
            }
        }

        void run()
        {
            LeituraCartas();
            
            Jogadores.begin();
            
            DistribuicaoCartas();
            
            // while(Jogadores.size() > 1)
            // {
            //   if(Jogadores.it->mao.empty())
            //     {
            //         //final de uma partida, ou seja, um jogador não possuei cartas
            //         int idJogadorSemCartas = Jogadores.it->idJogador;

            //         pair <int, int> auxMaximo = {0, 0};
            //         // pontuação, id

            //         do
            //         {
            //             if(Jogadores.it->idJogador != idJogadorSemCartas and Jogadores.it->pontuacao > auxMaximo.first)
            //             {
            //                 auxMaximo = {Jogadores.it->pontuacao, Jogadores.it->idJogador};
            //             }

            //             ++Jogadores;

            //         } 
            //         while (idJogadorSemCartas != Jogadores.it->idJogador);

            //         while(Jogadores.it->idJogador != auxMaximo.second)
            //         {
            //             ++Jogadores;
            //         }
                    
            //         Jogadores.pop();

            //         do
            //         {
            //             if(Jogadores.it->idJogador != idJogadorSemCartas and Jogadores.it->pontuacao > auxMaximo.first)
            //             {
            //                 auxMaximo = {Jogadores.it->pontuacao, Jogadores.it->idJogador};
            //             }

            //             ++Jogadores;

            //         } 
            //         while (idJogadorSemCartas != Jogadores.it->idJogador);

            //         //recomeçar partida
            //         //      redistribuir as 5 cartas para os jogadores restantes
            //     }
            // }
        }
};

int main()
{
    Jogo <string> j;

    j.run();
}