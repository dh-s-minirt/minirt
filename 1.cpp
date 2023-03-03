#include <pthread.h>
#include <stdio.h>
#include <math.h>

using namespace std;

#define N 16
const int ROW = 1536000 * 2;

double res[N][ROW];

double calc(double a, double b)
{
	return pow(sqrt(cos(a) * sin(b) + 1), 38);
}

void	*calculate(void *data)
{
	int thread_n = *(int *)data;
	int n;
	
	for (int k = 0; k < 10; k++)
		for (int i = 0; i < ROW; i++)
			res[thread_n][i] = calc(thread_n, i);
	return (NULL);
}

int main(void)
{
	int arr[N];
	pthread_t tid[N];
	int n;

	for (int i = 0; i < N; i++)
		arr[i] = i;
	for (int i = 0; i < N; i++)
		pthread_create(&(tid[i]),NULL,calculate, (void*)&(arr[i]));
	for (int i = 0; i < N; i++)
		pthread_join(tid[i], NULL);
	// for (int k =0; k < 10; k++){
	// 	for (int j = 0; j < N; j++){
	// 		for (int i = 0; i < ROW; i++)
	// 			res[j][i] = calc(j, i);
	// 	}
	// }
	// for (int j = 0; j < N; j++){
	// 	for (int i = 0; i < ROW; i++)
	// 		printf("%.1lf ", res[j][i]);
	// 	printf("\n");
	// }
}