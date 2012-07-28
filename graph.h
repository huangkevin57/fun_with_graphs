#ifndef GRAPH_H

#include "nauty.h"

//Represents when there is no connection
//graph.c adds stuff to infinity (crazy, I know),
//So make sure it won't overflow
#define GRAPH_INFINITY ((int)1000000)
#define MAX_K (int(3))
#define MAXN (int(10))

typedef struct {
	int *distances; //INFINITY for no connection
	int n; //number of vertices
	int sum_of_distances;
	int m;
	int *k;
	int diameter;
	int max_k;
} distance_matrix;

void floyd_warshall(distance_matrix g);
void fill_dist_matrix(distance_matrix g);

#define GRAPH_H
#endif //GRAPH_H
