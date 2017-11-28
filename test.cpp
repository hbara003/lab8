#include <iostream>
#include <vector>
#include "composite.h"

using namespace std;

int main() {
/*
	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Root* root = new Root(sub);
*/

/*
     	Op* op5 = new Op(5);
	Op* op7 = new Op(7);
	Op* op3 = new Op(3);
	Op* op2 = new Op(2);
	Sqr* sqr = new Sqr(op2);
	Add* a2 = new Add(op3, sqr);
	Sub* sub = new Sub(op5, op7);
	Add* a1 = new Add(sub, a2);
        Root* root = new Root(a1);
*/


	Op* op5 = new Op(5);
	Op* op7 = new Op(7);
	Op* op10 = new Op(10);
	Sub* sub1 = new Sub(op10, op7);
	Add* add1 = new Add(sub1, op5);
	Sqr* sqr1 = new Sqr(add1);
	Root* root = new Root(sqr1);

	cout << "--- PreOrder Iteration ---" << endl;
	PreorderIterator* pre_itr = new PreorderIterator(root);
        PrintVisitor* pv = new PrintVisitor(root);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}

	pv->execute();

};
