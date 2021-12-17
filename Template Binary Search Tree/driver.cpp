#include "TBST.h"
#include <string>

int main() {
	TBST<int>* tree = new TBST<int>(100);

	tree->addItem(10);
	tree->addItem(5);
	tree->addItem(11);
	tree->addItem(3);
	tree->addItem(16);
	tree->addItem(6);
	tree->addItem(7);
	tree->addItem(0);

	

	tree->traverseTree(TBST<int>::OrderType::PRE_ORDER);

	tree->traverseTree(TBST<int>::OrderType::IN_ORDER);

	tree->traverseTree(TBST<int>::OrderType::POST_ORDER);




	return EXIT_SUCCESS;
}

