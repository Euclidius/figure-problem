#pragma once

#include <iostream>
#include <cmath>
#include <string>

class Figure {
public:
    Figure(){};

    virtual ~Figure(){};

    virtual double area() = 0;
    virtual double perimetre() = 0;

    friend std::ostream &operator<<(std::ostream &stream, const Figure &f) ;

    virtual Figure &operator=(const Figure &f) = 0;

protected:
    virtual std::ostream &print(std::ostream &stream) const = 0;
};

inline Figure& Figure::operator = (const Figure& f) = default;

class Circle : public Figure {
public:
    Circle(double r = 0): R(r) {}; 

    ~Circle(){}; 

    std::ostream &print(std::ostream &stream) const override {
        stream << "Circle with radius: " << R << std::endl;
        return stream;
    }

    Circle &operator=(const Figure &f) override {
        if (this == &f) return *this;
        const Circle &c = dynamic_cast<const Circle &>(f);
        R = c.R;
        return *this;
    }

    double area() override {
        return M_PI * R * R;
    }

    double perimetre() override {
        return 2 * M_PI * R;
    }

    Circle &operator = (const Circle &c) = default;

private:
    double R;
};

class Rectangle : public Figure {
public:
    Rectangle(double a = 0, double b = 0): A(a), B(b) {};

    ~Rectangle(){};

    std::ostream &print(std::ostream &stream) const override {
        stream << "rectangle with sides: A = " << A << " B = " << B << std::endl;
        return stream;
    }

    Rectangle &operator=(const Figure &f) override {
        if (this == &f) return *this;
        const Rectangle &r = dynamic_cast<const Rectangle &>(f);
        A = r.A;
        B = r.B;
        return *this;
    }

    double area() override {
        return A * B;
    }

    double perimetre() override {
        return 2 * (A + B);
    }

    Rectangle &operator = (const Rectangle &c) = default;

private:
    double A, B;
};

class Ellipse : public Figure {
public:
    Ellipse(double a = 0, double b = 0) : A(a), B(b) {};

    ~Ellipse(){};

    std::ostream &print(std::ostream &stream) const override {
        stream << "Ellipse with halfaxes: A = " << A << " B = " << B << std::endl;
        return stream;
    }

    Ellipse &operator=(const Figure &f) override {
        if (this == &f) return *this;
        const Ellipse &e = dynamic_cast<const Ellipse &>(f);
        A = e.A;
        B = e.B;
        return *this;
    }


    double area() override {
        return M_PI * A * B;
    }

    double perimetre() override {
        return 4 * (M_PI*A*B + (A-B)*(A-B)) / (A+B);
    }

    Ellipse &operator = (const Ellipse &c) = default;

private:
    double A, B;
};

