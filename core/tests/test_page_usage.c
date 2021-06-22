# include "../inc/core.h"

int	main(int argc, char **argv)
{
	t_page	p;

	p = page(1);
	page_read_file(&p, argv[1]);
	page_print(p);
	page_write_file(argv[2], &p, CR_APPEND);
	page_free(&p);
}
