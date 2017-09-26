#include <iostream>
#include "BinarySearchTree.h"
#include "SequenceMap.h"
using namespace std;

int main(){

    string seq = "TTA'TAA";
    string acro = "AanI";
    string seq2 = "TTA'sAA";

    SequenceMap map1{seq, acro};
    SequenceMap map3{seq, "whatever"};
    map3.Merge(map1);
    SequenceMap map2{seq2};

    BinarySearchTree<SequenceMap> a_tree;
    a_tree.insert(map3);
    cout << a_tree.find(map1);
    return 0;
}
    

