#include<stdio.h>
#include<pthread.h>

#define MAX 10

pthread_mutex_t lock;
pthread_cond_t cond;

int counter=1;

void* print_even(void *arg)
{
	while(counter<=MAX)
	{
		pthread_mutex_lock(&lock);
	
		while(counter%2!=0)
		{
			pthread_cond_wait(&cond,&lock);
		}

		if(counter<=MAX)
		{
			printf("even : %d\n",counter);
			counter++;
		}

		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

void* print_odd(void *arg)
{
	while(counter<=MAX)
	{
		pthread_mutex_lock(&lock);
	
		while(counter%2==0)
		{
			pthread_cond_wait(&cond,&lock);
		}

		if(counter<=MAX)
		{
			printf("odd : %d\n",counter);
			counter++;
		}

		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main()
{
	pthread_t th1,th2;

	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&cond,NULL);

	pthread_create(&th1,NULL,print_even,NULL);
	pthread_create(&th2,NULL,print_odd,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);

	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);

	return 0;
}



