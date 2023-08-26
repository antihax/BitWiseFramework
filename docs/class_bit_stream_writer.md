---
title: BitStreamWriter
summary: A class for writing bits from a stream. 

---

# BitStreamWriter



A class for writing bits from a stream.  [More...](#detailed-description)

Inherited by [BitWiseScriptRPC](class_bit_wise_script_r_p_c.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[Align](class_bit_stream_writer.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| void | **[BitStreamWriter](class_bit_stream_writer.md#function-bitstreamwriter)**(Serializer context =NULL)<br>Initializes a [BitStreamWriter](class_bit_stream_writer.md) object.  |
| int | **[GetIndex](class_bit_stream_writer.md#function-getindex)**()<br>Returns the current bit index.  |
| protected void | **[Reset](class_bit_stream_writer.md#function-reset)**()<br>Resets the bitstream to the beginning. Should not be called by a developer.  |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(int value)<br>[AVOID] Writes an integer value to the bitstream, aligning the bitstream first.  |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(bool value)<br>[AVOID] Writes a boolean value to the bitstream in an aligned manner.  |
| bool | **[WriteAligned](class_bit_stream_writer.md#function-writealigned)**(string value)<br>[AVOID] Writes a string value to the bitstream in an aligned manner.  |
| bool | **[WriteHalfFloat](class_bit_stream_writer.md#function-writehalffloat)**(float value)<br>Writes a half-precision floating-point value [16 bits] to the bitstream. Useful when precision can be sacrificed for bandwidth.  |
| bool | **[WriteHalfVector](class_bit_stream_writer.md#function-writehalfvector)**(vector value)<br>Writes a half-precision vector [48 bits] to the bitstream. Useful when precision can be sacrificed for bandwidth.  |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(bool value)<br>Writes a boolean value [1 bit] to the bitstream.  |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(float value)<br>Writes a float value [32 bits] as an int to the bitstream.  |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(vector value)<br>Writes a vector value [96 bits] to the bitstream.  |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(string value)<br>Writes a packed string to the bitstream.  |
| bool | **[WritePacked](class_bit_stream_writer.md#function-writepacked)**(Object object)<br>Writes a packed object [64 bits] to the bitstream.  |
| bool | **[WriteRangedInt](class_bit_stream_writer.md#function-writerangedint)**(int value, int min, int max)<br>Writes a ranged integer value to the bitstream.  |
| bool | **[WriteSInt](class_bit_stream_writer.md#function-writesint)**(int value, int bits)<br>WriteSInt is a function that writes a signed integer value to a bitstream.  |
| bool | **[WriteUInt](class_bit_stream_writer.md#function-writeuint)**(int value, int bits)<br>Writes an unsigned integer value to the bitstream.  |
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

A class for writing bits from a stream. 

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

Returns the current bit index. 

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

[AVOID] Writes an integer value to the bitstream, aligning the bitstream first. 

**Parameters**: 

  * **value** The integer value to write to the bitstream. 


**Return**: True if the write was successful, false otherwise. 

**Note**: Aligned writes should not be used unless needed such as deep serialization however no compression takes place with these style of writes. Use sparingly. 

### function WriteAligned

```cpp
bool WriteAligned(
    bool value
)
```

[AVOID] Writes a boolean value to the bitstream in an aligned manner. 

**Parameters**: 

  * **value** The boolean value to be written. 


**Return**: Returns true if the write operation was successful, false otherwise. 

### function WriteAligned

```cpp
bool WriteAligned(
    string value
)
```

[AVOID] Writes a string value to the bitstream in an aligned manner. 

**Parameters**: 

  * **value** The string value to be written. 


**Return**: Returns true if the write operation was successful, false otherwise. 

### function WriteHalfFloat

```cpp
bool WriteHalfFloat(
    float value
)
```

Writes a half-precision floating-point value [16 bits] to the bitstream. Useful when precision can be sacrificed for bandwidth. 

**Parameters**: 

  * **value** The value to write. 


**Return**: True if the write was successful, false otherwise. 

### function WriteHalfVector

```cpp
bool WriteHalfVector(
    vector value
)
```

Writes a half-precision vector [48 bits] to the bitstream. Useful when precision can be sacrificed for bandwidth. 

**Parameters**: 

  * **value** The value to write. 


**Return**: True if the write was successful, false otherwise. 

### function WritePacked

```cpp
bool WritePacked(
    bool value
)
```

Writes a boolean value [1 bit] to the bitstream. 

**Parameters**: 

  * **value** The boolean value to write. 


**Return**: True if the value was successfully written, false otherwise. 

### function WritePacked

```cpp
bool WritePacked(
    float value
)
```

Writes a float value [32 bits] as an int to the bitstream. 

**Parameters**: 

  * **value** The float value to be written. 


**Return**: True if the write operation was successful, false otherwise. 

### function WritePacked

```cpp
bool WritePacked(
    vector value
)
```

Writes a vector value [96 bits] to the bitstream. 

**Parameters**: 

  * **value** The vector value to be written. 


**Return**: True if the write operation was successful, false otherwise. 

### function WritePacked

```cpp
bool WritePacked(
    string value
)
```

Writes a packed string to the bitstream. 

**Parameters**: 

  * **value** The string to write. 


**Return**: True if the string was successfully written, false otherwise. 

### function WritePacked

```cpp
bool WritePacked(
    Object object
)
```

Writes a packed object [64 bits] to the bitstream. 

**Parameters**: 

  * **object** The object to write. 


**Return**: True if the object was successfully written, false otherwise. 

### function WriteRangedInt

```cpp
bool WriteRangedInt(
    int value,
    int min,
    int max
)
```

Writes a ranged integer value to the bitstream. 

**Parameters**: 

  * **value** The integer value to be written to the bitstream. 
  * **min** The start of the range. 
  * **max** The end of the range. 


**Return**: Returns true if the operation is successful, false otherwise. 

### function WriteSInt

```cpp
bool WriteSInt(
    int value,
    int bits
)
```

WriteSInt is a function that writes a signed integer value to a bitstream. 

**Parameters**: 

  * **value** The integer value to be written to the bitstream. 
  * **bits** The number of bits to be written from the value to the bitstream. 


**Return**: Returns true if the operation is successful, false otherwise. 

### function WriteUInt

```cpp
bool WriteUInt(
    int value,
    int bits
)
```

Writes an unsigned integer value to the bitstream. 

**Parameters**: 

  * **value** The integer value to write. 
  * **bits** The number of bits to use to represent the integer value. 


**Return**: Returns true if the write operation was successful, false otherwise. 

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

Updated on 2023-08-26 at 16:48:44 -0500