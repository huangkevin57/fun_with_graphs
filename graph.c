#include "graph.h"


void floyd_warshall(distance_matrix g) {
	for (int k = 0; k < g.n; k++) {
		for (int i = 0; i < g.n; i++) {
			for (int j = 0; j < g.n; j++) {
				int dist = g.distances[g.n*i + k] + g.distances[g.n*k + j];
				if(dist < g.distances[g.n*i + j]) {
					g.distances[g.n*i + j] = dist;
				}
			}
		}
	}
}

void fill_dist_matrix(distance_matrix g)
{
	//Figure out distance from new node to each other node
	for(int i = 0; i < g.n-1; i++)
	{
		if(g.distances[g.n*i + g.n-1] == GRAPH_INFINITY)
		{
			int min_dist = GRAPH_INFINITY;
			for(int j = 0; j < g.n-1; j++)
				if(g.distances[g.n*(g.n-1) + j] == 1 
				   && g.distances[g.n*j + i] + 1 < min_dist)
					 min_dist = g.distances[g.n*j + i] + 1;
			g.distances[g.n*(g.n-1) + i] = g.distances[g.n*i + g.n-1] = min_dist;
		}
	}
	
	//One iteration of Floyd-Warshall with k = g.n - 1
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			int dist = g.distances[g.n*i + g.n-1] + g.distances[g.n*g.n-1 + j];
			if(dist < g.distances[g.n*i + j]) {
				g.distances[g.n*i + j] = dist;
			}
		}
	}
		
}

distance_matrix add_extra_node(distance_matrix input)
{
	distance_matrix output;
	output.n = (input.n + 1);
	output.distances = malloc(n*n*sizeof(*(out.distances)));
	for(int i = 0; i < input.n; i++)
		for(int j = 0; j < input.n; j++)
		output.distances[(output.n)*i + j)] = input.distances[(input.n)*i + j)];
	for(int i = 0; i  output n; i++)
	output.distances[(output.n)*i + output.n - 1] = output.distances[(output.n)*(output.n - 1) + i] = 1;
	return output
}