---
title: BitStreamReader
summary: A class for reading bits from a stream. 

---

# BitStreamReader



A class for reading bits from a stream.  [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[Align](class_bit_stream_reader.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| void | **[BitStreamReader](class_bit_stream_reader.md#function-bitstreamreader)**(Serializer _ctx)<br>Initializes a [BitStreamReader](class_bit_stream_reader.md) object with the given Serializer context.  |
| int | **[GetIndex](class_bit_stream_reader.md#function-getindex)**()<br>Returns the current bit index.  |
| bool | **[ReadAligned](class_bit_stream_reader.md#function-readaligned)**(out int value)<br>Reads an aligned integer value from the bitstream.  |
| bool | **[ReadAligned](class_bit_stream_reader.md#function-readaligned)**(out bool value)<br>Reads a boolean value from the bitstream.  |
| bool | **[ReadAligned](class_bit_stream_reader.md#function-readaligned)**(out Class value)<br>Reads a value from the bitstream in an aligned manner.  |
| bool | **[ReadAligned](class_bit_stream_reader.md#function-readaligned)**(out string value)<br>Reads a string value from the bitstream in an aligned manner.  |
| bool | **[ReadBool](class_bit_stream_reader.md#function-readbool)**(out bool value)<br>Reads a boolean value from the bitstream.  |
| bool | **[ReadHalfFloat](class_bit_stream_reader.md#function-readhalffloat)**(out float value)<br>Reads a half-precision floating-point value from the bit stream.  |
| bool | **[ReadHalfVector](class_bit_stream_reader.md#function-readhalfvector)**(out vector value)<br>Reads a half vector from the bitstream.  |
| bool | **[ReadPacked](class_bit_stream_reader.md#function-readpacked)**(out vector value)<br>Reads a packed vector value from the bitstream.  |
| bool | **[ReadPacked](class_bit_stream_reader.md#function-readpacked)**(out bool value)<br>Reads a packed boolean value from the bitstream.  |
| bool | **[ReadPacked](class_bit_stream_reader.md#function-readpacked)**(out int value)<br>Reads a packed integer value from the bitstream.  |
| bool | **[ReadPacked](class_bit_stream_reader.md#function-readpacked)**(out float value)<br>Reads a packed float value from the bitstream.  |
| bool | **[ReadPacked](class_bit_stream_reader.md#function-readpacked)**(out string value)<br>Reads a packed string from the bitstream.  |
| bool | **[ReadSInt](class_bit_stream_reader.md#function-readsint)**(out int value, int bits)<br>Reads a signed integer value from the bitstream.  |
| bool | **[ReadUInt](class_bit_stream_reader.md#function-readuint)**(out int value, int bits)<br>Reads an unsigned integer value from the bitstream.  |
| void | **[~BitStreamReader](class_bit_stream_reader.md#function-~bitstreamreader)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](class_bit_stream_reader.md#variable-m-bitindex)**  |
| public Serializer | **[m_Context](class_bit_stream_reader.md#variable-m-context)**  |
| public int | **[m_Working](class_bit_stream_reader.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](class_bit_stream_reader.md#variable-m-workingindex)**  |

## Detailed Description

```cpp
class BitStreamReader;
```

A class for reading bits from a stream. 

This class is responsible for reading data into a bitstream. It provides methods to read various types of data (like integers, floats, etc.) from the bitstream. 

## Public Functions Documentation

### function Align

```cpp
void Align()
```

Aligns the bitstream to the next integer boundary. 

### function BitStreamReader

```cpp
void BitStreamReader(
    Serializer _ctx
)
```

Initializes a [BitStreamReader](class_bit_stream_reader.md) object with the given Serializer context. 

**Parameters**: 

  * **_ctx** The Serializer context to use for reading bits. 


### function GetIndex

```cpp
int GetIndex()
```

Returns the current bit index. 

**Return**: The current bit index. 

### function ReadAligned

```cpp
bool ReadAligned(
    out int value
)
```

Reads an aligned integer value from the bitstream. 

**Parameters**: 

  * **value** The integer value read from the bitstream. 


**Return**: True if the read operation was successful, false otherwise. 

### function ReadAligned

```cpp
bool ReadAligned(
    out bool value
)
```

Reads a boolean value from the bitstream. 

**Parameters**: 

  * **value** - The boolean value to be read. 


**Return**: Returns true if the read operation was successful, false otherwise. 

### function ReadAligned

```cpp
bool ReadAligned(
    out Class value
)
```

Reads a value from the bitstream in an aligned manner. 

**Parameters**: 

  * **value** The value to be read from the bitstream. 


**Return**: Returns true if the value was successfully read, false otherwise. 

### function ReadAligned

```cpp
bool ReadAligned(
    out string value
)
```

Reads a string value from the bitstream in an aligned manner. 

**Parameters**: 

  * **value** The string value read from the bitstream. 


**Return**: True if the read operation was successful, false otherwise. 

### function ReadBool

```cpp
bool ReadBool(
    out bool value
)
```

Reads a boolean value from the bitstream. 

**Parameters**: 

  * **value** - The boolean value read from the bitstream. 


**Return**: True if the boolean value was successfully read, false otherwise. 

### function ReadHalfFloat

```cpp
bool ReadHalfFloat(
    out float value
)
```

Reads a half-precision floating-point value from the bit stream. 

**Parameters**: 

  * **value** The half-precision floating-point value read from the bit stream. 


**Return**: True if the read operation was successful, false otherwise. 

### function ReadHalfVector

```cpp
bool ReadHalfVector(
    out vector value
)
```

Reads a half vector from the bitstream. 

**Parameters**: 

  * **value** The vector to store the read value. 


**Return**: True if the read was successful, false otherwise. 

### function ReadPacked

```cpp
bool ReadPacked(
    out vector value
)
```

Reads a packed vector value from the bitstream. 

**Parameters**: 

  * **value** The vector value to be read. 


**Return**: True if the value was successfully read, false otherwise. 

### function ReadPacked

```cpp
bool ReadPacked(
    out bool value
)
```

Reads a packed boolean value from the bitstream. 

**Parameters**: 

  * **value** The boolean value to be read. 


**Return**: True if the value was read successfully, false otherwise. 

### function ReadPacked

```cpp
bool ReadPacked(
    out int value
)
```

Reads a packed integer value from the bitstream. 

**Parameters**: 

  * **value** The integer value read from the bitstream. 


**Return**: True if the integer value was successfully read, false otherwise. 

### function ReadPacked

```cpp
bool ReadPacked(
    out float value
)
```

Reads a packed float value from the bitstream. 

**Parameters**: 

  * **value** The float value read from the bitstream. 


**Return**: True if the value was successfully read, false otherwise. 

### function ReadPacked

```cpp
bool ReadPacked(
    out string value
)
```

Reads a packed string from the bitstream. 

**Parameters**: 

  * **value** The string value read from the bitstream. 


**Return**: True if the string was successfully read, false otherwise. 

### function ReadSInt

```cpp
bool ReadSInt(
    out int value,
    int bits
)
```

Reads a signed integer value from the bitstream. 

**Parameters**: 

  * **value** The integer value read from the bitstream. 
  * **bits** The number of bits to read for the integer value. 


**Return**: True if the integer value was successfully read, false otherwise. 

### function ReadUInt

```cpp
bool ReadUInt(
    out int value,
    int bits
)
```

Reads an unsigned integer value from the bitstream. 

**Parameters**: 

  * **value** - The integer value read from the bitstream. 
  * **bits** - The number of bits to read from the bitstream. 


**Return**: true if the value was successfully read, false otherwise. 

### function ~BitStreamReader

```cpp
void ~BitStreamReader()
```


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

Updated on 2023-08-26 at 12:05:38 -0500