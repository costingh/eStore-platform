#include "utility.h"
#include <set>
#include <fstream>

bool Utility::sort_ReasealedProducts__Price(Product *p1, Product *p2)
{
    NonFoodProduct *n1 = dynamic_cast<NonFoodProduct *>(p1);
    NonFoodProduct *n2 = dynamic_cast<NonFoodProduct *>(p2);

    return (n1->getPrice() < n2->getPrice());
}

bool Utility::sort__FoodProducts__Name__Country__Price(Product *p1, Product *p2)
{
    FoodProduct *fp1 = dynamic_cast<FoodProduct *>(p1);
    FoodProduct *fp2 = dynamic_cast<FoodProduct *>(p2);

    string name1 = p1->getName();
    string name2 = p2->getName();

    string country1 = fp1->getCountryOfOrigin();
    string country2 = fp2->getCountryOfOrigin();

    float price1 = fp1->getLeiPerKg();
    float price2 = fp2->getLeiPerKg();

    if (name1 < name2)
        return true;
    else if (name1 == name2)
    {
        if (country1 < country2)
            return true;
        else if (country1 == country2)
        {
            if (price1 < price2)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Utility::sort__User__ID(User *usr1, User *usr2)
{
    return (usr1->getUserID() < usr2->getUserID());
}

string Utility::find__MostPopularCounty(list<User *> allUsers)
{
    list<string> countyNamesList; // Vom crea o lista cu toate judetele ce apar in lista cu useri
    int max = 0;
    string County = "";

    for (list<User *>::iterator iterator = allUsers.begin(); iterator != allUsers.end(); ++iterator) // Din lista de useri extragem judetul fiecaruia
        countyNamesList.push_back((*iterator)->getBillingData().getCounty());                        // iar apoi il introducem in noua lista

    for (list<string>::iterator CountyName = countyNamesList.begin(); CountyName != countyNamesList.end(); ++CountyName) // Luam cate un nume din lista creata mai sus
    {
        int x = count(countyNamesList.begin(), countyNamesList.end(), *CountyName); // aflam de cate ori acesta se regaseste in lista
        if (x > max)                                                                // daca este numarul de aparitii este cel mai mare
        {
            max = x;
            County = *CountyName; // memoram numele acestui judet
        }
    }

    return County; // si il returnam
}
