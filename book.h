#pragma once

#include <string>

class Book
{
public:
	//properties of books
	//int bookId;
	std::wstring title;
	std::wstring abstract;
	double price;
	unsigned int amount;

	Book(std::wstring titleIn, std::wstring abstractIn, unsigned int amountIn, double priceIn) {
		title = titleIn;
		abstract = abstractIn;
		amount = amountIn;
		price = priceIn;
		soldNum = 0;
		popularity = 0.0;
	}
	

	void sell(int sellNum = 1);

	void purchase(int purchaseNum);
	
	//void updateAbstract(std::wstring newAbstract);

	void setPrice(double newPrice);
	double getPrice();

private:
	int soldNum;
	int popularity;
	void updatePopularity();



};

