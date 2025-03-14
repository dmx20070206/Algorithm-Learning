#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const int NumType = 0;
const int OperatorType = 1;
const int LeftBracket = 2;
const int RightBracket = 3;
const int ExprType = 4;

class Visitor;
class PrintVistor;
class Token;
class NumToken;
class OperatorToken;
class BracketToken;
class ExprToken;

// string -> float
float helpStringToNum(const std::string &text)
{
    float ret;
    std::stringstream ss;
    ss << text;
    ss >> ret;
    return ret;
}

class Visitor
{
public:
    virtual void apply(Token *token) = 0;
};

class Token
{
public:
    const std::string text;
    const int type;

    virtual void visit(Visitor *visitor);

protected:
    Token(std::string text, const int type)
        : text(text), type(type) {}

    virtual ~Token() {}
};

void Token::visit(Visitor *visitor)
{
    visitor->apply(this);
};

class NumToken : public Token
{
public:
    const float value;

    // 调用父类的构造函数
    // string text = op;
    // int type = NumType;
    NumToken(std::string text)
        : Token(text, NumType), value(helpStringToNum(text))
    {
    }
};

class OperatorToken : public Token
{
public:
    const char op;

    // 调用父类的构造函数
    // string text = op;
    // int type = OperatorType;
    OperatorToken(const char op)
        : Token(std::string(1, op), OperatorType), op(op) {}
};

class BracketToken : public Token
{
public:
    // 调用父类的构造函数
    // string text = op;
    // int type = LeftBracket or RightBracket;
    BracketToken(const char op)
        : Token(std::string(1, op),
                op == '(' ? LeftBracket : RightBracket)
    {
    }
};

class ExprToken : public Token
{
private:
    NumToken *num;
    OperatorToken *op;
    ExprToken *lhs, *rhs;
    bool bracket;

    float calc()
    {
        if (op)
        {
            float l(lhs->value), r(rhs->value);
            switch (op->op)
            {
            case '+':
                return l + r;
            case '-':
                return l - r;
            case '*':
                return l * r;
            case '/':
                return l / r;
            }
        }
        else
            return num->value;
        return 0;
    }

public:
    const float value;

    ExprToken(NumToken *num)
        : Token(num->text, ExprType), num(num),
          op(NULL), lhs(NULL), rhs(NULL), value(calc()) {}

    ExprToken(ExprToken *lhs, OperatorToken *op_, ExprToken *rhs)
        : Token(lhs->text + op_->text + rhs->text, ExprType),
          num(NULL), op(op_), lhs(lhs), rhs(rhs), value(calc()) {}

    ExprToken(BracketToken *lb, ExprToken *expr, BracketToken *rb)
        : Token(lb->text + expr->text + rb->text, ExprType),
          num(NULL), op(NULL), lhs(expr), rhs(NULL),
          value(expr->value)
    {
        bracket = true;
    }

    virtual void visit(Visitor *visitor)
    {
        if (lhs)
            lhs->visit(visitor);
        if (rhs)
            rhs->visit(visitor);
        visitor->apply(this);
    }

    virtual ~ExprToken()
    {
        delete num;
        delete op;
        delete lhs;
        delete rhs;
    }
};

class PrintVistor : public Visitor
{
private:
    int line;

public:
    PrintVistor() : line(0) {}

    virtual void apply(Token *token)
    {
        if (token->type == ExprType)
        {
            ExprToken *expr = dynamic_cast<ExprToken *>(token);
            std::cout << '#' << ++line << ": "
                      << token->text << " = ";
            if (expr)
                std::cout << expr->value;
            else
                std::cout << "NaN";
            std::cout << std::endl;
        }
    }
};

// 将字符串转换为 token 序列
std::vector<Token *> parse(std::string text)
{
    // 定义 token 数组，利用多态性质存放不同的 token 类型
    std::vector<Token *> vec;

    // 遍历字符串
    for (int i = 0; i < text.length(); ++i)
    {
        switch (text[i])
        {

        // 遇到空格省略
        case ' ':
            break;

        // 遇到四则运算符
        case '+':
        case '-':
        case '*':
        case '/':
            vec.push_back(new OperatorToken(text[i]));
            break;

        // 遇到括号
        case '(':
        case ')':
            vec.push_back(new BracketToken(text[i]));
            break;

        // 遇到数字
        default:
        {
            // "1234" => (int)1234

            // 确定数字的位数
            int r;
            for (r = i; r < text.length() && text[r] >= '0' && text[r] <= '9'; ++r)
                ;

            // substr(index, len)
            // 截取 str[i] ~ str[r - 1] 的子串
            vec.push_back(new NumToken(text.substr(i, r - i)));

            // 跳转到数字最后一位，保证 i++ 后下次从正确的位置继续遍历
            i = r - 1;
        }
        }
    }
    return vec;
}

