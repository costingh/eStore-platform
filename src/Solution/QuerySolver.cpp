#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
	server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
	if (server != nullptr)
	{
		server = nullptr;
	}
}

list<Product *> QuerySolver::Query_3a()
{
	list<Product *> allProducts = server->getProductsList();
	list<Product *> espressors;
	for (list<Product *>::iterator iter = allProducts.begin(); iter != allProducts.end(); ++iter)
	{
		if (((*iter)->getProductType() == "redus") && ((*iter)->getCategory() == "espressor"))
		{
			espressors.push_back(*iter);
		}
	}
	return espressors;
}

list<User *> QuerySolver::Query_3b()
{
	list<User *> allUsers = server->getUsersList();
	list<User *> nonpremium;

	for (list<User *>::iterator iter = allUsers.begin(); iter != allUsers.end(); ++iter)
	{
		if (((*iter)->getUserType() == "nonPremium") && ((*iter)->getTransportCost() <= 11.5))
		{
			nonpremium.push_back(*iter);
		}
	}
	return nonpremium;
}

list<Product *> QuerySolver::Query_3c()
{
	list<Product *> allProducts = server->getProductsList();
	list<Product *> resealed;

	for (list<Product *>::iterator iterator = allProducts.begin(); iterator != allProducts.end(); ++iterator)
		if (((*iterator)->getProductType() == "resigilat"))
			if (ResealedProduct *rslProd = dynamic_cast<ResealedProduct *>(*iterator))
				if (rslProd->getReason() == "lipsa_accesorii")
					resealed.push_back(*iterator);

	resealed.sort(Utility::sort_ReasealedProducts__Price);
	return resealed;
}

list<Product *> QuerySolver::Query_3d()
{
	list<Product *> allProducts = server->getProductsList();
	list<Product *> allFoodProducts;

	for (list<Product *>::iterator iterator = allProducts.begin(); iterator != allProducts.end(); ++iterator)
		if (((*iterator)->getProductType() == "alimentar"))
			allFoodProducts.push_back(*iterator);

	allFoodProducts.sort(Utility::sort__FoodProducts__Name__Country__Price);
	return allFoodProducts;
}

list<User *> QuerySolver::Query_3e()
{
	list<User *> allUsers = server->getUsersList();
	list<User *> someUsers;

	string County = Utility::find__MostPopularCounty(allUsers);

	for (list<User *>::iterator iterator = allUsers.begin(); iterator != allUsers.end(); ++iterator)
		if (
			((*iterator)->getBillingData().getCounty() == County) &&
			((*iterator)->getBillingData().getBlock() == "-") &&
			((*iterator)->getBillingData().getApartment() == 0) &&
			((*iterator)->getDeliveryData().getBlock() == "-") &&
			((*iterator)->getDeliveryData().getApartment() == 0))
			someUsers.push_back(*iterator);

	someUsers.sort(Utility::sort__User__ID);
	return someUsers;
}

list<User *> QuerySolver::Query_3f()
{
	list<Product *> allProducts = server->getProductsList();
	list<User *> allUsers = server->getUsersList();
	list<User *> premiumUsers;
	list<User *>::iterator user;
	list<Product *>::iterator produs;
	map<int, int>::iterator ProductID;
	map<int, int> discountedProductsMap;

	for (user = allUsers.begin(); user != allUsers.end(); ++user)
		if ((*user)->getUserType() == "premium") // am gasit userul de tip "premium", iar acum va trebui sa facem dynamic cast la tipul de date PremiumUer pentru a avea acces la campul map discounts
			if (PremiumUser *premium = dynamic_cast<PremiumUser *>(*user))
			{
				discountedProductsMap = premium->getDiscounts();
				for (ProductID = discountedProductsMap.begin(); ProductID != discountedProductsMap.end(); ++ProductID)
					for (produs = allProducts.begin(); produs != allProducts.end(); ++produs)
						if ((*produs)->getId() == (*ProductID).first)
							if (((*produs)->getCategory() == "telefon") || ((*produs)->getCategory() == "imprimanta"))
								premiumUsers.push_back(*user);
			}

	return premiumUsers;
}
