
#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "puzzle.h"


const heuristicFunction HEURISTIC_FUNCTION=manhattanDistance;


//Function prototypes
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth);
string progressiveDeepeningSearch_with_NonStrict_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth);

string breadthFirstSearch_with_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime);
string breadthFirstSearch(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime);

string aStar_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic);

#include <set>
#include <map>
#include <vector>


struct Node
{
        Puzzle* puzzle;
        Node *next;
};

struct VisitedList
{
        std::set<int> data;
};

struct NonStrictList
{
        std::map<int, int> data;
};

class Queue
{

    private:
        Node *front, *rear;
        int count; /*Keep track of the number of elements in queue*/

    public:

        /*Constructor*/
        Queue()
        {
            front = NULL;
            rear = NULL;
            count = 0;
        }

        /*Function that joins the new puzzle to the rear of the queue*/
        void join(Puzzle *newPuzzle)
        {
            Node *temp = new Node;
            temp->puzzle = newPuzzle;
            temp->next = NULL;
            if (rear != NULL)
            {
                rear->next = temp;
            }
            rear = temp;
            if (front == NULL)
            {
                front = temp;
            }
            count += 1;
        }

        /*Remove the first element of the queue*/
        void leave()
        {
            if (front == NULL)
            {
                return;
            }
            Node *temp = front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            delete temp->puzzle;
            delete temp;
            count -= 1;
        }

