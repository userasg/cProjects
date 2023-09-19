#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

/* initialise an empty graph */
/* return pointer to initialised graph */
Graph *init_graph(void)
{
    /*make a graph pointer and initialise and return pointer*/
    Graph *graph;
    graph = initialise_linked_list();
    /*error message to see if it returns a null pointer*/
    if(graph == NULL){
        fprintf(stderr, "warning: unable to intialise graph\n");
        return NULL;
    }
    /*return graph pointer*/
    return graph;
}



/* release memory for graph */
void free_graph(Graph *graph)
{
    Node *node;
    /*need to check if the graph is null gotten from the params*/
    if(graph == NULL)
    {
        fprintf(stderr, "warning: unable to free graph\n");
    }
    /*if its not null remove head of linekd list and free the verteces*/
    if(graph !=NULL)
    {
        /*error was being caused by not initialising the graph*/
        graph = init_graph();
        node = graph->head;
        while(node)
        {
            free_vertex(node->data);
            remove_head_linked_list(graph);
        }
        /*then free the graph*/
        free_linked_list(graph);
    }
}


/* initialise a vertex */
/* return pointer to initialised vertex */
Vertex *init_vertex(int id)
{
    /*need a vertex pointer*/
    Vertex *vertex;
    /*need memory for the vertex pointer*/
    vertex = malloc(sizeof(Vertex));
    /*if the pointer is null return the error message*/
    if(vertex == NULL)
    {
        fprintf(stderr, "warning: unable to intialise vertex\n");
        return NULL;
    }
    /*id part of vertex set to id param*/
    vertex->id = id;
    /*then cause vertex edges are a linked list we init them */
    vertex->edges = initialise_linked_list();
    return vertex;
}

/* release memory for initialised vertex */
void free_vertex(Vertex *vertex)
{
    Node *node;

    /*error at the start of every func to see if null vertex*/
    if(vertex == NULL)
    {
        fprintf(stderr, "warning: unable to free vertex\n");
    }
    /*if not null make the node pointer the head of the linked list in the vertex struct*/
    if(vertex != NULL)
    {
        node = vertex->edges->head;
        while(node)
        {
            /*remove head and move onto to next*/
            remove_head_linked_list(vertex->edges);
            node = vertex->edges->head;
        }
        /*free the linked list of edges in the vertex struct*/
        free_linked_list(vertex->edges);
        /*free the vertex struct*/
        free(vertex);
    } 
}

/* initialise an edge. */
/* return pointer to initialised edge. */
Edge *init_edge(void)
{
    /*need to malloc size for an edge pointer*/
    Edge *edge = malloc(sizeof(Edge));

    if(edge == NULL)
    {
        fprintf(stderr, "warning: unable to allocate memory for edge\n");
        return NULL;
    }
    /*setting the parts of the the edge struct to null*/
    edge->weight = 0.0;
    edge->vertex = NULL;
    return edge;
}

/* release memory for initialised edge. */
void free_edge(Edge *edge)
{
    if(edge == NULL)
    {
        fprintf(stderr, "warning: unable to free edge\n");
    } 
    /*
    edge->weight = 0.0;
    edge->vertex = NULL;*/

    free(edge);
}

/* remove all edges from vertex with id from to vertex with id to from graph. */
void remove_edge(Graph *graph, int from, int to)
{
    /*need a vertex to and from pointer to know which one is which*/
    Vertex *vertexFrom, *vertexTo;
    /*two node pointers to hold data whilst removing an edge */
    Node *node, *node2;
    Edge *edge;
    /*get the vertex from using the find_vertex function using the from id*/
    vertexFrom = find_vertex(graph, from);
    if(vertexFrom != NULL)
    {
        /*if its not null move onto the next find vertex*/
        vertexTo = find_vertex(graph, to);
        if(vertexTo == NULL)
        {
            /*if thats null warning message*/
            fprintf(stderr, "warning: unable to remove edges\n");
        }
        /*
        if(vertexFrom == NULL)
        {
            fprintf(stderr, "warning: unable to remove edges\n");
        } */
        if(vertexTo != NULL)
        {
            /*set up 2 node pointers and point to the head of vertex linked list*/
            node = initialise_node();
            node->next = vertexFrom->edges->head;
            node2 = initialise_node();
            node2 = node;
            while(node2)
            {
                if(node2 == NULL)
                {
                    break;
                }
                edge = init_edge();
                edge->vertex = node2->data;
                if(vertexTo == edge->vertex)
                {
                    /*using nodes move the prev and next values to next*/
                    if(node2->prev != NULL)
                    {
                        node2->prev->next = node2->next;
                    }
                    if(node2->prev == NULL)
                    {
                        node->prev = node2->next;
                    }
                    if(node2->next != NULL)
                    {
                        node2->next->prev = node2->prev;
                    }
                    if(node2->next == NULL)
                    {
                        node = node2->prev;
                    }
                    free_edge(edge);
                    free_node(node2);
                    node2 = node;
                }
                else
                {
                    node2 = node2->prev;
                }
            }
        }
    }
    else
    {
    /*error message for from*/
     fprintf(stderr, "warning: unable to remove edges\n");   
    }

}

