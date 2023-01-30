#include "./matrix.h"
#include "../libft/libft.h"
#include <stdio.h>

void print_vec(t_vec v){
	printf("%lf %lf %lf\n", v.x, v.y, v.z);
}
int main(void){
	t_mat4 a;
	a = _init_mat_(DEFAULT);
	print_mat(a);
	printf("\n\n");
	a = _init_mat_(I);
	print_mat(a);
		printf("\n\n");

	a = _mul_mat_(a, a);
	print_mat(a);
	printf("\n\n");

	double xyz[3][3] = {{1, 2, 3}, {1,2,3}, {1,2,4}};
	a = _make_cord_(xyz);
	print_mat(a);
		printf("\n\n");

	a = _mul_mat_(a, a);
			printf("\n\n");

	print_mat(a);

	t_vec v;
	v.x = 1;
	v.y = 2;
	v.z = 3;
	t_vec res = _mul_vec_mat(a, vec_2_arr_vec3(v));
	print_vec(res);
	printf("\n\n");

}