// Jack Chen
// Main file for Part2(b) of Homework 2.

#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "SequenceMap.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

namespace Part2B
{

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(b)  
  ifstream database{db_filename};
  
    /*A way to skip the first 10 lines of the database, that way the query
    starts at the first entry and not the database's title header"*/
    for(int i=0; i<10; i++){
      string what_am_i_suppose_to_do_with_all_these_lines;
      getline(database, what_am_i_suppose_to_do_with_all_these_lines, '\n');
    }
    
    string line;
    while(database >> line){
  
      string acro = line.substr(0, line.find('/')); //Substr up to the '/'
      line.erase(0, line.find('/') + 1);  //Remove the substring (including '/')
  
      //We keep removing each pack of data from the line until all that is left
      //is a '/' (which comes from the line ending with a "//").
      while(line != "/"){ 
        string sequence = line.substr(0, line.find('/'));
        line.erase(0, line.find('/') + 1);
  
        SequenceMap map{sequence, acro};
        a_tree.insert(map);
      }
    }
    database.close();

    cout << "2:" << a_tree.totalNode() << endl;
    cout << "3a:" << a_tree.averageDepth() << endl;

}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  const string param_tree(argv[3]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  cout << "Type of tree is " << param_tree << endl;

  //Binary Search Tree
  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    Part2B::TestTree(db_filename, seq_filename, a_tree);
  } 
  //AVL Search Tree
  else if (param_tree == "AVL") {
    // AvlTree<SequenceMap> a_tree;
    // Part2B::TestTree(db_filename, seq_filename, a_tree);
  } 
  else {
    cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
