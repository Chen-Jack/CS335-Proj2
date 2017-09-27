#include <iostream>
#include "BinarySearchTree.h"
#include "SequenceMap.h"
using namespace std;

int main(){

    int AverageHeight(somenode* t){
        if(t != nullptr){
            if(t->left == nullptr && t->right == nullptr){
                return 1;
            }
            else{
                return (AverageHeight(t->left) + AverageHeight(t->right))/2
            }
        }
        else{
            return 0;
        }
    }

    
    return 0;
}
    

