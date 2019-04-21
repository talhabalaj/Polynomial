# Polynomial
Don't complicate the easiest things. 

The main attribute you need to have in your Class is an array of "double". 
```cpp
class Polynomial {
 double * coeff;
 ...
}
```
Suppose that you have a polynomial:
![](https://latex.codecogs.com/gif.latex?\inline&space;2x^{}&space;&plus;&space;4x&space;&plus;&space;6)
The coefficients are 2, 4 and 6. The last one, 6 in this case,  is also the coefficient of Suppose that you have a polynomial:
![](https://latex.codecogs.com/gif.latex?\inline&space;x^{0}). So, In the coefficient array, you have store the constant first at index 0. Note that if stored in this way, the index becomes the power of x and the last index will be the degree. So, In this case, the coefficient array will look like:

```cpp
{ 6, 4, 2 }
```

Good luck doing the other functions like toString(), evaluate() and overloading the addition operator to add two polynomials. 
(Hint:  The resultant array will have size as large as the greater polynomial being added. Add coefficients at the same index. )
