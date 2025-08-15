#include "book.h"


void Book::sell(int sellNum = 1) {
	this->amount = this->amount - sellNum;
}

void Book::purchase(int purchaseNum) {
	this->amount = this->amount + purchaseNum;
}

void Book::updatePopularity() {
	//there should be a global standard to evaluate popularity
	//haven't decide yet
}