#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
};

struct Number : Expression
{
    explicit Number(double value)
        : value(value)
    {};
    double evaluate() const override {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), right(right), op(op)
    { }

    double evaluate() const override {
        if (op == '*') { return left->evaluate() * right->evaluate(); }
        if (op == '/') { return left->evaluate() / right->evaluate(); }
        if (op == '+') { return left->evaluate() + right->evaluate(); }
        if (op == '-') { return left->evaluate() - right->evaluate(); }
        return 0;
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

int main() {

    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    //Expression * expr = new BinaryOperation(new Number(3), '+', sube);

    std::cout << sube->evaluate() << std::endl;
    delete sube;

    return 0;
}