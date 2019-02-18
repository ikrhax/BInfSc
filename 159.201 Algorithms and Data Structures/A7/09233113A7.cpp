/*
***********************************
*                                 *
*     159.201 - Assignment 7	    *	
*	       Simon Parr 		       *
*          09233113               *
*                                 *
***********************************
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class Heap
{
public:
    Heap() : insertComparisons_{ 0 }, deleteComparisons_{ 0 } {};

    ~Heap() {};
    
    vector<int> GetData(std::ifstream& inputFile)
    {
        vector<int> sortingVector;
        char line[100] = { '\0' };
        int value = 0;

        while (inputFile >> value)
        {
            sscanf(line, "%d", &value);
            sortingVector.push_back(value);
        }
        
        return sortingVector;
    }
	 
	 
    void InsertHeap(int _value)
    {
        data_.push_back(_value);
        
        int childIndex = data_.size() - 1;
        int parentIndex = 0;
        bool swapping = true;
        while (swapping)
        {
            swapping = false;
            if (childIndex % 2 == 0)
                parentIndex = childIndex / 2 - 1;
            else
                parentIndex = childIndex / 2;
            if (parentIndex >= 0)
            {
                ++insertComparisons_;
                if (data_[childIndex] > data_[parentIndex])
                {
                    swap(data_[childIndex], data_[parentIndex]);
                    swapping = true;
                    childIndex = parentIndex;
                }
            }
        }
    }


    int DeleteRoot()
    {

        int root = data_[0];
        data_[0] = data_[data_.size() - 1];
        data_.resize(data_.size() - 1);
		 
        int parentIndex = 0;
        unsigned int left = parentIndex * 2 + 1;
        unsigned int right = parentIndex * 2 + 2;
        bool swapping = true;
		 
        if (left < data_.size()) 
            ++deleteComparisons_;
        if (right < data_.size()) 
            ++deleteComparisons_;

		  
		  
        while ((data_[parentIndex] < data_[left] ||
            data_[parentIndex] < data_[right]) &&
            swapping)
        {
            swapping = false;
			  
            if (left < data_.size() && data_[right] < data_[left])
            {
                swap(data_[left], data_[parentIndex]);
                parentIndex = left;
                swapping = true;
            }
            else if (right < data_.size() && data_[right] > data_[left])
            {
                swap(data_[right], data_[parentIndex]);
                parentIndex = right;
                swapping = true;
            }
            left = parentIndex * 2 + 1;
            right = parentIndex * 2 + 2;


            if (left < data_.size()) 
                ++deleteComparisons_;
            if (right < data_.size()) 
                ++deleteComparisons_;

            if (left > data_.size() - 1)
                break;
				
            if (right > data_.size() - 1)
            {
                if (data_[parentIndex] < data_[left])
                    swap(data_[parentIndex], data_[left]);
                break;
            }
        }
        
        return root;
    }


    void PrintHeap()
    {
        for (unsigned int i = 0; i < data_.size(); ++i)
		  cout << data_[i] << " ";
        cout << std::endl;
    }

	 
    void HeapSort(std::vector<int>& temp, char* file)
    {

        for (int i = 0; i < temp.size(); ++i)
            InsertHeap(temp[i]);
        cout << "Heap before sorting: " << file << std::endl;
        PrintHeap();
        
        for (int i = temp.size() - 1; i >= 0; --i)
            temp[i] = DeleteRoot();
		  
        cout << "InsertHeap: " << insertComparisons_ << " comparisons" << endl;
        cout << "DeleteRoot: " << deleteComparisons_ << " comparisons" << endl;

        cout << "Vector after sorting:" << endl;
        for (int i = 0; i < temp.size(); ++i)
			cout << temp[i] << " " << endl;
    }

private:
    int insertComparisons_; 
    int deleteComparisons_; 
    vector<int> data_; 
};

int main(int argc, char** argv)
{
    


    if (argc != 4)
    {
        cout << "The program needs 3 filenames, in this order:"<<" random, reversed and sorted." << std::endl;
        exit(1);
    }

    
    for (int i = 0; i < 3; ++i)
    {
        Heap myHeap;
        ifstream inFile;
        inFile.open(argv[i]);
        vector<int> tempVec = myHeap.GetData(inFile);
        myHeap.HeapSort(tempVec, argv[i]);
        if (i < 2)
			cout << std::endl;
    }
    
    return 0;
}