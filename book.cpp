#include "book.h"


void Book::sell(int sellNum) {
	this->amount = this->amount - sellNum;
}

void Book::purchase(int purchaseNum) {
	this->amount = this->amount + purchaseNum;
}

void Book::setPrice(double newPrice) {
	this->price = newPrice;
}

double Book::getPrice() {
	return this->price;
}

void Book::updatePopularity() {
	//there should be a global standard to evaluate popularity
	//haven't decide yet
}