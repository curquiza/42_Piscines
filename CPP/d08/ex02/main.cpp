#include "mutantstack.hpp"
#include <vector>
#include <list>

void	displayInt(int n) {
	std::cout << " " << n;
}

template <typename T>
void	displayIntContainer(T & container) {
	std::for_each(container.begin(), container.end(), displayInt);
	std::cout << std::endl;
}

int		main (void) {

	std::cout << "----- MY MAIN - STACK -----" << std::endl;
	{
		MutantStack<int, std::list<int> >	m;

		m.push(1);
		m.push(2);
		m.push(3);
		m.push(4);
		m.push(9);

		std::cout << "current stack =";
		displayIntContainer(m);
		std::cout << "begin = " << *m.begin() << std::endl;
		std::cout << "end = " << *(--m.end()) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----- MY MAIN - LIST -----" << std::endl;
	{
		std::list<int>	l;

		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(9);

		std::cout << "current stack =";
		displayIntContainer(l);
		std::cout << "begin = " << *l.begin() << std::endl;
		std::cout << "end = " << *(--l.end()) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----- ZAZ MAIN ----" << std::endl;
	{
		MutantStack<int>    mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "current stack =";
		displayIntContainer(mstack);

		std::cout << "top = " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "current stack after pop =";
		displayIntContainer(mstack);

		std::cout << "size = " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		std::cout << "current stack after pushes =";
		displayIntContainer(mstack);

		std::cout << std::endl;
		std::cout << "Display with iterators :" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);		
	}

	return 0;
}