---
title: BitStreamWriter

---

# BitStreamWriter



 [More...](#detailed-description)

Inherited by [BitWiseScriptRPC](class_bit_wise_script_r_p_c.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[Align](class_bit_stream_writer.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| void | **[BitStreamWriter](class_bit_stream_writer.md#function-bitstreamwriter)**(Serializer context =NULL)<br>Initializes a [BitStreamWriter](class_bit_stream_writer.md) object.  |
| int | **[GetIndex](class_bit_stream_writer.md#function-getindex)**() |
| protected void | **[Reset](class_bit_stream_writer.md#function-reset)**()<br>Resets the bitstream to the beginning. Should not be called by a developer.  |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(int value) |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(bool value) |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(string value) |
| bool | **[WriteHalfFloat](class_bit_stream_writer.md#function-writehalffloat)**(float value) |
| bool | **[WriteHalfVector](class_bit_stream_writer.md#function-writehalfvector)**(vector value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(bool value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(float value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(vector value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(string value) |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(Object object) |
| bool | **[WriteSInt](class_bit_stream_writer.md#function-writesint)**(int value, int bits) |
| bool | **[WriteUInt](class_bit_stream_writer.md#function-writeuint)**(int value, int bits) |
| void | **[~BitStreamWriter](class_bit_stream_writer.md#function-~bitstreamwriter)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](class_bit_stream_writer.md#variable-m-bitindex)**  |
| protected Serializer | **[m_Context](class_bit_stream_writer.md#variable-m-context)**  |
| public int | **[m_Working](class_bit_stream_writer.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](class_bit_stream_writer.md#variable-m-workingindex)**  |

## Detailed Description

```cpp
class BitStreamWriter;
```


This class is responsible for writing data into a bitstream. It provides methods to write various types of data (like integers, floats, etc.) into the bitstream. The data can then be read from the bitstream using a [BitStreamReader](class_bit_stream_reader.md). 

## Public Functions Documentation

### function Align

```cpp
bool Align()
```

Aligns the bitstream to the next integer boundary. 

**Return**: true if the bitstream is successfully aligned, false otherwise. 

If the current bit index is not aligned with the integer boundary, the working integer is written to the bitstream and the bit index is incremented to the next integer boundary.


### function BitStreamWriter

```cpp
void BitStreamWriter(
    Serializer context =NULL
)
```

Initializes a [BitStreamWriter](class_bit_stream_writer.md) object. 

**Parameters**: 

  * **context** A pointer to a Serializer object. 


**Return**: void 

### function GetIndex

```cpp
int GetIndex()
```


**Return**: The current bit index. 

Returns the current bit index. 


### function Reset

```cpp
protected void Reset()
```

Resets the bitstream to the beginning. Should not be called by a developer. 

### function WriteAligned

```cpp
bool WriteAligned(
    int value
)
```


**Parameters**: 

  * **value** The integer value to write to the bitstream. 


**Return**: True if the write was successful, false otherwise. 

**Note**: Aligned writes should not be used unless needed such as deep serialization however no compression takes place with these style of writes. Use sparingly. Writes an integer value to the bitstream, aligning the bitstream first.

### function WriteAligned

```cpp
bool WriteAligned(
    bool value
)
```


**Parameters**: 

  * **value** The boolean value to be written. 


**Return**: Returns true if the write operation was successful, false otherwise. 

Writes a boolean value to the bitstream in an aligned manner. 


### function WriteAligned

```cpp
bool WriteAligned(
    string value
)
```


**Parameters**: 

  * **value** The string value to be written. 


**Return**: Returns true if the write operation was successful, false otherwise. 

Writes a string value to the bitstream in an aligned manner.


### function WriteHalfFloat

```cpp
bool WriteHalfFloat(
    float value
)
```


**Parameters**: 

  * **value** The value to write. 


**Return**: True if the write was successful, false otherwise. 

Writes a half-precision floating-point value to the bitstream. Useful when precision can be sacrificed for bandwidth.


### function WriteHalfVector

```cpp
bool WriteHalfVector(
    vector value
)
```


**Parameters**: 

  * **value** The value to write. 


**Return**: True if the write was successful, false otherwise. 

Writes a half-precision vector to the bitstream. Useful when precision can be sacrificed for bandwidth.


### function WritePacked

```cpp
bool WritePacked(
    bool value
)
```


**Parameters**: 

  * **value** The boolean value to write. 


**Return**: True if the value was successfully written, false otherwise. 

Writes a boolean value to the bitstream. 


### function WritePacked

```cpp
bool WritePacked(
    float value
)
```


**Parameters**: 

  * **value** The float value to be written. 


**Return**: True if the write operation was successful, false otherwise. 

Writes a float value as an int to the bitstream.


### function WritePacked

```cpp
bool WritePacked(
    vector value
)
```


**Parameters**: 

  * **value** The vector value to be written. 


**Return**: True if the write operation was successful, false otherwise. 

Writes a vector value to the bitstream.


### function WritePacked

```cpp
bool WritePacked(
    string value
)
```


**Parameters**: 

  * **value** The string to write. 


**Return**: True if the string was successfully written, false otherwise. 

Writes a packed string to the bitstream.


### function WritePacked

```cpp
bool WritePacked(
    Object object
)
```


**Parameters**: 

  * **object** The object to write. 


**Return**: True if the object was successfully written, false otherwise. 

Writes a packed object to the bitstream.


### function WriteSInt

```cpp
bool WriteSInt(
    int value,
    int bits
)
```


**Parameters**: 

  * **value** The integer value to be written to the bitstream. 
  * **bits** The number of bits to be written from the value to the bitstream. 


**Return**: Returns true if the operation is successful, false otherwise. 

WriteSInt is a function that writes a signed integer value to a bitstream. 


### function WriteUInt

```cpp
bool WriteUInt(
    int value,
    int bits
)
```


**Parameters**: 

  * **value** The integer value to write. 
  * **bits** The number of bits to use to represent the integer value. 


**Return**: Returns true if the write operation was successful, false otherwise. 

Writes an unsigned integer value to the bitstream. 


### function ~BitStreamWriter

```cpp
void ~BitStreamWriter()
```


## Public Attributes Documentation

### variable m_BitIndex

```cpp
public int m_BitIndex;
```


### variable m_Context

```cpp
protected Serializer m_Context;
```


### variable m_Working

```cpp
public int m_Working;
```


### variable m_WorkingIndex

```cpp
public int m_WorkingIndex = 0;
```


-------------------------------

Updated on 2023-08-26 at 11:48:46 -0500