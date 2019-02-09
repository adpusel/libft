# include "ft_library_header.h"
/* C implementation QuickSort */
#include<stdio.h>

typedef struct s_sort
{
	void *big;
	void *little;
	void **arr;
	size_t all_size;
	int element_size;
} t_sort;

typedef struct nb_test
{
	int nb;
	int index;
} nb_test;

int printTestNb(void *test_nb)
{
	nb_test *test;
	test = test_nb;

	printf("nb : %d / ", test->nb);
	printf("%d\n", test->index);

	return TRUE;
}

void set_big_little(t_sort *sort, void *v_el)
{
	nb_test *el;

	el = v_el;
	if (sort->big == NULL)
	{
		sort->big = v_el;
		sort->little = v_el;
		return;
	}

	if (el->nb < ((nb_test *) sort->little)->nb)
		sort->little = el;
	if (el->nb > ((nb_test *) sort->big)->nb)
		sort->big = el;
}

/*
 * i need size of the array and push all struct inside,
 * i sort my ptr array,
 * not the el in the list
 * */
int init_arr_copy(t_array *array, t_sort *sort)
{
	nb_test *current_el = NULL;
	// je chope le premier element;
	current_el = array->arr;

	// je compte la list et je range les element q'avais dedans
	while (sort->all_size < array->arr_size)
	{
		set_big_little(sort, current_el);
		sort->all_size++;
		current_el++;
	}

	// je met ses element dans mon tab
	// faire attention au element a classer, les mettre correctement
	sort->arr = malloc(sort->all_size * sizeof(void **) * (sort->all_size + 1));
	sort->arr[0] = sort->little;
	sort->arr[sort->all_size - 1] = sort->big;

	printTestNb(sort->arr[0]);
	printTestNb(sort->arr[sort->all_size - 1]);



	// je le passe a ma fonction de set big // little

	// count element with my next function

	// mettre les elements dans mon array avec les


	return TRUE;
}
# define SIZE 6
// Driver program to test above functions
int main()
{
	//	int arr[] = { 10, 7, 8, 9, 1, 5 };
	//		int arr[] = {10, 5, 8, 9, 1, 11};
	nb_test arr[SIZE] = {
	 { 33,  1 },
	 { 234, 5 },
	 { 3,   2 },
	 { 4,   3 },
	 { -3,  0 },
	 { 99,  4 },
	};

	t_array arr_print = { SIZE, sizeof(nb_test), arr };

	t_sort sort = { 0 };

	init_arr_copy(&arr_print, &sort);

	//	print_array_func(&arr_print, printTestNb);

	printf("Sorted array: n");
	return 0;
}

// une fonction et un el qui dit si la list est trier
// 1 a la copie des element, quand je garde un ptr sur le plus grand et le plus petit
// 2 copie de +1 a -1
//   quand je rencontre le big or little, je le met au bon endroit
//   je n'est toujours pas de pivos si je fais ca
//   je passe dans ma list en gardant a chaque fois le plus grand et le plus petit,
//   je regarde a droite et a gauche si les nb sont different, si oui, je les echanges
//   et je comptinu a avancer, ma fonction de check diminu de 2 a chaque fois
//   je pense que cette nouvelle idee est la bonne
//   definitivement mieux pour trier














