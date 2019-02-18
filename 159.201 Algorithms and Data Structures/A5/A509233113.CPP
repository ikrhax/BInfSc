/*
***********************************
*                                 *
*     159.201 - Assignment 5      *	
*	       Simon Parr 		       *
*          09233113               *
*                                 *
***********************************
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>

/*
Tree class and method definitions.
*/
 

class Tree
{
public:
    Tree(char, Tree*, Tree*);
    ~Tree() {}
    char rootData() { return data; }
    Tree* left() { return leftPtr; }
    Tree* right() { return rightPtr; }
private:
    char data;
    Tree* leftPtr;
    Tree* rightPtr;
};


Tree::Tree(char _data, Tree* L, Tree* R)
{
    data = _data;
    leftPtr = L;
    rightPtr = R;
}


/*
Global validation and output functions.
*/

bool inputIsValid(const int);
Tree* generateTree(std::ifstream&);

/*
Print a tree using in-fix notation.
*/
void inOrder(Tree*);

/*
Print a tree using post-fix notation.
*/
void postOrder(Tree*);

int main(int argc, char** argv)
{
    if (!inputIsValid(argc))
    {
        std::cout << "The program needs a filename as argument." << std::endl;
        exit(0);
    }
    std::ifstream inFile;
    inFile.open(argv[1]);
    //! For debug
    //! inFile.open("RPN2.txt");
    Tree* T = generateTree(inFile);
    std::cout << "In-fix:\n";
    inOrder(T);
    std::cout << "\nPost-fix:\n";
    postOrder(T);
    std::cout << std::endl;
    return 0;
}

bool inputIsValid(const int args)
{
    return args == 2;
}

Tree* generateTree(std::ifstream& inFile)
{
    std::stack<Tree*> S;
    Tree *T1, *T2;
    char expression[100];
    while (inFile >> expression)
    {
        if (isdigit(expression[0]))
        {
            char digit;
            sscanf(expression, "%c", &digit);
            S.push(new Tree(digit, NULL, NULL));
        }
        else
        {
            char oper;
            sscanf(expression, "%c", &oper);
            T1 = S.top();
            S.pop();
            T2 = S.top();
            S.pop();
            S.push(new Tree(oper, T2, T1));
        }
    }
    return S.top();
}

void inOrder(Tree* T)
{
    if (T == NULL)
    {
        return;
    }
    else if (T->left() != NULL && T->right() != NULL)
    {
        std::cout << "(";
    }
	 
    inOrder(T->left());
    std::cout << T->rootData();
    inOrder(T->right());
	 
    if (T->left() != NULL && T->right() != NULL)
    {
        std::cout << ")";
    }
    return;
}





void postOrder(Tree* T)
{
    if (T == NULL)
    {
        return;
    }
    postOrder(T->left());
    postOrder(T->right());
    std::cout << T->rootData() << " ";
    return;
}