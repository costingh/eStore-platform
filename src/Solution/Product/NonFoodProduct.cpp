#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct() : yearsOfWarranty(0), price(0) {}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
	this->producer = producer;
	this->yearsOfWarranty = yearsOfWarranty;
	this->price = price;
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	producer = pn.producer;
	yearsOfWarranty = pn.yearsOfWarranty;
	price = pn.price;
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	yearsOfWarranty = garantieAni;
}

void NonFoodProduct::setPrice(float price)
{
	this->price = price;
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer = producer;
}

int NonFoodProduct::getYearsOfWarranty()
{
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	return price;
}

string &NonFoodProduct::getProducer()
{
	return producer;
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	return ((producer == obj.producer) && (yearsOfWarranty == obj.yearsOfWarranty) && (price == obj.price));
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	if (this != &a)
	{
		Product::operator=(a);
		producer = a.producer;
		yearsOfWarranty = a.yearsOfWarranty;
		price = a.price;
	}
	return *this;
}

string NonFoodProduct::getProductType()
{
	return "nealimentar";
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
