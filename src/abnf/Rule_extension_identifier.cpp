/* -----------------------------------------------------------------------------
 * Rule_extension_identifier.cpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Dec 31 10:33:28 CET 2017
 *
 * -----------------------------------------------------------------------------
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Rule_extension_identifier.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_DIGIT.hpp"

using namespace abnf;

Rule_extension_identifier::Rule_extension_identifier(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_extension_identifier::Rule_extension_identifier(const Rule_extension_identifier& rule) : Rule(rule)
{
}

Rule_extension_identifier& Rule_extension_identifier::operator=(const Rule_extension_identifier& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_extension_identifier* Rule_extension_identifier::clone() const
{
  return new Rule_extension_identifier(this->spelling, this->rules);
}

void* Rule_extension_identifier::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_extension_identifier* Rule_extension_identifier::parse(ParserContext& context)
{
  context.push("extension-identifier");

  bool parsed = true;
  int s0 = context.index;
  vector<const Rule*> e0;
  const Rule* rule;

  parsed = false;
  if (!parsed)
  {
    {
      vector<const Rule*> e1;
      int s1 = context.index;
      parsed = true;
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Rule_DIGIT::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        for (int i1 = 1; i1 < 5 && f1; i1++)
        {
          rule = Rule_DIGIT::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 >= 1;
      }
      if (parsed)
        e0.insert(e0.end(), e1.begin(), e1.end());
      else
        context.index = s1;
    }
  }

  rule = NULL;
  if (parsed)
    rule = new Rule_extension_identifier(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("extension-identifier", parsed);

  return (Rule_extension_identifier*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */