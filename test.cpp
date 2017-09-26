#include <iostream>
#include "BinarySearchTree.h"
#include "SequenceMap.h"
using namespace std;

int main(){

    string seq = "TTA'TAA";
    string acro = "AanI";
    string seq2 = "TTA'sAA";

    SequenceMap map1{seq, acro};
    map1.Merge(*(new SequenceMap{seq, acro}));
    //map1.PrintRecognitionSequence();
    map1.PrintEnzSequence();
    return 0;
}
    

