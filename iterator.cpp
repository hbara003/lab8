#include "iterator.h"
//---------------------------------------------------------
//Operator Iterator
//---------------------------------------------------------
OperatorIterator::OperatorIterator(Base* ptr) : Iterator(ptr){}
void OperatorIterator::first(){
	current_ptr = self_ptr->get_left();	
}
void OperatorIterator::next(){
	if(current_ptr != self_ptr->get_right()){
		current_ptr = self_ptr->get_right();
	}
	else{
		current_ptr = NULL;
	}
}
bool OperatorIterator::is_done(){
	return (current_ptr == NULL);
}
Base* OperatorIterator::current(){
	return current_ptr;
}
//---------------------------------------------------------
//Unary Iterator
//---------------------------------------------------------
UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr){}
void UnaryIterator::first(){
	current_ptr = self_ptr->get_left();
}
void UnaryIterator::next(){
	current_ptr = NULL;
}
bool UnaryIterator::is_done(){
	return (current_ptr == NULL);
}
Base* UnaryIterator::current(){
	return current_ptr;
}
//----------------------------------------------------------
//Null Iterator
//----------------------------------------------------------
NullIterator::NullIterator(Base* ptr) : Iterator(ptr){}
void NullIterator::first(){}
void NullIterator::next(){}
bool NullIterator::is_done(){
	return true;
}
Base* NullIterator::current(){
	return NULL;
}
//----------------------------------------------------------
//Preorder Iterator
//---------------------------------------------------------
PreorderIterator::PreorderIterator(Base* ptr) : Iterator(ptr){}
void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    while(!iterators.empty()){
    	iterators.pop();
	}
    // Create an iterator for the Base* that we built the iterator for
	Iterator* it = self_ptr->create_iterator();
    // Initialize that iterator and push it onto the stack
	it->first();
	iterators.push(it);
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    Iterator* it = iterators.top()->current()->create_iterator();
    // Initialize the iterator and push it onto the stack
    it->first();
    iterators.push(it);
    // As long as the top iterator on the stack is_done(), 
    //    pop it off the stack and then advance whatever iterator is now on top of the stack
    while(iterators.top()->is_done()){
			iterators.pop();
			if(iterators.empty()){
				break;
			}
			iterators.top()->next();
	}
}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
    return iterators.empty(); 
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
	if(!iterators.empty()){
		return iterators.top()->current();
	}
	else{
		return 0;
	}
}
