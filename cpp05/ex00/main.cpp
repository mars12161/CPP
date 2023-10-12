#include "Bureaucrat.hpp"

int	main(void) {

	Bureaucrat peter("Peter", 125);
	std::cout << peter << std::endl;
	try {
		Bureaucrat bureaucrat("Bob", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("Foo", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		peter.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		peter.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << peter << std::endl;
}