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

main: main.cpp menu.cpp utils.cpp payment_system.cpp payment_system.h utils.h fries.o burger.o drink.o cart.o burger_information.h drink_information.h fries_information.h
	g++ menu.cpp utils.cpp main.cpp payment_system.cpp -o main fries.o burger.o drink.o ingredient.o sized_item.o item.o cart.o -lpthread -std=c++17

tests: test_burger test_drink test_fries test_item test_ingredient test_sized_item

test_burger: tests/test_burger.cpp utils.cpp burger.o
	g++ tests/test_burger.cpp utils.cpp -o test_burger burger.o item.o ingredient.o
test_drink: tests/test_drink.cpp utils.cpp drink.o
	g++ tests/test_drink.cpp utils.cpp -o test_drink drink.o sized_item.o item.o
test_fries: tests/test_fries.cpp utils.cpp fries.o
	g++ tests/test_fries.cpp utils.cpp -o test_fries fries.o sized_item.o item.o
test_cart: tests/test_cart.cpp utils.cpp utils.h cart.o burger.o fries.o drink.o
	g++ tests/test_cart.cpp utils.cpp utils.h -o test_cart cart.o burger.o fries.o drink.o ingredient.o sized_item.o item.o
test_item: tests/test_item.cpp item.o utils.cpp
	g++ tests/test_item.cpp utils.cpp -o test_item item.o
test_ingredient: tests/test_ingredient.cpp ingredient.o item.o utils.cpp
	g++ tests/test_ingredient.cpp utils.cpp -o test_ingredient ingredient.o item.o
test_sized_item: tests/test_sized_item.cpp item.o utils.cpp sized_item.o
	g++ tests/test_sized_item.cpp utils.cpp -o test_sized_item item.o sized_item.o

clean:
	rm -f main test_burger test_drink test_fries *.o