/*
	ret = printf("non-supported conversion %b\n", "test");
	printf("ret is %d\n", ret);

	ret = printf("wrong argument %s\n", 1);
	printf("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%010p'\n", NULL);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing test_pointer %%p '%010p'\n", NULL);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("testing test_pointer %%p '%0p'\n", NULL);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing test_pointer %%p '%0p'\n", NULL);
	printf_ptr("ret is %d\n", ret);

		ret = printf("testing string '%0100.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf("ret is %d\n", ret);


	ret = printf("16 '%#+1.5d' '%#+1.5i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

	ret = printf("17 '%-#+1.5d' '%-#+1.5i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

	ret = printf("18 '%-#+ 1.5d' '%-#+ 1.5i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

	ret = printf("19 '%#-+ 1.5d' '%#-+ 1.5i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

	ret = printf("20 '% #-1.5d' '% #-1.5i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);
	
	ret = printf("21 '% #-1.0d' '% #-1.0i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

	ret = printf("22 '% #-10.10d' '% #-10.10i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

	ret = printf("23 '% #-10d' '% #-10i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

		ret = printf("18 '%-+ 1.5d' '%-+ 1.5i'\n", signed_int, signed_int);
	printf("ret is %d\n", ret);

		ret = printf("18 '%-#+ 1.5o' '%-#+ 1.5u' '%-#+ 1.5x' '%-#+ 1.5X'\n", uint, uint, uint, uint);
	printf("ret is %d\n", ret);

*/