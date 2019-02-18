/**
 *  @author Adam Peryman (09079122)
 *  @date   13/05/15
 *  @brief  159.201 Assignment 06.
 *          Semester 01, 2015.
 *          Implement Dijkstra's algorithm using a graph and an adjacency list.
 *          As per my emails with Andre I'm submitting on Monday the 18th :)
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

/**
 *  Linked List definitions.
 */
struct Node
{
    char key;
    int cost;
    Node* next;
};

struct GraphNode
{
    char key;
    int minimumCost;
    char state;
    Node* listPointer;
};

/**
 *  Linked list function: add node to tail.
 */
void addNode(Node*& listPointer, char newKey, int newCost)
{
    Node* current;
    current = listPointer;

    if (current != NULL)
        while (current->next != NULL)
            current = current->next;

    Node* temp;
    temp = new Node;
    temp->key = newKey;
    temp->cost = newCost;
    temp->next = NULL;

    if (current != NULL)
        current->next = temp;
    else
        listPointer = temp;
}

/**
 *  Graph class definition.
 */
class Graph
{
public:
    Graph() {};
    ~Graph() {};
    //! Get data from text file.
    void getData(std::ifstream&);
    //! Add new struct GraphNode to vertexList.
    void addNewGraphNode(char);
    //! Add node to vertexList[N]'s linked list.
    void addNewEdgeBetweenGraphNodes(char, char, int);
    //! Apply Dijkstra's algorithm to current object.
    void applyDijkstra();
    //! Check for a temporary state within vertexList.
    bool temporaryStateExists();
    //! Interpret and print costs[].
    void printGraph();
private:
    int numberOfNodes;
    std::vector<GraphNode> vertexList;
};

/**
 *  Graph class methods.
 */
void Graph::getData(std::ifstream& inFile)
{
    std::string token;
    std::string expression;

    while (!inFile.eof())
    {
        //! First line's always a comment.
        getline(inFile, expression);
        std::stringstream line(expression);

        //! Exit on empty file.
        if (inFile.eof()) break;

        //! Check for comments.
        if (expression[0] == '#') continue;
        char node_name;

        //! Get nodes.
        if (expression[0] == 'N' && expression[1] == 'o')
        {
            getline(line, token, ' ');
            getline(line, token, ' ');
            node_name = (token.c_str())[0];
            Graph::addNewGraphNode(node_name);
        }
        //! Get edges.
        else
        {
            char nodefrom;
            getline(line, token, ' ');
            nodefrom = (token.c_str())[0];

            char nodeto;
            getline(line, token, ' ');
            nodeto = (token.c_str())[0];

            int cost;
            getline(line, token, ' ');
            cost = atoi(token.c_str());

            Graph::addNewEdgeBetweenGraphNodes(nodefrom, nodeto, cost);
        }
    }
}

void Graph::addNewGraphNode(char newGraphNode)
{
    GraphNode temp;
    temp.key = newGraphNode;

    temp.minimumCost = std::numeric_limits<int>::max();
    temp.state = 't';
    //! As per brief, 'A' is always permanent
    //! and we don't care about its minimum cost.
    if (temp.key == 'A')
    {
        temp.minimumCost = 0;
        temp.state = 'p';
    }
    temp.listPointer = NULL;

    vertexList.push_back(temp);
    ++numberOfNodes;
}

void Graph::addNewEdgeBetweenGraphNodes(char nodeFrom, char nodeTo, int cost)
{
    int i;
    for (i = 0; vertexList.size(); ++i)
        if (nodeFrom == vertexList[i].key) break;
    addNode(vertexList[i].listPointer, nodeTo, cost);
}

void Graph::applyDijkstra()
{
    //! Get 'A'.
    GraphNode* current = nullptr;
    for (int i = 0; i < numberOfNodes; ++i)
        if (vertexList[i].key == 'A') current = &vertexList[i];

    //! Loop while any vertex is still marked as temporary.
    while (temporaryStateExists())
    {
        //! Loop through neighbors of current.
        Node* temp = current->listPointer;
        while (temp != NULL)
        {
            for (int i = 0; i < numberOfNodes; ++i)
            {
                //! Set minimum cost for each vertex marked as temp.
                if (vertexList[i].key == temp->key
                    && vertexList[i].state == 't')
                {
                    vertexList[i].minimumCost = std::min(vertexList[i].minimumCost,
                        current->minimumCost + temp->cost);
                }
            }
            temp = temp->next;
        }

        //! Find minimum and maximum remaining costs.
        int minimum = std::numeric_limits<int>::max();
        int maximum = 0;
        for (int i = 0; i < numberOfNodes; ++i)
        {
            if (vertexList[i].minimumCost < minimum
                && vertexList[i].state == 't')
                minimum = vertexList[i].minimumCost;

            if (vertexList[i].minimumCost > maximum
                && vertexList[i].state == 't')
                maximum = vertexList[i].minimumCost;
        }

        //! Update state for each vertex from vertexList[1] (we don't care about 'A').
        for (int i = 1; i < numberOfNodes; ++i)
        {
            if (vertexList[i].minimumCost == minimum
                && vertexList[i].state == 't')
            {
                //! Update current with the address of the vertex with minimum cost.
                current = &vertexList[i];
                vertexList[i].state = 'p';

                //! Skip current vertex if current has no neighbors.
                if (current->listPointer == NULL)
                {
                    current = &vertexList[i + 1];
                    vertexList[i + 1].state = 'p';
                }

                //! We only want to alter one vertex at a time.
                break;
            }
        }
    }
}

bool Graph::temporaryStateExists()
{
    for (int i = 0; i < numberOfNodes; ++i)
        if (vertexList[i].state == 't') return true;
    return false;
}

void Graph::printGraph()
{
    for (int i = 1; i < numberOfNodes; ++i)
        std::cout << "From A to " << vertexList[i].key <<
        ":" << vertexList[i].minimumCost << std::endl;
}

//! Global graph, should fix this.
Graph my_graph;

int main(int argc, char** argv)
{
    std::ifstream inFile;

    //! For debug.
    //! inFile.open("graph1.txt");

    //! Check for valid input file.
    if (argc != 2)
    {
        std::cout << "Type a file name. " << std::endl << argv[1] << std::endl;
        exit(0);
    }

    //! Try open file.
    inFile.open(argv[1]);

    //! Error out if open failed.
    if (inFile.is_open() == false)
    {
        std::cout << "Could not read file: " << std::endl << argv[1] << std::endl;
        exit(0);
    }

    //! Get data from file.
    my_graph.getData(inFile);

    //! Apply Dijkstra's algorithm to graph.
    my_graph.applyDijkstra();

    //! Print updated costs.
    my_graph.printGraph();

    return 0;
}
