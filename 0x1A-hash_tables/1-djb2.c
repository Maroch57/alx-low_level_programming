/**
 * hash_djb2 - ensures implementation of the djb2 algorithm.
 * @str: the string that ensures generation of hash value.
 *
 * Return: hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