        /*Check if queue is empty. True if empty, false otherwise.*/
        bool isEmpty()
        {
            if (front == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /*Return the first(front) element of the queue*/
        Node *Front()
        {
            return front;
        }

        Puzzle * frontPuzzle()
        {
            return front->puzzle;
        }

};

class Stack
{
    private:
        Node * front;
    public:
        /*Constructor*/
        Stack()
        {
            front = NULL;
        }

        /*Put a new element at the top of the stack*/
        void push(Puzzle * newPuzzle)
        {
            Node *temp = new Node;
            temp->puzzle = newPuzzle;
            temp->next = front;
            front = temp;
        }

        /*Remove the top element of the stack*/
        void pop()
        {
            Node *temp = front;
            if (front != NULL)
            {
                front = front->next;
                delete temp;
            }

        }

        /*Return the top(first) element of the stack*/
        Puzzle* Top()
        {
            if (front != NULL)
            {
                return front->puzzle;
            }
            return NULL;
        }

        /*Check if stack is empty.*/
        bool isEmpty()
        {
            return (front == NULL);
        }

};

class Heap
{

    private:
        vector<Puzzle*> data;
        int last;

    public:

        Heap()
        {
            last = -1;
        }

        int getLast()
        {
            return last;
        }

        void printHeap()
        {
            for (int i = 0; i <= last; i++)
            {
                cout << data[i]->toNumber() << " " << data[i]->getFCost() << endl;
            }
        }

        //Function to check if there is a state that is the same as the new one but has smaller Fcost
        int hasSmallerCost(Puzzle *puzzle)
        {
            /*get the string representation of the state*/
            int state = puzzle->toNumber();
            int fcost = puzzle->getFCost();

            for (int i = 0; i <= last; i++)
            {
                if (data[i]->toNumber() == state)
                {
                    if (data[i]->getFCost() <= fcost)
                    {
                        return -1;
                    }
                    else if (data[i]->getFCost() > fcost)
                    {
                        return i;
                    }
                }

            }
            return -2;
        }

        bool insertToHeap(Puzzle* puzzle, int &numOfDeletionsFromMiddleOfHeap)
        {
            int index = hasSmallerCost(puzzle);

            if (index == -1)
            {
                numOfDeletionsFromMiddleOfHeap++;
                return false;
            }
            else if (index != -1 && index != -2)
            {
                numOfDeletionsFromMiddleOfHeap++;
                deleteFromMiddle(index);
            }

            data.push_back(puzzle);

            last++;

            if (last == 0)
            {
                return true;
            }

            bool swap = true;
            int leaf = last;
            int root = 0;

            while (swap)
            {
                swap = false;
                root = (leaf - 1) / 2;

                if (root >= 0)
                {
                    if (data[leaf]->getFCost() < data[root]->getFCost())
                    {
                        Puzzle*temp = data[leaf];
                        data[leaf] = data[root];
                        data[root] = temp;
                        swap = true;
                        leaf = root;
                    }
                }
            }
            return true;
        }

        //Function that delete the puzzle from the middle of the heap
        void deleteFromMiddle(int index)
        {
            Puzzle* temp = data[index];
            data[index] = data[last];
            delete temp;
            last--;
            data.pop_back();

            int root = index;
            int left = (root * 2) + 1; /*Left child of the root*/
            int right = (root * 2) + 2; /*Right child of the root*/

            if (left > last)
            {
                return;
            }
            else if (right > last)
            {
                if (data[left]->getFCost() < data[root]->getFCost())
                {
                    Puzzle *temp = data[left];
                    data[left] = data[root];
                    data[root] = temp;
                }
                return;
            }

            int side;
            if (data[left]->getFCost() <= data[right]->getFCost())
            {
                side = left;
            }
            else
            {
                side = right;
            }

            while (data[side]->getFCost() < data[root]->getFCost())
            {
                Puzzle* temp = data[side];
                data[side] = data[root];
                data[root] = temp;
                root = side;
                left = (root * 2) + 1;
                right = (root * 2) + 2;
                if (left > last)
                {
                    break;
                }
                else if (right > last)
                {
                    if (data[left]->getFCost() < data[root]->getFCost())
                    {
                        Puzzle *temp = data[left];
                        data[left] = data[root];
                        data[root] = temp;
                    }
                    break;
                }
                else
                {
                    if (data[left]->getFCost() <= data[right]->getFCost())
                    {
                        side = left;
                    }
                    else
                    {
                        side = right;
                    }
                }
            }
        }

        void deleteHeapRoot(Puzzle **front)
        {
            if (last < 0)
            {
                (*front) = NULL;
                return;
            }
            (*front) = data[0];
            data[0] = data[last];
            data[last] = NULL;
            last--;
            data.pop_back();

            int root = 0;
            int left = 1;
            int right = 2;
            if (left > last)
            {
                return;
            }
            else if (right > last)
            {
                //check if the last leaf has smaller fcost, swap if true
                if (data[left]->getFCost() < data[root]->getFCost())
                {
                    Puzzle *temp = data[left];
                    data[left] = data[root];
                    data[root] = temp;
                }
                return;
            }
            int side;
            //Check which leaf of the root has a lower FCOST swap with that side
            if (data[left]->getFCost() <= data[right]->getFCost())
            {
                side = left;
            }
            else
            {
                side = right;
            }

            while (data[side]->getFCost() < data[root]->getFCost())
            {
                Puzzle* temp = data[side];
                data[side] = data[root];
                data[root] = temp;
                root = side;
                left = (root * 2) + 1;
                right = (root * 2) + 2;
                if (left > last)
                {
                    break;
                }
                else if (right > last)
                {
                    if (data[left]->getFCost() < data[root]->getFCost())
                    {
                        Puzzle *temp = data[left];
                        data[left] = data[root];
                        data[root] = temp;
                    }
                    break;
                }
                else
                {
                    if (data[left]->getFCost() <= data[right]->getFCost())
                    {
                        side = left;
                    }
                    else
                    {
                        side = right;
                    }
                }
            }
        }
};

// Define utility function
void addToList(struct VisitedList &myList, int data);

bool isVisited(struct VisitedList const &myList, int data);

void addToNonStrictList(struct NonStrictList &myList, int state, int depthLevel);

bool isVisitedNonStrict(struct NonStrictList &myList, int state, int depth);

#endif
