int	ft_printf(const char *fmt, ...);

int main(int ac, char **av)
{
	ft_printf("String with %% symbol\n");
	ft_printf("String with %s symbol\n", "INSIDE");
	return (0);
}
