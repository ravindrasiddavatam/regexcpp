// File: inverse_node.cpp
// Purpose: Definition of the inverse node class.
// Author: Robert Lowe
#include "inverse_node.h"

// Constructor
InverseNode::InverseNode(RegexNode *node) : _node(node) {}

// Destructor
InverseNode::~InverseNode() {
  delete _node;
}

// Attempt to match the string at position pos
bool InverseNode::match(const std::string &str, size_t &pos) {
  // Save the original position
  size_t originalPos = pos;

  // Attempt to match the inverse of the node
  if (pos < str.length() && !_node->match(str, pos)) {
    // Advance the position and return true if the match is successful
    ++pos;
    return true;
  }

  // Reset the position if no match is found
  pos = originalPos;
  return false;
}
