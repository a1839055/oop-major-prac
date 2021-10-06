test_burger:
	g++ item.cpp ingredient.cpp burger.cpp tests/test_burger.cpp -o test_burger
test_drink:
	g++ item.cpp sized_item.cpp drink.cpp tests/test_drink.cpp -o test_drink