#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/User/User.h"

class Utility
{

public:
    static bool sort_ReasealedProducts__Price(Product *, Product *);
    static bool sort__FoodProducts__Name__Country__Price(Product *, Product *);
    static bool sort__User__ID(User *, User *);
    static string find__MostPopularCounty(list<User *>);
};