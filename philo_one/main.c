#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void		*yes(void *arr)
{
	int i = 0;
	while (1)
	{
		printf("Yes! [%d]\n", i++);
		usleep(500000);
	}	
	return (NULL); 
}

void		*no(void *arr)
{
	int i = 0;

	while (1)
	{
		printf("No! [%d]\n", i++);		
		usleep(500000);
	}
	return (NULL); 
}

int			main(int argc, char **argv)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, yes, NULL);
	pthread_create(&thread, NULL, no, NULL);
	pthread_join(thread, NULL);
}