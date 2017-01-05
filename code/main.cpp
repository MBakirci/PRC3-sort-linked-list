#include <iostream>
// #include <fstream> // Enable for generate readable txt file ***
#include "FileStructure.h"

/**
  BRONNENLIJST

  Merge sort:
  https://en.wikipedia.org/wiki/Comparison_sort

  Code examples from:
  http://stackoverflow.com/questions/5630994/merge-sorting-a-linked-list
  http://stackoverflow.com/a/25883550
  http://algorithmsandme.in/2015/04/merge-sort-on-linked-list/
**/

template <class T>
void MergeSort(T **node) {
  T *head = *node;
  T *mid = NULL;
  T *half = NULL;

  if (head == NULL || head->getNext() == NULL) {
    return;
  }

  Split(head, &mid, &half);
  MergeSort(&mid);
  MergeSort(&half);

  *node = Merge(mid, half);
}

template <class T>
T *Merge(T *firstNode, T *secondNode) {
  T *result = NULL;
  if (firstNode == NULL) {
    return secondNode;
  } else if (secondNode == NULL) {
    return firstNode;
  }
  if (firstNode->getName() <= secondNode->getName()) {
    result = firstNode;
    result->setNext(Merge(firstNode->getNext(), secondNode));
  } else {
    result = secondNode;
    result->setNext(Merge(firstNode, secondNode->getNext()));
  }
  return result;
}

template <class T>
void Split(T *head, T **front, T **back) {
  T *firstNode = head;
  T *secondNode = head->getNext();

  while (secondNode) {
    secondNode = secondNode->getNext();
    if (secondNode) {
      secondNode = secondNode->getNext();
      firstNode = firstNode->getNext();
    }
  }
  *front = head;
  *back = firstNode->getNext();
  firstNode->setNext(NULL);
}

template <class T>
void Sort(T *current) {
  if (current != NULL) {
    Dir *currentSubdir = current->getFirstSubdir();
    File *currentFile = current->getFirstFile();
    // MergeSort(current);
    if (currentFile != NULL) {
      MergeSort(&currentFile);
      current->setFirstFile(currentFile);
    }
    if (currentSubdir != NULL) {
      MergeSort(&currentSubdir);
      current->setFirstSubdir(currentSubdir);
    }
    while (currentSubdir != NULL) {
      Sort(currentSubdir);
      currentSubdir = currentSubdir->getNext();
    }
  }
}

/*** Enable for generate readable txt file ***
void WirteDataToTxt(Dir *head) {
  std::ofstream file;
  file.open("sorted.txt");
  file << head->toString(false);
  file.close();
}
*/

int main() {
  FileStructure f;
  Dir head;

  f.loadFile("data/gibberish.bin", head);

  // next line is only to show what kind of data we're working with
  // remove this line to increase performance!
  // std::cout << head.toString(false);
  // sort all data
  // todo: your code here!
  Dir *current = &head;
  Sort(current);

  // Write data to readable txt file
  // WirteDataToTxt(current);

  // save sorted data into a new file called sorted.bin
  f.saveFile(head, "sorted.bin");

  return 0;
}