#ifndef VISITOR_H
#define VISITOR_H

class PrintVisitor : public Visitor {
	private:
		std::string output;

	public:
		PrintVisitor();

		void rootNode();	//For visiting a root node (do nothing)
		void sqrNode();		//For visiting a square node
		void multNode();	//For visiting a multiple node
		void subNode();		//For visiting a subtraction node
		void addNode();		//For visiting an add node
		void opNode(Op* op);	//For visiting a leaf node

		void execute();		//Prints all visited nodes
};

#endif
