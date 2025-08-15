#pragma once

#include <string>

class Book
{
public:
	//properties of books
	int bookId;
	std::string title;
	std::string abstract;
	float price;
	unsigned int amount;
	int popularity;

	void sell(int sellNum = 1);

	void purchase(int purchaseNum);
	
	void updateAbstract(std::string newAbstract);

	void setPrice(float newPrice);
	float getPrice();

private:
	int soldNum;
	void updatePopularity();



};

