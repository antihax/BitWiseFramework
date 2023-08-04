---
title: BitStreamWriter

---

# BitStreamWriter



 [More...](#detailed-description)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitStreamWriter](Classes/class_bit_stream_writer.md#function-bitstreamwriter)**(Serializer _ctx) |
| void | **[~BitStreamWriter](Classes/class_bit_stream_writer.md#function-~bitstreamwriter)**() |
| int | **[GetIndex](Classes/class_bit_stream_writer.md#function-getindex)**()<br>GetIndex returns the current bit index.  |
| void | **[Align](Classes/class_bit_stream_writer.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| bool | **[WriteBool](Classes/class_bit_stream_writer.md#function-writebool)**(bool value)<br>Writes a boolean value to the bitstream and returns the original value.  |
| bool | **[WriteUint](Classes/class_bit_stream_writer.md#function-writeuint)**(int value, int bits) |
| void | **[writeSInt](Classes/class_bit_stream_writer.md#function-writesint)**(int value, int bits) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](Classes/class_bit_stream_writer.md#variable-m-bitindex)**  |
| public Serializer | **[ctx](Classes/class_bit_stream_writer.md#variable-ctx)**  |
| public int | **[m_Working](Classes/class_bit_stream_writer.md#variable-m-working)**  |
| public int | **[m_WorkingIndex](Classes/class_bit_stream_writer.md#variable-m-workingindex)**  |

## Detailed Description

```cpp
class BitStreamWriter;
```


This class is responsible for writing data into a bitstream. It provides methods to write various types of data (like integers, floats, etc.) into the bitstream. The data can then be read from the bitstream using a [BitStreamReader](Classes/class_bit_stream_reader.md). 

## Public Functions Documentation

### function BitStreamWriter

```cpp
void BitStreamWriter(
    Serializer _ctx
)
```


### function ~BitStreamWriter

```cpp
void ~BitStreamWriter()
```


### function GetIndex

```cpp
int GetIndex()
```

GetIndex returns the current bit index. 

### function Align

```cpp
void Align()
```

Aligns the bitstream to the next integer boundary. 

Generally, this function is only called at the end of a message to ensure proper alignment. 


### function WriteBool

```cpp
bool WriteBool(
    bool value
)
```

Writes a boolean value to the bitstream and returns the original value. 

**Parameters**: 

  * **value** The boolean value to be written to the bitstream. 


**Return**: The original boolean value that was written to the bitstream. 

### function WriteUint

```cpp
bool WriteUint(
    int value,
    int bits
)
```


**Parameters**: 

  * **value** The integer value to be written to the bitstream. 
  * **bits** The number of bits to be written from the value to the bitstream.


**Return**: Returns true if the operation is successful, false otherwise. 

WriteUint is a function that writes an unsigned integer value to a bitstream.


### function writeSInt

```cpp
void writeSInt(
    int value,
    int bits
)
```


## Public Attributes Documentation

### variable m_BitIndex

```cpp
public int m_BitIndex;
```


### variable ctx

```cpp
public Serializer ctx;
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

Updated on 2023-08-04 at 16:20:12 -0500