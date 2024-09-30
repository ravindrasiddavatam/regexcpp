// File: group_node.cpp
// Purpose: Match a group of RegexNodes.
// Author: Robert Lowe
#include <string>
#include <vector>
#include "group_node.h"

// Delete all the nodes in the group
GroupNode::~GroupNode() {
  for (auto node : _nodes) {
    delete node;
  }
}

// Attempt to match the string beginning at the given position.
bool GroupNode::match(const std::string &str, size_t &pos) {
  size_t originalPos = pos;

  // Scanning for missed items in the sequence
  for (auto reg : _nodes) {
    if (!reg->match(str, pos)) {
      pos = originalPos;
      return false;
    }
  }

  // If we get here, we have a match
  return true;
}

// Add a node to the group
void GroupNode::add_node(RegexNode *node) {
  this->_nodes.push_back(node);
}
