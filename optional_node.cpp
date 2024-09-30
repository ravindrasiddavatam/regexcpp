// File: optional_node.cpp
// Purpose: The optional node quantifier
// Author: Robert Lowe
#include "optional_node.h"

OptionalNode::OptionalNode(RegexNode *node) { this->_node = node; }

OptionalNode::~OptionalNode() { delete this->_node; }

// Attempt to match the string at position pos
bool OptionalNode::match(const std::string &str, size_t &pos) {
  // Save the original position
  size_t originalPos = pos;

  // Attempt to match the node zero or one time
  _node->match(str, pos);

  // Always return true, even if no match occurred, because it's optional
  return true;
}
