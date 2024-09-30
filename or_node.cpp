// File: or_node.cpp
// Purpose: Implements a multi-way or operator.
// Author: Robert Lowe
#include "or_node.h"
#include <iostream>
#include <string>
#include <vector>

OrNode::~OrNode() {
  for (auto node : _nodes) {
    delete node;
  }
}

// Perform a greedy or match on the given string starting at pos
bool OrNode::match(const std::string &str, size_t &pos) {
  // Save the original position
  size_t originalPos = pos;

  // Try to match each node in _nodes
  for (auto node : _nodes) {
    // Temporarily store the position
    size_t tempPos = pos;

    // Attempt to match the current node
    if (node->match(str, tempPos)) {
      // If any node matches, update the position and return true
      pos = tempPos;
      return true;
    }
  }

  // If none of the nodes match, reset the position and return false
  pos = originalPos;
  return false;
}

// Add a node to the or
void OrNode::add_node(RegexNode *node) { this->_nodes.push_back(node); }
