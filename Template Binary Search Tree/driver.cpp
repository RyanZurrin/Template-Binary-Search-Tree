#include "TBST.h"
#include <string>

int main() {
	TBST<int>* tree = new TBST<int>(100);

	tree->addItem(7);
	tree->addItem(20);
	tree->addItem(10);
	tree->addItem(17);
	tree->addItem(8);
	tree->addItem(26);
	tree->addItem(11);
	tree->addItem(1);
	tree->addItem(15);
	tree->addItem(3);
	tree->addItem(13);
	tree->addItem(2);

	tree->traverseTree(TBST<int>::OrderType::PRE_ORDER);

	tree->traverseTree(TBST<int>::OrderType::BREADTH_FIRST);

	tree->traverseTree(TBST<int>::OrderType::POST_ORDER);

	std::cout << tree->rankOf(tree->returnRoot(), 13) << std::endl;

	std::cout << tree->getCount() << std::endl;
	std::cout << tree->getQty() << std::endl;




	return EXIT_SUCCESS;
}