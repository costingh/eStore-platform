#include "Server.h"

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

	unsigned int differentUsers = 0; // variabila care reprezinta de cate ori nu a fost gasit userul cautat in lista
	for (map<int, ShoppingCart *>::iterator userID__Cart = __UserID__ProductsCart__.begin(); userID__Cart != __UserID__ProductsCart__.end(); ++userID__Cart)
	{
		unsigned int differentProducts = 0; // variabila care reprezinta de cate ori nu a fost gasit produsul cautat in lista
		if ((*userID__Cart).first == userID)
		{
			for (list<Product *>::iterator product = prod.begin(); product != prod.end(); ++product)
			{
				if ((*product)->getId() == productID) // daca am gasit produsul
				{
					int cartProductQuantity = (*userID__Cart).second->getQuantity(productID); // Memoram cantitatea produsului din lista de cumparaturi a unui USER
					int serverProductQuantity = (*product)->getQuantity();					  // Memoram cantitatea produsului din lista de pe SERVER
																							  // Daca produsul se afla in lista USERULUI si daca cantitatea dorita de user este cel mult egala cu cea de pe SERVER
					if (serverProductQuantity >= quantity)									  // daca cantitatea disponibila pe server este de ajuns
					{
						if (cartProductQuantity != -1) // daca produsul se afla in cos
						{
							(*userID__Cart).second->raiseQuantity(productID, quantity);
							(*product)->decreaseQuantity(quantity);
						}
						else
						{
							(*userID__Cart).second->addProduct(productID, quantity);
							(*product)->decreaseQuantity(quantity);
						}
					}
					else
						return false;
				}
				else
				{
					differentProducts++; // creste numarul de produse diferite
				}

				if (differentProducts == prod.size()) // daca numarul de produse diferite gasite corespunde cu numarul total de produse din lista, atunci produsul cautat nu a fost gasit
					return false;
			}
		}
		else
		{
			differentUsers++;
		}
		if (differentUsers == __UserID__ProductsCart__.size())
			return false;
	}

	return true;
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	if (quantity <= 0)
		return false;

	unsigned int differentUsers = 0;

	for (map<int, ShoppingCart *>::iterator userID__Cart = __UserID__ProductsCart__.begin(); userID__Cart != __UserID__ProductsCart__.end(); ++userID__Cart)
	{
		unsigned int differentProducts = 0;
		if ((*userID__Cart).first == userID)
		{
			for (list<Product *>::iterator product = prod.begin(); product != prod.end(); ++product)
			{
				if ((*product)->getId() == productID) // daca am gasit produsul
				{
					if ((*userID__Cart).second->getQuantity(productID) != -1) // daca se afla in cosul de cumparaturi
					{
						if ((*userID__Cart).second->getQuantity(productID) < quantity) // daca incercam sa stergem o cantitate mai mare decat cea deja existenta in cos
						{
							(*product)->increaseQuantity((*userID__Cart).second->getQuantity(productID));
							(*userID__Cart).second->deleteProduct(productID);
						}
						else
						{
							(*product)->increaseQuantity(quantity);
							(*userID__Cart).second->lowerQuantity(productID, quantity);
						}
					}
					else
						return false;
				}
				else
				{
					differentProducts++;
				}

				if (differentProducts == prod.size())
					return false;
			}
		}
		else
		{
			differentUsers++;
		}

		if (differentUsers == __UserID__ProductsCart__.size())
			return false;
	}

	return true;
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