#include <bits/stdc++.h>

using namespace std;

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
                Head = It = P -> Next = P -> Prev = P;
            }
            else
            {
                P -> Prev = Head -> Prev;

                P -> Next = Head;

                (Head -> Prev) -> Next = P;

                Head -> Prev = P;

                Head = P;
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

            while (It != Head and (It -> D) != x)
            {
                It = It -> Next;
            }
            
            if ((It -> D) == x)
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

            if(!It)
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
};

template <typename dado>

class Lista_DE_Circular
{
    NodeLista <dado>* Head;

    NodeLista <dado>* it;

    int quantidadeNode;
   
    public:

        Lista_DE_Circular()
        {
            Head = NULL;
            it = NULL;

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

        bool push(dado d)
        {
            //adicionar na frente da lista
            it = NodeLista <dado> :: MontaNode(d);

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

        dado get()
        {
            return it -> Dado;
        }

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


class t
{
    public:

        Lista_Duplamente_Encadeada <string> a;
};

int main()
{
    Lista_DE_Circular < t > teste;

    t tt;

    tt.a.insert("01");
    tt.a.insert("02");

    tt.a.begin();
    cout << tt.a.get().second << endl;
    // teste.push(t);
}