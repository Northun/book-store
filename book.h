#pragma once

#include <string>

class Book
{
public:
	//properties of books
	int bookId;
	std::string title;
	std::string abstract;
	double price;
	unsigned int amount;
	

	void sell(int sellNum = 1);

	void purchase(int purchaseNum);
	
	void updateAbstract(std::string newAbstract);

	void setPrice(double newPrice);
	double getPrice();

private:
	int soldNum;
	int popularity;
	void updatePopularity();



};

