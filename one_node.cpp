// File: one_node.cpp
// Purpose: The one node matches the one or more quantifier.
// Author: Robert Lowe
#include "one_node.h"
#include <string>

// Construct a one node with the node to repeat
OneNode::OneNode(RegexNode *node) { this->_node = node; }

// Destruct a one node
OneNode::~OneNode() { delete _node; }

// Attempt to match the string beginning at the given position.
bool OneNode::match(const std::string &str, size_t &pos) {
  // Save the original position
  size_t originalPos = pos;

  // Attempt to match the node at least once
  if (!_node->match(str, pos)) {
    // If the node doesn't match at least once, return false
    return false;
  }

  // Keep attempting to match the node as many times as possible
  while (_node->match(str, pos)) {
    // Continue matching
  }

  // If we managed to match the node at least once, return true
  return pos > originalPos;
}
