main:
	g++ burger.cpp drink.cpp fries.cpp ingredient.cpp item.cpp sized_item.cpp menu.cpp main.cpp -o main -lpthread -std=c++17
test_burger:
	g++ item.cpp ingredient.cpp burger.cpp tests/test_burger.cpp -o test_burger
test_drink:
	g++ item.cpp sized_item.cpp drink.cpp tests/test_drink.cpp -o test_drink
test_fries:
	g++ item.cpp sized_item.cpp fries.cpp tests/test_fries.cpp -o test_fries