/*
 *  dijkstra.c
 *  ProgrammingPortfolio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "graph.h"
#include "dijkstra.h"
#define   SIZE 512

/* find shortest paths between source node id and all other nodes in graph. */
/* upon success, returns an array containing a table of shortest paths.  */
/* return NULL if *graph is uninitialised or an error occurs. */
/* each entry of the table array should be a Path */
/* structure containing the path information for the shortest path between */
/* the source node and every node in the graph. If no path exists to a */
/* particular desination node, then next should be set to -1 and weight */
/* to DBL_MAX in the Path structure for this node */
Path *dijkstra(Graph *graph, int id, int *pointerToEntry)
{
    Path *table;
    Edge *edge; 
    int *unvisited;
    int *visited;
    int *notHop;
    int *hopGot;
    double *unreachedWeights;
    double *weights;
    int counter;
    int x;
    int i, j;
    int maxSize;
    int shortestDistance;
    double weight;
    
    /*int index;*/

    /*stops warning errors*/
    table = NULL;

    /*=================ERROR CHECKING=====================*/
    if(graph == NULL)
    {
        fprintf(stderr, "warning: unable to initialise graph");
        return table;
    }
    if(find_vertex(graph, id) == NULL)
    {
        fprintf(stderr, "warning: unable to find network\n");
        return table;
    }

    unvisited = calloc(SIZE, sizeof(int));
    x = 0;
    i = 1;
    while (i < SIZE)
    {
        if (i == id || find_vertex(graph, i) != NULL)
        {
            unvisited[x] = i;
            x++;
        }
        i++;
    }

    /* ================CALCULALTES ARRAY SIZES================*/
    counter = 0;
    i=0;
    while(unvisited[i]!=0)
    {
        counter++;
        i++;
    }
    i=0;

    maxSize=0;
    i=0;
    while(i<counter)
    {
        if(unvisited[i] > maxSize)
        {
            maxSize = unvisited[i];
        }
        i++;
    }
    *pointerToEntry = maxSize+1;

    /*====================INITIALISE ALL ARRAYS=======================*/
    notHop = calloc(*pointerToEntry, sizeof(int));
    unreachedWeights = calloc(*pointerToEntry, sizeof(double));
    hopGot = calloc(*pointerToEntry, sizeof(int));
    weights = calloc(*pointerToEntry, sizeof(double));
    visited = calloc(counter + 1, sizeof(int));
    i=0;
    while (i < counter) 
    {

        edge = get_edge(graph, id, unvisited[i]);
        if (edge == NULL) 
        {
            unreachedWeights[unvisited[i]] = DBL_MAX;
            notHop[unvisited[i]] = 0;
        } 
        if(edge != NULL)
        {
            unreachedWeights[unvisited[i]] = edge->weight;
            notHop[unvisited[i]] = unvisited[i];
        }
        i++;
    }

   

    /*====INITIALISE VISITED ARRAY, HOPS AND WEIGHTS STARTS VALUE OF VISITED NETWORK=====*/
     i = 0;
    while (i < *pointerToEntry)
    {
        hopGot[i] = notHop[i];
        weights[i] = unreachedWeights[i];
        i++;
    }
    
    /*===================ITERATE AND FIND SMALLEST WEIGHT============================*/
    while (i < *pointerToEntry) 
    {
        weight = DBL_MAX;
        j = 0;
            while (j < *pointerToEntry)
            {
                if (!(weights[j]))
                {
                    j++;
                }
                 if (weights[j] < weight) 
                {
                    weight = weights[j];
                    shortestDistance = j;
                }
            j++;
            }
        weights[shortestDistance] = 0;
        j = 0;
        while (j < *pointerToEntry)
        {
            weights[j] = unreachedWeights[j];
            hopGot[j] = notHop[j];
            j++;
        }
        visited[i + 1] = shortestDistance;
        i++;
    }

   i = 0;
    while (i < *pointerToEntry) 
    {
        if (notHop[i] == 0)
        {
            notHop[i] = -1;
            unreachedWeights[i] = DBL_MAX;
        }
        i++;
    }

    table = calloc(*pointerToEntry, sizeof(Path));
    
    i = 0;
    while (i < *pointerToEntry)
    {
        table[i].next_hop = notHop[i];
        table[i].weight = unreachedWeights[i];
        i++;
    }    
    return table;
}


