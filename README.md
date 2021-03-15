# eStore-platform-c++

### Description

This is a c++ program that follows the example of an online ecommerce store, where there is a server with json data about products, clients, addresses. A user can perform minimalistic tasks, such like adding a product in his cart, removing it, searching a product on the server by different attributes. It can also have a plan (basic, premium) that brigns them some benefits (like transport decuction).

### Implementation

* The implementation follows OOP concepts (abstraction, encaplsulation, inheritance, polymorphism). 
* The design pattern used is singleton.
	* Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object. 
	* This is useful when exactly one object is needed to coordinate actions across the system (our server). 
* All the data is stored in JSON format, using a JSON library called nlohmann-json. Check it out [here](https://github.com/nlohmann/json) 

### Project structure

```bash
src/
┣ Solution/
┃ ┣ LRUCache/
┃ ┃ ┣ LRUCache.cpp
┃ ┃ ┗ LRUCache.h
┃ ┣ Product/
┃ ┃ ┣ DiscountedProduct.cpp
┃ ┃ ┣ DiscountedProduct.h
┃ ┃ ┣ FoodProduct.cpp
┃ ┃ ┣ FoodProduct.h
┃ ┃ ┣ NonFoodProduct.cpp
┃ ┃ ┣ NonFoodProduct.h
┃ ┃ ┣ Product.cpp
┃ ┃ ┣ Product.h
┃ ┃ ┣ ResealedProduct.cpp
┃ ┃ ┣ ResealedProduct.h
┃ ┃ ┣ ReturnedProduct.cpp
┃ ┃ ┗ ReturnedProduct.h
┃ ┣ Server/
┃ ┃ ┣ Server.cpp
┃ ┃ ┗ Server.h
┃ ┣ ShoppingCart/
┃ ┃ ┣ ShoppingCart.cpp
┃ ┃ ┗ ShoppingCart.h
┃ ┣ User/
┃ ┃ ┣ Address.cpp
┃ ┃ ┣ Address.h
┃ ┃ ┣ BasicUser.cpp
┃ ┃ ┣ BasicUser.h
┃ ┃ ┣ PremiumUser.cpp
┃ ┃ ┣ PremiumUser.h
┃ ┃ ┣ User.cpp
┃ ┃ ┗ User.h
┃ ┣ QuerySolver.cpp
┃ ┗ QuerySolver.h
┣ utils/ 
┃ ┣ objectFactory/ 
┃ ┃ ┣ objectFactory.cpp 
┃ ┃ ┗ objectFactory.h 
┃ ┣ FinalQuestionsHelper.cpp 
┃ ┣ FinalQuestionsHelper.h 
┃ ┣ JSONSerializer.cpp 
┃ ┣ JSONSerializer.h 
┃ ┣ TestHelper.cpp 
┃ ┣ TestHelper.h 
┃ ┣ utility.cpp
┃ ┗ utility.h
┣ json.hpp 
┗ main.cpp 
```

# Below there is the Product Hierarchy
![product-hierarchy](https://github.com/costingh/eStore-platform-cpp/blob/master/README-producthierarchy.jpg?raw=true)

![product](https://github.com/costingh/eStore-platform-cpp/blob/master/README-produs.png?raw=true)

# Below there is the User Hierarchy
![user-hierarchy](https://github.com/costingh/eStore-platform-cpp/blob/master/README-userhierarchy.png?raw=true)

# Example of json response

### Marketing analisys

* All users that have the same delivery and billing address, and lives in the city with the most users. The list is sorted after users id.

	* ```json
	{
	    "type": "nonPremium",
	    "UserId": 1278,
	    "firstName": "Ecaterina",
	    "lastName": "Stefan",
	    "email": "ecaterinastefan@gmail.com",
	    "billingData": {
	      "county": "Mures",
	      "locality": "Iernut",
	      "street": "Mihai_Viteazu",
	      "number": 122,
	      "block": "-", //adresa facturare la casa
	      "apartment": 0
	    },
	    "deliveryData": {
	      "county": "Mures",
	      "locality": "Iernut",
	      "street": "Mihai_Viteazu",
	      "number": 122,
	      "block": "-", //adresa livrare la casa
	      "apartment": 0
	    },
	    "costTransport": 12.80
	  }
	  ```
 
* Show the premium users that have deduction cupons for a certain type of product (all the cupons are generated automatically)
	* ```json
		{
		    "type": "premium",
		    "UserId": 2163,
		    "firstName": "Magdalena",
		    "lastName": "Apostol",
		    "email": "magdalenaapostol@gmail.com",
		    "billingData": {
		      "county": "Calarasi",
		      "locality": "Fundulea",
		      "street": "Parcului",
		      "number": 132,
		      "block": "X13",
		      "apartment": 10
		    },
		    "deliveryData": {
		      "county": "Calarasi",
		      "locality": "Fundulea",
		      "street": "Parcului",
		      "number": 132,
		      "block": "X13",
		      "apartment": 10
		    },
		    "premiumSubscriptionCost": 98.75,
		    "discounts": [    //exemplu map reduceri
		      [
			1435,
			10
		      ],
		      [
			3669,
			8
		      ],
		      [
			2497,
			24
		      ],
		      [
			5402,
			17
		      ],
		      [
			2888,
			24
		      ]
		    ]
		  }
		  ```
  
# Features

## Last Recently Used Cache

Store the id of the last n searched products, where n is the cache array capacity.
 
### Installing

* **Run this command** git clone https://github.com/costingh/eStore-platform-cpp.git
* To run this project, the operationg system must be linux (or linux subsystem like WSL2 - on Windows 10)

## Checker and testing

There are two entities used for this operations:
* The checker (data, in, out - folders)
* TestHelper Class (src/utils/TestHelper.h, TestHelper.cpp)

### Checker

#### The checker contains 3 folders:
* data - all the data stored in json format (not all tests needs all the data)
* out - the output resulted after the program execution
* ref - the refference (if the output value is the same as ref value, then the action was performed correctly)

### TestHelper

This is a class which tests every function implemented

#### Debugging

To debug the project, an executable must be created by running the following command: ** ./eStore date.in <output_file> <numar_test_din_main> **
* eStore is the executable name
* date.in is the folder that contains all that data
* <output_file> is the name of a folder that will be creted if it doesn't exist. (can have any name)
* <numar_test_din_main> is the index of the test from main.cpp which will check the test that needs to be debugged

### Tech Stack
* C++