// 检查 lhs op rhs 是否构成一个表达式
// priority: op 必须是有优先级的运算符
bool is_expr(Token *lhs, Token *op, Token *rhs, bool priority = false)
{
    if (lhs->type != ExprType || op->type != OperatorType || rhs->type != ExprType)
        return false;
    OperatorToken *_op = dynamic_cast<OperatorToken *>(op);

    // 若 priority 为 1，则 op 必须是 * 或 / 优先级高的运算符
    bool priority_op = _op->op == '*' || _op->op == '/';
    return _op && (!priority ^ priority_op);
}

void compile(std::vector<Token *> &vec)
{
    // 将 NumToken 转换成 ExprToken
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i]->type == NumType)
        {
            // Token* => NumToken*
            NumToken *num = dynamic_cast<NumToken *>(vec[i]);

            if (num)
                vec[i] = new ExprToken(num);
            else
                vec[i] = new ExprToken(new NumToken("0"));
        }

    while (vec.size() > 1)
    {
        bool flag = false;

        // 处理 ( expr ) 形式
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (vec[i]->type == LeftBracket && vec[i + 2]->type == RightBracket && vec[i + 1]->type == ExprType)
            {
                flag = true;
                ExprToken *expr = new ExprToken(
                    dynamic_cast<BracketToken *>(vec[i]),
                    dynamic_cast<ExprToken *>(vec[i + 1]),
                    dynamic_cast<BracketToken *>(vec[i + 2]));

                // 将 (  expr  ) 变成 expr
                vec.erase(vec.begin() + i + 1, vec.begin() + i + 3);
                vec[i] = expr;
            }
            if (flag)
                break;
        }
        if (flag)
            continue;

        // 处理 expr priority_op expr 形式
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (is_expr(vec[i], vec[i + 1], vec[i + 2], true))
            {
                flag = true;
                ExprToken *expr = new ExprToken(
                    dynamic_cast<ExprToken *>(vec[i]),
                    dynamic_cast<OperatorToken *>(vec[i + 1]),
                    dynamic_cast<ExprToken *>(vec[i + 2]));

                // 将 expr op expr 转换为 expr
                vec.erase(vec.begin() + i + 1, vec.begin() + i + 3);
                vec[i] = expr;
            }
            if (flag)
                break;
        }
        if (flag)
            continue;

        // 处理 expr normal_op expr 形式
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (is_expr(vec[i], vec[i + 1], vec[i + 2]))
            {
                // 前后没有 * / 这种优先级更高的运算符
                if (i > 0 && vec[i - 1]->type == OperatorType && (dynamic_cast<OperatorToken *>(vec[i - 1])->op == '*' || dynamic_cast<OperatorToken *>(vec[i - 1])->op == '/'))
                    continue;
                if (i + 3 < vec.size() && vec[i + 3]->type == OperatorType && (dynamic_cast<OperatorToken *>(vec[i + 3])->op == '*' || dynamic_cast<OperatorToken *>(vec[i + 3])->op == '/'))
                    continue;

                flag = true;
                ExprToken *expr = new ExprToken(
                    dynamic_cast<ExprToken *>(vec[i]),
                    dynamic_cast<OperatorToken *>(vec[i + 1]),
                    dynamic_cast<ExprToken *>(vec[i + 2]));

                // 将 expr op expr 转换为 expr
                vec.erase(vec.begin() + i + 1, vec.begin() + i + 3);
                vec[i] = expr;
            }
            if (flag)
                break;
        }

        // 如果本次循环没有任何 token 可以进行转化
        if (!flag)
        {
            std::cout << "error" << std::endl;
            return;
        }
    }

    PrintVistor v;
    vec[0]->visit(&v);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<Token *> vec = parse(s);
    compile(vec);
    return 0;
}