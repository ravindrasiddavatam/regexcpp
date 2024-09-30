#include "character_node.h"
#include "group_node.h"
#include "inverse_node.h"
#include "one_node.h"
#include "optional_node.h"
#include "or_node.h"
#include "range_node.h"
#include "wildcard_node.h"
#include "zero_node.h"
#include <iostream>
#include <string>

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex);

// Construct regular expression .*
RegexNode *construct_regex1();

// Construct regular expression a*
RegexNode *construct_regex2();

// Construct regular expression (ab)*ac
RegexNode *construct_regex3();

// Construct regular expression (ab)+ac
RegexNode *construct_regex4();

// Construct regular expression (a|(aa))b
RegexNode *construct_regex5();

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex6();

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex7();

// Construct the regular expression "[^"]*"
RegexNode *construct_regex8();

// Construct the regular expression ...
RegexNode *construct_regex9();

int main() {
  std::string input_str;
  RegexNode *regex1 = construct_regex1();
  RegexNode *regex2 = construct_regex2();
  RegexNode *regex3 = construct_regex3();
  RegexNode *regex4 = construct_regex4();
  RegexNode *regex5 = construct_regex5();
  RegexNode *regex6 = construct_regex6();
  RegexNode *regex7 = construct_regex7();
  RegexNode *regex8 = construct_regex8();
  RegexNode *regex9 = construct_regex9();

  while (std::cin) {
    // get the user input
    std::cout << "Input> ";
    getline(std::cin, input_str);
    if (!std::cin)
      continue;

    // print the result
    print_match(".*", input_str, regex1);
    print_match("a*", input_str, regex2);
    print_match("(ab)*ac", input_str, regex3);
    print_match("(ab)+ac", input_str, regex4);
    print_match("(a|(aa))b", input_str, regex5);
    print_match("[0-9]+(\\.[0-9]+)?", input_str, regex6);
    print_match("[a-zA-Z]+", input_str, regex7);
    print_match("\"[^\"]*\"", input_str, regex8);
    print_match("...", input_str, regex9);
  }

  // cleanup
  delete regex1;
  delete regex2;
  delete regex3;
  delete regex4;
  delete regex5;
  delete regex6;
  delete regex7;
  delete regex8;
  delete regex9;
}

// Construct regular expression .*
RegexNode *construct_regex1() {
  // create the result
  GroupNode *regex = new GroupNode();

  /*  Design AST
                 GROUP    regex
                 /
                *         zero
               /
              .           wildcard
   */

  WildcardNode *wildcard = new WildcardNode();
  ZeroNode *zero = new ZeroNode(wildcard);
  regex->add_node(zero);

  return regex;
}

// Construct regular expression a*
RegexNode *construct_regex2() {
  // create the result
  GroupNode *regex = new GroupNode();

  /*  Design AST
                 GROUP    regex
                /
              *           wildcard
            /
           a              a
   */

  CharacterNode *a = new CharacterNode('a');
  ZeroNode *zero = new ZeroNode(a);
  regex->add_node(zero);

  return regex;
}

// Construct regular expression (ab)*ac
RegexNode *construct_regex3() {
  // create the result
  GroupNode *regex = new GroupNode();



  GroupNode *group1 = new GroupNode();
  CharacterNode *a1 = new CharacterNode('a');
  CharacterNode *b = new CharacterNode('b');
  group1->add_node(a1);
  group1->add_node(b);
  ZeroNode *zero = new ZeroNode(group1);


  CharacterNode *a2 = new CharacterNode('a');
  CharacterNode *c = new CharacterNode('c');


  regex->add_node(zero);
  regex->add_node(a2);
  regex->add_node(c);

  return regex;
}

// Construct regular expression (ab)+ac
RegexNode *construct_regex4() {
  // create the result
  GroupNode *regex = new GroupNode();



  GroupNode *group1 = new GroupNode();
  CharacterNode *a1 = new CharacterNode('a');
  CharacterNode *b = new CharacterNode('b');
  group1->add_node(a1);
  group1->add_node(b);
  OneNode *one = new OneNode(group1);


  CharacterNode *a2 = new CharacterNode('a');
  CharacterNode *c = new CharacterNode('c');


  regex->add_node(one);
  regex->add_node(a2);
  regex->add_node(c);

  return regex;
}

// Construct regular expression (a|(aa))b
RegexNode *construct_regex5() {
  // create the result
  GroupNode *regex = new GroupNode();


  OrNode *orNode = new OrNode();


  GroupNode *group1 = new GroupNode();
  CharacterNode *a1 = new CharacterNode('a');
  CharacterNode *a2 = new CharacterNode('a');
  group1->add_node(a1);
  group1->add_node(a2);
  orNode->add_node(group1);


  CharacterNode *a3 = new CharacterNode('a');
  orNode->add_node(a3);


  regex->add_node(orNode);


  CharacterNode *b = new CharacterNode('b');


  regex->add_node(b);

  return regex;
}

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex6() {
  GroupNode *regex = new GroupNode();




  RangeNode *range1 = new RangeNode('0', '9');
  OneNode *one = new OneNode(range1);


  GroupNode *group = new GroupNode();
  CharacterNode *dot = new CharacterNode('.');
  RangeNode *range2 = new RangeNode('0', '9');
  OneNode *oneRange2 = new OneNode(range2);
  group->add_node(dot);
  group->add_node(oneRange2);
  OptionalNode *optional = new OptionalNode(group);


  regex->add_node(one);
  regex->add_node(optional);

  return regex;
}

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex7() {
  GroupNode *regex = new GroupNode();



  // Create the range [a-zA-Z]
  RangeNode *range1 = new RangeNode('a', 'z');
  RangeNode *range2 = new RangeNode('A', 'Z');
  OrNode *orNode = new OrNode();
  orNode->add_node(range1);
  orNode->add_node(range2);

  OneNode *one = new OneNode(orNode);

  regex->add_node(one);

  return regex;
}

// Construct the regular expression "[^"]*"
RegexNode *construct_regex8() {
  GroupNode *regex = new GroupNode();

  // TODO: Impelemnt this function;

  CharacterNode *openingQuote = new CharacterNode('"');
  regex->add_node(openingQuote);

  InverseNode *inverse = new InverseNode(new CharacterNode('"'));
  ZeroNode *zero = new ZeroNode(inverse);
  regex->add_node(zero);
  CharacterNode *closingQuote = new CharacterNode('"');
  regex->add_node(closingQuote);
  return regex;
}

// Construct the regular expression ...
RegexNode *construct_regex9() {
  GroupNode *regex = new GroupNode();

  WildcardNode *wildcard1 = new WildcardNode();
  WildcardNode *wildcard2 = new WildcardNode();
  WildcardNode *wildcard3 = new WildcardNode();

  regex->add_node(wildcard1);
  regex->add_node(wildcard2);
  regex->add_node(wildcard3);

  return regex;
}

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex) {
  size_t pos = 0;

  std::cout << label << ": ";
  if (regex->match(input, pos) && pos == input.length()) {
    std::cout << "Match!" << std::endl;
  } else {
    std::cout << "No match." << std::endl;
  }
}


