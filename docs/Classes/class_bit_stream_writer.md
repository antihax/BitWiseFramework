---
title: BitStreamWriter

---

# BitStreamWriter



 [More...](#detailed-description)

Inherited by [BitWiseScriptRPC](Classes/class_bit_wise_script_r_p_c.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[BitStreamWriter](Classes/class_bit_stream_writer.md#function-bitstreamwriter)**(Serializer context =NULL) |
| void | **[~BitStreamWriter](Classes/class_bit_stream_writer.md#function-~bitstreamwriter)**() |
| int | **[GetIndex](Classes/class_bit_stream_writer.md#function-getindex)**()<br>GetIndex returns the current bit index.  |
| bool | **[Align](Classes/class_bit_stream_writer.md#function-align)**()<br>Aligns the bitstream to the next integer boundary.  |
| protected void | **[Reset](Classes/class_bit_stream_writer.md#function-reset)**()<br>Resets the bitstream to the beginning. Should not be called by a developer.  |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(bool value)<br>Writes a boolean value to the bitstream and returns the original value.  |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(float value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(string value) |
| bool | **[WritePacked](Classes/class_bit_stream_writer.md#function-writepacked)**(Object object) |
| bool | **[WriteUInt](Classes/class_bit_stream_writer.md#function-writeuint)**(int value, int bits) |
| bool | **[WriteSInt](Classes/class_bit_stream_writer.md#function-writesint)**(int value, int bits) |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(int value)<br>Write a value to the RPC stream, aligns to next int and writes the value.  |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(bool value) |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(Class value) |
| bool | **[WriteAligned](Classes/class_bit_stream_writer.md#function-writealigned)**(string value) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| public int | **[m_BitIndex](Classes/class_bit_stream_writer.md#variable-m-bitindex)**  |
| protected Serializer | **[m_Context](Classes/class_bit_stream_writer.md#variable-m-context)**  |
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
    Serializer context =NULL
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
bool Align()
```

Aligns the bitstream to the next integer boundary. 

Generally, this function is only called at the end of a message to ensure proper alignment. 


### function Reset

```cpp
protected void Reset()
```

Resets the bitstream to the beginning. Should not be called by a developer. 

### function WritePacked

```cpp
bool WritePacked(
    bool value
)
```

Writes a boolean value to the bitstream and returns the original value. 

**Parameters**: 

  * **value** The boolean value to be written to the bitstream. 


**Return**: Returns true if the operation is successful, false otherwise. 

### function WritePacked

```cpp
bool WritePacked(
    float value
)
```


### function WritePacked

```cpp
bool WritePacked(
    string value
)
```


### function WritePacked

```cpp
bool WritePacked(
    Object object
)
```


### function WriteUInt

```cpp
bool WriteUInt(
    int value,
    int bits
)
```


**Parameters**: 

  * **value** The integer value to be written to the bitstream. 
  * **bits** The number of bits to be written from the value to the bitstream.


**Return**: Returns true if the operation is successful, false otherwise. 

WriteUInt is a function that writes an unsigned integer value to a bitstream.


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


### function WriteAligned

```cpp
bool WriteAligned(
    int value
)
```

Write a value to the RPC stream, aligns to next int and writes the value. 

**Note**: Aligned writes should not be used unless needed such as deep serialization however no compression takes place with these style of writes. Use sparingly. 

### function WriteAligned

```cpp
bool WriteAligned(
    bool value
)
```


### function WriteAligned

```cpp
bool WriteAligned(
    Class value
)
```


### function WriteAligned

```cpp
bool WriteAligned(
    string value
)
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

Updated on 2023-08-25 at 15:23:18 -0500