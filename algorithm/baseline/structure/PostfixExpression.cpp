#include <bits/stdc++.h>
using namespace std;
// 比较操作符A和操作符B的优先级
bool opAisBiggerThanOpB(string opA, string opB)
{
  if (opA == "*" || opA == "/" && opB != "*" && opB != "/" && opB != "(")
  {
    return true;
  }
  else
  {
    return false;
  }
}

// 中缀表达式转后缀表达式
bool parseFormula(string formula)
{
  vector<string> rpn_;             // 总输出
  vector<string> rpn_stack;        // 符号堆栈
  string sign_;                    // 临时保存操作数
  for (int i = 0; i < formula.size(); ++i )
  {
    if(formula[i] != '+' && formula[i] != '-' && formula[i] != '*' && formula[i] != '/'
            && formula[i] != '(' && formula[i] != ')')
    {  // 如果是操作数的话就保存起来等待输出
      sign_ += formula[i];
    }
    else
    {
      string t_formula;
      t_formula += formula[i];

      // 操作数输出
      if (!sign_.empty())
      {
        rpn_.push_back(sign_);
        sign_.clear();                // 清空，保存下一个操作数
      }

      // 操作符入栈
      if (t_formula == ")")
      {
        while(rpn_stack[rpn_stack.size() - 1] != "(")
        {
          if (rpn_stack.empty())
          {
            return false;
          }
          rpn_.push_back(rpn_stack[rpn_stack.size() - 1]);
          rpn_stack.pop_back();
        }
        rpn_stack.pop_back();
      }
      else if (rpn_stack.empty())
      {
        rpn_stack.push_back(t_formula);
      }
      else if (t_formula == "(" || rpn_stack[rpn_stack.size() - 1] == "(")
      {
        rpn_stack.push_back(t_formula);
      }
      else if (opAisBiggerThanOpB(t_formula, rpn_stack[rpn_stack.size() - 1]))
      {
        rpn_stack.push_back(t_formula);
      }
      else
      {
        while (!opAisBiggerThanOpB(t_formula, rpn_stack[rpn_stack.size() - 1]) && rpn_stack[rpn_stack.size() - 1] != "(")
        {
          rpn_.push_back(rpn_stack[rpn_stack.size() - 1]);
          rpn_stack.pop_back();
          if (rpn_stack.empty())
          {
            break;
          }
        }
        rpn_stack.push_back(t_formula);
      }
    } // end else
  } // end for

  // 处理最后的还留在暂存区的操作数和操作符
  if (!sign_.empty())
  {
    rpn_.push_back(sign_);
  }
  if (!rpn_stack.empty())
  {
    for(int i = rpn_stack.size() - 1; i >= 0; --i)
    {
      rpn_.push_back(rpn_stack[i]);
    }
  }

  // 输出测试
  string rpn;
  for (int i = 0; i < rpn_.size(); ++i)
  {
    rpn += rpn_[i];
  }
  cout << rpn << endl;

  return true;
}