// File: zero_node.cpp
// Purpose: The zero node matches zero or more occurrences of its child node.
// Author: Robert Lowe
#include "zero_node.h"
#include <string>

// Construct a zero node with the node to repeat
ZeroNode::ZeroNode(RegexNode *node) : _node(node) {}

// Destruct a zero node
ZeroNode::~ZeroNode() {
  delete _node;
}

// Attempt to match the string beginning at the given position
bool ZeroNode::match(const std::string &str, size_t &pos) {
  // Keep attempting to match the node as many times as possible
  while (_node->match(str, pos)) {
    // Continue matching
  }

  // Zero or more matches always succeed
  return true;
}
