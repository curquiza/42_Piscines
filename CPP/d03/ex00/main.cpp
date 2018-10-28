#include "FragTrap.hpp"

int		main ( void ) {

	{
		FragTrap	choupi("Choupi");
		FragTrap	albert("Albert");
		
		std::cout << std::endl;
		choupi.rangedAttack(albert.getName());
		albert.takeDamage(20);

		std::cout << std::endl;
		std::cout << "Candy for everyone !!!! 🍭" << std::endl;
		choupi.beRepaired(5);
		albert.beRepaired(5);

		std::cout << std::endl;
		albert.vaulthunter_dot_exe(choupi.getName());
		choupi.takeDamage(45);

		std::cout << std::endl;
		std::cout << choupi.getName() << " is very angry... 😡" << std::endl;
		choupi.meleeAttack(albert.getName());
		choupi.meleeAttack(albert.getName());
		choupi.meleeAttack(albert.getName());
		choupi.meleeAttack(albert.getName());
		albert.takeDamage(120);

		std::cout << std::endl;
		std::cout << albert.getName() << " is KO but " << choupi.getName() << " is still very angry... 😡 😡" << std::endl;
		choupi.vaulthunter_dot_exe(albert.getName());
		choupi.vaulthunter_dot_exe(albert.getName());
		choupi.vaulthunter_dot_exe(albert.getName());
		choupi.vaulthunter_dot_exe(albert.getName());
		choupi.vaulthunter_dot_exe(albert.getName());

		std::cout << std::endl;
		std::cout << "THE END !!" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---- CONSTRUCTORS TESTS ----" << std::endl;
	{
		FragTrap	a;
		FragTrap	b("Yoyo");
		FragTrap	c(a);
		FragTrap	d("titi");

		d = a;

		std::cout << "a name should be Boby -> " << a.getName() << std::endl;
		std::cout << "b name should be Yoyo -> " << b.getName() << std::endl;
		std::cout << "c name should be Boby -> " << c.getName() << std::endl;
		std::cout << "d name should be Boby -> " << d.getName() << std::endl;

		std::cout << std::endl;
		std::cout << "Clearing out the energy of a :" << std::endl;
		a.vaulthunter_dot_exe(b.getName());
		a.vaulthunter_dot_exe(b.getName());
		a.vaulthunter_dot_exe(b.getName());
		a.vaulthunter_dot_exe(b.getName());
		a.vaulthunter_dot_exe(b.getName());

		std::cout << std::endl;
		std::cout << "Vault on c (copy of a) :" << std::endl;
		c.vaulthunter_dot_exe(b.getName());

		std::cout << std::endl;
		std::cout << "Vault on d (= a) :" << std::endl;
		d.vaulthunter_dot_exe(b.getName());

		std::cout << std::endl;
	}
	return 0;
}