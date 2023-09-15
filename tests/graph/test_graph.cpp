//
// Created by daniel on 13/09/23.
//
#include "gtest/gtest.h"
#include "graph.h"


TEST(UndirectedGraph, AddingNodesAndEdges)
{
    epi::Graph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addEdge('A', 'B');
    graph.addEdge('B', 'C');

    ASSERT_EQ(graph.numNodes(), 3);
    ASSERT_EQ(graph.numEdges(), 2);
    ASSERT_TRUE(graph.areNeighbors('A', 'B'));
    ASSERT_TRUE(graph.areNeighbors('B', 'C'));
    ASSERT_FALSE(graph.areNeighbors('A', 'C'));
}


TEST(UndirectedGraph, DepthFirstSearch)
{
    std::vector<std::pair<char, char>> edgeList {
            {'A', 'B'}, {'A', 'C'},
            {'B', 'D'}, {'B', 'E'},
            {'D', 'F'}, {'D', 'E'},
            {'E', 'F'}, {'C', 'E'},
            {'G', 'H'}
    };
    epi::Graph<char> graph(edgeList);
    std::vector<char> dfs {graph.depthFirstSearch()};
    std::vector<char> expected {'A', 'B', 'D', 'F', 'E', 'C', 'G', 'H'};
    ASSERT_EQ(dfs, expected);
}


//TEST(UndirectedGraph, BreadthFirstSearch)
//{
//
//}