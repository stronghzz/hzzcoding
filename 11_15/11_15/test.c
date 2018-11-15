//strchr()函数与strrchr()函数的实现




char *my_strchr(const char *s, int c)
{
	if (s == NULL)
	{
		return NULL;
	}

	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return (char *)s;
		}
		s++;
	}
	return NULL;
}
char *strrchr(const char *s, int c)
{
	if (s == NULL)
	{
		return NULL;
	}

	char *p_char = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			p_char = (char *)s;
		}
		s++;
	}

	return p_char;
}
