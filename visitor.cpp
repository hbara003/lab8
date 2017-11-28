#include "visitor.h"

PrintVisitor::PrintVisitor() { 
    output = "";
}

void PrintVisitor::rootNode() {

}

void PrintVisitor::sqrNode() {
    output.append(" ^2");
}

void PrintVisitor::multNode() {
    output.append(" *");
}

void PrintVisitor::subNode() {
    output.append(" -");
}

void PrintVisitor::addNode() {
    output.append(" +");
}

void PrintVisitor::opNode(Op* op) {
    std::stringstream opvalue;
    opvalue << op->evaluate();
    output.append(" ");
    output.append(opvalue.str());
}

void PrintVisitor::execute() {
    std::cout << output << std::endl;
}
