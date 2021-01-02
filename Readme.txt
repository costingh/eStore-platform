	#################################
	# Consideri că tema este utilă? #
	#################################
	
	- Da, am invatat foarte multe din aceasta tema, spre exemplu, am luat contact cu libraria JSON, m-am familiarizat cu esign pattern-ul Singleton, dar am vazut si o alta structura a makefile-ului
	
	################################################################
	# Consideri implementarea naivă, eficientă, se putea mai bine? #
	################################################################
	
	- Cred ca sunt destule lucruri care puteau fi imbunatatite petru a creste eficienta, dar in general cred ca e ok

	##########################################################################
	# De specificat dacă întregul enunț al temei e implementat sau ce bucăți #
	##########################################################################

	- Toate problemele au fost implementate si functioneaza corect, dupa cum reflecta si checker-ul

	#################
	# Corner cases: #
	#################
	
	- La exercitiul 3e, pentru a se obtine un output identic cu cel din fisierul ref, am observat ca lista este sortata crescator dupa id-urile userilor, lucru ce nu este specificat in enuntul problemei	
	

	######################
	# EXERCITIILE 1 SI 2 #
	######################

	- Am inceput prin implementarea metodelor din clasele propuse la exercitiile 1, 2 (fara a modifica fisierele .h), respectand regulile de derivare si agregare
	-Exemplu de o metoda in care se poate observa apelul in clasa derivata (NonFoodProduct) la o metoda (operator=) din clasa de Baza (Product):
	 __________________________________________________________________________
	|const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)  |
	|{									   |
	|	if (this != &a)							   |
	|	{								   |
	|		Product::operator=(a);                                     |
	|		producer = a.producer;                                     |
	|		yearsOfWarranty = a.yearsOfWarranty;                       |
	|		price = a.price;                                           |
	|	}                                                                  |
	|	return *this;                                                      |
	|}                                                                         |
	|__________________________________________________________________________|

	################
	# EXERCITIUL 3 #
	################

	Pentru exercitiul 3 am creat 4 metode ajutatoare in clasa utility:
		= >static bool sort_ReasealedProducts__Price(Product *, Product *); 		
			| aceasta metoda face compararea a 2 obiecte de tip Product in functie de pret (camp ce se afla in clasa NonFoodProduct, derivata din clasa Product,
			| deci pentru a avea acces la aceasta clasa, se va face dynamic_cast
    		=> static bool sort__FoodProducts__Name__Country__Price(Product *, Product *);	
    			| aceasta metoda compara 2 produse de tip FoodProducts in functie de nume, tara de provenienta, si pret
			| campurile menitionate mai sus se afla in clasa derivata FoodProduct, deci vom face dynamic_cast de la clasa Product la clasa FoodProduct
			| se compara numele, daca sunt egale se compara numele tarii de provenienta, iar daca si acestea sunt egale, se va compara pretul
		=> static bool sort__User__ID(User *, User *);
			| metoda care compara ID-urile a 2 useri	
			| la exercitiul 3e, pentru a se obtine un output identic cu cel din fisierul ref, am observat ca lista este sortata crescator dupa id-urile userilor, lucru ce nu este specificat in enuntul problemei					=> static string find__MostPopularCounty(list<User *>);				
			| metoda care gaseste judetul cu cei mai multi utilizatori

		Primele trei functii (care incep cu sort___) se dau ca parametru functiei specializate std::sort()    --> A se observa utilizarea keyword-ului static
		EXEMPLU: 
			lista.sort(Utility::sort__FoodProducts__Name__Country__Price); --> se transmite doar referinta functiei
		OBSERVATIE: Daca functiile nu erau declarate ca static, atunci linia de mai sus ar fi trebuit modificata:
			Utility utils;
			lista.sort(utils.sort__FoodProducts__Name__Country__Price);
	
	################
	# EXERCITIUL 4 #
	################
		
	- nu a fost implementata nici o alta metoda in plus fata de cele specificate
	- folosind exemplul din enuntul exercitiului a fost implementata functia processRequests(vector<int> requestsNo) care introduce in vectorul cu o capacitate limitata, pe prima pozitie cate un element
	- daca vectorul este plin, se sterge ultimul element, se face o shiftare la dreapta, si se completeaza prima pozitie cu valoarea ce se doreste a fi introdusa
	- daca se incearca introducerea in vector a unei valori deja existente in continutul acestuia, se va elimina aceasta valoarea deja existenta in vector, se va face o shiftare la dreapta a tuturor valorilor aflate la stanga acestui 	  element si se va introduce pe prima pozitie noul element

	################
	# EXERCITIUL 5 #
	################
	
	- Au fost implementate cele doua metode requestAddProduct si requestDeleteProduct