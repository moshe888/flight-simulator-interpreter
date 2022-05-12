#include <map>

using std::string;

class Expression {
public:
    Expression()
    {}

    virtual double calculate() = 0;

    virtual ~Expression()
    {}
};

class Number : public Expression {
    double num;

public:
    Number(double num) : 
        Expression(), num(num)
    {}

    double calculate() {
        return num;
    }
};

class BinaryExpression : public Expression {
protected:
    Expression* left;
    Expression* right;
  
public:
    BinaryExpression(Expression* left, Expression* right) :
        left(left), right(right)
    {}
 
    double calculate() = 0;

    ~BinaryExpression() {
        delete left;
        delete right;
    }
};

class Plus : public BinaryExpression {
public:
    Plus(Expression* left, Expression* right):
        BinaryExpression(left,right)
    {}

     double calculate() {
        return left->calculate() + right->calculate();
    }
};

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right):
        BinaryExpression(left,right)
    {}

     double calculate() {
        return left->calculate() - right->calculate();
    }
 };


 
class BoolExpression : public Expression {
    
};
