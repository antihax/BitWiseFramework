---
title: BitStreamReader
summary: A class for reading bits from a stream. 

---

# BitStreamReader



A class for reading bits from a stream.  [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitStreamReader](Classes/class_bit_stream_reader.md#function-bitstreamreader)**(Serializer _ctx)<br>Initializes a [BitStreamReader](Classes/class_bit_stream_reader.md) object with the given Serializer context.  |
| void | **[~BitStreamReader](Classes/class_bit_stream_reader.md#function-~bitstreamreader)**() |
| int | **[GetIndex](Classes/class_bit_stream_reader.md#function-getindex)**() |
| bool | **[ReadBool](Classes/class_bit_stream_reader.md#function-readbool)**(out bool value) |
| bool | **[ReadUInt](Classes/class_bit_stream_reader.md#function-readuint)**(out int value, int bits) |
| bool | **[ReadSInt](Classes/class_bit_stream_reader.md#function-readsint)**(out int value, int bits) |
| bool | **[ReadHalfFloat](Classes/class_bit_stream_reader.md#function-readhalffloat)**(out float value) |
| void | **[Align](Classes/class_bit_stream_reader.md#function-align)**()<br>Aligns the bitstream to the next integer boundary. Generally, this function is only called at the end of a message to ensure proper alignment.  |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out bool value) |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out int value) |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out float value) |
| bool | **[ReadPacked](Classes/class_bit_stream_reader.md#function-readpacked)**(out string value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out int value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out bool value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out Class value) |
| bool | **[ReadAligned](Classes/class_bit_stream_reader.md#function-readaligned)**(out string value) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](Classes/class_bit_stream_reader.md#variable-m-bitindex)**  |
| public Serializer | **[m_Context](Classes/class_bit_stream_reader.md#variable-m-context)**  |
| public int | **[m_Working](Classes/class_bit_stream_reader.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](Classes/class_bit_stream_reader.md#variable-m-workingindex)**  |

## Detailed Description

```cpp
class BitStreamReader;
```

A class for reading bits from a stream. 

This class is responsible for reading data into a bitstream. It provides methods to read various types of data (like integers, floats, etc.) from the bitstream. 

## Public Functions Documentation

### function BitStreamReader

```cpp
void BitStreamReader(
    Serializer _ctx
)
```

Initializes a [BitStreamReader](Classes/class_bit_stream_reader.md) object with the given Serializer context. 

**Parameters**: 

  * **_ctx** The Serializer context to use for reading bits. 


### function ~BitStreamReader

```cpp
void ~BitStreamReader()
```


### function GetIndex

```cpp
int GetIndex()
```


**Return**: The current bit index. 

Returns the current bit index.


### function ReadBool

```cpp
bool ReadBool(
    out bool value
)
```


**Parameters**: 

  * **value** - The boolean value read from the bitstream. 


**Return**: True if the boolean value was successfully read, false otherwise. 

Reads a boolean value from the bitstream. 


### function ReadUInt

```cpp
bool ReadUInt(
    out int value,
    int bits
)
```


**Parameters**: 

  * **value** - The integer value read from the bitstream. 
  * **bits** - The number of bits to read from the bitstream.


**Return**: true if the value was successfully read, false otherwise. 

Reads an unsigned integer value from the bitstream.


### function ReadSInt

```cpp
bool ReadSInt(
    out int value,
    int bits
)
```


**Parameters**: 

  * **value** The integer value read from the bitstream. 
  * **bits** The number of bits to read for the integer value.


**Return**: True if the integer value was successfully read, false otherwise. 

Reads a signed integer value from the bitstream.


### function ReadHalfFloat

```cpp
bool ReadHalfFloat(
    out float value
)
```


**Parameters**: 

  * **value** The half-precision floating-point value read from the bit stream. 


**Return**: True if the read operation was successful, false otherwise. 

Reads a half-precision floating-point value from the bit stream. 


### function Align

```cpp
void Align()
```

Aligns the bitstream to the next integer boundary. Generally, this function is only called at the end of a message to ensure proper alignment. 

### function ReadPacked

```cpp
bool ReadPacked(
    out bool value
)
```


**Parameters**: 

  * **value** The boolean value to be read. 


**Return**: True if the value was read successfully, false otherwise. 

Reads a packed boolean value from the bitstream. 


### function ReadPacked

```cpp
bool ReadPacked(
    out int value
)
```


**Parameters**: 

  * **value** The integer value read from the bitstream. 


**Return**: True if the integer value was successfully read, false otherwise. 

Reads a packed integer value from the bitstream. 


### function ReadPacked

```cpp
bool ReadPacked(
    out float value
)
```


**Parameters**: 

  * **value** The float value read from the bitstream. 


**Return**: True if the value was successfully read, false otherwise. 

Reads a packed float value from the bitstream. 


### function ReadPacked

```cpp
bool ReadPacked(
    out string value
)
```


**Parameters**: 

  * **value** The string value read from the bitstream. 


**Return**: True if the string was successfully read, false otherwise. 

Reads a packed string from the bitstream.


### function ReadAligned

```cpp
bool ReadAligned(
    out int value
)
```


**Parameters**: 

  * **value** The integer value read from the bitstream. 


**Return**: True if the read operation was successful, false otherwise. 

Reads an aligned integer value from the bitstream. 


### function ReadAligned

```cpp
bool ReadAligned(
    out bool value
)
```


**Parameters**: 

  * **value** - The boolean value to be read. 


**Return**: Returns true if the read operation was successful, false otherwise. 

Reads a boolean value from the bitstream. 


### function ReadAligned

```cpp
bool ReadAligned(
    out Class value
)
```


**Parameters**: 

  * **value** The value to be read from the bitstream. 


**Return**: Returns true if the value was successfully read, false otherwise. 

Reads a value from the bitstream in an aligned manner. 


### function ReadAligned

```cpp
bool ReadAligned(
    out string value
)
```


**Parameters**: 

  * **value** The string value read from the bitstream. 


**Return**: True if the read operation was successful, false otherwise. 

Reads a string value from the bitstream in an aligned manner. 


## Public Attributes Documentation

### variable m_BitIndex

```cpp
public int m_BitIndex = 0;
```


### variable m_Context

```cpp
public Serializer m_Context;
```


### variable m_Working

```cpp
public int m_Working;
```


### variable m_WorkingIndex

```cpp
public int m_WorkingIndex;
```


-------------------------------

Updated on 2023-08-25 at 22:01:36 -0500