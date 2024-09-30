// File: range_node.cpp
// Purpose: Definition of a character range node class.
// Author: Robert Lowe
#include "range_node.h"
#include <algorithm>

RangeNode::RangeNode(char start, char end) {
  this->_start = std::min(start, end);
  this->_end = std::max(start, end);
}

// Attempt to match the string at position pos
bool RangeNode::match(const std::string &str, size_t &pos) {
  // Check if the current position is within the string length
  if (pos < str.length()) {
    // Check if the character at the current position is within the range
    if (str[pos] >= _start && str[pos] <= _end) {
      // If it is, advance the position and return true
      pos++;
      return true;
    }
  }

  // If not, return false
  return false;
}
