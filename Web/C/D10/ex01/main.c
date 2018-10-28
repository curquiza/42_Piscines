void	ft_foreach(int *tab, int length, void(*f)(int));
void	ft_putnbr(int nb);

int 	main(void)
{
	int		tab[6] = {0, 12, -1, 13, -2, 14};
	
	ft_foreach(tab, 6, &ft_putnbr);
	return (0);
}
