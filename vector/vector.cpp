#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <cmath>

// Used types
typedef int vectDimension;
typedef double elemType;

#define PI 3.1415926535897932;

class Vector {
    private :
        int vectDim;
        elemType* elems;
    public :
        // Constructors & Destructor
        Vector();
        Vector(vectDimension n);
        Vector(Vector &oldVect);
        ~Vector();
        // Getters and setters
        int getDim() const;
        void setValues(double newValues[], int size);
        // Operation overloads
        Vector operator + (const Vector &toAddVect);
        Vector operator - (const Vector &toSubstractVect);
        elemType operator * (const Vector &toMultiplyVect);
        Vector operator = (const Vector &toAssignVect);
        // toString, magnitude, angle, orthogonal vector...
        std::string toString() const;
        double magnitude() const;
        double angleToAxis(const int nth_axe);
        double angle(Vector &otherVect);
        // Vector* orthogonal() const;
        // Vector* orthonormal() const;
};

// Constructors implementations 
Vector::Vector() {
    vectDim = 0;
    elems = NULL;
};

Vector::Vector(vectDimension n): vectDim(n) {
    // Create a n-dim dynamic array with 0 values
    elems = new elemType[vectDim];
    for (int i=0; i<n; i++) {
        elems[i] = 0;
    };
};

Vector::Vector(Vector &oldVect) : vectDim(oldVect.vectDim) {
    elems = new elemType[vectDim];
    for (int i=0; i<vectDim; i++) {
        elems[i] = oldVect.elems[i];
    };
};

Vector::~Vector() {
    vectDim = 0;
    delete[] elems;
    elems = NULL;
};

// Getters and setters
int Vector::getDim() const { return vectDim;};

void Vector::setValues(double newValues[], int size) {  // TODO: Strenghten this method
    // Passing an array of value
    // Ensure that the number of elements are the same
    elemType *newElm = new elemType[vectDim];
    for (int x=0; x<size; x++) {
        newElm[x] = newValues[x];
    }
    delete elems;
    this -> vectDim = size;
    this -> elems = newElm;
};

// Operation overloads
Vector Vector::operator + (const Vector &toAddVect){
    // Ensure that they are of the same size
    assert(vectDim == toAddVect.vectDim);
    Vector temp(toAddVect.vectDim);
    
    for (int i = 0; i < vectDim; i++) {
        temp.elems[i] = this->elems[i] + toAddVect.elems[i];
    }
    return temp;
};

Vector Vector::operator - (const Vector &toSubstractVect){
    // Ensure that they are of the same size
    assert(vectDim == toSubstractVect.vectDim);

    Vector temp(toSubstractVect.vectDim);
    for (int i = 0; i < vectDim; i++)
        temp.elems[i] = this->elems[i] - toSubstractVect.elems[i];
    return temp;
};

elemType Vector::operator * (const Vector &toMultiplyVect){
    // Ensure that they are of the same size
    assert(vectDim == toMultiplyVect.vectDim);

    elemType sc_prod = 0;
    for (int i = 0; i < vectDim; i++)
        sc_prod += this ->elems[i] * toMultiplyVect.elems[i];
    return sc_prod;
};

Vector Vector::operator = (const Vector& toAssignVect){
    if (this != &toAssignVect){
        elemType *newElm = new elemType[toAssignVect.vectDim];
        // std::copy(toAssignVect.elems, toAssignVect.elems + toAssignVect.vectDim, newElm);
        for(int x=0; x < toAssignVect.vectDim; x++) {
            newElm[x] = toAssignVect.elems[x];
        };
        delete[] elems;
        this->vectDim = toAssignVect.vectDim;
        this->elems = newElm;
    };
    return *this;
};

std::string Vector::toString() const {
    // Return closed empty brackets for empty vectors
    if (vectDim == 0) {return "[]";};

    std::stringstream stream;
    std::string stringOutput;
    for(int i=0; i < vectDim; i++) {
        stream << elems[i];
        if (i != vectDim -1)
            stream << ",";
    };
    stream >> stringOutput;
    stringOutput = "[" + stringOutput + "]";
    return stringOutput; 
};

