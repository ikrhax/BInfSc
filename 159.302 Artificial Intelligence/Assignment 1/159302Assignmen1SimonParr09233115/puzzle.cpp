#include "puzzle.h"
#include  <cmath>
#include  <assert.h>

using namespace std;

//////////////////////////////////////////////////////////////
//constructor
//////////////////////////////////////////////////////////////
Puzzle::Puzzle(const Puzzle &p) : path(p.path){
	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = p.board[i][j];
		    goalBoard[i][j] = p.goalBoard[i][j];
		}
	}	
	
	x0 = p.x0;
	y0 = p.y0;
	//path = p.path;
	pathLength = p.pathLength;
	hCost = p.hCost;
	fCost = p.fCost;	
	strBoard = toString(); //uses the board contents to generate the string equivalent
	depth = p.depth;
	
}

//////////////////////////////////////////////////////////////
//constructor
//inputs:  initial state, goal state
//////////////////////////////////////////////////////////////
Puzzle::Puzzle(string const elements, string const goal){
	
	int n;
	
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = elements[n] - '0';
		    if(board[i][j] == 0){
			    x0 = j;
			    y0 = i;
			 }
		    n++;
		} 
	}
		
	///////////////////////
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    goalBoard[i][j] = goal[n] - '0';
		    n++;
		} 
	}		
	///////////////////////	
	path = "";
	pathLength=0;
	hCost = 0;
	fCost = 0;
	depth = 0;
	strBoard = toString();	
}


void Puzzle::setDepth(int d){
	depth = d;
}

int Puzzle::getDepth(){
	return depth;
}

void Puzzle::updateHCost(heuristicFunction hFunction){
	hCost = h(hFunction);
}

void Puzzle::updateFCost(){
	//fCost = h(hFun)
    // fCost is total of path length and hCost
    fCost = pathLength + hCost;
}

int Puzzle::getFCost(){
	return fCost;
}

int Puzzle::getHCost(){
	return hCost;
}

int Puzzle::getGCost(){
	return pathLength;
}

//Heuristic function implementation
int Puzzle::h(heuristicFunction hFunction){
	
	int sum = 0;
    int h = 0;
    int numOfMisplacedTiles = 0;

    switch (hFunction)
    {
    case misplacedTiles:
        //place your implementation here
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != goalBoard[i][j] && board[i][j] != 0)
                {
                    numOfMisplacedTiles++;
                }
            }
        }
        h = numOfMisplacedTiles;
        break;

    case manhattanDistance:
        //place your implementation here
        int temp = 0, x = 0, y = 0;
        for (int tileX = 0; tileX < 3; tileX++)
        {
            for (int tileY = 0; tileY < 3; tileY++)
            {
                if (board[tileX][tileY] != 0)
                {
                    getXY(board[tileX][tileY], x, y);
                    temp = abs(tileX - x) + abs(tileY - y);
                    sum += temp;
                }
            }
        }
        h = sum;
        break;

    };

    return h;
	
}


//converts board state into its string representation
string Puzzle::toString(){
  int n;
  string stringPath;
  
  n=0;
  for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){			    
		    stringPath.insert(stringPath.end(), board[i][j] + '0');
		    n++;
		} 
  }
  
//  cout << "toString = " << stringPath << endl;
  
  return stringPath;
}



bool Puzzle::goalMatch()
{
    bool result = true;

    //this is incomplete...
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != goalBoard[i][j])
            {
                result = false;
                break;
            }
        }
    }
    return result;
}

bool Puzzle::canMoveLeft(){
   return (x0 > 0);
	
}

const string Puzzle::getPath(){
	return path;
}

bool Puzzle::canMoveRight(){

   return (x0 < 2);
	
}


bool Puzzle::canMoveUp(){

   return (y0 > 0);
	
}

bool Puzzle::canMoveDown(){

   return (y0 < 2);
	
}

///////////////////////////////////////////////
//these functions will be useful for Progressive Deepening Search 

bool Puzzle::canMoveLeft(int maxDepth){
  	//put your implementations here
    if(!canMoveLeft())
        return false;
    return (maxDepth >= depth + 1);
}
bool Puzzle::canMoveRight(int maxDepth){
   //put your implementations here
    if(!canMoveRight())
        return false;
    return (maxDepth >= depth + 1);
}


bool Puzzle::canMoveUp(int maxDepth){
   //put your implementations here	
    if(!canMoveUp())
        return false;
    return (maxDepth >= depth + 1);
}

bool Puzzle::canMoveDown(int maxDepth){
   //put your implementations here
    if(!canMoveDown())
        return false;
    return (maxDepth >= depth + 1);
}

///////////////////////////////////////////////

Puzzle *Puzzle::moveLeft(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(x0 > 0){
		
		p->board[y0][x0] = p->board[y0][x0-1];
		p->board[y0][x0-1] = 0;
		
		p->x0--;
		
		p->path = path + "L";
		p->pathLength = pathLength + 1;  
		p->depth = depth + 1; 
		
		
	}
	p->strBoard = p->toString();

	return p;
	
}


Puzzle *Puzzle::moveRight(){
	
   Puzzle *p = new Puzzle(*this);
	
	
   if(x0 < 2){
		
		p->board[y0][x0] = p->board[y0][x0+1];
		p->board[y0][x0+1] = 0;
		
		p->x0++;
		
		p->path = path + "R";
		p->pathLength = pathLength + 1; 
     	
		p->depth = depth + 1;
		
	}
	
	p->strBoard = p->toString();
	
	return p;
	
}


Puzzle *Puzzle::moveUp(){
	
   Puzzle *p = new Puzzle(*this);
	
	
   if(y0 > 0){
		
		p->board[y0][x0] = p->board[y0-1][x0];
		p->board[y0-1][x0] = 0;
		
		p->y0--;
		
		p->path = path + "U";
		p->pathLength = pathLength + 1;  
	
		p->depth = depth + 1;
		
	}
	p->strBoard = p->toString();
	
	return p;
	
}

Puzzle *Puzzle::moveDown(){
	
   Puzzle *p = new Puzzle(*this);
	
	
   if(y0 < 2){
		
		p->board[y0][x0] = p->board[y0+1][x0];
		p->board[y0+1][x0] = 0;
		
		p->y0++;
		
		p->path = path + "D";
		p->pathLength = pathLength + 1;  
		
		p->depth = depth + 1;
		
	}
	p->strBoard = p->toString();	
	
	return p;
	
}

/////////////////////////////////////////////////////


void Puzzle::printBoard(){
	cout << "board: "<< endl;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		  cout << endl << "board[" << i << "][" << j << "] = " << board[i][j];
		}
	}
	cout << endl;
	
}

int Puzzle::getPathLength(){
	return pathLength;
}

//////////////////////////////////////////////
void Puzzle::getXY(int tile, int &x, int &y)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tile == goalBoard[i][j])
            {
                x = i;
                y = j;
                break;
            }
        }
    }
}

bool Puzzle::isLocalLoop(int currentState)
{
    return (previousStates.find(currentState) != previousStates.end());
}

set<int> Puzzle::getPreviousStates()
{
    return previousStates;
}

void Puzzle::setPreviousStates(const set<int> pState)
{
    previousStates = pState;
    previousStates.insert(toNumber());
}

int Puzzle::toNumber()
{
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            num = num * 10 + board[i][j];
        }
    }
    return num;
}

void Puzzle::printStateList()
{
    for (int n : previousStates)
    {
        cout << n << " , ";
    }
    cout << "\n";
}
