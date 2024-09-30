#include "regex_node.h"
#include "regex_parser.h"
#include <string>

RegexNode *make_regex(const std::string &str) {
  RegexParser parser;

  return parser.parse(str);
}