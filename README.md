# CurrencyStoringAndFinder

## HOW TO RUN
At first create a file named "currencies.txt" in the same folder as the source code.
Then run this command
   `gcc _UCF_MINIPROJECT.c -o mini`
`./mini`
Default username = "username"
Default password = "pass123"

# ABSTRACT :
The above code is a C program that implements a doubly linked list data structure to create a collection of currencies. The program reads in a list of currencies from a text file, allowing the user to build up a collection of currencies with name, dynasty, king, and buy value information. The doubly linked list data structure provides a flexible and efficient way to store and manipulate the collection of currencies in this program.
The program starts by defining a struct called 'Currency_t', which contains the name, dynasty, king, buyValue, prev and next pointer. It then creates a series of functions to manipulate the linked list data structure. The createCurrency function is used to create a new node in the list and initialize its values, while the insertCurrency function adds a new node to the list and links the current last node with the new node.
The program also includes a findCurrency function which allows the user to search the collection of currencies for a specific coin by name. It compares the input name with the name of the nodes in the list and returns the currency if found. The printCurrency function is used to print the details of the specific node when called. Additionally, the program has a addCurrencyToFile function which allows user to add new coin to the file, and 14 printCurrencies function which prints the details of all the currencies in the collection.
The main function of the program reads in the currencies from a file and then prompts the user to search for a specific currency. If the currency is found, its details are printed, otherwise the user is prompted to add the currency to the collection. After the search, the program prints the details of all the currencies in the collection, displaying the total number of coins in the collection as well.
Overall, the program is a useful tool for building and managing a collection of currencies. The doubly linked list data structure allows for efficient manipulation of the collection, such as adding and removing currencies and searching for specific currencies. Additionally, it provides a user-friendly interface for interacting with the collection, allowing for easy search and addition of new currencies. It also provides the functionality to add new coin to the file and to print the details of all currencies in the collection.


