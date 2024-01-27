---
title: BitWiseHelpers
summary: A class that contains helper functions for bitwise operations. 

---

# BitWiseHelpers



A class that contains helper functions for bitwise operations. 

## Public Functions

|                | Name           |
| -------------- | -------------- |
| string | **[BitRepresentation](class_bit_wise_helpers.md#function-bitrepresentation)**(int value) |
| int | **[BitSize](class_bit_wise_helpers.md#function-bitsize)**(int n) |
| int | **[FloatToHalf](class_bit_wise_helpers.md#function-floattohalf)**(float fi) |
| int | **[FloatToInt](class_bit_wise_helpers.md#function-floattoint)**(float value) |
| float | **[HalfToFloat](class_bit_wise_helpers.md#function-halftofloat)**(int h) |
| float | **[IntToFloat](class_bit_wise_helpers.md#function-inttofloat)**(int value) |

## Public Functions Documentation

### function BitRepresentation

```cpp
static string BitRepresentation(
    int value
)
```


**Parameters**: 

  * **value** The integer value to be converted to binary. 


**Return**: The binary representation of the integer value as a string. 

Returns the binary representation of an integer value as a string.


### function BitSize

```cpp
static int BitSize(
    int n
)
```


**Parameters**: 

  * **n** The integer to calculate the number of bits for. 


**Return**: The number of bits required to represent the given integer. 

Calculates the number of bits required to represent a given integer.


### function FloatToHalf

```cpp
static int FloatToHalf(
    float fi
)
```


**Parameters**: 

  * **fi** The float value to be converted. 


**Return**: The half value of the given float. 

Converts float to half-float stored as int.


### function FloatToInt

```cpp
static int FloatToInt(
    float value
)
```


**Parameters**: 

  * **value** The float value to be converted. 


**Return**: The integer value of the given float. 

Converts float to float bits in an integer.


### function HalfToFloat

```cpp
static float HalfToFloat(
    int h
)
```


**Parameters**: 

  * **h** The half value to be converted. 


**Return**: The float value of the given half. 

Converts half-float stored as int to float.


### function IntToFloat

```cpp
static float IntToFloat(
    int value
)
```


**Parameters**: 

  * **value** The integer value to be converted. 


**Return**: The float value of the given integer. 

Converts integer float bits to float.


-------------------------------

Updated on 2024-01-27 at 14:16:25 -0600