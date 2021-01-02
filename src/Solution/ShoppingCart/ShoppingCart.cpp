#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	this->payMethod = payMethod;
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	shoppingCart.insert(std::pair<int, int>(id, quantity));
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	shoppingCart.find(id)->second += quantity;
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	shoppingCart.find(id)->second -= quantity;
}

int ShoppingCart::getQuantity(int productID)
{
	return (shoppingCart.find(productID)->second) ? shoppingCart.find(productID)->second : -1;
}

void ShoppingCart::deleteProduct(int productID)
{
	shoppingCart.erase(shoppingCart.find(productID));
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
	typedef map<int, int>::const_iterator MapIterator;
	for (MapIterator iter = shoppingCart.begin(); iter != shoppingCart.end(); iter++)
		cout << "productID:" << iter->first << endl
			 << "quantity:" << iter->second << endl;
}

json ShoppingCart::toJSON()
{
	return json(*this);
}