double Vector::magnitude() const {
    // Summarize the vector components : |a| = sqrt({x_a}^2 + ... + {x_n}^2)
    double norm = 0;
    for(int i=0; i<vectDim; i++) {
        norm += elems[i]*elems[i];
    };
    return std::sqrt(norm);
};

double Vector::angleToAxis(const int nth_axe) {
    // angle formula : arccos(nth_value_in_vect / norm) = arccos(projection_on_nth_axe / norm);
    elemType nth_value = elems[nth_axe - 1];
    std::cout << nth_value << std::endl;
    elemType norm = magnitude();
    double cos_angle = nth_value / norm;
    std::cout << cos_angle << std::endl;
    std::cout << norm << std::endl;
    double value = std::acos(cos_angle) * 180 / PI;
    return value;      
};

double Vector::angle(Vector &otherVect) {
    // angle formula : arccos(scalar_product / product of norms)
    assert(vectDim == otherVect.vectDim);
    elemType sc_prod = 0;
    for (int i = 0; i < vectDim; i++)
        sc_prod += this ->elems[i] * otherVect.elems[i];
    // norms
    elemType norm_this = magnitude();
    elemType norm_other = otherVect.magnitude();

    elemType cos_angle = sc_prod / norm_this / norm_other;
    elemType value = std::acos(cos_angle) * 180 / PI;
    return value;
};

int main() {
    int dim;
    std::string strr;
    vectDimension n = 10;

    // Testing Default Constructor
    Vector empty{};
    dim = empty.getDim();
    strr = empty.toString();
    std::cout << "Dimension for default constructor: " << dim << std::endl;
    std::cout << "Value for default constructor: " << strr << std::endl;

    // Testing Constructor with dim as argument
    Vector withArgs{n};
    dim = withArgs.getDim();
    strr = withArgs.toString();
    std::cout << "Dimension of normal vector (from normal constructor): " << dim << std::endl;
    std::cout << "Value for normal constructor: " << strr << std::endl;

    // Testing for copy constructor
    vectDimension m = 4;
    Vector toCopy{m};
    Vector vect{toCopy};
    dim = vect.getDim();
    strr = vect.toString();
    std::cout << "Dimension of copy: " << dim << std::endl;
    std::cout << "Value for copy constructor: " << strr << std::endl;

    // + operator (- operator, * operator analog)
    Vector vect1{m};
    Vector vect2{m};
    std::cout << "Value for operation+: " << vect1.operator+(vect2).toString() << std::endl;
    std::cout << "Value for operation-: " << vect1.operator-(vect2).toString() << std::endl;
    std::cout << "Value for operation*: " << vect1.operator*(vect2) << std::endl;

    // operator =
    Vector vect3{4};
    Vector vect4{};
    vect4 = vect3;
    std::cout << "Value for operator =: " << vect3.toString() << std::endl;

    // magnitude, angleToAxis, angle
    Vector vec{10};
    elemType arr[10] = {3, 4, 2, 5, 6, 4, 10, 0, 34, 56};
    vec.setValues(arr, 10);
    double magnit = vec.magnitude();
    double angleToY = vec.angleToAxis(2); // Assuming that 2 is the y-axis
    Vector other_vec{10};
    elemType arrr[10] = {3, 4, 23, 51, 62, 24, 112, 0, 34, 56};
    other_vec.setValues(arrr, 10);
    elemType angle = vec.angle(other_vec);

    std::cout << "New values of vec: " << vec.toString() << std::endl;
    std::cout << "Magnitude of vec: " << magnit << std::endl;
    std::cout << "Angle to the y-axis of vec: " << angleToY << std::endl;
    std::cout << "New values of other_vec: " << other_vec.toString() << std::endl;
    std::cout << "Angle between vec and other_vec: " << angle << std::endl;
};