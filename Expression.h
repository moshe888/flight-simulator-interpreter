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

class BinaryExprassion : public Expression {
protected:
    Expression* left;
    Expression* right;
  
public:
    BinaryExprassion(Expression* left, Expression* right) :
        left(left), right(right)
    {}
 
    double calculate() = 0;

    ~Expression() {
        delete left;
        delete right;
    }
}

class Plus : public BinaryExpression {
public:
    Plus(Expression* left, Expression* right):
        BinaryExprassion(left,right)
    {}

     double calculate() {
        return left->calculate() + right->calculate();
    }
}

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right):
        BinaryExprassion(left,right)
    {}

     double calculate() {
        return left->calculate() - right->calculate();
    }
}
