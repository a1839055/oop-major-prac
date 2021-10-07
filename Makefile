all: main test

Item.o:
	g++ -c item.cpp

SizedItem.o: Item.o
	g++ -c sized_item.cpp

Ingredient.o: Item.o
	g++ -c ingredient.cpp

Burger.o: Item.o Ingredient.o
	g++ -c burger.cpp

Drink.o: SizedItem.o
	g++ -c drink.cpp

Fries.o: SizedItem.o
	g++ -c fries.cpp

main: Fries.o Burger.o Drink.o
	g++ menu.cpp main.cpp -o main -lpthread -std=c++17

tests: test_burger test_drink test_fries

test_burger: Burger.o
	g++ tests/test_burger.cpp -o test_burger
test_drink: Drink.o
	g++ tests/test_drink.cpp -o test_drink
test_fries: Fries.o
	g++ tests/test_fries.cpp -o test_fries