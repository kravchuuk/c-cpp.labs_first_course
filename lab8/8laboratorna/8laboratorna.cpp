#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Node {
public:
    int re;
    int im;
    Node* previousNode;

    Node(int re, int im) {
        this->re = re; //присвоїв значеня змінних полям
        this->im = im;
        this->previousNode = NULL;  // немає попередньої ноди 
    }

    bool operator == (const Node& nodeToCompare) { //приймаю ноду з якою хочу порівняти
        return this->im == nodeToCompare.im && this->re == nodeToCompare.re; //вказівник на мій обєкт (THIS) порівнюю ноду з іншою нодою з означенням ім і ре
    }

    Node operator + (const Node& nodeToSummarize) {
        int newRe = this->re + nodeToSummarize.re;
        int newIm = this->im + nodeToSummarize.im;
        return Node(newRe, newIm);
    }

    friend ostream& operator << (ostream& out, const Node& node)
    {
        cout << "Re: " << node.re << "\t Im: " << node.im << endl;
        return out;
    }
};


class Stack {
private:
    int index(Node* nodeToSearch, Node* currentNode, int counter) { //посилання на ноду яку я збираюсь шукати,теперішня , рахівник індексу(сіреньким)
        if (nodeToSearch != currentNode) {
            counter++;
            return index(nodeToSearch, currentNode->previousNode, counter);  //карент->прівіус  ми викликаємо самі себе не від поточної ноди а від попередньої.
        }
        return counter;
    }

    Node* last(Node* currentNode) {
        if (currentNode->previousNode != NULL) {// якщо значення ноди яка стоїть перед нашою не дорівнює нулу ми викликаємо функцію ласт але не від поточної  ноди а від ноди яка стоїть перед поточною
            return last(currentNode->previousNode);   //рекурсія.
        }
        return currentNode;
    }

public:
    Node* topNode;

    Stack() {
        this->topNode = NULL;
    }

    void push(Node* node) {// приймає в себе ноду
        node->previousNode = topNode;//попередня нода буде посилатись на  ноду яка є попереду нової ноди буде самою верхнюю нодою яка була в сеткові до даного моменту
        this->topNode = node; //міняєм верхню ноду стека на яку зараз добавляєм
    }

    Node* pop() { // Node*( тип данних який вона вертає)
        Node* node = topNode;//ми сстоврюємо нову ноду чкій присвоюємо значення самої верхньої ноди в стеку.
        topNode = topNode->previousNode;//ми присвоюжмо свмій верхній ноді значення попередника.
        return node;//вертаємо саму верхню ноду.
    }

    Node* getLast() { //це тип данних який вертає функція getLast.
        return last(topNode);//ми ретурнемо значення яке аерне функція ласт.
    }

    int getIndex(Node* nodeToSearch) {//функція яка вертає ііндекс ноди починаючи зверху стеку.
        return index(nodeToSearch, topNode, 0);//topNode ми жо нього звертаємось щоб пройти по всьому стеку, початкове значення індексу 0
    }

    int getLenght() {
        return index(NULL, topNode, 0);//довжина стеку, нулл це значення тої ноди яка стоїть перед самою нижньою.  
    }

    Node getSumOfLastAndFirst() {
        Node* last = getLast();
        return *topNode + *last;
    }
};


int main() {
    Stack stack = Stack(); //нова змінна стек з мал. в якої буде тип данних Стек з ВЕЛИКОЇ присвоюєм їм значення які верне конструктор стеккк.
    Node node1 = Node(1, 2); //ми присвоїюмо ноді один значення яке верне конструктор ноди 
    Node node2 = Node(1, 3);
    Node node3 = Node(2, 5);
    Node node4 = Node(3, 7);
    Node yan5 = Node(4, 8);

    stack.push(&node1);
    stack.push(&node2);
    stack.push(&node3);
    stack.push(&node4);
   

    cout << "Lenght of stack:" << stack.getLenght() << endl;
    cout << "Index:" << stack.getIndex(&node2) << "\nIndex:" << stack.getIndex(&node4) << "\nIndex:" << stack.getIndex(&node3) << "\nIndex:" << stack.getIndex(&node1) <<endl;
    cout << stack.getSumOfLastAndFirst() << endl;

    return 0;
}