/* remove all edges from vertex with specified id. */
void remove_edges(Graph *graph, int id)
{
    /*innit a linked list pointer for edges*/
    LinkedList *edges;
    Vertex *vertex;
    Node *node;
    /*again if null print an error*/
    if(graph == NULL)
    {
        fprintf(stderr, "warning: unable to remove edge\n");
    }

    /*get a vertex from the graph*/
    vertex =  find_vertex(graph, id);
    if(vertex == NULL)
    {
        fprintf(stderr, "warning: unable to remove edge\n");
    }
    /*if its not null set the edge pointer and init the node*/
    if(vertex != NULL)
    {
        edges = vertex->edges;
        node = initialise_node();
        /*while node is valid point node to head if its empty break out of while loop*/
        while(node)
        {
            node = edges->head;
            if(node == NULL){
                break;
            }
            /*free the edge and loop removing the edges*/
            free_edge(node->data);
            remove_head_linked_list(edges);
        }
    }

}

/* output all vertices and edges in graph. */
/* each vertex in the graphs should be printed on a new line */
/* each vertex should be printed in the following format: */
/* vertex_id: edge_to_vertex[weight] edge_to_vertex[weight] ... */
/* for example: */
/* 1: 3[1.00] 5[2.00] */
/* indicating that vertex id 1 has edges to vertices 3 and 5 */
/* with weights 1.00 and 2.00 respectively */
/* weights should be output to two decimal places */
void print_graph(Graph *graph)
{
    Node *node;
    Vertex *vertex;
    Edge *edge;
    Node *nodeEdge;
    if (graph == NULL) 
    {
        fprintf(stderr, "warning: unable to print graph\n");
        return;
    }

    if(graph != NULL) 
    {
        /*set a node pointer to head of the graph*/
        node = graph->head;
        while(node)
        {   
            /*if at any point the node is pointing to null break out of while loop*/
            if (node == NULL)
             {
                break;
             }
        /*set the vertex pointer to the nodes data*/
        vertex = node->data;
        /*set a node edge pointer to the head of the edges list*/
        nodeEdge = vertex->edges->head;
        /*print the vertex ids*/
        printf("%d:", vertex->id);
        /*then the node edge for each edge is not nul*/
        while (nodeEdge != NULL)
         {
            edge = nodeEdge->data;  
            /*print the data*/
            printf(" %d[%.2f]", edge->vertex->id, edge->weight);
            nodeEdge = nodeEdge->next;
         }
            printf("\n");
            node = node->next;
        }
    }
}

/* find vertex with specified id in graph. */
/* return pointer to vertex, or NULL if no vertex found. */
Vertex *find_vertex(Graph *graph, int id)
{
    Vertex* vertex;
    Node* node;

    if(graph == NULL){
        fprintf(stderr, "warning: unable to find vertex\n");
        /*returns null if empty graph*/
        return NULL; 
    }
    /*returns the vertex if the vertex id matches id provided */
    node = graph->head;
    while(node)
    {
        vertex = node->data;
        if(vertex->id == id)
        {
            return vertex;
        }
        node = node->next;
    }
    return NULL;
}

/* create and add vertex with specified id to graph. */
/* return pointer to vertex or NULL if an error occurs. */
/* if vertex with id already exists, return pointer to existing vertex. */
Vertex *add_vertex(Graph *graph, int id)
{
    Vertex *vertex;

    if(graph == NULL)
    {
        fprintf(stderr, "warning: unable to add vertex\n");
        return NULL;
    }
    /*if its not null see if the vertex finds the vertex on graph*/
    if (graph != NULL)
    {

        vertex = find_vertex(graph, id);
        if(vertex != NULL)
        {
            /*if the vertex isnt null it means it already exists so return that*/
            return vertex;
        }
        if(vertex == NULL)
        {
            /*if not init the vetext based on id and appened the graph with the vertex*/
            vertex = init_vertex(id);
            append_linked_list(graph, vertex);
            return vertex;
        }
    }
    /*return because causing warning*/
    return vertex;
}

/* remove vertex with specified id from graph. */
/* remove all edges between specified vertex and any other vertices in graph. */
void remove_vertex(Graph *graph, int id)
{
    Vertex *vertex;
    Node *node, *node2;
    Edge *edge;

    if(graph == NULL)
    {
        fprintf(stderr, "warning: unable to remove vertex\n");
    }
    vertex = find_vertex(graph, id);
    /*get vertex pointer*/
    if(vertex == NULL)
    {
        fprintf(stderr, "warning: unable to remove vertex\n");
    }
    if(vertex != NULL)
    {
        node = vertex->edges->head;
        /*while the first node pointer is valid remove the edge*/
        while(node)
        {
            edge = node->data;
            remove_edge(graph, id, edge->vertex->id);
            node = node->next;
        }
        node2 = graph->head;
        /*same process of insertion like before prev->next = next logic*/
        while(node2)
        {
            if(vertex == node2->data)
            {
                if(node2->prev != NULL)
                {
                    node2->prev->next = node2->next;
                }
                if(node2->prev == NULL) 
                {
                    graph->head = node2->next;
                }
                if(node2->next != NULL)
                {
                    node2->next->prev = node2->prev;
                }
                if(node2->next == NULL) 
                {
                    graph->tail = node2->prev;
                }
                free_vertex(vertex);
                free_node(node2);
                break;
            }
            node2 = node2->next;
        }
    }
}

