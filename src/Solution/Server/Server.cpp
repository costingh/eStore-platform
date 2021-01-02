#include "Server.h"
#include <fstream>
using namespace std;

/* NU MODIFICATI */
Server::Server() {}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	list<User *>::iterator userIterator;
	for (userIterator = usr.begin(); userIterator != usr.end(); ++userIterator)
	{
		__UserID__ProductsCart__.insert(pair<int, ShoppingCart *>((*userIterator)->getUserID(), new ShoppingCart));
	}
}

list<Product *> &Server::getProductsList()
{
	return prod;
}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	if (quantity <= 0)
		return false;

	for (auto userID__Cart = __UserID__ProductsCart__.begin(); userID__Cart != __UserID__ProductsCart__.end(); ++userID__Cart)
	{
		if ((*userID__Cart).first == userID)
		{
			for (auto product = prod.begin(); product != prod.end(); ++product)
			{
				if ((*product)->getId() == productID)
				{
					if ((*userID__Cart).second->getQuantity(productID))
					{
						// Daca produsul EXISTA in lista de cumparaturi a userului curent
						(*userID__Cart).second->raiseQuantity(productID, quantity);
						(*product)->decreaseQuantity(quantity);
					}
					else
					{
						// Daca produsul NU EXISTA in lista de cumparaturi a userului curent
						(*userID__Cart).second->addProduct(productID, quantity);
						(*product)->decreaseQuantity(quantity);
					}
				}
				else
				{
					throw("Product doesen't exist on the server");
					return false;
				}
			}
		}
		else
		{
			throw("User doesen't exist on the server");
			return false;
		}
	}
	ofstream MyFile;
	MyFile.open("example.txt");
	MyFile << "asdasdasssssssssssssssssssssssssssssssssss" << endl;
	MyFile.close();
	return true;
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	throw("undefined");
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}