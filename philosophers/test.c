#include "philo_two/philo.h"

void	*fun(void* param)
{
	int *i = (int*)param;

	while (1)
	{
		if (*i >= 10)	
		{
			printf("exit =(\n");
			exit(0x0);
		}	
		*i += 1;
		printf("%d\n", *i);
	}
}

int main()
{
	pthread_t th;
	int x = 0;

	pthread_create(&th, NULL, fun, &x);
	printf("waiting\n");
	pthread_join(th, NULL);
	printf("hello world\n");
	return 0;
}