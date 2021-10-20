all: main tests

item.o: item.cpp item.h
	g++ -c item.cpp

sized_item.o: sized_item.cpp sized_item.h item.o
	g++ -c sized_item.cpp

ingredient.o: ingredient.cpp ingredient.h item.o
	g++ -c ingredient.cpp

burger.o: burger.cpp burger.h item.o ingredient.o
	g++ -c burger.cpp

drink.o: drink.cpp drink.h sized_item.o
	g++ -c drink.cpp

fries.o: fries.cpp fries.h sized_item.o
	g++ -c fries.cpp

cart.o: cart.cpp cart.h
	g++ -c cart.cpp

main: main.cpp menu.cpp fries.o burger.o drink.o cart.o burger_information.h drink_information.h fries_information.h
	g++ menu.cpp main.cpp -o main fries.o burger.o drink.o ingredient.o sized_item.o item.o cart.o -lpthread -std=c++17

tests: test_burger test_drink test_fries

test_burger: test_burger.cpp burger.o
	g++ tests/test_burger.cpp -o test_burger burger.o item.o ingredient.o
test_drink: test_drink.cpp drink.o
	g++ tests/test_drink.cpp -o test_drink drink.o sized_item.o item.o
test_fries: test_fries.cpp fries.o
	g++ tests/test_fries.cpp -o test_fries fries.o sized_item.o item.o

clean:
	rm -f main test_burger test_drink test_fries *.o

# Working compile command:
# g++ item.cpp sized_item.cpp fries.cpp ingredient.cpp burger.cpp drink.cpp cart.cpp menu.cpp main.cpp -o main -lpthread -std=c++17