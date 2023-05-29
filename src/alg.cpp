// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string word;
  std::ifstream f(filename);
  if (!f)
    std::cout << "error" << std::endl;
  while (!f.eof()) {
    char ch = tolower(f.get());
    if (isalpha(ch)) {
      word += ch;
    } else {
      tree.add(word);
      word.clear();
    }
  }
  f.close();
  return tree;
}
