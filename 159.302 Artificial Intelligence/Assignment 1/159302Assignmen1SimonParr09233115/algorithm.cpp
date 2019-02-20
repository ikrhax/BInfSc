#include "algorithm.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search 
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime)
{
    string path;
    clock_t startTime;
    //add necessary variables here

    //algorithm implementation
    // cout << "------------------------------" << endl;
    //    cout << "<<breadthFirstSearch>>" << endl;
    //    cout << "------------------------------" << endl;

    startTime = clock();

    numOfStateExpansions = 0; /*number of expansion is 0 at the begining*/
    maxQLength = 1; /*Max Q length is 1 at the begining(initial state)*/
    int currentQLength = 1; /*Used to keep track of currentQLength. If currentQ is greater than maxQ, set maxQ as currentQ*/

    Queue *myQueue = new Queue();
    Puzzle *initial = new Puzzle(initialState, goalState);

    set<int> tempSet;
    initial->setPreviousStates(tempSet);
    myQueue->join(initial);

    try
    {
        while (!myQueue->isEmpty())
        {
            numOfStateExpansions++;
            Puzzle *front = myQueue->frontPuzzle();
            currentQLength--;
            /*check the goal*/
            if (front->goalMatch())
            {
                break;
            }

            if (front->canMoveUp())
            {
                Puzzle *temp = front->moveUp();
                //avoid local loop
                if (!front->isLocalLoop(temp->toNumber()))
                {
                    temp->setPreviousStates(front->getPreviousStates());
                    myQueue->join(temp);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
                else
                {
                    delete temp;
                }
            }
            if (front->canMoveDown())
            {
                Puzzle *temp = front->moveDown();
                if (!front->isLocalLoop(temp->toNumber()))
                {
                    temp->setPreviousStates(front->getPreviousStates());
                    myQueue->join(temp);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
                else
                {
                    delete temp;
                }
            }
            if (front->canMoveLeft())
            {
                Puzzle *temp = front->moveLeft();
                /*avoid local loop*/
                if (!front->isLocalLoop(temp->toNumber()))
                {
                    temp->setPreviousStates(front->getPreviousStates());
                    myQueue->join(temp);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
                else
                {
                    delete temp;
                }
            }
            /*check if the blank tile can move right*/
            if (front->canMoveRight())
            {
                Puzzle *temp = front->moveRight();
                /*avoid local loop*/
                if (!front->isLocalLoop(temp->toNumber()))
                {
                    temp->setPreviousStates(front->getPreviousStates());
                    myQueue->join(temp);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
                else
                {
                    delete temp;
                }
            }
            /*First element expanded, remove from queue*/
            myQueue->leave();
        }
    }
    catch (exception &e)
    {
        actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
        delete myQueue;
        cout << "Error occur. Out of memory !" << endl;
        return NULL;
    }

//***********************************************************************************************************
    actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
    if (!myQueue->isEmpty())
    {
        path = myQueue->frontPuzzle()->getPath();
    }
    else
    {
        path = "";
    }

    delete myQueue;
    return path;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search with VisitedList
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch_with_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength,
        float &actualRunningTime)
{
    string path;
    clock_t startTime;
    //add necessary variables here

    //algorithm implementation
    // cout << "------------------------------" << endl;
    //    cout << "<<breadthFirstSearch_with_VisitedList>>" << endl;
    //    cout << "------------------------------" << endl;

    startTime = clock();

    numOfStateExpansions = 0; /*number of expansion is 0 at the begining*/
    maxQLength = 1;/*Max Q length is 1 at the begining(initial state)*/
    int currentQLength = 1; /*Used to keep track of currentQLength. If currentQ is greater than maxQ, set maxQ as currentQ*/

    /*Generate a visited list*/
    VisitedList visited;
    /*Add the initial state to the visited list*/
    Puzzle *initialPuzzle = new Puzzle(initialState, goalState);

    Queue *myQueue = new Queue();
    myQueue->join(initialPuzzle);
    addToList(visited, initialPuzzle->toNumber());
    try
    {
        while (!myQueue->isEmpty())
        {
            numOfStateExpansions++;
            Puzzle *temp = myQueue->frontPuzzle();
            currentQLength--;
            /*goal check*/
            if (temp->goalMatch())
            {
                break;
            }

            if (temp->canMoveUp())
            {

                int num = temp->moveUp()->toNumber();
                if (!isVisited(visited, num))
                {
                    myQueue->join(temp->moveUp());
                    addToList(visited, num);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
            }

            if (temp->canMoveDown())
            {

                int num = temp->moveDown()->toNumber();
                if (!isVisited(visited, num))
                {
                    myQueue->join(temp->moveDown());
                    addToList(visited, num);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
            }

            if (temp->canMoveLeft())
            {
                int num = temp->moveLeft()->toNumber();
                if (!isVisited(visited, num))
                {
                    myQueue->join(temp->moveLeft());
                    addToList(visited, num);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
            }

            if (temp->canMoveRight())
            {
                int num = temp->moveRight()->toNumber();
                if (!isVisited(visited, num))
                {
                    myQueue->join(temp->moveRight());
                    addToList(visited, num);
                    currentQLength++;
                    if (currentQLength > maxQLength)
                    {
                        maxQLength = currentQLength;
                    }
                }
            }

            myQueue->leave();
        }
    }
    catch (exception &e)
    {
        actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
        cout << "Error occur. Out of memory !" << endl;
        delete myQueue;
        return NULL;
    }

//***********************************************************************************************************
    actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
    if (!myQueue->isEmpty())
    {
        path = myQueue->frontPuzzle()->getPath();
    }
    else
    {
        path = "";
    }

    delete myQueue;
    return path;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength,
        float &actualRunningTime, int ultimateMaxDepth)
{
    string path;
    clock_t startTime;
    //add necessary variables here

    //algorithm implementation
    // cout << "------------------------------" << endl;
    //    cout << "<<progressiveDeepeningSearch_No_VisitedList>>" << endl;
    //    cout << "------------------------------" << endl;

    startTime = clock();

    numOfStateExpansions = 0;
    maxQLength = 1;
    int currentQLength = 1;
    Stack *myStack = new Stack();
    Puzzle* initialPuzzle = new Puzzle(initialState, goalState);
    int maxDepth = 3;

    set<int> tempSet;
    initialPuzzle->setPreviousStates(tempSet);
    initialPuzzle->setDepth(0);
    myStack->push(initialPuzzle);

    while (maxDepth <= 30)
    {
        Puzzle *puzzle = myStack->Top();
        numOfStateExpansions++;
        myStack->pop();
        currentQLength--;
        if (puzzle->goalMatch())
        {
            path = puzzle->getPath();
            break;
        }

        if (puzzle->canMoveUp(maxDepth))
        {
            Puzzle *newPuzzle = puzzle->moveUp();
            if (!puzzle->isLocalLoop(newPuzzle->toNumber()))
            {
                newPuzzle->setDepth(puzzle->getDepth() + 1);
                newPuzzle->setPreviousStates(puzzle->getPreviousStates());
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (puzzle->canMoveDown(maxDepth))
        {
            Puzzle *newPuzzle = puzzle->moveDown();
            if (!puzzle->isLocalLoop(newPuzzle->toNumber()))
            {

                newPuzzle->setDepth(puzzle->getDepth() + 1);
                newPuzzle->setPreviousStates(puzzle->getPreviousStates());
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }
        if (puzzle->canMoveLeft(maxDepth))
        {
            Puzzle *newPuzzle = puzzle->moveLeft();
            // check local loop
            if (!puzzle->isLocalLoop(newPuzzle->toNumber()))
            {
                newPuzzle->setDepth(puzzle->getDepth() + 1);
                newPuzzle->setPreviousStates(puzzle->getPreviousStates());
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (puzzle->canMoveRight(maxDepth))
        {
            Puzzle *newPuzzle = puzzle->moveRight();
            if (!puzzle->isLocalLoop(newPuzzle->toNumber()))
            {
                newPuzzle->setDepth(puzzle->getDepth() + 1);
                newPuzzle->setPreviousStates(puzzle->getPreviousStates());
                /*push to the stack*/
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (myStack->isEmpty())
        {
            delete puzzle;
            maxDepth += 1;
            if (maxDepth <= 30)
            {
                currentQLength = 1;
                numOfStateExpansions = 0;
            }
            Puzzle* initialPuzzle = new Puzzle(initialState, goalState);
            set<int> tempSet;
            initialPuzzle->setPreviousStates(tempSet);
            initialPuzzle->setDepth(0);
            myStack->push(initialPuzzle);
            continue;
        }
        delete puzzle;
    }
//***********************************************************************************************************
    actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
    delete myStack;
    return path;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_with_NonStrict_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength,
        float &actualRunningTime, int ultimateMaxDepth)
{
    string path;
    clock_t startTime;
    //add necessary variables here

    //algorithm implementation
    // cout << "------------------------------" << endl;
    //    cout << "<<progressiveDeepeningSearch_with_NonStrict_VisitedList>>" << endl;
    //    cout << "------------------------------" << endl;

    startTime = clock();
    numOfStateExpansions = 0;
    maxQLength = 1;
    int currentQLength = 1;

    int maxDepth = 3;
    Stack *myStack = new Stack();
    Puzzle* initialPuzzle = new Puzzle(initialState, goalState);
    initialPuzzle->setDepth(0);
    myStack->push(initialPuzzle);

    NonStrictList visited;
    addToNonStrictList(visited, initialPuzzle->toNumber(), initialPuzzle->getDepth());

    //algorithm starts
    while (maxDepth <= 30)
    {
        Puzzle *puzzle = myStack->Top();
        myStack->pop();

        numOfStateExpansions++;
        currentQLength--;

        if (puzzle->goalMatch())
        {
            path = puzzle->getPath();
            break;
        }

        //check if depthlevel
        if (puzzle->canMoveUp(maxDepth))
        {

            Puzzle *newPuzzle = puzzle->moveUp();
            newPuzzle->setDepth(puzzle->getDepth() + 1);
            /*check visited list, if the state is not visited, the state will be added to both stack the visited list*/
            if (!isVisitedNonStrict(visited, newPuzzle->toNumber(), newPuzzle->getDepth()))
            {
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (puzzle->canMoveDown(maxDepth))
        {

            Puzzle *newPuzzle = puzzle->moveDown();
            newPuzzle->setDepth(puzzle->getDepth() + 1);
            if (!isVisitedNonStrict(visited, newPuzzle->toNumber(), newPuzzle->getDepth()))
            {
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (puzzle->canMoveLeft(maxDepth))
        {
            Puzzle *newPuzzle = puzzle->moveLeft();
            newPuzzle->setDepth(puzzle->getDepth() + 1);
            if (!isVisitedNonStrict(visited, newPuzzle->toNumber(), newPuzzle->getDepth()))
            {
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (puzzle->canMoveRight(maxDepth))
        {
            Puzzle *newPuzzle = puzzle->moveRight();
            newPuzzle->setDepth(puzzle->getDepth() + 1);
            if (!isVisitedNonStrict(visited, newPuzzle->toNumber(), newPuzzle->getDepth()))
            {
                myStack->push(newPuzzle);
                currentQLength++;
                if (currentQLength > maxQLength)
                {
                    maxQLength = currentQLength;
                }
            }
            else
            {
                delete newPuzzle;
            }
        }

        if (myStack->isEmpty())
        {
            //cout << "Depth now " << maxDepth << "\n";
            delete puzzle;
            maxDepth += 1;
            if (maxDepth <= 30)
            {
                currentQLength = 1;
                numOfStateExpansions = 0;
            }
            Puzzle* initialPuzzle = new Puzzle(initialState, goalState);
            initialPuzzle->setDepth(0);
            myStack->push(initialPuzzle);
            NonStrictList temp;
            visited = temp;
            addToNonStrictList(visited, initialPuzzle->toNumber(), initialPuzzle->getDepth());

            continue;
        }
        delete puzzle;

    }
//***********************************************************************************************************
    actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
    delete myStack;
    return path;

}

string aStar_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime,
        int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic)
{

    string path;
    clock_t startTime;

    numOfDeletionsFromMiddleOfHeap = 0;
    numOfLocalLoopsAvoided = 0;
    numOfAttemptedNodeReExpansions = 0;

    // cout << "------------------------------" << endl;
    // cout << "<<aStar_ExpandedList>>" << endl;
    // cout << "------------------------------" << endl;
    actualRunningTime = 0.0;
    startTime = clock();
    numOfStateExpansions = 0;
    maxQLength = 1;
    int currentQLength = 1;
    Heap *myHeap = new Heap();
    VisitedList visited;
    Puzzle* initialPuzzle = new Puzzle(initialState, goalState);
    initialPuzzle->updateHCost(heuristic);
    initialPuzzle->updateFCost();
    set<int> tempSet;
    initialPuzzle->setPreviousStates(tempSet);
    myHeap->insertToHeap(initialPuzzle, numOfDeletionsFromMiddleOfHeap);

    try
    {
        while (myHeap->getLast() >= 0)
        {
            numOfStateExpansions++;
            Puzzle *front;

            myHeap->deleteHeapRoot(&front);

            int num = front->toNumber();
            addToList(visited, num);
            currentQLength--;

            if (front->goalMatch())
            {
                path = front->getPath();
                break;
            }

            if (front->canMoveUp())
            {
                Puzzle *temp = front->moveUp();
                temp->updateHCost(heuristic);
                temp->updateFCost();
                num = temp->toNumber();

                if (!isVisited(visited, num) && !front->isLocalLoop(num))
                {
                    if (myHeap->insertToHeap(temp, numOfDeletionsFromMiddleOfHeap))
                    {
                        temp->setPreviousStates(front->getPreviousStates());
                        currentQLength++;
                        if (currentQLength > maxQLength)
                        {
                            maxQLength = currentQLength;
                        }
                    }
                    else
                    {
                        delete temp;
                    }
                }
                else
                {
                    numOfAttemptedNodeReExpansions++;
                    delete temp;
                }
            }

            if (front->canMoveDown())
            {
                Puzzle *temp = front->moveDown();
                temp->updateHCost(heuristic);
                temp->updateFCost();
                num = temp->toNumber();
                if (!isVisited(visited, num) && !front->isLocalLoop(num))
                {
                    if (myHeap->insertToHeap(temp, numOfDeletionsFromMiddleOfHeap))
                    {
                        temp->setPreviousStates(front->getPreviousStates());
                        currentQLength++;
                        if (currentQLength > maxQLength)
                        {
                            maxQLength = currentQLength;
                        }
                    }
                    else
                    {
                        delete temp;
                    }

                }
                else
                {
                    numOfAttemptedNodeReExpansions++;
                    delete temp;
                }
            }

            if (front->canMoveLeft())
            {
                Puzzle *temp = front->moveLeft();
                temp->updateHCost(heuristic);
                temp->updateFCost();
                num = temp->toNumber();

                if (!isVisited(visited, num) && !front->isLocalLoop(num))
                {
                    if (myHeap->insertToHeap(temp, numOfDeletionsFromMiddleOfHeap))
                    {
                        temp->setPreviousStates(front->getPreviousStates());
                        currentQLength++;
                        if (currentQLength > maxQLength)
                        {
                            maxQLength = currentQLength;
                        }
                    }
                    else
                    {
                        delete temp;
                    }
                }
                else
                {
                    numOfAttemptedNodeReExpansions++;
                    delete temp;
                }
            }

            if (front->canMoveRight())
            {
                Puzzle *temp = front->moveRight();
                temp->updateHCost(heuristic);
                temp->updateFCost();

                /*get the number format of the state*/
                num = temp->toNumber();

                /*check if the state is not visited and if it is not a local loop*/
                if (!isVisited(visited, num) && !front->isLocalLoop(num))
                {
                    if (myHeap->insertToHeap(temp, numOfDeletionsFromMiddleOfHeap))
                    {
                        temp->setPreviousStates(front->getPreviousStates());
                        currentQLength++;
                        if (currentQLength > maxQLength)
                        {
                            maxQLength = currentQLength;
                        }
                    }
                    else
                    {
                        delete temp;
                    }
                }
                else
                {
                    numOfAttemptedNodeReExpansions++;
                    delete temp;
                }
            }
            delete front;
        }
    }
    catch (exception &e)
    {
        actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
        delete myHeap;
        cout << "Error occurs. Out of memory!" << endl;
        return NULL;
    }
//***********************************************************************************************************
    actualRunningTime = ((float) (clock() - startTime) / CLOCKS_PER_SEC);
    delete myHeap;
    return path;

}


// Define utility function
void addToList(struct VisitedList &myList, int data)
{
    myList.data.insert(data);
}

bool isVisited(struct VisitedList const &myList, int data)
{
    return (myList.data.find(data) != myList.data.end());
}

void addToNonStrictList(struct NonStrictList &myList, int state, int depthLevel)
{
    myList.data.insert(make_pair(state, depthLevel));
}

bool isVisitedNonStrict(struct NonStrictList &myList, int state, int depth)
{
    map<int, int>::iterator it = myList.data.find(state);
    if (it == myList.data.end())
    {
        // Not found
        addToNonStrictList(myList, state, depth);
        return false;
    }
    else
    {
        if (myList.data[state] <= depth)
        {
            return true;
        }
        else
        {
            myList.data[state] = depth;
            return false;
        }
    }
}
