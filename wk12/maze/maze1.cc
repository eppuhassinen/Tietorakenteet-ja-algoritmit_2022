#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include "maze.hh"

using namespace std;

// Remember to implement your own container here or in another cc file to store the nodes in the maze
// If you define it elsewhere, remember to make sure it's accessible by this file as well.

map<pair<int,int>,Node> nodes = {};

/**
 * @brief Create a Node object
 * 
 * @param loc  The location of the node
 * @return Node*  A pointer to the node that is created. If the node already exists, return a pointer to the existing node
 */
Node* createNode  (std::pair<int, int> loc, std::map<std::string, Node*> paths) {

    if ( nodes.find(loc) != nodes.end() ) { return &nodes[loc]; }

    Node new_node;
    new_node.loc = loc;
    new_node.paths = paths;

    nodes[loc] = new_node;

    return &nodes[loc];


}