/* add directed edge with specified weight between vertex with id from */
/* to vertex with id to. */
/* if no vertices with specified ids (from or to) exist */
/* then the vertices will be created. */
/* multiple vertices between the same pair of vertices are allowed. */
/* return pointer to edge, or NULL if an error occurs found. */
Edge *add_edge(Graph *graph, int from, int to, double weight)
{
    Edge *edge;
    Vertex *vertex_from, *vertex_to;

    if(graph == NULL){
        fprintf(stderr, "warning: unable to add edge\n");
        return NULL;
    }
    if(graph !=NULL)
    {
        vertex_from = find_vertex(graph, from);
        if(vertex_from == NULL)
        {
            /*adds a vertex from if pointer isnt null*/
            vertex_from = add_vertex(graph, from);
        }
        vertex_to = find_vertex(graph, to);
        if(vertex_to == NULL)
        {
            /*adds a vertex to if pointer is null*/
            vertex_to = add_vertex(graph, to);
        }

        if(vertex_from != NULL && vertex_to != NULL)
        {
            /*initialises an edge between from and two and sets the weight*/
            edge = init_edge();
            edge->weight = weight;
            /*then the vertex using vertex to*/
            edge->vertex = vertex_to;
            append_linked_list(vertex_from->edges, edge);
        }
        else
        {
            fprintf(stderr, "warning: unable to add edge\n");
            return NULL;
        }
    }

    return edge;
}

/* add two edges to graph, one from vertex with id from to vertex with id to, */
/* and one from vertex with id to to vertex with id from. */
/* both edges should have the same weight */
/* if no vertices with specified ids (from or to) exist */
/* then the vertices will be created. */
/* multiple vertices between the same pair of vertices are allowed. */
void add_edge_undirected(Graph *graph, int from, int to, double weight)
{
    
    Edge *edge;
    Vertex *vertex_from, *vertex_to;

    if(graph == NULL){
        fprintf(stderr, "warning: unable to add undirected edge\n");
    }
    if(graph != NULL)
    {
        vertex_from = find_vertex(graph, from);
        if(vertex_from == NULL)
        {
            vertex_from = add_vertex(graph, from);
        }
        vertex_to = find_vertex(graph, to);
        if(vertex_to == NULL)
        {
            vertex_to = add_vertex(graph, to);
        }
        /*similar process to above but have to do back and forth using from and to edge pointers to make undirected*/

        if(vertex_from != NULL)
        {
            if(vertex_to != NULL)
            {
                edge = init_edge();
                edge->weight = weight;
                edge->vertex = vertex_to;
                append_linked_list(vertex_from->edges, edge);
                edge = init_edge();
                edge->weight = weight;
                edge->vertex = vertex_from;
                append_linked_list(vertex_to->edges, edge);
            }
        }
    }

}

/* return array of node ids in graph. */
/* array of node ids should be dynamically allocated */
/* set count to be the number of nodes in graph */
/* return NULL if no vertices in graph */
int *get_vertices(Graph *graph, int *count)
{
    /*doesnt return correct values*/
    return 0;
}

/* return array of pointers to edges for a given vertex. */
/* array of edges should be dynamically allocated */
/* set count to be number of edges of vertex */
/* return NULL if no edges from/to vertex */
Edge **get_edges(Graph *graph, Vertex *vertex, int *count)
{
    Node *node;
    Edge **edges;
    int i;
    int edgeNum;
    int j;

    edgeNum = 0;
    i=0;
    while(vertex->edges->head != NULL)
    {
        edgeNum++;
        i++;
    }
    if(edgeNum > 0)
    {
        edges = calloc(edgeNum, sizeof(Edge *));
        j=0;
        while(vertex->edges->head != NULL)
        {
            edges[j] = calloc(1, sizeof(Edge));
            node = vertex->edges->head;
            edges[j] = node->data;
            j++;
        }
    }
    *count = edgeNum;
    return edges;
}

/* return pointer to edge from vertex with id from, to vertex with id to. */
/* return NULL if no edge */
Edge *get_edge(Graph *graph, int from, int to)
{
    Edge* edge;
    Node* node;
    Vertex *vertex_from, *vertex_to;

    vertex_from = find_vertex(graph, from);
    vertex_to = find_vertex(graph, to);
    if(vertex_from->edges == NULL){
        return NULL;
    }

    node= vertex_from->edges->head;
    edge = node->data;
    if(edge != NULL){
        if(vertex_to != edge->vertex){
            node = vertex_to->edges->head;
            edge = node->data;
        }
    }

    return edge;
}

/* return id of destination node of edge. */
int edge_destination(Edge *edge)
{
    return edge->vertex->id;
}

/* return weight of edge. */
double edge_weight(Edge *edge)
{
    return edge->weight;
}