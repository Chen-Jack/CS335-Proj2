// Jack Chen
// Main file for Part2(a) of Homework 2.

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "SequenceMap.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace Project2{

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
  
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

}

}  // namespace

int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <tree-type>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string param_tree(argv[2]);
  cout << "Input filename is " << db_filename << endl;
  cout << "Type of tree is " << param_tree << endl;

  //"Please enter three recognition sequences."
  string seq1, seq2, seq3;
  for(int i=0; i<3; i++){
    cin >> seq1 >> seq2 >> seq3;
  }

  if (param_tree == "BST") {
    BinarySearchTree<SequenceMap> a_tree;
    Project2::QueryTree(db_filename, a_tree);
    cout << a_tree.contains(seq1) << endl;
  } 
  else if (param_tree == "AVL") {
    AvlTree<SequenceMap> a_tree;
    Project2::QueryTree(db_filename, a_tree);
  } 
  else {
    cout << "Unknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
  }
  return 0;
}
